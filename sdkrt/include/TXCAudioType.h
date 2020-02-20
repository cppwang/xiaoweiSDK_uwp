/*
 * Tencent is pleased to support the open source community by making  XiaoweiSDK Demo Codes available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company. All rights reserved.
 *
 * Licensed under the MIT License (the "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 * http://opensource.org/licenses/MIT
 *
 * Unless required by applicable law or agreed to in writing, software distributed under the License
 * is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
 * or implied. See the License for the specific language governing permissions and limitations under
 * the License.
 *
 */
#ifndef __TX_CLOUD_AUDIO_TYPE_H__
#define __TX_CLOUD_AUDIO_TYPE_H__

#include "TXSDKCommonDef.h"

CXX_EXTERN_BEGIN

/**
 *
 * 语音云通道层接口
 *
 */
#define TXCA_BUF_MAX_LENGHT 6400

#define TXCA_PARAM_LOG_EVENT_PLAYER_START  "client_OnStart"
#define TXCA_PARAM_LOG_EVENT_PLAYER_PREPARE  "client_OnPrepareAsync"
#define TXCA_PARAM_LOG_EVENT_TTS_BEGIN  "client_OnTTSBegin"
#define TXCA_PARAM_LOG_EVENT_TTS_PREPARED  "client_OnTTSCallback"
#define TXCA_PARAM_LOG_EVENT_TTS_END  "client_OnTTSEnd"

#define TXCA_PARAM_LOG_EVENT_QQCALL_CALL_OUT  "status_qqcall_call_out" // 主叫
#define TXCA_PARAM_LOG_EVENT_QQCALL_CALL_INVITE  "status_qqcall_invite" // 被叫
#define TXCA_PARAM_LOG_EVENT_QQCALL_ING  "status_qqcall_ing" // 通话中
#define TXCA_PARAM_LOG_EVENT_QQCALL_OUT  "status_qqcall_out" // 退出通话

typedef enum _txca_event {
    txca_event_on_idle = 0,          // 空闲
    txca_event_on_request_start = 1, // 请求开始
    txca_event_on_speak = 2,         // 检测到说话
    txca_event_on_silent = 3,        // 检测到静音(only@device has not txca_device_local_vad)
    txca_event_on_recognize = 4,     // 识别文本实时返回
    txca_event_on_response = 5,      // 请求收到响应
    txca_event_on_tts = 6,           // 小微后台推送的TTS信息
    txca_event_on_iot_info = 8,
} TXCA_EVENT;

typedef enum _txca_device_property {
    txca_device_local_vad = 0x0000000000000001, // use local vad
    txca_device_gps = 0x0000000000000002,
    txca_device_wifi_ap = 0x0000000000000004,
    txca_device_local_tts = 0x0000000000000008, // use local tts
    txca_device_dump_silk = 0x0000000000000010, // dump silk
} TXCA_DEVICE_PROPERTY;

typedef enum _txca_resource_format {
    txca_resource_url = 0,  //url资源
    txca_resource_text = 1, //纯文本(无TTS)
    txca_resource_tts = 2,  //TTS播放(附带文本信息)
    txca_resource_file = 3, //提醒类
    txca_resource_location = 4,
    txca_resource_command = 5, //指令类型
    txca_resource_intent = 6,  //语义类型
    txca_resource_tts_url = 7,
    txca_resource_unknown = 99,
} TXCA_RESOURCE_FORMAT;

typedef enum _txca_playlist_action {
    txca_playlist_replace_all = 0,     // 中断当前播放，替换列表
    txca_playlist_enqueue_front = 1,   // 拼接到列表队头
    txca_playlist_enqueue_back = 2,    // 拼接到列表队尾
    txca_playlist_replace_enqueue = 3, // 不中断当前播放的资源，替换列表的详情
    txca_playlist_update_enqueue = 4,  // 不中断播放，更新列表中某些播放资源的url和quality字段信息
} TXCA_PLAYLIST_ACTION;

typedef enum _txca_chat_type {
    txca_chat_via_voice = 0,  //语音请求
    txca_chat_via_text = 1,   //文本请求
    txca_chat_only_tts = 2,   //tts请求
    txca_chat_via_intent = 3, //
    txca_chat_via_wakeup_check = 4, //唤醒校验请求
} TXCA_CHAT_TYPE;

typedef enum _txca_playstate {
    txca_playstate_preload = 0,  // 预加载
    txca_playstate_start = 1,    // 一首歌开始播放
    txca_playstate_paused = 2,   // 暂停
    txca_playstate_stopped = 3,  // 一首歌播放完毕
    txca_playstate_finished = 4, // 所有资源播放结束，停止播放了
    txca_playstate_idle = 5,
    txca_playstate_resume = 6, //继续
} TXCA_PLAYSTATE;

typedef enum _txca_account_type {
    txca_account_null = 0,
    txca_account_qq = 1,  // QQ
    txca_account_wx = 2,  // 微信
    txca_account_3rd = 3, // 3rd
} TXCA_ACCOUNT_TYPE;

typedef enum _txca_wakeup_flag {
    txca_wakeup_flag_no = 0, // 不是云端校验唤醒的结果
    txca_wakeup_flag_fail = 1, // 唤醒校验失败
    txca_wakeup_flag_suc = 2, // 成功唤醒，只说了唤醒词没有连续说话
    txca_wakeup_flag_suc_rsp = 3,// 成功唤醒并且收到了最终响应
    txca_wakeup_flag_suc_continue = 4,// 成功唤醒并且还需要继续传声音，还不知道会不会连续说话
} TXCA_WAKEUP_FLAG;

typedef enum _txca_audio_data_format {
    txca_audio_data_pcm = 0,
    txca_audio_data_silk = 1,
    txca_audio_data_opus = 2,
} TXCA_AUDIO_DATA_FORMAT;

typedef enum _txca_wakeup_type {
    txca_wakeup_type_local = 0,
    txca_wakeup_type_cloud = 1,
    txca_wakeup_type_local_with_text = 2,
} TXCA_WAKEUP_TYPE;

typedef enum _txca_wakeup_profile {
    txca_wakeup_profile_far = 0,  // 
    txca_wakeup_profile_near = 1, // 
} TXCA_WAKEUP_PROFILE;

//account data
typedef struct _txca_param_account
{
    unsigned int type;   // TXCA_ACCOUNT_TYPE
    const char *account; // if type is QQ/WX, must set value to token and appid
    const char *token;   // if type is 3rd, token is null, and must bind/unbind device by cgi
    const char *appid;

    char *buffer;            // account buffer
    unsigned int buffer_len; // account buffer length
} TXCA_PARAM_ACCOUNT;

//设备能力集合，比如使用本地vad、有gps、可以做wifiap等
typedef struct _txca_param_device
{
    unsigned long long properties; // devices prop as txca_device_property
    char *extend_buffer;
    unsigned int extend_buffer_len;
} TXCA_PARAM_DEVICE;

typedef struct _txca_param_log
{
    int type; //1=ULS; 2=ALR; 3=All;

    const char *event;
    int ret_code;
    unsigned long long time_stamp_ms;
    const char *voice_id;
    const char *log_data;
    unsigned int sub_cmd;

    const char *skill_name;
    const char *skill_id;
} TXCA_PARAM_LOG;

//场景信息
typedef struct _txca_param_skill
{
    const char *name; // name
    const char *id;   // ID
    int type;
} TXCA_PARAM_SKILL;

// 播放资源
typedef struct _txca_param_resource
{
    TXCA_RESOURCE_FORMAT format; // url/tts/notify/text/command
    char *id;                    // resource's id, if format == text or notify, id is null
    char *content;               // url(url/notify) or text(tts/text) or command value
    int play_count;              // play count, if value == -1, means no limit
    unsigned int offset;         // url's seek
    char *extend_buffer;         // json
} TXCA_PARAM_RESOURCE;

// 播放资源集合
typedef struct _txca_param_res_group
{
    TXCA_PARAM_RESOURCE *resources;
    unsigned int resources_size;
} TXCA_PARAM_RES_GROUP;

//上下文
typedef struct _txca_param_context
{
    const char *id;              //context id
    unsigned int speak_timeout;  //wait speak timeout time(ms)
    unsigned int silent_timeout; //speak to silent timeout time(ms)
    bool voice_request_begin;
    bool voice_request_end;
    TXCA_WAKEUP_PROFILE wakeup_profile; //远场or近场
    TXCA_WAKEUP_TYPE wakeup_type;
    const char *wakeup_word; // 唤醒词文本
    bool vad_only;           // 这次请求只进行vad检测
} TXCA_PARAM_CONTEXT;

// 语音云返回数据
typedef struct _txca_param_response
{
    TXCA_PARAM_SKILL skill_info; //场景信息
    TXCA_PARAM_SKILL last_skill_info; //之前的场景信息

    unsigned int error_code; //请求错误码

    char voice_id[33];          //请求id
    TXCA_PARAM_CONTEXT context; //上下文信息

    const char *request_text;   //ASR结果文本
    unsigned int response_type; //用于信息展示的json数据type
    const char *response_data;  //用于信息展示的json数据

    unsigned int resource_groups_size;     //资源集合列表size
    TXCA_PARAM_RES_GROUP *resource_groups; //资源集合列表
    bool has_more_playlist;                //是否可以加载更多
    bool is_recovery;                      //是否可以恢复播放
    bool is_notify;                        //是通知
    unsigned int wakeup_flag;              //TXCA_WAKEUP_FLAG 云端校验唤醒请求带下来的结果，0表示非该类结果，1表示唤醒失败，2表示唤醒成功并且未连续说话，3表示说的指令唤醒词，4可能为中间结果，表示唤醒成功了，还在继续检测连续说话或者已经在连续说话了
    TXCA_PLAYLIST_ACTION play_behavior;    //列表拼接类型
    
    const char *auto_test_data;  //用于自动化测试的相关信息
    const char* rsp_text;
} TXCA_PARAM_RESPONSE;

//state for report
typedef struct _txca_param_state
{
    TXCA_PARAM_SKILL skill_info; //场景信息

    unsigned int play_state; //txca_playstate
    const char *play_id;
    const char *play_content;
    unsigned long long play_offset; // 单位是s
    unsigned int play_mode;
} TXCA_PARAM_STATE;

//audio data, for TTS&etc..
typedef struct _txca_param_audio_data
{
    const char *id;                // 资源id
    unsigned int seq;              // 序号
    unsigned int is_end;           // 最后一包了
    unsigned int pcm_sample_rate;  // pcm采样率
    unsigned int sample_rate;      // 音频数据的(例如:opus)采样率
    unsigned int channel;          // 声道
    TXCA_AUDIO_DATA_FORMAT format; // 格式(例如:opus)
    const char *raw_data;          // 数据内容
    unsigned int raw_data_len;     // 数据长度
} TXCA_PARAM_AUDIO_DATA;

CXX_EXTERN_END

#endif // __TX_CLOUD_AUDIO_TYPE_H__
