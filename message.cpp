#include <string>
#include <iostream>
#include <fstream> 	
#include <iostream>	
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <sys/types.h>
#include <sys/stat.h>
//int S_IRUSR ;
//int S_IWUSR;
//int S_IXUSR ;
using namespace std;

#define messagepath "~\tmp\filemess.txt"
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
void writemessagefile(Message _message) {
}

void readmessagefile() {
    // int fr = -1;
    // ifstream file("filemessage.txt");
    // if (fr == file.is_open())
    //     //"fileuser.txt", O_RDWR | O_CREAT, 0777))
    fstream mess_file = fstream("filemessage.txt", ios::in | ios::out);
    if (!mess_file)
        // 	// Для создания файла используем параметр ios::trunc
    {
        cout << "файл не существует" << endl;
        cout << "создаем файл" << endl;
        mess_file = fstream("filemessage.txt", ios::in | ios::out | ios::trunc);
#if defined(__linux__) 
        {
            int stat = _chmod("filemessage.txt", S_IRUSR | S_IWUSR | S_IXUSR);
        }
#endif
        cout << "создан пустой файл" << endl;
        return;
    }


    else {
        int i = 1;
        mess_file.seekg(0, ios_base::beg);
        while (!mess_file.eof())
        {
            // 	 Считываем данные из файла
            mess_file >> message;;
            // 		//user_file >> obj2;
            cout << "строчка " << i << message << endl;

            i++;
        }
        mess_file.close();
    }
}