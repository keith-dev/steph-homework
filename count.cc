#include <set>
#include <iostream>

typedef std::set<int>		numbers_t;
typedef std::set<numbers_t>	set_t;
typedef std::set<set_t>		sets_t;

std::ostream& print(std::ostream& os, const set_t& set);
void insert(set_t& set, int i, int j, int k);
void check(set_t& set);
void check1(set_t& set, int start);
void check2(set_t& set, int i, int start);
void check3(set_t& set, int i, int j, int start);

template <typename MAJOR, typename MINOR>
bool dup(const MAJOR& major, const MINOR& minor)
{
	for (const MINOR& inner : major)
		for (const typename MINOR::value_type& n : inner)
			if (minor.find(n) != minor.end())
				return true;

	return false;
}

int main()
{
	sets_t sets;
	for (int a = 1; a < 9; ++a) {
		set_t set;
		check1(set, a);

		if (set.size() == 3 && !dup(sets, set)) {
			sets.insert(set);
			print(std::cout, set);
		}
	}
}

std::ostream& print(std::ostream& os, const set_t& set)
{
	for (const numbers_t& numbers : set) {
		os << "{ ";
		for (int number : numbers)
			os << number << " ";
		os << "} ";
	}
	os << std::endl;

	return os;
}

void insert(set_t& set, int i, int j, int k)
{
	if (i == j) return;
	if (i == k) return;
	if (j == k) return;

	if (i + j + k == 15) {
		numbers_t numbers;
		numbers.insert(i);
		numbers.insert(j);
		numbers.insert(k);

		if (!dup(set, numbers))
			set.insert(numbers);
	}
}

void check1(set_t& set, int start)
{
	for (int i = start; i <= 9; ++i) {
		for (int j = 1; j <= 9; j += 1) check2(set, i, j);
		for (int j = 1; j <= 9; j += 2) check2(set, i, j);
		for (int j = 1; j <= 9; j += 3) check2(set, i, j);
		for (int j = 1; j <= 9; j += 4) check2(set, i, j);
		for (int j = 1; j <= 9; j += 5) check2(set, i, j);
		for (int j = 1; j <= 9; j += 6) check2(set, i, j);
		for (int j = 1; j <= 9; j += 7) check2(set, i, j);
		for (int j = 1; j <= 9; j += 8) check2(set, i, j);
		for (int j = 1; j <= 9; j += 9) check2(set, i, j);
	}
}

void check2(set_t& set, int i, int start)
{
	for (int j = start; j <= 9; ++j) {
		for (int k = 1; k <= 9; k += 1) check3(set, i, j, k);
		for (int k = 1; k <= 9; k += 2) check3(set, i, j, k);
		for (int k = 1; k <= 9; k += 3) check3(set, i, j, k);
		for (int k = 1; k <= 9; k += 4) check3(set, i, j, k);
		for (int k = 1; k <= 9; k += 5) check3(set, i, j, k);
		for (int k = 1; k <= 9; k += 6) check3(set, i, j, k);
		for (int k = 1; k <= 9; k += 7) check3(set, i, j, k);
		for (int k = 1; k <= 9; k += 8) check3(set, i, j, k);
		for (int k = 1; k <= 9; k += 9) check3(set, i, j, k);
	}
}

void check3(set_t& set, int i, int j, int start)
{
	for (int k = start; k <= 9; k += 1) insert(set, i, j, k);
}

void check(set_t& set)
{
	for (int i = 1; i <= 9; ++i) {
		for (int j = 1; j <= 9; ++j) {
			for (int k = 1; k <= 9; ++k) {
				if (i == j) continue;
				if (i == k) continue;
				if (j == k) continue;

				insert(set, i, j, k);
			}
		}
	}
}
