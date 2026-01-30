#include <iostream>
#include <vector>

void dynamicVectorModifications() {
    // 初始vector
    std::vector<int> vec = { 1, 2, 3, 4, 5 };

    // TODO 1: 打印初始vector
    std::cout << "初始vector: ";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << ' ';
    }
    std::cout << std::endl;
    // TODO 2: 使用push_back添加元素6, 7, 8
    // 每次添加后打印vector大小和容量，观察容量变化
    vec.push_back(6);
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << ' ';
    }
    std::cout << std::endl;
    std::cout << std::endl << "大小：" << vec.size() << std::endl << "容量：" << vec.capacity() << std::endl;
    vec.push_back(7);
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << ' ';
    }
    std::cout << std::endl;
    std::cout << std::endl << "大小：" << vec.size() << std::endl << "容量：" << vec.capacity() << std::endl;
    vec.push_back(8); for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << ' ';
    }
    std::cout << std::endl;
    std::cout << std::endl << "大小：" << vec.size() << std::endl << "容量：" << vec.capacity() << std::endl;
    std::cout << std::endl;
    // TODO 3: 使用pop_back删除尾部元素
    // 删除前先打印要删除的元素，删除后打印vector
    std::cout << vec.back() << std::endl;
    vec.pop_back();
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << ' ';
    }
    std::cout << std::endl;
    // TODO 4: 在位置2（第三个元素前）插入元素100
    // 使用insert(iterator position, const value_type& val)
    // 提示：vec.begin() + 2 获取位置2的迭代器
    vec.insert(vec.begin() + 2, 100);
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << ' ';
    }
    std::cout << std::endl;
    // TODO 5: 在位置3插入3个相同的元素200
    // 使用insert(iterator position, size_type n, const value_type& val)
    vec.insert(vec.begin() + 3, 3, 200);
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << ' ';
    }
    std::cout << std::endl;
    // TODO 6: 删除位置4的元素（单个元素删除）
    // 使用erase(iterator position)
    vec.erase(vec.begin() + 4);
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << ' ';
    }
    std::cout << std::endl;
    // TODO 7: 删除位置1到位置4的范围（不包含位置4）
    // 使用erase(iterator first, iterator last)
    vec.erase(vec.begin() + 1, vec.begin() + 4);
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << ' ';
    }
    std::cout << std::endl;
}
int main() {
    dynamicVectorModifications();
}