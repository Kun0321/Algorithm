#include <vector>
#include <algorithm>

void generate_sequential_data(std::vector<int>& v, size_t n)
{
	auto f = []() -> int {static int i = 0; return ++i; };
	v.resize(n);
	std::generate(v.begin(), v.end(), f);
}
