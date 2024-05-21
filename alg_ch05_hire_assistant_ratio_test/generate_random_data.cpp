#include <vector>

void generate_random_data(std::vector<int>& v, int size)
{
	v.resize(size);
	for (int i = 0; i < v.size(); i++) {
		v[i] = rand() % (size * 2) - size;
	}
}
