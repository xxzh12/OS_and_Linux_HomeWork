#include<Online.h>

bool Online::appendUser(int fd, int account, string username){
    this->UserList[account] = username;
    this->user.push_back(fd);
}

bool Online::removeUser(int fd){
    remove(this->user.begin(), this->user.end(), fd);
}

vector<int> Online::getAllReadFd() {
    return this->user;
}

string Online::getUserName(int account){
    return this->UserList[account];
}