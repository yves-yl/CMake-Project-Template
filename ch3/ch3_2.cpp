#include <iostream>
using namespace std;

class some_value_t;
using mfp_t = int (some_value_t::*)(int);
template <mfp_t func>
int call(some_value_t &val, int op) {

	return (val.*func)(op);
}

class some_value_t {
	int val_;

public:
	some_value_t(int val) : val_(val) {
	}
	int add(int op = 1) {
        val_ += op;
		return val_;
	}
	int sub(int op = 1) {
         val_ -= op;
		return val_;
	}
};

int main(int, char **) {
    some_value_t some_value(0);
    cout<<call<&some_value_t::add>(some_value,5)<<endl;
    cout<<call<&some_value_t::sub>(some_value,2)<<endl;
	return 0;
}