#pragma once


//ȫ�ִ������
namespace sdkrt
{
    public enum class error_code
    {
        /** global error, begin */
        error_null = 0,                                     /// success���ɹ�
        error_failed = 1,                                   /// failed��ʧ��
        error_re_init = 5002,                               /// re-init device sdk���ظ���ʼ��SDK
        error_init_path_invalid = 5003,                     /// sdk can not access this path��·�����ɴ�
        error_account_invalid = 5004,                       /// account invalid���Ƿ����˺���Ϣ
        error_param_invalid = 5005,                         /// param invalid�������Ƿ�
        error_sdk_uninit = 5006,                            /// sdk not inited��SDKδ��ʼ��
        error_memory_not_enough = 5007,                     /// input char[] size not enough���ڴ治��
        error_account_not_register = 5008,                  /// account register not success����¼δ�ɹ�
        /** global error, end */

        /** xiaowei err, begin */
        xiaowei_err_unknown = 2,                            /// δ֪����
        xiaowei_err_invalid_param = 3,                      /// �����Ƿ�
        xiaowei_err_login_failed = 4,                       /// SDK��û��¼�ɹ�
        xiaowei_err_mem_alloc = 5,                          /// �����ڴ�ʧ��
        xiaowei_err_internal = 6,                           /// �ڲ�����
        xiaowei_err_device_inited = 7,                      /// �豸�Ѿ���ʼ������
        xiaowei_err_invalid_export_id = 8,                  /// �Ƿ���exportID��username
        xiaowei_err_not_impl = 17,                          /// δʵ��
        xiaowei_err_call_too_frequently = 28,               /// ���õ�̫Ƶ����

        /** xiaowei dialog error */
        xiaowei_err_ai_audio_parse_req = 10000,              /// ����������
        xiaowei_err_ai_audio_empty_voice_data = 10001,       /// �յ���������
        xiaowei_err_ai_audio_voice_to_text = 10002,          /// ����ת�ı�ʧ�ܻ���Ϊ��
        xiaowei_err_ai_audio_text_analysis = 10003,          /// �������ʧ��
        xiaowei_err_ai_audio_text_to_voice = 10004,          /// �ı�ת����ʧ��
        xiaowei_err_ai_audio_resource_error = 10005,         /// ��Դ�޷���ȡ
        xiaowei_err_ai_audio_invalid_dev = 10006,            /// �����ƽ�����豸
        xiaowei_err_ai_audio_vad_too_long = 10007,           /// ������������ʱ�䳬����ֻ��30s
        xiaowei_err_ai_audio_vad_time_out = 10008,           /// ������������,5sû˵����������ⳬʱ
        xiaowei_err_ai_audio_change_scene = 10009,           /// ���ֶԻ��г����л���
        xiaowei_err_ai_audio_not_match_skill = 10010,        /// û�������κ�skill
        xiaowei_err_ai_audio_wait_result_timeout = 10017,    /// ˵�껰��ȴ�С΢��Ӧ��ʱ
        xiaowei_err_ai_audio_end_timeout = 10018,            /// β��������ⳬʱ
        xiaowei_err_ai_audio_is_not_understand = 20001,      /// û�����������˼��NLP�������������޷����
        xiaowei_err_ai_audio_not_support = 20002,            /// С΢������˼������Ŀǰ��֧���������
        xiaowei_err_ai_audio_internal_err = 20003,           /// ��̨�ڲ��������̴��������ߵ�����ֵķ�֧
        xiaowei_err_ai_audio_parameter_err = 20004,          /// ����Я���Ĳ����Ƿ�
        xiaowei_err_ai_audio_auth_err = 20005,               /// ��¼̬����δ��Ȩ
        xiaowei_err_ai_audio_req_logic_err = 20006,          /// �����߼�����������һ�����������
        xiaowei_err_ai_audio_illegal = 20007,                /// ���󲻺�г�����лƷ�����������
        xiaowei_err_ai_audio_too_frenquently = 21031,        /// Ƶ�����ñ����������

        /** Music related */
        xiaowei_music_err_music_parameter = -100000, /// ��������
        xiaowei_music_err_not_login = -100032, /// δ��¼���
        xiaowei_music_err_not_vip = -100033, /// ���Ѹ������ǻ�Ա���ܲ���
        xiaowei_music_err_not_find_singer_song = -100034, /// �Ը���-������ʽ��裬δ�ҵ����
        xiaowei_music_err_singer_song_copyright = -100035, /// �����û�а�Ȩ���ܲ���
        xiaowei_music_err_nothing_find = -100036, /// δ��ѯ������
        xiaowei_music_err_not_homeuser = -100037, /// ����������ܲ���
        xiaowei_music_err_need_buy = -100038, /// �����Ϊ����ר���������ܲ���
        xiaowei_music_err_unplayable_other = -100039, /// ����ԭ���ܲ���
        xiaowei_music_err_change_singer = -100040, /// ������ʧ��
        xiaowei_music_err_account_verify = -100041, /// �˻���Ϣ��֤����
        xiaowei_music_err_sys_parameter = -200001, /// ��������
        xiaowei_music_err_sys_pre_get = -200010, /// Ԥ��ȡ��������ʧ��
        xiaowei_music_err_sys_pick_para = -200012, /// �㲥��������
        xiaowei_music_err_sys_pick_id_err = -200013, /// �㲥ID����ȷ
        xiaowei_music_err_sys_pick_faild = -200015, /// �㲥��������ʧ��
        xiaowei_music_err_sys_play_list_fial = -200017, /// ��ѯ�б���������ʧ��
        xiaowei_music_err_sys_item_detail_para = -200021, /// �������������
        xiaowei_music_err_sys_item_id_err = -200022, /// ������ID����ȷ
        xiaowei_music_err_sys_play_list_no_more = -200030, /// ��ѯ�б�û������
        xiaowei_music_err_sys_pre_get_parameter = -200036, /// Ԥ��ȡ��������
        xiaowei_music_err_sys_play_list_id = -200044, /// ��ѯ�б����id������
        xiaowei_music_err_sys_pre_get_no_more = -200049, /// Ԥ��ȡû������
        xiaowei_music_err_sys_deletitem_para = -200051, /// �б���ɾ��Ԫ�ز�������
        xiaowei_music_err_sys_delet_item_faild = -200052, /// �б���ɾ��Ԫ�ز���ʧ��
        xiaowei_music_err_sys_no_history_list = -200053, /// ��������ʷ�б�
        xiaowei_music_err_sys_clear_play_list = -200054, /// ���������ݲ���ʧ��
        xiaowei_music_err_sys_get_history_list = -200055, /// ��ѯ��ʷ�б���������ʧ��
        xiaowei_music_err_sys_favorite_param = -200060, /// �����ղ�û��resid

        /** xiaowei err, end */
    };
}
