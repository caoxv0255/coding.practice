//练习5：模板函数——通用容器统计
//任务描述：
//编写一个模板函数 containerStats，能够计算任意数值类型容器的统计信息。函数应返回一个结构体，包含：
//最小值
//最大值
//平均值
//总和
//具体要求：
//模板函数应支持 std::vector、std::array、普通数组等容器
//使用迭代器遍历容器元素
//处理空容器情况（返回合理的默认值）
//编写特化版本或重载以支持 std::string 容器（统计字符串长度）
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <iterator>
#include <algorithm>
#include <numeric>
// 统计信息结构体
template<typename T> 
struct Stats{
	// 成员变量
	T min;
	T max;
	double average;
	T sum;
	// 默认构造函数初始化成员变量
	Stats() : min(T()), max(T()), average(0.0), sum(T()) {}
	void print() const {
		std::cout << "Min: " << min <<
			std::endl << "Max: " << max <<
			std::endl << "Average: " << average <<
			std::endl << "Sum: " << sum << std::endl << std::endl;
	}//打印统计信息
};

// 通用模板函数计算统计信息
template<typename Container>
Stats<typename Container::value_type> containerStats(const Container& container) {
	using T = typename Container::value_type;
	Stats<T> stats;
	if (container.empty()) {
		return stats; // 返回默认值
	}
	//STL语法: minmax, accumulate
	auto minmax = std::minmax_element(std::begin(container), std::end(container));
	stats.min = *minmax.first;
	stats.max = *minmax.second;
	stats.sum = std::accumulate(std::begin(container), std::end(container), T{});
	stats.average = stats.sum * 1.0 / container.size();
	return stats;
}

// 重载版本处理普通数组
// 注意：传入数组时需要传递大小
template<typename T, size_t N>
Stats<T> containerStats(const T(&array)[N]) {
	Stats<T> stats;
	if (N == 0) {
		return stats; // 返回默认值
	}
	auto minmax = std::minmax_element(std::begin(array), std::end(array));
	stats.min = *minmax.first;
	stats.max = *minmax.second;
	stats.sum = std::accumulate(std::begin(array), std::end(array), T{});
	stats.average = stats.sum * 1.0 / N;
	return stats;
}

// 特化版本处理 std::string 容器
Stats<size_t> containerStats(const std::vector<std::string>& container) {
	Stats<size_t> stats;
	if (container.empty()) {
		return stats; // 返回默认值
	}
	std::vector<size_t> lengths;
	for (const auto& str : container) {
		lengths.push_back(str.length());
	}
	auto minmax = std::minmax_element(lengths.begin(), lengths.end());
	stats.min = *minmax.first;
	stats.max = *minmax.second;
	stats.sum = std::accumulate(lengths.begin(), lengths.end(), size_t{});
	stats.average = stats.sum * 1.0 / container.size();
	return stats;
}

// 特化版本处理 std::array<std::string, N>
template<size_t N>
Stats<size_t> containerStats(const std::array<std::string, N>& container) {
	Stats<size_t> stats;
	if (N == 0) return stats;

	std::vector<size_t> lengths;
	for (const auto& str : container) {
		lengths.push_back(str.length());
	}

	auto minmax = std::minmax_element(lengths.begin(), lengths.end());
	stats.min = *minmax.first;
	stats.max = *minmax.second;
	stats.sum = std::accumulate(lengths.begin(), lengths.end(), size_t{});
	stats.average = static_cast<double>(stats.sum) / N;
	return stats;
}

int main() {
	// 测试1：std::vector (整数)
	std::vector<int> vec = { 1, 5, 3, 9, 2 };
	std::cout << "Vector<int> 统计结果: ";
	auto result1 = containerStats(vec);
	result1.print();

	// 测试2：std::array (浮点数)
	std::array<double, 4> arr = { 1.5, 2.5, 3.5, 4.5 };
	std::cout << "Array<double> 统计结果: ";
	auto result2 = containerStats(arr);
	result2.print();

	// 测试3：普通数组
	int c_array[] = { 10, 20, 30, 40, 50 };
	std::cout << "C数组 统计结果: ";
	auto result3 = containerStats(c_array);
	result3.print();

	// 测试4：std::vector<std::string> (字符串长度统计)
	std::vector<std::string> strings = { "hello", "world", "C++", "template" };
	std::cout << "Vector<string> 长度统计: ";
	auto result4 = containerStats(strings);
	result4.print();

	// 测试5：空容器
	std::vector<int> empty_vec;
	std::cout << "空容器 统计结果: ";
	auto result5 = containerStats(empty_vec);
	result5.print();

	return 0;
}