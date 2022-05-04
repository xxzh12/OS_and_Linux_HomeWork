#include<Online.h>

bool Online::appendUser(int fd, int account, string username){
    this->UserList[account] = username;
    this->user.push_back(fd);
}

bool Online::removeUser(int fd){
    for (vector<int>::iterator iter = this->user.begin(); iter != this->user.end(); iter++)
        if ((*iter) == fd) 
        {
            this->user.erase(iter);
            break;
        }
}

vector<int> Online::getAllReadFd() {
    return this->user;
}

string Online::getUserName(int account){
    return this->UserList[account];
}


void Online::printAllUserFd(){
    for (int i = 0; i < this->user.size(); i++)
    {
        printf("fd list %d\n", this->user[i]);
    }
}
