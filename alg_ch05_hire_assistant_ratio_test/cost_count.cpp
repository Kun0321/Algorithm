#include <iostream>
#include <vector>
#include <iomanip>		// setw, fixed, setprecission

void generate_sequential_data(std::vector<int>& v, size_t n);

const int COST_OF_HIRE = 100;

void cost_count(int (*fun)(std::vector<int>&, int), const std::vector<double> data_size, std::vector<double>& hire_cost) {

	std::vector<int> A;

	for (auto i = 0; i < data_size.size(); ++i) {
		auto average_cost = 0;
		for (auto j = 0; j < 30; ++j) {
			generate_sequential_data(A, data_size[i]);
			average_cost += fun(A, COST_OF_HIRE);
		} // end of for auto j
		hire_cost.push_back(average_cost / 30.0);
	} // end of for auto i
}

void cost_log(const std::string name, const std::vector<double>& x, const std::vector<double>& y)
{
	std::cout << name << ":" << std::endl;
	for (auto i = 0; i < x.size(); ++i) {
		std::cout << "Size:" << std::setw(7) << (int)x[i] << " Cost:" << std::fixed << std::setprecision(7) << y[i] << std::endl;
	}
	std::cout << std::endl;
}
