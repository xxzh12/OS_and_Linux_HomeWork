#include "protocolmsg.h"
#include "encoder.h"
#include "keyboard.h"

#ifndef CLIENT_H
#define CLIENT_H
//按tab键进入登陆模式
#define KEY_LOGIN 9
//按esc键进入登出模式
#define KEY_LOGOUT 27
#define KEY_INPUT -1
#endif


struct clientdata
{
    /* data */
    unsigned int protocolId;
    unsigned int account;
    unsigned int dataType;
    unsigned int dataLength;
    char *data;
};
