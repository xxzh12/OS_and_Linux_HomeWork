#include "protocolmsg.h"
#include "encoder.h"

struct clientdata
{
    /* data */
    unsigned int protocolId;
    unsigned int account;
    unsigned int dataType;
    unsigned int dataLength;
    char *data;
};
