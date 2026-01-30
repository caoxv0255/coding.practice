#include <iostream>
#include <vector>
#include <deque>
#include <string>

// 场景 D：模拟大型对象
struct LargeObject {
    int data[1000]; // 模拟占用大量内存
    LargeObject(int x = 0) { data[0] = x; }
};

// 场景 C：模拟 C 风格函数，要求连续内存指针
void cStyleFunction(int* ptr, size_t size) {
    // 处理连续内存数据
    std::cout << "C函数接收到数据，首地址: " << ptr << std::endl;
}

int main() {
    // =====================================================
    // 场景 A：频繁随机访问 + 尾部添加
    // =====================================================
    {
        std::vector<int> vec;
        // 尾部添加
        for (int i = 0; i < 100; ++i) {
            vec.push_back(i);
        }
        // 频繁随机访问
        int sum = vec[50] + vec[10]; // 直接下标访问，速度极快
        std::cout << "场景A(vector) 随机访问结果: " << sum << std::endl;
    }

    // =====================================================
    // 场景 B：频繁头尾操作 + 随机访问
    // =====================================================
    {
        std::deque<int> deq;
        // 头尾混合操作
        deq.push_back(10);   // 尾部加
        deq.push_front(1);   // 头部加 (vector做这个很慢)
        deq.push_back(20);
        deq.push_front(0);
        
        // 随机访问中间元素 (deque支持，虽然比vector慢一点)
        std::cout << "场景B(deque) 中间元素: " << deq[2] << std::endl; 
        
        deq.pop_front(); // 头部删
        deq.pop_back();  // 尾部删
    }

    // =====================================================
    // 场景 C：C 函数接口 (必须用连续内存)
    // =====================================================
    {
        std::vector<int> vec = {1, 2, 3, 4, 5};
        // 获取连续内存指针，传递给 C 函数
        cStyleFunction(vec.data(), vec.size()); 
        // std::deque 无法提供这样的指针，这里无法用 deque 替代
    }

    // =====================================================
    // 场景 D：高成本对象，动态增长
    // =====================================================
    {
        std::deque<LargeObject> deq;
        // 动态添加大量对象
        for (int i = 0; i < 1000; ++i) {
            deq.push_back(LargeObject(i));
            // deque 扩容时不会移动已有的 LargeObject
            // 如果是 vector，扩容时会触发大量 LargeObject 的拷贝/移动构造
        }
        std::cout << "场景D(deque) 存储大型对象数量: " << deq.size() << std::endl;
    }

    return 0;
}
