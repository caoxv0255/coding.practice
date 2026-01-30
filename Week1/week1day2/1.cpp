//任务描述：
//声明一个整型变量 num 并初始化为 100
//声明一个整型指针 pNum，使其指向 num
//使用指针修改 num 的值为 200
//分别输出：num 的值、 & num 的地址、pNum 的值、 & pNum 的地址、 * pNum 的值
#include<iostream>
int main() {
	int num = 100;
	int* pNum = &num;
	*pNum = 200;
	std::cout << num << std::endl << &num << std::endl << pNum << std::endl << &pNum << std::endl << *pNum << std::endl;
}