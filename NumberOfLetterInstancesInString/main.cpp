#include <iostream>
#include <map>

using namespace std;

int rest(char a)
{
	return a % 10;
}

struct Functor
{
	bool operator()(char a, char b) const
	{
		return rest(a) < rest(b);
	}
};

int main()
{
	string s1 = "aaaabbbddc";

	map<char, int, Functor> letterMap;

	for (auto iter = s1.begin(); iter != s1.end(); iter++)
	{
		letterMap[*iter]++;
	}

	letterMap.insert({'e', 1});
	letterMap.erase('d');

	for (auto iter = letterMap.begin(); iter != letterMap.end(); iter++)
	{
		cout << iter->first << ' ' << iter->second << '\n';
	}

	return 0;
}