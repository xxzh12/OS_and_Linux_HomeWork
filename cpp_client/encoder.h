#include "protocolmsg.h"
#include <string>

using namespace std;
class Encoder
{
private:
    string data;
    char head[BASE_BUFFER_SIZE];
    char * hp;
    void encodeElement(unsigned int data, unsigned int len);

public:
    Encoder();
    string encode(unsigned int protocolId, unsigned int account, unsigned int dataType, unsigned int dataLength);
};