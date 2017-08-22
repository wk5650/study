#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "public.h"

#define UPLOAD_OK        "upload_ok"
#define DOWNLOAD_OK      "download_ok"
#define DELETE_OK        "delete_ok"
#define DELETE_FAILED    "delete_failed"
#define RENAME_OK        "rename_ok"
#define RENAME_FAILED    "rename_failed"

enum ENUM_MSG_TYPE
{
	ENUM_MSG_TYPE_MIN = 0,
	ENUM_MSG_TYPE_REGIST_REQUEST,       //注册请求
	ENUM_MSG_TYPE_REGIST_RESPOND,       //注册回复
	ENUM_MSG_TYPE_LOGIN_REQUEST,        //登录请求
	ENUM_MSG_TYPE_LOGIN_RESPOND,        //登录回复
	ENUM_MSG_TYPE_PRIVATE_CHAT_REQUEST, //私聊请求
	ENUM_MSG_TYPE_PRIVATE_CHAT_RESPOND, //私聊回复
	ENUM_MSG_TYPE_GROUP_CHAT_REQUEST,   //群聊请求
	ENUM_MSG_TYPE_GROUP_CHAT_RESPOND,   //群聊回复
	ENUM_MSG_TYPE_EXIT_REQUEST,         //退出请求
	ENUM_MSG_TYPE_EXIT_RESPOND,         //退出回复

	ENUM_MSG_TYPE_SEARCH_REQUEST,    //查看请求
	ENUM_MSG_TYPE_SEARCH_RESPOND,    //查看回复
	ENUM_MSG_TYPE_UPLOAD_REQUEST,    //上传请求
	ENUM_MSG_TYPE_UPLOAD_RESPOND,    //上传回复
	ENUM_MSG_TYPE_DOWNLOAD_REQUEST,  //下载请求
	ENUM_MSG_TYPE_DOWNLOAD_RESPOND,  //下载回复
	ENUM_MSG_TYPE_REANME_REQUEST,    //重命名请求
	ENUM_MSG_TYPE_REANME_RESPOND,    //重命名回复
	ENUM_MSG_TYPE_DELETE_REQUEST,    //删除请求
	ENUM_MSG_TYPE_DELETE_RESPOND,    //删除回复
	ENUM_MSG_TYPE_MAX = 0x00ffffff
};

#define LOGIN_OK "ok"
#define LOGIN_FAILED "failed"

typedef struct PDU  //协议数据单元
{
	uint uiPDULen;        //消息的总的大小
	uint uiMsgType;       //消息的类型
	uint uiFrom;          //消息发送者的id
	uint uiTo;            //消息接收者的id
	uint uiMsgLen;        //实际消息的大小
	char caMsg[4];        //实际消息
	char caName[64];  //文件名
	uint uiFileSize;  //文件大小
	uint uiMsgLen;    //消息大小
	char caMsg[4];    //消息

}PDU;

PDU *makePDU(uint uiMsgLen);
void sendPDU(int sockfd, PDU *pdu);
void freePDU(PDU *pdu);
PDU *readPDU(int sockfd);
PDU *recvPDU(int sockfd);

#endif











