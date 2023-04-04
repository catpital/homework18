#include <string>
#include <iostream>
#include <fstream> 	
#include <iostream>	
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <vector>
//#include <sstream>
//#include <filesystem>
using namespace std;
//using namespace std::filesystem;
//int S_IRUSR ;
//int S_IWUSR ;
//int S_IXUSR ;
#define userpath "~\tmp\fileuser.txt"


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
    User();
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

void writeuserfile(User _user) {
}

void readuserfile() {
    //path userpath(L"~\tmp\fileuser.txt");
    fstream user_file = fstream(userpath, ios::in | ios::out);
    if (!user_file)
        // 	// Для создания файла используем параметр ios::trunc
    {
        cout << "файл не существует" << endl;
        cout << "создаем файл" << endl;
        user_file = fstream("fileuser.txt", ios::in | ios::out | ios::trunc);
#if defined(__linux__)
        {
            int stat = _chmod(userpath, S_IRUSR | S_IWUSR | S_IXUSR);
        }
#endif
        cout << "создан пустой файл" << endl;
        return;
    }

    else {
        int i = 1;
        user_file.seekg(0, ios_base::beg);
        vector<User> user_t;
        User user;
        while (!user_file.eof())
        {
            // 	 Считываем данные из файла
            user_file >> user;
            user_t.push_back(user);
            // 		//user_file >> obj2;
            cout << "строчка " << i << user_t.back() << endl;
             i++;
        }
        user_file.close();
    }
}