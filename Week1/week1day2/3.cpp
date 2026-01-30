//任务描述：
//动态创建一个 3×4 的整型二维数组（使用指针的指针）
//使用嵌套循环为数组赋值：matrix[i][j] = i * 10 + j
//输出整个二维数组的内容（格式化输出为矩阵形式）
//正确释放所有动态分配的内存
#include<iostream>
int main() {
	int** matrix = new int* [3];
	for (int i = 0; i < 3; i++) {
		matrix[i] = new int[4];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			matrix[i][j] = i * 10 + j;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << matrix[i][j];
			if (j < 3) { std::cout << ' '; }
		}
		std::cout << std::endl;
	}
	delete[] matrix;
	matrix = nullptr;
}