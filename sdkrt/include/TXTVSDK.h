#ifndef __TX_TV_SDK_H__
#define __TX_TV_SDK_H__

#include "TXSDKCommonDef.h"

CXX_EXTERN_BEGIN

typedef struct tag_tx_tv_notify
{
	//电视首次被绑定成功时回调 bBind == 1 代表已经被人绑定
	void (*on_bind_complete)(unsigned long long ddwID, int bBind);

	//收到视频请求
	void (*on_receive_video_push)(char * pBufReply, int nLenReply, unsigned long long sendUin, int sendUinType);

	//通知绑定者在LAN
	void (*on_binder_in_lan) (unsigned long long tinyId);
	void (*on_binder_out_lan) (unsigned long long tinyId);

	#ifdef QIETVGUID
    void (*on_upload_din_and_guid)(int err_code);
    #endif
}tx_tv_notify;


//设置电视相关的回调
SDK_API void tx_set_tv_notify(tx_tv_notify * notify);

//发送视频请求
typedef void (*on_receive_video_reply)(char * pBufReply, int nLenReply);
SDK_API void tx_send_video_request(int type, unsigned long long toDin, const char * pBuff, unsigned int uLen, on_receive_video_reply callback);

//uin与tinyid互换
SDK_API unsigned long long tx_get_uin_by_tinyid(unsigned long long ddwID);

SDK_API unsigned long long tx_get_tinyid_by_uin(unsigned long long ddwID);

SDK_API int tx_get_video_chat_signature(char* pBuf, int* puLen);
SDK_API int tx_get_msg_proxy_flag();
#ifdef QIETVGUID
SDK_API void tx_upload_tv_guid(const char* guid);
SDK_API void tx_set_tv_domain_mapping(const char ** domainArray, const char ** domainHideArray, unsigned int count);
#endif
CXX_EXTERN_END
#endif // __TX_TV_SDK_H__
