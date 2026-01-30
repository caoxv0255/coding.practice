#include <iostream>
#include <vector>
#include <stdexcept>

void basicVectorOperations() {
    // TODO 1: 创建一个包含5个整数的vector，初始值为{10, 20, 30, 40, 50}
    // 提示：使用初始化列表语法
    std::vector<int>v = { 10, 20, 30, 40, 50 };
    // TODO 2: 打印vector的所有元素（使用[]访问）
    std::cout << "vector元素: ";
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << ' ';
    }
    // TODO 3: 使用at()方法访问第3个元素（索引2），并打印
    // 注意：at()会进行边界检查
    std::cout << std::endl << v.at(2);
    // TODO 4: 打印首元素(front)和尾元素(back)
    std::cout << "首元素：" << v.front();
    std::cout << std::endl;
    std::cout << "尾元素：" << v.back();
    // TODO 5: 打印vector的大小(size)和容量(capacity)
    std::cout << std::endl;
    std::cout << "大小：" << v.size();
    std::cout << std::endl;
    std::cout << "容量：" << v.capacity();
    std::cout << std::endl;
    // TODO 6: 尝试使用at()访问越界元素（如索引10），捕获异常并打印错误信息
    // 提示：使用try-catch块捕获std::out_of_range异常
    try {
        int val = v.at(10);
    }
    catch(const std::out_of_range&e){
        std::cerr << "at()越界访问异常: 索引10超出范围";
    }
    // TODO 7: 对比[]和at()的差异：使用[]访问越界元素，观察会发生什么
    std::cout << v[10];
}
int main() {
    basicVectorOperations();
}