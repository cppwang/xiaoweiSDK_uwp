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
 * ������ͨ����ӿ�
 *
 */
#define TXCA_BUF_MAX_LENGHT 6400

#define TXCA_PARAM_LOG_EVENT_PLAYER_START  "client_OnStart"
#define TXCA_PARAM_LOG_EVENT_PLAYER_PREPARE  "client_OnPrepareAsync"
#define TXCA_PARAM_LOG_EVENT_TTS_BEGIN  "client_OnTTSBegin"
#define TXCA_PARAM_LOG_EVENT_TTS_PREPARED  "client_OnTTSCallback"
#define TXCA_PARAM_LOG_EVENT_TTS_END  "client_OnTTSEnd"

#define TXCA_PARAM_LOG_EVENT_QQCALL_CALL_OUT  "status_qqcall_call_out" // ����
#define TXCA_PARAM_LOG_EVENT_QQCALL_CALL_INVITE  "status_qqcall_invite" // ����
#define TXCA_PARAM_LOG_EVENT_QQCALL_ING  "status_qqcall_ing" // ͨ����
#define TXCA_PARAM_LOG_EVENT_QQCALL_OUT  "status_qqcall_out" // �˳�ͨ��

typedef enum _txca_event {
    txca_event_on_idle = 0,          // ����
    txca_event_on_request_start = 1, // ����ʼ
    txca_event_on_speak = 2,         // ��⵽˵��
    txca_event_on_silent = 3,        // ��⵽����(only@device has not txca_device_local_vad)
    txca_event_on_recognize = 4,     // ʶ���ı�ʵʱ����
    txca_event_on_response = 5,      // �����յ���Ӧ
    txca_event_on_tts = 6,           // С΢��̨���͵�TTS��Ϣ
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
    txca_resource_url = 0,  //url��Դ
    txca_resource_text = 1, //���ı�(��TTS)
    txca_resource_tts = 2,  //TTS����(�����ı���Ϣ)
    txca_resource_file = 3, //������
    txca_resource_location = 4,
    txca_resource_command = 5, //ָ������
    txca_resource_intent = 6,  //��������
    txca_resource_tts_url = 7,
    txca_resource_unknown = 99,
} TXCA_RESOURCE_FORMAT;

typedef enum _txca_playlist_action {
    txca_playlist_replace_all = 0,     // �жϵ�ǰ���ţ��滻�б�
    txca_playlist_enqueue_front = 1,   // ƴ�ӵ��б��ͷ
    txca_playlist_enqueue_back = 2,    // ƴ�ӵ��б��β
    txca_playlist_replace_enqueue = 3, // ���жϵ�ǰ���ŵ���Դ���滻�б������
    txca_playlist_update_enqueue = 4,  // ���жϲ��ţ������б���ĳЩ������Դ��url��quality�ֶ���Ϣ
} TXCA_PLAYLIST_ACTION;

typedef enum _txca_chat_type {
    txca_chat_via_voice = 0,  //��������
    txca_chat_via_text = 1,   //�ı�����
    txca_chat_only_tts = 2,   //tts����
    txca_chat_via_intent = 3, //
    txca_chat_via_wakeup_check = 4, //����У������
} TXCA_CHAT_TYPE;

typedef enum _txca_playstate {
    txca_playstate_preload = 0,  // Ԥ����
    txca_playstate_start = 1,    // һ�׸迪ʼ����
    txca_playstate_paused = 2,   // ��ͣ
    txca_playstate_stopped = 3,  // һ�׸貥�����
    txca_playstate_finished = 4, // ������Դ���Ž�����ֹͣ������
    txca_playstate_idle = 5,
    txca_playstate_resume = 6, //����
} TXCA_PLAYSTATE;

typedef enum _txca_account_type {
    txca_account_null = 0,
    txca_account_qq = 1,  // QQ
    txca_account_wx = 2,  // ΢��
    txca_account_3rd = 3, // 3rd
} TXCA_ACCOUNT_TYPE;

typedef enum _txca_wakeup_flag {
    txca_wakeup_flag_no = 0, // �����ƶ�У�黽�ѵĽ��
    txca_wakeup_flag_fail = 1, // ����У��ʧ��
    txca_wakeup_flag_suc = 2, // �ɹ����ѣ�ֻ˵�˻��Ѵ�û������˵��
    txca_wakeup_flag_suc_rsp = 3,// �ɹ����Ѳ����յ���������Ӧ
    txca_wakeup_flag_suc_continue = 4,// �ɹ����Ѳ��һ���Ҫ����������������֪���᲻������˵��
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

//�豸�������ϣ�����ʹ�ñ���vad����gps��������wifiap��
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

//������Ϣ
typedef struct _txca_param_skill
{
    const char *name; // name
    const char *id;   // ID
    int type;
} TXCA_PARAM_SKILL;

// ������Դ
typedef struct _txca_param_resource
{
    TXCA_RESOURCE_FORMAT format; // url/tts/notify/text/command
    char *id;                    // resource's id, if format == text or notify, id is null
    char *content;               // url(url/notify) or text(tts/text) or command value
    int play_count;              // play count, if value == -1, means no limit
    unsigned int offset;         // url's seek
    char *extend_buffer;         // json
} TXCA_PARAM_RESOURCE;

// ������Դ����
typedef struct _txca_param_res_group
{
    TXCA_PARAM_RESOURCE *resources;
    unsigned int resources_size;
} TXCA_PARAM_RES_GROUP;

//������
typedef struct _txca_param_context
{
    const char *id;              //context id
    unsigned int speak_timeout;  //wait speak timeout time(ms)
    unsigned int silent_timeout; //speak to silent timeout time(ms)
    bool voice_request_begin;
    bool voice_request_end;
    TXCA_WAKEUP_PROFILE wakeup_profile; //Զ��or����
    TXCA_WAKEUP_TYPE wakeup_type;
    const char *wakeup_word; // ���Ѵ��ı�
    bool vad_only;           // �������ֻ����vad���
} TXCA_PARAM_CONTEXT;

// �����Ʒ�������
typedef struct _txca_param_response
{
    TXCA_PARAM_SKILL skill_info; //������Ϣ
    TXCA_PARAM_SKILL last_skill_info; //֮ǰ�ĳ�����Ϣ

    unsigned int error_code; //���������

    char voice_id[33];          //����id
    TXCA_PARAM_CONTEXT context; //��������Ϣ

    const char *request_text;   //ASR����ı�
    unsigned int response_type; //������Ϣչʾ��json����type
    const char *response_data;  //������Ϣչʾ��json����

    unsigned int resource_groups_size;     //��Դ�����б�size
    TXCA_PARAM_RES_GROUP *resource_groups; //��Դ�����б�
    bool has_more_playlist;                //�Ƿ���Լ��ظ���
    bool is_recovery;                      //�Ƿ���Իָ�����
    bool is_notify;                        //��֪ͨ
    unsigned int wakeup_flag;              //TXCA_WAKEUP_FLAG �ƶ�У�黽������������Ľ����0��ʾ�Ǹ�������1��ʾ����ʧ�ܣ�2��ʾ���ѳɹ�����δ����˵����3��ʾ˵��ָ��Ѵʣ�4����Ϊ�м�������ʾ���ѳɹ��ˣ����ڼ����������˵�������Ѿ�������˵����
    TXCA_PLAYLIST_ACTION play_behavior;    //�б�ƴ������
    
    const char *auto_test_data;  //�����Զ������Ե������Ϣ
    const char* rsp_text;
} TXCA_PARAM_RESPONSE;

//state for report
typedef struct _txca_param_state
{
    TXCA_PARAM_SKILL skill_info; //������Ϣ

    unsigned int play_state; //txca_playstate
    const char *play_id;
    const char *play_content;
    unsigned long long play_offset; // ��λ��s
    unsigned int play_mode;
} TXCA_PARAM_STATE;

//audio data, for TTS&etc..
typedef struct _txca_param_audio_data
{
    const char *id;                // ��Դid
    unsigned int seq;              // ���
    unsigned int is_end;           // ���һ����
    unsigned int pcm_sample_rate;  // pcm������
    unsigned int sample_rate;      // ��Ƶ���ݵ�(����:opus)������
    unsigned int channel;          // ����
    TXCA_AUDIO_DATA_FORMAT format; // ��ʽ(����:opus)
    const char *raw_data;          // ��������
    unsigned int raw_data_len;     // ���ݳ���
} TXCA_PARAM_AUDIO_DATA;

CXX_EXTERN_END

#endif // __TX_CLOUD_AUDIO_TYPE_H__
