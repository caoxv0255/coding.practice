#include<iostream>
#include<list>
#include<deque>
#include<chrono>
#include<random>
#include<cstdlib>
#include<vector>
int main(){
	const int N = 10000;//插入元素个数
	//预生成随机数据
	std::vector<int>data(N);
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int>dis(1,100000);
	for(int i=0;i<N;i++){
		data[i]=dis(gen);
	}

	
        std::deque<int>dq;
        std::list<int>lst;
	{//中间插入
	std::cout<<"中间插入10000个元素："<<std::endl;
        //插入deque
	auto start_d = std::chrono::high_resolution_clock::now();
        for(int i=0;i<N;i++){
		auto it = dq.begin() + dq.size()/2;
                dq.insert(it,data[i]);
        }
        auto end_d = std::chrono::high_resolution_clock::now();
        auto duration_d = std::chrono::duration_cast<std::chrono::microseconds>(end_d - start_d);
        std::cout<<"deque用时: "<<duration_d.count()<<" μs"<<std::endl;

        //插入list
        auto start_l = std::chrono::high_resolution_clock::now();
        for(int i=0;i<N;i++){
		auto it = lst.begin();
		std::advance(it,lst.size()/2);
                lst.insert(it,data[i]);
        }
        auto end_l = std::chrono::high_resolution_clock::now();
        auto duration_l = std::chrono::duration_cast<std::chrono::microseconds>(end_l - start_l);
        std::cout<<"list用时: "<<duration_l.count()<<" μs"<<std::endl;
	}

	{//头部插入
	std::cout<<"头部插入10000个元素："<<std::endl;
	//插入deque                                                 
	auto start_d = std::chrono::high_resolution_clock::now();
        for(int i=0;i<N;i++){
                dq.insert(dq.begin(),data[i]);
        }
        auto end_d = std::chrono::high_resolution_clock::now
();
        auto duration_d = std::chrono::duration_cast<std::chrono::microseconds>(end_d - start_d);
        std::cout<<"deque用时: "<<duration_d.count()<<" μs"<<std::endl;
        //插入list
        auto start_l = std::chrono::high_resolution_clock::now();
        for(int i=0;i<N;i++){
                lst.insert(lst.begin(),data[i]);
        }
        auto end_l = std::chrono::high_resolution_clock::now
();
        auto duration_l = std::chrono::duration_cast<std::chrono::microseconds>(end_l - start_l);
        std::cout<<"list用时: "<<duration_l.count()<<" μs"<<std::endl;
	}

	{//尾部插入
	std::cout<<"尾部插入10000个元素："<<std::endl;
	//插入deque
	auto start_d = std::chrono::high_resolution_clock::now();
        for(int i=0;i<N;i++){
                dq.insert(dq.end(),data[i]);
        }
        auto end_d = std::chrono::high_resolution_clock::now
();
        auto duration_d = std::chrono::duration_cast<std::chrono::microseconds>(end_d - start_d);
        std::cout<<"deque用时: "<<duration_d.count()<<" μs"<<std::endl;
        //插入list
        auto start_l = std::chrono::high_resolution_clock::now();
        for(int i=0;i<N;i++){
                lst.insert(lst.end(),data[i]);
        }
        auto end_l = std::chrono::high_resolution_clock::now
();
        auto duration_l = std::chrono::duration_cast<std::chrono::microseconds>(end_l - start_l);
        std::cout<<"list用时: "<<duration_l.count()<<" μs"<<std::endl;
	}
	return 0;
}
