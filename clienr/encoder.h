#include "protocolmsg.h"

char* encodeElement(char* hp, unsigned int data, unsigned int len);
char* encode(char* head, unsigned int protocolId, unsigned int account, unsigned int dataType, unsigned int dataLength);