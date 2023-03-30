//#include <fstream> 	// Для типа ifstream 
//#include <iostream>	// Для cout
//using namespace std;
//void readfile()
//{
//    // Создаем объект типа ifstream с именем file_reader
//	// int fd2 = open("/tmp/test.svg", O_RDWR|O_CREAT, 0777); 
//	//#define pathuser /tmp/user.txt
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
//}
//void writefile() {
//	
//		// Откроем файл для записи, если его не было, то он создастся
//		ofstream file_writer("hello_file.txt");
//		if (!file_writer.is_open()) {
//			cout << "Could not open file!" << '\n';
//			return 0;
//		}
//
//		// Запишем в файл строку hello, world
//		file_writer << "hello, world";
//		// Скорректируем строку, чтобы в файле получилось 
//		// строка Hello, Linux!
//		file_writer.seekp(7);
//		file_writer << "Linux";
//		file_writer.seekp(0, ios_base::beg);
//		file_writer << 'H';
//		file_writer.seekp(0, std::ios_base::end);
//		file_writer << '!';
//		file_writer.close();
//	
//};
//
//
//
//class User {
//	string _name;
//	string _login;
//	string _pass;
//
//public:
//	User(string name, string login, string pass) :_name(name), _login(login), _pass(pass) {}
//
//	friend fstream& operator >>(fstream& is, User& obj);
//	friend ostream& operator <<(ostream& os, const User& obj);
//};
//
//fstream& operator >>(fstream& is, User& obj)
//{
//	is >> obj._name;
//	is >> obj._login;
//	is >> obj._pass;
//	return is;
//}
//ostream& operator <<(ostream& os, const User& obj)
//{
//	os << obj._name;
//	os << ' ';
//	os << obj._login;
//	os << ' ';
//	os << obj._pass;
//	return os;
//}
//int main() {
//
//	fstream user_file = fstream("users.txt", ios::in | ios::out);
//	if (!user_file)
//		// Для создания файла используем параметр ios::trunc
//		user_file = fstream("users.txt", ios::in | ios::out | ios::trunc);
//
//	if (user_file) {
//		User obj("Alex", "qwerty", "12345");
//		// Запишем данные по в файл
//		user_file << obj << endl;
//		// Чтобы считать данные из файла, надо установить позицию для чтения в начало файла
//		user_file.seekg(0, ios_base::beg);
//		// Считываем данные из файла
//		user_file >> obj;
//		cout << obj << endl;
//	}
//	else
//	{
//		cout << "Could not open file users.txt !" << '\n';
//		return 0;
//
//	}
//}
//
//}