#include <iostream>
#include <string>
using namespace std;
template <class T>
void print(T val) {
	cout << "print(T): " << val << endl;
}

template <class T>
typename  std::enable_if_t<std::is_class_v<T>> print(T* val) {
	cout << "print(T*): " << val << endl;
}


template <>
void print<char>(char val) {
	cout << "print(char):" << val << endl;
}
template <>
void print<const char*>(const char* val) {
	cout << "print(const char*):" << val << endl;
}

template <>
void print<std::string const&>(std::string const& val) {
	cout << "print(std::string const&):" << val << endl;
}


int main(int, char **) {
    int val = 1;
    print("hjahahah");
	return 0;
}