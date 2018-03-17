#include <string>
#include <list>
#include <iostream>
#include <string.h>	// strlen

typedef std::list<std::string> strings_t;

strings_t split(const char* s, const char* d)
{
	strings_t ss;

	size_t dlen = strlen(d);
	for (const char* p; (p = strstr(s, d)); s = p + dlen)
		ss.emplace_back(s, p);
	ss.emplace_back(s);

	return ss;
}
 
int main(int argc, char* argv[])
{
	for (int i = 0; 2*i + 2 < argc; ++i) {
		strings_t ss = split(argv[i*2 + 1], argv[i*2 + 2]);
		for (auto& s : ss)
			std::cout << s << ":[" << s.size() << "] ";
		std::cout << '\n';
	}
}
