//任务描述
//实现一个IntArray类，用于管理动态整数数组，实践RAII（Resource Acquisition Is Initialization）模式。
//类设计：
//私有成员：int* data（指向动态数组）、size_t size（数组大小）
//公有接口：
//构造函数：IntArray(size_t n) - 分配n个int的数组，元素初始化为0
//析构函数：释放动态内存
//void set(size_t index, int value) - 设置指定位置的值，检查索引越界
//int get(size_t index) const - 获取指定位置的值，检查索引越界
//void print() const - 打印数组所有元素
//要求
//构造函数使用new[]分配内存，析构函数使用delete[]释放
//实现基本的边界检查（简化处理：越界时输出错误信息即可）
//演示RAII：对象离开作用域时自动释放资源
//完成建议
//先实现基本的构造 / 析构和内存管理
//添加边界检查逻辑
//测试代码：
#include<iostream>
#include<stdexcept>
class IntArray {
private:
	int* data;
	size_t size;
public:
	IntArray(size_t n) : size(n) {
		data = new int[n]{0};
	}
	~IntArray() {
		delete[] data;
	}
	void set(size_t index, int value) {
		if (index >= size || index < 0) {
			std::cerr << "Index out of bounds" << std::endl;
			return;
		}
		data[index] = value;
	}
	int get(size_t index) const {
		if (index >= size) {
			std::cerr << "Index out of bounds" << std::endl;
			return -1; // Return an invalid value
		}
		return data[index];
	}
	void print() const {
		for (size_t i = 0; i < size; ++i) {
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}
};

int main() {
	{
		IntArray arr(5);
		arr.set(0, 10);
		arr.set(2, 30);
		arr.print();
		std::cout << "arr[2] = " << arr.get(2) << std::endl;
		// 测试越界
		arr.set(10, 100);  // 应输出错误
	} // arr离开作用域，析构函数自动释放内存
}
