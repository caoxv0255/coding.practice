#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <chrono>

void test_push_front() {
    const int N = 100000;
    
    // vector 头部插入（极慢）
    std::vector<int> vec;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) vec.insert(vec.begin(), i);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "vector push_front: " 
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() 
              << " ms\n";
    
    // deque 头部插入（高效）
    std::deque<int> dq;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) dq.push_front(i);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "deque push_front: " 
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() 
              << " ms\n";
    
    // list 头部插入（高效）
    std::list<int> lst;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) lst.push_front(i);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "list push_front: " 
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() 
              << " ms\n";
}

int main() {
    test_push_front();
    return 0;
}
