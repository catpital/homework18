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
#include "user.cpp"
#include "message.cpp"
using namespace std;
//int S_IRUSR, S_IWUSR, S_IXUSR = 1;

int main()
{
    
    readuserfile();
    User user("Alex", "alex", "12345");
    writeuserfile(user);
   readuserfile();
   //readmessagefile();
    //Message message("Vsem privet", "Alex", "ALL");
    //writemessagefile(message);
    //readmessagefile();
    
	return 0;
}