//
//  xiaoweiSDK.h
//  xiaoweiSDK
//
//  Created by cppwang(王缘) on 2019/4/14.
//  Copyright © 2019年 Tencent. All rights reserved.
//

#ifndef xiaoweiSDK_h
#define xiaoweiSDK_h

#include "deviceCommonDef.h"
#include "xiaoweiAudioType.h"


/**
 * @brief Start xiaowei voice assistant service, call this after on_login_complete(0).
 * @return {@see device_error_code}
 */
DEVICE_API int xiaowei_service_start(XIAOWEI_CALLBACK *callback, XIAOWEI_NOTIFY *notify);

/**
 * @brief voice/text/tts request
 * @param voice_id [output] A pointer to get voiceID, malloc size should be 33.
 * @param type @XIAOWEI_CHAT_TYPE
 * @param chat_data audio/text data
 * @param context context and setting for request. @XIAOWEI_PARAM_CONTEXT
 * @return {@see device_error_code}
 * @code
     // sample 1, text request
     char voice_id[33] = {0};  // size must be 33
     XIAOWEI_PARAM_CONTEXT context = {0};
     context.silent_timeout = 500;
     context.speak_timeout = 5000;
     context.voice_request_begin = true;
     context.voice_request_end = false;
     const char *text = "我要听林俊杰的歌";  //request text utf-8 type, NO emoji
     xiaowei_request(voice_id, xiaowei_chat_via_text, text, (uint32_t)strlen(text), &context);
     
     //////////
 
     // sample 2, voice request
     char buf[1024] = {your voice data, 1ch, 16bit, 16KHz, PCM format};  // XIAOWEI_BUF_MIN_LENGTH < leen < XIAOWEI_BUF_MAX_LENGTH
     // The first call
     char voice_id[33] = {0};
     XIAOWEI_PARAM_CONTEXT context = {0};
     context.silent_timeout = 500;
     context.speak_timeout = 5000;
     context.voice_request_begin = true;
     context.voice_request_end = false;
     XIAOWEI_PARAM_PROPERTY property = xiaowei_param_local_vad; // Using local vad(need to send end flag by yourself). If using cloud vad, you need to stop sendding data when the on_silent event triggered.
     context.request_param = property;
     xiaowei_request(voice_id, xiaowei_chat_via_voice, buf, sizeof(buf), &context);
 
     // The continully call
     context.voice_request_begin = false;
     memset(buf, new_data, 1024); // next audio data
     xiaowei_request(voice_id, xiaowei_chat_via_voice, buf, sizeof(buf), &context);
 
     // ....
 
     // The last call
     context.voice_request_end = true;
     memset(buf, 0, 1024); // th last call to send request_end flag, buf will be abandom.
     xiaowei_request(voice_id, xiaowei_chat_via_voice, buf, sizeof(buf), &context);
 
 */
DEVICE_API int xiaowei_request(char *voice_id, XIAOWEI_CHAT_TYPE type, const char *chat_data, unsigned int char_data_len, XIAOWEI_PARAM_CONTEXT *context);

/**
 * @brief Stop xiawoei service
 * @return {@see device_error_code}
 */
DEVICE_API int xiaowei_service_stop();

/**
 * @brief Force stop a request by voice id, set nullptr to stop all request.
 * @return {@see device_error_code}
 */
DEVICE_API int xiaowei_request_cancel(const char *voice_id);

/**
 * @brief reserved
 * @param st login account.
 * @return {@see device_error_code}
 */
DEVICE_API int xiaowei_set_skill_account(char *voice_id, XIAOWEI_PARAM_LOGIN_STATUS *st);

/**
 * @brief reserved
 * @param st only need to set skillID
 * @return {@see device_error_code}
 */
DEVICE_API int xiaowei_get_skill_account(char *voice_id, XIAOWEI_PARAM_LOGIN_STATUS *st);

/**
 * @brief report current play status. The device should report ASAP while the state changes.
 * @param state the current playing state of the device.
 * @return {@see device_error_code}
 * @note
     Only resume-abled resources(resources that can be recovered after interruption) need to be reported, such as music and FM.
     No need to report nonrecoverable resources, such as TTS playback.
     Here are some common sample to report:
     1. switch song: report twice. Firstly, report the replaced song play_state_abort. Then report the new song play_state_start(It's better if you can report preload first).
     2. Interrupted by wakeup and voice request(the playing need to pause automaticly): report play_state_paused.
     3. If 2 asked for playing a new song:Report this paused song play_state_abort，then report new song play_state_start(It's better if you can report preload first).
     4. If 2 asked for the weather or chat：Firstly, no need for any report, just playing the weather or chat TTS, Then the privious song resume automaticly and report it play_state_resume.
     5. All resource play finish, nothing todo, report play_state_idle.
     6. A song play finish and play next song automaticly: Report the first one play_state_stoped, then report the next one play_state_start(It's better if you can report preload first).
     7. All URL resource, if possible, report preload befor start.
     8. Switch to a new skill and play list refreshed, report the previous play_state_abort and play_state_finished, Then report new one. Pay attention to report the correct skill ID.
 */
DEVICE_API int xiaowei_report_state(XIAOWEI_PARAM_STATE *state);

/**
 * @brief common request to get resources, set account info, get alarm list and so on. Get the detail information in our document.
 * @param voice_id reqeust id, like which in xiaowei_request(...).
 * @param cmd see in web
 * @param sub_cmd see in web
 * @param callback get result in callback. You can set different callback for different request, or set a static callback and handle it by voiceID.
 * @return {@see device_error_code}
 */
DEVICE_API int xiaowei_request_cmd(char* voice_id, const char* cmd, const char* sub_cmd,  const char* param, XIAOWEI_ON_REQUEST_CMD_CALLBACK callback);

/**
 * @Deprecated use xiaowei_request_cmd(...) instead.
 * @brief set reource quality for QQ music.
 * @param quality quality，0 fluent(mp3)  1 standard(m4a) 2 high quality(m4a) 3 Nondestructive(flac)
 * @return 0 success, other failed
 */
DEVICE_API int xiaowei_resource_set_quality(int quality) DEPRECATED_API;
//__attribute__((deprecated));

/**
 * @Deprecated use `xiaowei_request_cmd(...)` instead.
 * @brief pre-load more resource list.
 * @return {@see device_error_code}
 */
DEVICE_API int xiaowei_resource_get_list(char *voice_id, const XIAOWEI_PARAM_SKILL *skill_info, const char *play_id, unsigned int max_list_size, bool is_up) DEPRECATED_API;

/**
 * @Deprecated use `xiaowei_request_cmd(...)` instead.
 * @brief Load details of resources. Deprecated, use `xiaowei_request_cmd(...)` instead.
 * @return {@see device_error_code}
 */
DEVICE_API int xiaowei_resource_get_detail_info(char *voice_id, const XIAOWEI_PARAM_SKILL *skill_info, char **list_play_id, int list_size) DEPRECATED_API;

/**
 * @Deprecated use `xiaowei_request_cmd(...)` instead.
 * @brief Refresh url of resources. Deprecated, use `xiaowei_request_cmd(...)` instead.
 * @return {@see device_error_code}
 */
DEVICE_API int xiaowei_resource_refresh_list(char *voice_id, const XIAOWEI_PARAM_SKILL *skill_info, char **list_play_id, int list_size)DEPRECATED_API;

/**
 * @Deprecated use `xiaowei_request_cmd(...)` instead.
 * @brief set favorite of one resource
 * @return {@see device_error_code}
 */
DEVICE_API int xiaowei_resource_set_favorite(char *voice_id, const XIAOWEI_PARAM_SKILL *skill_info, const char *play_id, bool is_favorite) DEPRECATED_API;

/**
 * @brief enable/disable visual to access function.
 * @param enable true:enable false:disable
 * @return {@see device_error_code}
 */
DEVICE_API int xiaowei_enable_v2a(bool enable);

/**
 * @brief set v2a or user contact(not xiaowei contact, usually for phone)
 * @param type 0:v2a words list 1:user contact
 * @param words_list {@see XIAOWEI_WORDS_TYPE for detail}
 * @param list_size size of words_list
 * @param callback only for type xiaowei_words_contact
 * @return {@see device_error_code}
 */
DEVICE_API int xiaowei_set_wordslist(XIAOWEI_WORDS_TYPE type, char** words_list, int list_size, XIAOWEI_SET_WORDSLIST_CALLBACK callback);

/**
 * @brief reserved
 * @return {@see device_error_code}
 */
DEVICE_API int xiaowei_request_protocol_tts(char* voice_id, const char *remark, unsigned long long timestamp, int cmd);

/**
 * @brief Set GPS callback, Will be called at the begin of a round of request while XIAOWEI_PARAM_PROPERTY.xiaowei_param_gps is enabled.
   This is a synchronous call, so please make sure it will never block and faster enough. It is recommended that the user set a buffer to store GPS information
 * @return {@see device_error_code}
 */
DEVICE_API int xiaowei_set_gps_callback(XIAOWEI_GPS_CALLBACK callback);


/**
 * @brief If not satisfied with one request, call this to feedback.
 * @param voice_id voiceID of dissatisfied request
 * @return {@see device_error_code}
 */
DEVICE_API int xiaowei_error_feed_back(const char *voice_id);


/**
 * @brief Upload some logs to cloud to analysis problems, such as crash log, stacktree. Do not call this if there were no fatal problem.
 * @param log {@see XIAOWEI_PARAM_LOG_REPORT}
 * @return {@see device_error_code}
 */
DEVICE_API int xiaowei_user_report(XIAOWEI_PARAM_LOG_REPORT *log);


/**
 * @brief Fetch IoT device list of this device's binder(manager), will return by on_request(...)
 * @return {@see device_error_code}
 */
DEVICE_API int xiaowei_get_iot_device_list();

/**
 * @brief reserved
 * @param availability XIAOWEI_PARAM_AVAILABILITY
 * @return {@see device_error_code}
 */
DEVICE_API int xiaowei_set_device_availability(int availability);


#endif /* xiaoweiSDK_h */
