#include <iostream>

using namespace std;

template <class T, void (*f)(T &v)>
void forEach(T arr[], size_t len) {
	for (size_t i = 0; i < len; ++i) {
		f(arr[i]);
	}
}
template <class T>
void print(T &v) {
	cout << v << endl;
}

int main(int, char **) {
	int arr[] = {1, 3, 5, 7, 9};
	forEach<int, print<int>>(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}
