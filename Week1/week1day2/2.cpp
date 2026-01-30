//任务描述：
//创建一个整型数组 arr，包含元素{ 5, 10, 15, 20, 25 }
//声明一个指针 p 指向数组首元素
//使用指针算术（p++ 或 p + i）完成以下任务：
//输出数组所有元素（使用指针遍历）
//计算数组元素总和
//找到最大值并输出其值和索引位置
#include<iostream>
int main() {
	int arr[] = { 5, 10, 15, 20, 25 };
	int* p = arr;
	for (int i = 0; i < 5; i++) {
		std::cout << *p + i << ' ';
	}
	std::cout << std::endl;
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += *p + i;
	}
	std::cout << "sum:" << sum << std::endl;
	int max = *p;
	int pos = 0;
	for (int i = 0; i < 5; i++) {
		if (max < *p + i) {
			max = *p + i;
			pos = i;
		}
	}
	std::cout << "max:" << max << std::endl;
	std::cout << "index:" << pos << std::endl;
	return 0;
}