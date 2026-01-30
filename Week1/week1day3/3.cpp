//任务描述
//实现一个简单的String类，练习拷贝构造函数、拷贝赋值运算符，并理解深拷贝的必要性。
//类设计：
//私有成员：char* data（C风格字符串）、size_t length（字符串长度，不含结尾空字符）
//公有接口：
//构造函数：String(const char* str) - 从C字符串构造
//析构函数：释放内存
//拷贝构造函数：实现深拷贝
//拷贝赋值运算符：实现深拷贝，正确处理自赋值
//void print() const - 打印字符串
//size_t getLength() const - 返回字符串长度
//要求
//必须实现深拷贝，避免多个对象共享同一内存
//拷贝赋值运算符需检查自赋值
//遵循"三五法则"：管理资源的类需定义拷贝控制函数
//完成建议
//实现基本构造 / 析构
//实现深拷贝的拷贝构造函数
//实现拷贝赋值运算符（注意自赋值检查）
//测试代码：

#include<iostream>
#include<cstring>

class String {
private:
	char* data;
	size_t length;

public:
	String(const char* str) {
		if (str == nullptr) {
			length = 0;
			data = new char[1];
			data[0] = '\0';
		}
		else {
			length = strlen(str);
			data = new char[length + 1];
			strcpy_s(data, length + 1, str);
		}
	}

	~String() {
		delete[] data;
	}

	String(const String& other) {
		length = other.length;
		data = new char[length + 1];
		strcpy_s(data, length + 1, other.data);
	}

	String& operator=(const String& other) {
		if (this != &other) {
			char* new_data = new char[other.length + 1];
			strcpy_s(new_data, length + 1, other.data);
			delete[] data;
			length = other.length;
			data = new_data;
		}
		return *this;
	}

	void print() const {
		std::cout << data << std::endl;
	}
	size_t getLength() const {
		return length;
	}
};

int main() {
	String s1("Hello");
	String s2 = s1;  // 拷贝构造
	String s3("World");
	s3 = s1;         // 拷贝赋值

	s1.print();
	s2.print();
	s3.print();
	
	// 测试自赋值
	s1 = s1;  // 应安全处理
}