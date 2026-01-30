//** 任务描述** ：
//使用 std::unique_ptr 创建一个动态整型数组（5个元素）
//初始化数组值为{ 1, 3, 5, 7, 9 }
//计算数组元素的平方和
//使用 std::shared_ptr 实现一个简单的共享资源示例：
//创建 shared_ptr<int> 指向动态分配的整型
//创建另一个 shared_ptr 共享同一对象
//输出引用计数变化
#include<iostream>
#include<memory>
#include<cmath>
int main() {
	std::unique_ptr<int[]>p1(new int[5] {1, 3, 5, 7, 9});
	int square_sum = 0;
	for (int i = 0; i < 5; i++) {
		square_sum += std::pow(p1[i], 2);
	}
	std::cout << "sum of squares:" << square_sum << std::endl;
	std::shared_ptr<int>sp1 = std::make_shared<int>(10);
	std::cout << "count:" << sp1.use_count() << std::endl;
	std::shared_ptr<int>sp2 = sp1;
	std::cout << "count:" << sp1.use_count() << std::endl;
	sp1.reset();
	std::cout << "count:" << sp1.use_count() << std::endl;
	return 0;
}