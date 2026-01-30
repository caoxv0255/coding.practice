#include <iostream>
#include <vector>

void vectorCapacityManagement() {
    // TODO 1: 创建一个空vector，打印初始大小和容量
    std::vector<int>v;
    std::cout << "大小：" << v.size() << std::endl << "容量：" << v.capacity();
    std::cout << std::endl;
    // TODO 2: 使用reserve(10)预留容量，再次打印大小和容量
    // 注意：reserve只影响容量，不影响大小
    v.reserve(10);
    std::cout << "大小：" << v.size() << std::endl << "容量：" << v.capacity();
    std::cout << std::endl;
    // TODO 3: 添加5个元素（1到5），每次添加后打印大小和容量
    // 观察容量是否变化（因为已预留容量，不应触发扩容）
    for (int i = 1; i <= 5; i++) {
        v.push_back(i);
        std::cout << "大小：" << v.size() << std::endl << "容量：" << v.capacity();
        std::cout << std::endl;
        for (int i = 0; i < v.size(); i++) {
            std::cout << v[i] << ' ';
        }
        std::cout << std::endl;

    }
    // TODO 4: 使用resize(8)将大小改为8，打印vector内容和容量
    // 注意：resize会增加默认初始化的元素（int默认为0）
    v.resize(8);
    std::cout << "大小：" << v.size() << std::endl << "容量：" << v.capacity();
    std::cout << std::endl;
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << ' ';
    }
    std::cout << std::endl;

    // TODO 5: 使用resize(3)将大小改为3，打印vector内容和容量
    // 注意：resize减小大小时会丢弃多余元素，但容量不变
    v.resize(3);
    std::cout << "大小：" << v.size() << std::endl << "容量：" << v.capacity();
    std::cout << std::endl;
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << ' ';
    }
    std::cout << std::endl;
    // TODO 6: 使用shrink_to_fit()请求减少容量，打印容量变化
    // 注意：shrink_to_fit是请求，实现可能忽略
    v.shrink_to_fit();
    std::cout << "大小：" << v.size() << std::endl << "容量：" << v.capacity();
    std::cout << std::endl;
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << ' ';
    }
    std::cout << std::endl;
    // TODO 7: 清除所有元素(clear())，再次尝试shrink_to_fit()
    v.clear();
    v.shrink_to_fit();
    std::cout << "大小：" << v.size() << std::endl << "容量：" << v.capacity();
    std::cout << std::endl;
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << ' ';
    }
    std::cout << std::endl;
    // TODO 8: 对比两种扩容策略的性能影响
    // 创建两个vector，分别使用默认扩容和预分配策略，插入10000个元素
    // 使用clock()计时，对比耗时
    clock_t start_time1 = clock();
    std::vector<int> vec1;
    for (int i = 0; i < 100000000; ++i) {
        vec1.push_back(i);
    }
    clock_t end_time1 = clock();
    double duration_default1 = static_cast<double>(end_time1 - start_time1) / CLOCKS_PER_SEC;
    std::cout << "默认扩容策略耗时: " << duration_default1 << " 秒" << std::endl;
    
    clock_t start_time2 = clock();
    std::vector<int> vec2;
    vec1.reserve(100000000);
    for (int i = 0; i < 100000000; ++i) {
        vec2.push_back(i);
    }
    clock_t end_time2 = clock();
    double duration_default2 = static_cast<double>(end_time2 - start_time2) / CLOCKS_PER_SEC;
    std::cout << "预分配扩容策略耗时: " << duration_default2 << " 秒" << std::endl;
}
int main() {
    vectorCapacityManagement();
}