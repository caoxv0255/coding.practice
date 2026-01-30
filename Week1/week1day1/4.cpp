#include <iostream>
#include <vector>
#include <algorithm>

void vectorIterators() {
    std::vector<int> vec = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

    // TODO 1: 使用普通迭代器(begin/end)正向遍历并打印元素
	std::cout << "正向：" << std::endl;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
    // TODO 2: 使用反向迭代器(rbegin/rend)逆向遍历并打印元素
    std::cout << "逆向：" << std::endl;
    for (auto rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        std::cout << *rit << ' ';
    }
    std::cout << std::endl;
    // TODO 3: 使用const迭代器(cbegin/cend)遍历，尝试修改元素（应编译失败）
    std::cout << "const：" << std::endl;
    for (auto cit = vec.cbegin(); cit != vec.cend(); ++cit) {
        //*cit = 100;
        std::cout << *cit << ' ';
    }
    std::cout << std::endl;
    // TODO 4: 使用迭代器修改元素：将所有偶数乘以2
    std::cout << "偶数×2：" << std::endl;
    for (auto dit = vec.begin(); dit != vec.end(); ++dit) {
        if (*dit % 2 == 0) {
            *dit *= 2;
        }
    }
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    // TODO 5: 使用迭代器和算法：使用std::find查找元素40
    // 如果找到，打印位置；否则打印未找到
    std::cout << "find 40：" << std::endl;
    auto found_it = std::find(vec.begin(), vec.end(), 40);
    if (found_it!=vec.end()) {
        //std::cout << "找到，索引为：" << found_it - vec.begin() << std::endl;
        std::cout << "找到，索引为：" << std::distance(vec.begin(),found_it) << std::endl;

    }
    else {
        std::cout << "未找到" << std::endl;
    }
    // TODO 6: 迭代器失效演示（选做）
    // 在遍历过程中执行insert/erase操作，观察迭代器失效问题
    // 提示：insert/erase会使指向插入/删除点之后的迭代器失效
    std::cout << "失效：" << std::endl;
    //for (auto it = vec.begin(); it != vec.end(); ++it) {
    //    std::cout << *it << ' ';
    //    //vec.insert(vec.begin() + 3, 3, 100); // insert后扩容，全部失效
    //}
    
    //for (auto it = vec.begin(); it != vec.end(); ++it) {
    //    if (*it % 2 == 0) {
    //        //vec.erase(it); // erase后 it 失效，下一次 ++it 是非法的
    //    }
    //}
    for (auto it = vec.begin(); it != vec.end(); ) {
        if (*it % 2 == 0) {
            it = vec.erase(it);
        }
        else {
            it++;
        }
    }
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}
int main() {
    vectorIterators();
}