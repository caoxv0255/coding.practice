//练习4：Lambda表达式——数据筛选与转换
//任务描述：
//使用Lambda表达式配合STL算法，完成以下任务：
//筛选偶数：从整数向量中筛选出所有偶数
//字符串长度筛选：从字符串向量中筛选出长度大于5的字符串
//数值转换：将整数向量中的每个元素平方，生成新向量
//自定义排序：按绝对值大小对整数向量进行降序排序
//具体要求：
//使用 std::copy_if、std::transform、std::sort 等算法
//每种操作用一个Lambda表达式实现
//在 main 函数中创建测试数据并验证结果

#include<iostream>
#include<vector>
#include<algorithm>

int main() {
	std::vector<int> numbers = { 1, -2, 3, -4, 5, 6, -7, 8, 9, -10 };
	std::vector<std::string> words = { "apple", "banana", "cat", "elephant", "dog" };
	
	std::vector<int> even;
	std::copy_if(numbers.begin(), numbers.end(),
		std::back_inserter(even),
		[](int x) {return x % 2 == 0; });
	std::cout << "Even numbers: ";
	for (int n : even) {
		std::cout << n << " ";
	}
	std::cout << std::endl;
	
	std::vector<std::string> Morethan5;
	std::copy_if(words.begin(), words.end(),
		std::back_inserter(Morethan5),
		[](std::string word) { return word.length() > 5; });
	std::cout << "Words more than 5 chareters: ";
	for (std::string word : Morethan5) {
		std::cout << word << " ";
	}
	std::cout << std::endl;

	std::vector<int> squares;
	std::transform(numbers.begin(), numbers.end(),
		std::back_inserter(squares),
		[](int x) {return x * x; });
	std::cout << "Squares: ";
	for (int n : squares) {
		std::cout << n << " ";
	}
	std::cout << std::endl;

	std::sort(numbers.begin(), numbers.end(),
		[](int a, int b) {return std::abs(a) > std::abs(b); });
	std::cout << "Sorted numbers: ";
	for (int n : numbers) {
		std::cout << n << " ";
	}
	std::cout << std::endl;
	return 0;
}