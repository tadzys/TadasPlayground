#include <iostream>
#include <boost/array.hpp>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <string>
#include <unordered_map>
#include <boost/functional/hash.hpp>

using namespace std;

template<typename T>
bool pair_comparer(T a, T b) {
	// In real-world code, we wouldn't compare floating point values like
	// this. It would make sense to specialize this function for floating
	// point types to use approximate comparison.
	return a == b;
}

template<typename T, typename... Args>
bool pair_comparer(T a, T b, Args... args) {
	return a == b && pair_comparer(args...);
}

class StringBuilder
{
public:
	std::string makeObject() const
	{
		return std::string("Jhony WTF?");
	}
};

template <typename B>
auto makeAndProcessObject(const B& builder)
{
	auto val = builder.makeObject();
	// do stuff with val
	return val;
}

string::size_type strcmp_pos(const string& first, const string& second)
{
	string::size_type counter = 0;
	string::size_type res = 0;
	for (auto i : first)
	{
		if (counter >= second.length())
			break;
		if (i == second[counter++])
			res++;
		else break;
	}
	return res;
}

int main(int argc, char* argv)
{

	boost::array<string, 5> bla{ "a","b","c","d","e" };

	vector<int> xxx {1,2,3};

	shared_ptr<int> a = make_shared<int>(5);

	for (auto i : bla)
	{
		cout << i << endl;
	}

	
	cout << "Hello world" << endl;

	cout << (pair_comparer(1.5, 1.5, 2, 2, 6, 6) ? "Yes" : "NOOO") << endl;

	unordered_map<int, string, boost::hash<int>> test;
	test.insert(std::make_pair(1, "test"));
	test[2] = "3";

	StringBuilder builder;

	auto ret = makeAndProcessObject(builder);

	string s = "google";

	using namespace boost::algorithm;

	boost::iterator_range<string::iterator> r = find_first(s, "test");
	cout << r << endl;

	r = find_first(s, "test");

	auto n = s.find_first_not_of("google - analytics");

	cout << string("googledrive").compare("googlesyndication") << endl;
	
	string first = "googledrive";
	string second = "bz";
	auto x = mismatch(first.begin(), first.end(), second.begin(),second.end());
	auto b = x.first - first.begin();

	cout << n << " "<< strcmp_pos(s, "google - analytics") << endl;

	cout << r << endl;
	return 0;


}