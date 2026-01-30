//任务描述
//实现一个Fraction（分数）类，重载常用运算符，使分数运算更直观。
//类设计：
//私有成员：int numerator（分子）、int denominator（分母，不能为0）
//公有接口：
//构造函数：Fraction(int num, int den) - 分母为0时抛出异常或设为1
//约分函数：void reduce() - 将分数化为最简形式（可选实现）
//运算符重载：
//Fraction operator+(const Fraction & other) const 加法
//Fraction operator-(const Fraction & other) const 减法
//Fraction operator*(const Fraction & other) const 乘法
//Fraction operator/(const Fraction & other) const 除法
//bool operator==(const Fraction & other) const 相等比较
//friend std::ostream & operator<<(std::ostream & os, const Fraction & f) 输出
//friend std::istream & operator>>(std::istream & is, Fraction & f) 输入
//要求
//实现基本的分数运算（加减乘除）
//流运算符应支持格式："分子/分母"（如"3/4"）
//比较运算符应比较约分后的值
//完成建议
//实现基本构造和约分辅助函数
//从简单的运算符开始（如加法）
//实现流运算符支持输入输出
//测试代码：
#include<iostream>

class Fraction {
private:
	int numerator;
	int denominator;
public:
	Fraction(int num, int den) : numerator(num), denominator(den) {
		if (denominator == 0) {
			denominator = 1; // or throw an exception
		}
		reduce();
	}
	void reduce() {
		int a = numerator;
		int b = denominator;
		while (b != 0) {
			int temp = b;
			b = a % b;
			a = temp;
		}
		numerator /= a;
		denominator /= a;
	}

	//运算符重载
	Fraction operator+(const Fraction & other) const {
		return Fraction(numerator * other.denominator + other.numerator * denominator,
			denominator * other.denominator);
	}
	Fraction operator-(const Fraction & other) const {
		return Fraction(numerator * other.denominator - other.numerator * denominator,
			denominator * other.denominator);
	}
	Fraction operator*(const Fraction& other) const {
		return Fraction(numerator * other.numerator,
			denominator * other.denominator);
	}
	Fraction operator/(const Fraction& other) const {
		return Fraction(numerator * other.denominator,
			denominator * other.numerator);
	}

	bool operator==(const Fraction& other) const {
		return numerator == other.numerator && denominator == other.denominator;
	}

	friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
		os << f.numerator << " / " << f.denominator ;
		return os;
	}
	friend std::istream & operator>>(std::istream & is, Fraction & f) {
		char slash = '/';
		is >> f.numerator >> slash>> f.denominator;
		if(f.denominator == 0) {
			f.denominator = 1; // or throw an exception
		}
		f.reduce();
		return is;
	}

};

int main() {
	Fraction f1(1, 2);
	Fraction f2(3, 4);

	Fraction sum = f1 + f2;
	Fraction diff = f1 - f2;
	Fraction prod = f1 * f2;
	Fraction quot = f1 / f2;

	std::cout << "f1 = " << f1 << std::endl;
	std::cout << "f2 = " << f2 << std::endl;
	std::cout << "sum = " << sum << std::endl;
	std::cout << "f1 == f2? " << (f1 == f2) << std::endl;
}