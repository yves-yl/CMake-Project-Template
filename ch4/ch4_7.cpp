#include <iostream>

using namespace std;

template <int N>
void print() {
	print<N - 1>();
	cout << N << endl;
}
template <>
void print<1>() {

	cout << 1 << endl;
}

int main(int, char **) {
    print<5>();
	return 0;
}