#include <iostream>

using namespace std;

template <template <typename > class Func,class T>
void forEach(T arr[], size_t len) {
	Func<T> f;
	for (size_t i = 0; i < len; ++i) {
		
		f(arr[i]);
	}
}
template <class T>
class print {

public:
	void operator()(T const &val) {
		cout << val << endl;
	}
};

int main(int, char **) {
	int arr[] = {1, 3, 5, 7, 9};
	forEach<print>(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}
