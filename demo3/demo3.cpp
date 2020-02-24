#include <iostream>
#include <string>
#include <type_traits>
using namespace std;
template <typename T>
using EnableIfString = std::enable_if_t<std::is_convertible_v<T, std::string>>;

class Person {
public:
	template <typename STR, EnableIfString<STR>* = nullptr>
	explicit Person(STR &&n) : name(std::forward<STR>(n)) {
		cout << "explicit Person(STR &&n) : name(std::forward<STR>(n)) " << endl;
	}
	Person(const Person &p) : name(p.name) { cout << "Person(const Person &p) : name(p.name)" << endl; }
	Person(Person &&p) : name(std::move(p.name)) { cout << "Person(Person &&p) : name(std::move(p.name))" << endl; }

private:
	std::string name;
};

int main() {
	std::string s = "sname";
	Person p1(s);			  // explicit Person(STR &&n) : name(std::forward<STR>(n))
	Person p2("tmp");		  // explicit Person(STR &&n) : name(std::forward<STR>(n))
	Person p3(p1);			  // Person(const Person &p) : name(p.name)
	Person p4(std::move(p1)); // Person(Person &&p) : name(std::move(p.name))
}