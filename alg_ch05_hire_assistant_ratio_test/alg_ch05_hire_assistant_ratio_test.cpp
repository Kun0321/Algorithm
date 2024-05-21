// alg_ch05_randomized_hire_assistant.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include <iostream>     // cout, endl
#include <vector>       // vector
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

const int COST_OF_HIRE = 100;

void generate_sequential_data(std::vector<int>&, size_t);
int randomized_hire_assistant(std::vector<int>& rank, int);
void cost_count(int (*fun)(std::vector<int>&, int), const std::vector<double> data_size, std::vector<double>& hire_cost);
void cost_log(const std::string name, const std::vector<double>& x, const std::vector<double>& y);

int main()
{
	std::vector<int> candidates;
	std::vector<double> data_size;
	std::vector<double> hire_cost;
	std::vector<double> ln_func;
	std::vector<double> ratio_test;

	for (int i = 1; i <= 100; i++) {
		data_size.push_back(i * 10000);
		ln_func.push_back(1.1 * COST_OF_HIRE * log(i * 10000));
	}

	cost_count(randomized_hire_assistant, data_size, hire_cost);
	cost_log("randomized_hire_assistant", data_size, hire_cost);

	for (size_t i = 0; i < hire_cost.size(); ++i)
		ratio_test.push_back(hire_cost[i] / ln_func[i]);

	plt::named_plot("Hire_Cost / Ln", data_size, ratio_test, "b-");
	plt::title("Ratio Test of randomized_hire_assistant vs. ln n");
	plt::legend();
	plt::ylim(0, 5);
	plt::pause(2);
	plt::show();

	return 0;
}
