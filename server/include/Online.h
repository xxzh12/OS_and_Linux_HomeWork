#include<common.h>

using namespace std;

class Online {
private:
    vector<int> user;
    map <int, string> UserList;
public:
    bool appendUser(int fd, int account, string username);

    bool removeUser(int fd);

    vector<int> getAllReadFd();

    string getUserName(int account);
};