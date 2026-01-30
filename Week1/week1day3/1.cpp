//任务描述
//定义一个Student类，包含以下成员：
//私有数据成员：
//std::string name：学生姓名
//int age：学生年龄
//double gpa：平均绩点（范围0.0 - 4.0）
//公有成员函数：
//void setInfo(const std::string & n, int a, double g)：设置学生信息，如果g不在[0.0, 4.0]范围内，设为0.0
//void displayInfo() const：显示学生信息，格式："姓名: [name], 年龄: [age], GPA: [gpa]"
//double getGPA() const：返回GPA值
//要求
//使用访问控制修饰符正确封装数据
//在setInfo中进行参数验证
//displayInfo应为const成员函数
//完成建议
//先定义类的基本结构
//实现setInfo的参数验证逻辑
//实现简单的displayInfo输出
//编写main函数测试：
#include <iostream>
#include<string>
class Student {
private:
	std::string name;
	int age;
	double gpa;
public:
	void setInfo(const std::string & n, int a, double g);
	void displayInfo() const;
	double getGPA() const;
};
//成员函数实现
void Student::setInfo(const std::string & n, int a, double g) {
	name = n;
	age = a;
	if (g < 0.0 || g>4.0) {
		gpa = 0.0;
	}
	else {
		gpa = g;
	}
}
void Student::displayInfo() const {
	std::cout << "姓名: [" << name << "], 年龄: [" << age << "], GPA: [" << gpa << "]" << std::endl;
}
double Student::getGPA() const { 
	return gpa;
}



int main() {
	Student s1, s2;
	s1.setInfo("张三", 20, 3.8);
	s2.setInfo("李四", 22, 4.5);  // 非法GPA，应设为0.0
	s1.displayInfo();
	s2.displayInfo();
	std::cout << "s1的GPA: " << s1.getGPA() << std::endl;
}