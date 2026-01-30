#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <chrono>

void test_middle_insert() {
    const int N = 10000;
    
    // vector 中间插入
    std::vector<int> vec(N/2, 0);
    auto start = std::chrono::high_resolution_clock::now();
    vec.insert(vec.begin() + N/4, 999);  // 在1/4位置插入
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "vector middle insert: " 
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() 
              << " μs\n";
    
    // list 中间插入（已知位置）
    std::list<int> lst(N/2, 0);
    auto it = lst.begin();
    std::advance(it, N/4);  // 定位到1/4位置
    start = std::chrono::high_resolution_clock::now();
    lst.insert(it, 999);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "list middle insert (known position): " 
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() 
              << " μs\n";
    
    // list 中间插入（需要查找位置）
    std::list<int> lst2(N/2, 0);
    start = std::chrono::high_resolution_clock::now();
    auto it2 = lst2.begin();
    std::advance(it2, N/4);  // 定位操作本身就是O(n)
    lst2.insert(it2, 999);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "list middle insert (find + insert): " 
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() 
              << " μs\n";
}

int main() {
    test_middle_insert();
    return 0;
}
