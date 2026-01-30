#include<iostream>
#include<memory>
int main() {
	//1
	//int* ptr = nullptr;
	//*ptr = 10;  // 错误
		//错误类型：空指针解引用
		//为什么错：空指针没有指向有效的内存地址，解引用会导致未定义行为。
		//正确代码：
	int value = 10;
	int* ptr = &value;

//4
//int arr[5] = { 0 };
//for (int i = 0; i <= 5; i++) {  // 错误：i=5时越界
//    arr[i] = i * 2;
//}
	//错误类型：数组越界访问
	//为什么错：数组索引超出范围，访问了未分配的内存。
	//正确代码：
	int arr4[5] = { 0 };
	for (int i = 0; i < 5; i++) {
		arr4[i] = i * 2;
	}
}
//2
	//void createArray() {
	//    int* arr = new int[100];
	//    // 使用数组...
	//    // 忘记释放内存
	//}
		//错误类型：内存泄露
		//为什么错：内存分配后没有释放，导致内存泄露。
		//正确代码：
void createArray() {
	int* arr = new int[100];
	delete[] arr;
	arr = nullptr; // 建议：将指针置空，防止野指针
}

//3
//int* getPointer() {
//    int value = 42;
//    return &value;  // 返回局部变量地址
//}
	//错误类型：返回局部变量地址，非法悬空指针
	//为什么错：返回的指针指向的内存已经被释放，使用会导致未定义行为。
	//正确代码：
	int* getPointer() {
		int* value = new int(42);
		return value;  // 返回动态分配的内存地址
		// 使用完 value 后
		delete value;  // 释放单个对象的内存
		value = nullptr; // 建议：将指针置空，防止野指针
	}

