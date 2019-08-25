/*
数组和矩阵的输出
*/

#include <vector>

namespace sort {
template <typename T>
void print_vector(std::vector<T>& nums)
{
    for (T& item : nums) {
        std::cout << item << ' ';
    }
    std::cout << endl;
}

template <typename T>
void print_matrix(std::vector<std::vector<T>>& matrix)
{
    for (std::vector<T>& item : matrix) {
        print_vector(item);
    }
}
} // namespace sort
