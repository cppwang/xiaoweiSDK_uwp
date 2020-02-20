#pragma once
using namespace Platform;

namespace sdkrt
{
    const String^ DEF_TXCA_SKILL_ID_UNKNOWN = "8dab4796-fa37-4114-ffff-ffffffffffff";
    const String^ DEF_TXCA_SKILL_ID_MUSIC = "8dab4796-fa37-4114-0011-7637fa2b0001";    //skill name: 音乐
    const String^ DEF_TXCA_SKILL_ID_FM = "8dab4796-fa37-4114-0024-7637fa2b0001";       //skill name: FM-笑话/FM-电台/FM-小说/FM-相声/FM-评书/FM-故事/FM-杂烩
    const String^ DEF_TXCA_SKILL_ID_WEATHER = "8dab4796-fa37-4114-0012-7637fa2b0003";  //skill name: 天气服务
    const String^ DEF_TXCA_SKILL_ID_NEWS = "8dab4796-fa37-4114-0019-7637fa2b0001";     //skill name: 新闻
    const String^ DEF_TXCA_SKILL_ID_WIKI = "8dab4796-fa37-4114-0020-7637fa2b0001";     //skill name: 百科
    const String^ DEF_TXCA_SKILL_ID_HISTORY = "8dab4796-fa37-4114-0027-7637fa2b0001";  //skill name: 历史上的今天
    const String^ DEF_TXCA_SKILL_ID_DATETIME = "8dab4796-fa37-4114-0028-7637fa2b0001"; //skill name: 当前时间
    const String^ DEF_TXCA_SKILL_ID_CALC = "8dab4796-fa37-4114-0018-7637fa2b0001";     //skill name: 计算器
    const String^ DEF_TXCA_SKILL_ID_TRANSLATE = "8dab4796-fa37-4114-0030-7637fa2b0001";//skill name: 翻译
    const String^ DEF_TXCA_SKILL_ID_CHAT = "8dab4796-fa37-4114-0029-7637fa2b0001";     //skill name: 闲聊

    const String^ DEF_TXCA_SKILL_ID_IOTCTRL = "8dab4796-fa37-4114-0016-7637fa2b0001";//skill name: 物联-物联设备控制

    const String^ DEF_TXCA_SKILL_ID_ALARM = "8dab4796-fa37-4114-0012-7637fa2b0001";   //skill name: 提醒类
    const String^ DEF_TXCA_SKILL_ID_QQTEL = "8dab4796-fa37-4114-0001-7637fa2b0001";   //skill name: 通讯-QQ通话
    const String^ DEF_TXCA_SKILL_ID_QQMSG = "8dab4796-fa37-4114-0002-7637fa2b0001";   //skill name: 通讯-QQ消息
    const String^ DEF_TXCA_SKILL_ID_MSGBOX = "8dab4796-fa37-4114-0012-7637fa2b0002";  //skill name: 消息盒子
    const String^ DEF_TXCA_SKILL_ID_NAVIGATE = "8dab4796-fa37-4114-0015-7637fa2b0001";//skill name: 导航
    const String^ DEF_TXCA_SKILL_ID_VOD = "8dab4796-fa37-4114-0026-7637fa2b0001";     //skill name: 视频

    const String^ DEF_TXCA_SKILL_ID_GLOBAL = "8dab4796-fa37-4114-0000-7637fa2b0000";  //skill name: 通用控制

    const String^ DEF_TXCA_SKILL_NAME_CHAT_EX = "小微闲聊";

    // 播放控制
    const unsigned int PROPERTY_ID_PLAY = 700003;            // 播放
    const unsigned int PROPERTY_ID_PAUSE = 700004;           // 暂停
    const unsigned int PROPERTY_ID_PREV = 700005;            // 上一首
    const unsigned int PROPERTY_ID_NEXT = 700006;            // 下一首
    const unsigned int PROPERTY_ID_STOP = 700100;            // 停止播放
    const unsigned int PROPERTY_ID_PLAYMODE_RANDOM = 700103; // 随机播放
    const unsigned int PROPERTY_ID_PLAYMODE_ORDER = 700104;  // 顺序播放
    const unsigned int PROPERTY_ID_PLAYMODE_LOOP = 700137;   // 循环播放
    const unsigned int PROPERTY_ID_PLAYMODE_SINGLE = 700113; // 单曲循环
    const unsigned int PROPERTY_ID_REPEAT = 700108;          // 重播

    // 通用控制
    const unsigned int PROPERTY_ID_VOLUME_SET = 700101;        // 设置音量
    const unsigned int PROPERTY_ID_VOLUME_INC = 700001;        // 音量大
    const unsigned int PROPERTY_ID_VOLUME_DEC = 700002;        // 音量小
    const unsigned int PROPERTY_ID_KEEP_SHARE = 700126;        // 收藏 分享
    const unsigned int PROPERTY_ID_KEEP_SILENCE = 700128;      // 静音 取消静音
    const unsigned int PROPERTY_ID_UPLOAD_LOG = 700129;        // 上报日志
    const unsigned int PROPERTY_ID_FETCH_DEVICE_INFO = 700130; // 查询设备基础信息（pid,sn,din,mac,ip等）
    const unsigned int PROPERTY_ID_ERROR_FEEDBACK = 700141;    // 错误反馈，将上一次请求上报到后台
    const unsigned int PROPERTY_ID_VOLUME_MAX = 700150;        // 音量最大
    const unsigned int PROPERTY_ID_VOLUME_MIN = 700151;        // 音量最小

    // 下面是视频使用
    const unsigned int PROPERTY_ID_SPEED = 700134;              // 快进
    const unsigned int PROPERTY_ID_REWIND = 700135;            // 快退
    const unsigned int PROPERTY_ID_DEFINITION = 700138;         // 分辨率调整
    const unsigned int PROPERTY_ID_CURRENT_POSITION = 700139;   // 查询已播放时长
    const unsigned int PROPERTY_ID_REMAINDER_DURATION = 700140; // 查询剩余播放时长

    //下面只导航使用
    const unsigned int PROPERTY_ID_ENSURE = 700142; // 确定
    const unsigned int PROPERTY_ID_CANCEL = 700143; // 取消
    const unsigned int PROPERTY_ID_BACK = 700144;   // 返回

    // 下面是视频和导航使用
    const unsigned int PROPERTY_ID_SELECT = 700145;    // 选项确认 第几集
    const unsigned int PROPERTY_ID_PREV_PAGE = 700148; // 上一页
    const unsigned int PROPERTY_ID_NEXT_PAGE = 700149; // 下一页

    // 下面是视频使用
    const unsigned int PROPERTY_ID_SPEED_TO = 700152;  // 进度调节，快进到，快退到
    const unsigned int PROPERTY_ID_EXIT = 700153;      // 退出
    const unsigned int PROPERTY_ID_REWIND_TO = 700155; // 快退到

    // 下面是通话
    const unsigned int PROPERTY_ID_QQCALL_REQUEST = 11020; //
    const unsigned int PROPERTY_ID_QQCALL_REQUEST_NEW = 11052;
    const unsigned int PROPERTY_ID_QQCALL_CANCEL = 11021; //11055
    const unsigned int PROPERTY_ID_QQCALL_ACCEPT = 11022; //11056
    const unsigned int PROPERTY_ID_QQCALL_REJECT = 11023; //11057
    const unsigned int PROPERTY_ID_QQCALL_INVITE = 666666;
    const unsigned int PROPERTY_ID_QQCALL_UI_REQUEST = 666667;
    const unsigned int PROPERTY_ID_QQCALL_PROMPT = 11027;   //11058
    const unsigned int PROPERTY_ID_QQCALL_CONTACTS = 11061; //打电话给手机联系人

    // 下面是消息盒子的
    const unsigned int PROPERTY_ID_START = 700125;
    const unsigned int PROPERTY_ID_START_BY_ID = 700127;
    const unsigned int PROPERTY_ID_MSG_READED = 700128;
    const unsigned int PROPERTY_ID_IMAGENT = 11054;
}