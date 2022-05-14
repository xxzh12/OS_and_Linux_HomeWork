#include<Online.h>

bool Online::appendUser(int fd, int account, string username){
    this->UserList[account] = username;
    this->user.push_back(fd);
}

bool Online::removeUser(int fd, int account){
    for (vector<int>::iterator iter = this->user.begin(); iter != this->user.end(); iter++)
        if ((*iter) == fd) 
        {
            this->user.erase(iter);
            break;
        }
    this->UserList.erase(account);
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

string Online::getUserList(){
    string ul;
    for(auto it : UserList){
        ul = ul + it.second + "(" + to_string(it.first) + "),";
    }
    return ul;
}
