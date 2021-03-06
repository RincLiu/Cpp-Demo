#include <iostream>
#include <forward_list>

int main (int argc, char ** argv) {

	std::forward_list<int> fl = {0,1,2,3,4,5,6,7,8,9};

	auto prev = fl.before_begin();
	auto curr = fl.begin();

	while (curr != fl.end()) {
		if (*curr % 2)
			curr = fl.erase_after(prev); // erase it and move curr
		else {
			prev = curr;
			curr++;
		}
	}

	for (curr = fl.begin(); curr != fl.end(); curr++) {
		std::cout << *curr << std::endl;
	}

	return 0;
}