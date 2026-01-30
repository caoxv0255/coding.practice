//练习1：函数基础——计算器功能模块
//任务描述：
//创建一个简单的四则运算计算器模块，包含四个独立的函数：add、subtract、multiply、divide。每个函数接受两个 double 参数，返回计算结果。注意 divide 函数需要处理除零错误。
//具体要求：
//在头文件 calculator.h 中声明四个函数
//在源文件 calculator.cpp 中实现函数定义
//创建 main.cpp 测试这些函数
//divide 函数在除零时返回 NaN（std::numeric_limits<double>::quiet_NaN()）

#include <iostream>
#include <limits>
#include"calculate.h"


int main() {
	// 在main函数中测试
	std::cout << add(5.0, 3.0) << std::endl;      // 输出 8
	std::cout << subtract(5.0, 3.0) << std::endl; // 输出 2
	std::cout << multiply(5.0, 3.0) << std::endl; // 输出 15
	std::cout << divide(5.0, 0.0) << std::endl;   // 输出 nan
}
