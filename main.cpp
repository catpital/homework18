//Напишите программу, которая сможет считывать из файла при своей загрузке и записывать в файл
//состояния объектов классов User и Message(для каждого класса свой файл) :
//    Сделайте это таким образом, чтобы файлы были недоступны для других пользователей, то есть чтобы
//    прочитать или записать информацию в файлы мог бы только пользователь, который запускает программу.
#include <io.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string>
#include <iostream>
#include <fstream> 	
#include <iostream>	
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
using namespace std;
#define userpath "~\tmp\fileuser.txt"
#define messagepath "~\tmp\filemess.txt"
class User {
private:
    std::string _name;
    std::string _login;
    std::string _pass;
public:
    string name;
    string login;
    string pass;
    User(string _name, string _login, string _pass) : name(_name), login(_login), pass(_pass) {}
    ~User();
    friend fstream& operator >>(fstream& is, User& obj);
    friend ostream& operator <<(ostream& os, const User& obj);
};

fstream& operator >>(fstream& is, User& obj)
{
    is >> obj._name;
    is >> obj._login;
    is >> obj._pass;
    return is;
}
ostream& operator <<(ostream& os, const User& obj)
{
    os << obj._name;
    os << ' ';
    os << obj._login;
    os << ' ';
    os << obj._pass;
    return os;
}

class Message {
private:
    std::string _text;
    std::string _sender;
    std::string _receiver;
public:
    string text;
    string sender;
    string receiver;
    Message(string _text, string _sender, string _reciver) : text(_text), sender(_sender), receiver(_receiver) {}
    ~Message();
    friend fstream& operator >>(fstream& is, Message& obj);
    friend ostream& operator <<(ostream& os, const Message& obj);
};
fstream& operator >>(fstream& is, Message& obj)
{
    is >> obj._text;
    is >> obj._sender;
    is >> obj._receiver;
    return is;
}
ostream& operator <<(ostream& os, const Message& obj)
{
    os << obj._text;
    os << ' ';
    os << obj._sender;
    os << ' ';
    os << obj._receiver;
    return os;
}
int S_IRUSR, S_IWUSR, S_IXUSR=1;

void writeuserfile(User _user) {
}
void writemessagefile(Message _message) {
}


void readuserfile() {
   
    int fr = -1;
    ifstream file("fileuser.txt");
    if (fr == file.is_open())
        //"fileuser.txt", O_RDWR | O_CREAT, 0777))
    {
        cout << "файл не существует" << endl;
    }
    else {
        int stat=_chmod(userpath, S_IRUSR | S_IWUSR | S_IXUSR);
    }
}
void readmessagefile() {
    int fr = -1;
    ifstream file("filemessage.txt");
    if (fr == file.is_open())
        //"fileuser.txt", O_RDWR | O_CREAT, 0777))
    {
        cout << "файл не существует" << endl;
    }
    else {
        int stat = _chmod(messagepath, S_IRUSR | S_IWUSR | S_IXUSR);
    }
}


int main()
{
    readuserfile();
    User user("Alex", "alex", "12345");
    writeuserfile(user);
    readuserfile();
    readmessagefile();
    Message message("Vsem privet", "Alex", "ALL");
    writemessagefile(message);
    readmessagefile();

	return 0;
}