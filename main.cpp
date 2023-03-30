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
};
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
};
int S_IRUSR, S_IWUSR, S_IXUSR=1;


void writeuserfile(User _user) {
}
void writemassagefile(Message _message) {
}


void readuserfile() {
    // string filepath;
    int fr = -1;
    ifstream file("fileuser.txt");
    if (fr == file.is_open())
        //"fileuser.txt", O_RDWR | O_CREAT, 0777))
    {
        cout << "файл не существует" << endl;
    }
    else {
        _chmod("fileuser.txt", S_IRUSR | S_IWUSR | S_IXUSR);
    }
}
void readmessagefile() {

}

#define userpath="~\tmp\fileuser.txt";
#define messagepath="~\tmp\filemess.txt";
int main()
{
    readuserfile();
    readmessagefile();
    User user("Alex", "alex", "12345");
        
    writeuserfile(user);
    Message message("Vsem privet", "Alex", "ALL");
    readuserfile();
    readmessagefile();

	return 0;
}