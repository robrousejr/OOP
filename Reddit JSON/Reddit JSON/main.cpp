#include "stdafx.h"
#include "json.hpp"
#include <iostream>
#include <string>
#include <iterator>
using namespace std;

int main()
{
	std::istreambuf_iterator<char> first(std::cin);
	std::istreambuf_iterator<char> last;
	std::string s(first, last);

	json::Value* val = json::parse(s);

	std::cout << size(val) << ' ' << height(val) << '\n';
	std::cout << *val << '\n';




	//ADD: Type 'file' or 'link'
	//Link --> accepts as getline
	//File --> Reads in

	// Accepts reddit link as input

	/*std::string link;
	std::cout << "Reddit link: ";
	getline(cin, link);

	if (link.substr(link.length() - 5) != ".json")
	{
		std::cerr << "Not a json link. End with '.json'";
	}*/




    return 0;
}

