#include<common.h>>

using namespace std;

class DataEncoder {
private:
    char head[BASE_BUFFER_SIZE];
    char *hp;

    void encodeElement(unsigned int data, unsigned int len);

public:
    DataEncoder();

    string encode(unsigned int protocolId, unsigned int account, unsigned int dataType, unsigned int dataLength);

};
