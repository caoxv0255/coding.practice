//练习2：参数传递机制——数据修改对比
//任务描述：
//编写一个程序，演示三种参数传递方式（值传递、引用传递、指针传递）对原始数据的不同影响。创建三个函数：
//modifyByValue：值传递，尝试修改参数
//modifyByReference：引用传递，修改参数
//modifyByPointer：指针传递，修改参数
//具体要求：
//每个函数接受一个整数参数，并尝试将其乘以2
//在 main 函数中创建变量 x = 5，分别用三种方式调用函数
//打印每次调用后 x 的值，观察变化

#include <iostream>
int modifyByValue(int num) {
	num *= 2;
	return num;
}
int modifyByReference(int &num) {
	num *= 2;
	return num;
}
int modifyByPointer(int *num) {
	*num *= 2;
	return *num;
}
int main() {
	int x = 5;
	std::cout << "原始值：" << "x = " << x << std::endl;
	modifyByValue(x);
	std::cout << "值传递后：" << "x = " << x << std::endl;
	modifyByReference(x);
	std::cout << "引用传递后：" << "x = " << x << std::endl;
	modifyByPointer(&x);
	std::cout << "指针传递后：" << "x = " << x << std::endl;
}