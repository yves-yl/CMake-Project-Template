#include <iostream>

using namespace std;

template <class T0, class T1, class T2>
struct S {
	std::string id() {

		return "General";
	}
};

template <class T1, class T2>
struct S<char, T1, T2> {
	std::string id() {

		return "S<char,T1,T2> ";
	}
};

template <class T0>
struct S<T0, char, char> {
	std::string id() {

		return "S<T0,char,char> ";
	}
};

template <class T>
struct S<int, T, T> {
	std::string id() {

		return "S<int,T,T>  ";
	}
};

int main(int, char **) {
	cout << S<float, float, float>().id() << endl; //"General"
	cout << S<int, int, int>().id() << endl;	   //"S<int,T,T>  "
	cout << S<int, int, char>().id() << endl;	   //"S<int,T,T>  "
	//cout << S<char, char, char>().id() << endl;	   //"General"
	//cout << S<int,char,char>().id() << endl;
	return 0;
}