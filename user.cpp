#include <string>
#include <iostream>
#include <fstream> 	
#include <stdio.h>
#include <stdlib.h>
// #include <io.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <vector>
#include <sstream>
#include <filesystem>
//using namespace std;
//using namespace filesystem;
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
    std::string name;
    std::string login;
    std::string pass;
    User(std::string _name, std::string _login, std::string _pass) : name(_name), login(_login), pass(_pass) {}
   //User() {};
  //  ~User();
    friend std::fstream& operator >>(std::fstream& is, User& obj);
    friend std::ostream& operator <<(std::ostream& os, const User& obj);
};

std::fstream& operator >>(std::fstream& is, User& obj)
{
    is >> obj._name;
    is >> obj._login;
    is >> obj._pass;
    return is;
}
std::ostream& operator <<(std::ostream& os, const User& obj)
{
    os << obj._name;
    os << ' ';
    os << obj._login;
    os << ' ';
    os << obj._pass;
    return os;
}

void writeuserfile(User _user) {
   std::fstream user_file = std::fstream("fileuser.txt", std::ios::in | std::ios::out);
    if (!user_file)
        // 	// Для создания файла используем параметр ios::trunc
    {
        std::cout << "файл не существует" << std::endl;
        std::cout << "создаем файл" << std::endl;
        user_file = std::fstream("fileuser.txt", std::ios::in | std::ios::out | std::ios::trunc);
#if defined(__linux__)
        {
            int stat = chmod(userpath, S_IRUSR | S_IWUSR | S_IXUSR);
        }
#endif
        std::cout << "создан пустой файл" << std::endl;
        return;
    }

    else {
        int i = 1;
        user_file.seekg(0, std::ios_base::end);
        
             // 	 записываем данные в файл
            user_file << _user << std::endl;
            
          
            std::cout << "записана строчка " << std::endl;
             
        }
        user_file.close(); 
}

void readuserfile() {
    //path userpath(L"~\tmp\fileuser.txt");
    std::fstream user_file = std::fstream("fileuser.txt", std::ios::in | std::ios::out);
    if (!user_file)
        // 	// Для создания файла используем параметр ios::trunc
    {
        std::cout << "файл не существует" << std::endl;
        std::cout << "создаем файл" << std::endl;
        user_file = std::fstream("fileuser.txt", std::ios::in | std::ios::out | std::ios::trunc);
#if defined(__linux__)
        {
            int stat = chmod(userpath, S_IRUSR | S_IWUSR | S_IXUSR);
        }
#endif
        std::cout << "создан пустой файл" << std::endl;
        return;
    }

    else {
        int i = 1;
        user_file.seekg(0, std::ios_base::beg);
        std::vector<User> user_t;
        User user("", "", "");
        while (!user_file.eof())
        {
            // 	 Считываем данные из файла
            user_file >> user;
            user_t.push_back(user);
            // 		запись в вектор
            std::cout << "строчка " << i << user_t.back() << std::endl;
             i++;
        }
        user_file.close();
    }
}