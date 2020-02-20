#pragma once
using namespace Platform;

namespace sdkrt
{
    const String^ DEF_TXCA_SKILL_ID_UNKNOWN = "8dab4796-fa37-4114-ffff-ffffffffffff";
    const String^ DEF_TXCA_SKILL_ID_MUSIC = "8dab4796-fa37-4114-0011-7637fa2b0001";    //skill name: ����
    const String^ DEF_TXCA_SKILL_ID_FM = "8dab4796-fa37-4114-0024-7637fa2b0001";       //skill name: FM-Ц��/FM-��̨/FM-С˵/FM-����/FM-����/FM-����/FM-�ӻ�
    const String^ DEF_TXCA_SKILL_ID_WEATHER = "8dab4796-fa37-4114-0012-7637fa2b0003";  //skill name: ��������
    const String^ DEF_TXCA_SKILL_ID_NEWS = "8dab4796-fa37-4114-0019-7637fa2b0001";     //skill name: ����
    const String^ DEF_TXCA_SKILL_ID_WIKI = "8dab4796-fa37-4114-0020-7637fa2b0001";     //skill name: �ٿ�
    const String^ DEF_TXCA_SKILL_ID_HISTORY = "8dab4796-fa37-4114-0027-7637fa2b0001";  //skill name: ��ʷ�ϵĽ���
    const String^ DEF_TXCA_SKILL_ID_DATETIME = "8dab4796-fa37-4114-0028-7637fa2b0001"; //skill name: ��ǰʱ��
    const String^ DEF_TXCA_SKILL_ID_CALC = "8dab4796-fa37-4114-0018-7637fa2b0001";     //skill name: ������
    const String^ DEF_TXCA_SKILL_ID_TRANSLATE = "8dab4796-fa37-4114-0030-7637fa2b0001";//skill name: ����
    const String^ DEF_TXCA_SKILL_ID_CHAT = "8dab4796-fa37-4114-0029-7637fa2b0001";     //skill name: ����

    const String^ DEF_TXCA_SKILL_ID_IOTCTRL = "8dab4796-fa37-4114-0016-7637fa2b0001";//skill name: ����-�����豸����

    const String^ DEF_TXCA_SKILL_ID_ALARM = "8dab4796-fa37-4114-0012-7637fa2b0001";   //skill name: ������
    const String^ DEF_TXCA_SKILL_ID_QQTEL = "8dab4796-fa37-4114-0001-7637fa2b0001";   //skill name: ͨѶ-QQͨ��
    const String^ DEF_TXCA_SKILL_ID_QQMSG = "8dab4796-fa37-4114-0002-7637fa2b0001";   //skill name: ͨѶ-QQ��Ϣ
    const String^ DEF_TXCA_SKILL_ID_MSGBOX = "8dab4796-fa37-4114-0012-7637fa2b0002";  //skill name: ��Ϣ����
    const String^ DEF_TXCA_SKILL_ID_NAVIGATE = "8dab4796-fa37-4114-0015-7637fa2b0001";//skill name: ����
    const String^ DEF_TXCA_SKILL_ID_VOD = "8dab4796-fa37-4114-0026-7637fa2b0001";     //skill name: ��Ƶ

    const String^ DEF_TXCA_SKILL_ID_GLOBAL = "8dab4796-fa37-4114-0000-7637fa2b0000";  //skill name: ͨ�ÿ���

    const String^ DEF_TXCA_SKILL_NAME_CHAT_EX = "С΢����";

    // ���ſ���
    const unsigned int PROPERTY_ID_PLAY = 700003;            // ����
    const unsigned int PROPERTY_ID_PAUSE = 700004;           // ��ͣ
    const unsigned int PROPERTY_ID_PREV = 700005;            // ��һ��
    const unsigned int PROPERTY_ID_NEXT = 700006;            // ��һ��
    const unsigned int PROPERTY_ID_STOP = 700100;            // ֹͣ����
    const unsigned int PROPERTY_ID_PLAYMODE_RANDOM = 700103; // �������
    const unsigned int PROPERTY_ID_PLAYMODE_ORDER = 700104;  // ˳�򲥷�
    const unsigned int PROPERTY_ID_PLAYMODE_LOOP = 700137;   // ѭ������
    const unsigned int PROPERTY_ID_PLAYMODE_SINGLE = 700113; // ����ѭ��
    const unsigned int PROPERTY_ID_REPEAT = 700108;          // �ز�

    // ͨ�ÿ���
    const unsigned int PROPERTY_ID_VOLUME_SET = 700101;        // ��������
    const unsigned int PROPERTY_ID_VOLUME_INC = 700001;        // ������
    const unsigned int PROPERTY_ID_VOLUME_DEC = 700002;        // ����С
    const unsigned int PROPERTY_ID_KEEP_SHARE = 700126;        // �ղ� ����
    const unsigned int PROPERTY_ID_KEEP_SILENCE = 700128;      // ���� ȡ������
    const unsigned int PROPERTY_ID_UPLOAD_LOG = 700129;        // �ϱ���־
    const unsigned int PROPERTY_ID_FETCH_DEVICE_INFO = 700130; // ��ѯ�豸������Ϣ��pid,sn,din,mac,ip�ȣ�
    const unsigned int PROPERTY_ID_ERROR_FEEDBACK = 700141;    // ������������һ�������ϱ�����̨
    const unsigned int PROPERTY_ID_VOLUME_MAX = 700150;        // �������
    const unsigned int PROPERTY_ID_VOLUME_MIN = 700151;        // ������С

    // ��������Ƶʹ��
    const unsigned int PROPERTY_ID_SPEED = 700134;              // ���
    const unsigned int PROPERTY_ID_REWIND = 700135;            // ����
    const unsigned int PROPERTY_ID_DEFINITION = 700138;         // �ֱ��ʵ���
    const unsigned int PROPERTY_ID_CURRENT_POSITION = 700139;   // ��ѯ�Ѳ���ʱ��
    const unsigned int PROPERTY_ID_REMAINDER_DURATION = 700140; // ��ѯʣ�ಥ��ʱ��

    //����ֻ����ʹ��
    const unsigned int PROPERTY_ID_ENSURE = 700142; // ȷ��
    const unsigned int PROPERTY_ID_CANCEL = 700143; // ȡ��
    const unsigned int PROPERTY_ID_BACK = 700144;   // ����

    // ��������Ƶ�͵���ʹ��
    const unsigned int PROPERTY_ID_SELECT = 700145;    // ѡ��ȷ�� �ڼ���
    const unsigned int PROPERTY_ID_PREV_PAGE = 700148; // ��һҳ
    const unsigned int PROPERTY_ID_NEXT_PAGE = 700149; // ��һҳ

    // ��������Ƶʹ��
    const unsigned int PROPERTY_ID_SPEED_TO = 700152;  // ���ȵ��ڣ�����������˵�
    const unsigned int PROPERTY_ID_EXIT = 700153;      // �˳�
    const unsigned int PROPERTY_ID_REWIND_TO = 700155; // ���˵�

    // ������ͨ��
    const unsigned int PROPERTY_ID_QQCALL_REQUEST = 11020; //
    const unsigned int PROPERTY_ID_QQCALL_REQUEST_NEW = 11052;
    const unsigned int PROPERTY_ID_QQCALL_CANCEL = 11021; //11055
    const unsigned int PROPERTY_ID_QQCALL_ACCEPT = 11022; //11056
    const unsigned int PROPERTY_ID_QQCALL_REJECT = 11023; //11057
    const unsigned int PROPERTY_ID_QQCALL_INVITE = 666666;
    const unsigned int PROPERTY_ID_QQCALL_UI_REQUEST = 666667;
    const unsigned int PROPERTY_ID_QQCALL_PROMPT = 11027;   //11058
    const unsigned int PROPERTY_ID_QQCALL_CONTACTS = 11061; //��绰���ֻ���ϵ��

    // ��������Ϣ���ӵ�
    const unsigned int PROPERTY_ID_START = 700125;
    const unsigned int PROPERTY_ID_START_BY_ID = 700127;
    const unsigned int PROPERTY_ID_MSG_READED = 700128;
    const unsigned int PROPERTY_ID_IMAGENT = 11054;
}