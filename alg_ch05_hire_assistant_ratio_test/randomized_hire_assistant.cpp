#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

void randomize(std::vector<int>& v)
{
    std::default_random_engine generator(time(NULL));
    std::shuffle(v.begin(), v.end(), generator); // Randomize 
}

void randomize_in_place(std::vector<int>& A)
{
    auto n = A.size();
    for (auto i = 0; i < n; i++)
        std::swap(A[i], A[(i + rand()) % n]);
    // [TODO]
} // end of randomize_in_place

int hire_assistant(std::vector<int>& rank, int c_h)
{
    int best = 0;
    int cost = 0;

    for (auto i : rank) {
        if (i > best) {
            best = i;
            cost += c_h;
        }
    }
    return cost;
    // [TODO]
} // end of hire_assistant

int randomized_hire_assistant(std::vector<int>& rank, int c_h)
{
    randomize_in_place(rank);
    return hire_assistant(rank, c_h);
    // [TODO]
} // end of randomized_hire_assistant
