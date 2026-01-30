#include<vector>
#include<deque>
#include<chrono>
#include<iostream>
int main(){
	std::vector<int>v;
	std::deque<int>d;
        auto start_v = std::chrono::high_resolution_clock::now();
        for(int i =0;i<10000;i++){
		v.insert(v.begin(),i);
        }
        auto end_v = std::chrono::high_resolution_clock::now();
        auto duration_v = std::chrono::duration_cast<std::chrono::microseconds>(end_v-start_v);
	std::cout<<"vector 耗时："<<duration_v.count()<<" 微秒"<<std::endl;

        auto start_d = std::chrono::high_resolution_clock::now();
        for(int i =0;i<10000;i++){
		d.push_front(i);
        }
        auto end_d = std::chrono::high_resolution_clock::now();
        auto duration_d = std::chrono::duration_cast<std::chrono::microseconds>(end_d-start_d);
	std::cout<<"deque 耗时："<<duration_d.count()<<" 微秒"<<std::endl;

	std::cout<<"性能差异："<<duration_v.count() / duration_d.count()<<"倍"<<std::endl;
        return 0;
}
