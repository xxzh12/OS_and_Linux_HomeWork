#include <string>
#include <unistd.h>
#include "encoder.h"

Encoder::Encoder(string msg){
    this->data = msg;

}

//编码数据头中的元素信息
void Encoder::encodeElement(unsigned int data, unsigned int len) {
    char* c = hp + len - 1;
    for (int i = len; i > 0; i--) {
        *c = (char)(data & 0xff);
        c--;
        data >>= 8;
    }
    hp = hp + len;
}

//编码数据包
string Encoder::encode(unsigned int protocolId, unsigned int account, unsigned int dataType, unsigned int dataLength) {
    hp = head;
    encodeElement(protocolId, PROTOCOL_ID_SIZE);
    encodeElement(account, ACCOUNT_SIZE);
    encodeElement(dataType, DATA_TYPE_SIZE);
    encodeElement(dataLength, DATA_SIZE);
    return string(head,sizeof(head));
}

