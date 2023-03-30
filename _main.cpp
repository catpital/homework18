//Напишите программу, которая сможет считывать из файла при своей загрузке и записывать в файл
//состояния объектов классов User и Message(для каждого класса свой файл) :
//    Сделайте это таким образом, чтобы файлы были недоступны для других пользователей, то есть чтобы
//    прочитать или записать информацию в файлы мог бы только пользователь, который запускает программу.
//
#include <string>
#include <iostream>
#include <fstream> 	// Для типа ifstream 
#include <iostream>	// Для cout
using namespace std;

//class User {
//    std::string _name;
//    std::string _login;
//    std::string _pass;
//};
//class Message {
//    std::string _text;
//    std::string _sender;
//    std::string _receiver;
//};


//int main() {
//    // Создаем объект типа ifstream с именем file_reader
//    ifstream file_reader("input_file.txt");
//
//    // Проверяем, открылся ли файл, если нет, то выходим из программы
//    if (!file_reader.is_open()) {
//        cout << "Could not open input file!" << '\n';
//        return 1;
//    }
//
//    int number;
//    // Проверяем успешность считывания целого значения
//    if (file_reader >> number) {
//        cout << "The value is: " << number;
//    }
//    else cout << "have not read" << endl;
//    return 0;
//}

class User {
		string _name;
		string _login;
		string _pass;
	
	public:
		User(string name, string login, string pass) :_name(name), _login(login), _pass(pass) {}
	
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
	  int main()
	  {
	
		fstream user_file = fstream("users.txt", ios::in | ios::out);
		if (!user_file)
			// Для создания файла используем параметр ios::trunc
			user_file = fstream("users.txt", ios::in | ios::out | ios::trunc);
	
		if (user_file) {
			User obj1("Alex", "qwerty", "12345");
			
			// Запишем данные по в файл
			user_file << obj1 << endl;
			User obj2("Alexander", "next", "456678");
			user_file << obj2 << endl;
			// Чтобы считать данные из файла, надо установить позицию для чтения в начало файла
			user_file.seekg(0, ios_base::beg);
			// Считываем данные из файла
			//int i = 1;
			while (!user_file.eof()) {
				user_file >> obj1;
				//user_file >> obj2;
				//cout <<" 1 obj" << obj1 << endl;
				cout << obj1 << endl;
				//i++;
			}
		}
		else
		{
			cout << "Could not open file users.txt !" << '\n';
			return 0;
	
		}
		
		user_file.close(); 
		return 0;
	  }
	
	 