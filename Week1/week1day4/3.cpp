//练习3：函数重载——打印多种数据类型
//任务描述：
//实现一组重载的 print 函数，能够处理不同类型的数据。要求支持：
//int 类型：打印整数
//double 类型：打印浮点数（保留2位小数）
//const char* 类型：打印C风格字符串
//std::string 类型：打印C++字符串
//std::vector<int> 类型：打印向量内容
//具体要求：
//所有函数名为 print，根据参数类型自动选择合适版本
//浮点数输出使用 std::fixed 和 std::setprecision(2)
//向量输出格式为[1, 2, 3, 4, 5]
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>

void print(int a) {
	std::cout << a << std::endl;
}
void print(double a) {
	std::cout << std::fixed<<std::setprecision(2)<< a <<std::endl;
}
void print(const char* a) {
	std::cout << *a << std::endl;
}
void print(std::string a) {
	std::cout << a << std::endl;
}
void print(std::vector<int> a) {
	std::cout << "[";
	for (int i = 0; i < a.size(); i++) {
		std::cout << a[i];
		if (i < a.size()-1) {
			std::cout << ",";
		}
	}
	std::cout << "]";
}

int main() {
	print(1);
	print(2.0);
	const char a = 'a';
	print(&a);
	std::string b = "hello world";
	print(b);
	std::vector<int> c = { 1,2,3,4,5 };
	print(c);

}