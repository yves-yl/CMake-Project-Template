#include <iostream>
#include <vector>
using namespace std;

template <class T>
struct dummy_template {};
template <class T, template <class> class TMPL = dummy_template>
struct meta_filter {

	typedef T return_type;
	void type() {

		cout << typeid(return_type).name() << endl;
	}
};
template <class T, template <class> class TMPL>
struct meta_filter<TMPL<T>, dummy_template> {

	typedef T return_type;
	void type() {

		cout << typeid(return_type).name() << endl;
	}
};

int main(int, char **) {
	meta_filter<meta_filter<string>::return_type>().type();
	meta_filter<string>().type();
	meta_filter<vector<int>>().type();
	meta_filter<int>().type();
	return 0;
}