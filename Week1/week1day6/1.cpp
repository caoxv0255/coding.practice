#include<iostream>
#include<list>
int main(){
	std::list<int>list1={1,3,5,7};
	std::cout<<"初始list1: ";
	for(int i:list1){std::cout<<i<<' ';}
	std::cout<<std::endl;

	std::list<int>list2={2,4,6,8};
	std::cout<<"初始list2: ";
        for(int i:list2){std::cout<<i<<' ';}
	std::cout<<std::endl;
	
	auto it = list2.begin();
	list1.splice(list1.end(),list2,list2.begin(),++it);
	std::cout<<"移动list2第一个元素后 list1: ";
	for(int i:list1){std::cout<<i<<' ';}
	std::cout<<std::endl;
	
	std::cout<<"移动list2剩余元素后 list1: ";
	list1.splice(list1.begin(),list2,it,list2.end());
	for(int i:list1){std::cout<<i<<' ';}
        std::cout<<std::endl;

	std::cout<<"排序后 list1: ";
	list1.sort();
	for(int i:list1){std::cout<<i<<' ';}
        std::cout<<std::endl;
	
	std::cout<<"添加重复值后 list1: ";
	auto it1 = list1.begin();
	list1.insert(it1,1);
	for(int i:list1){std::cout<<i<<' ';}
        std::cout<<std::endl;

	std::cout<<"unique()后 list1: ";
	list1.unique();
	for(int i:list1){std::cout<<i<<' ';}
        std::cout<<std::endl;

	std::cout<<"list3: ";
	std::list<int>list3 = {0,10,20};
	for(int i:list3){std::cout<<i<<' ';}
        std::cout<<std::endl;

	std::cout<<"merge()后: ";
	list1.merge(list3);
	for(int i:list1){std::cout<<i<<' ';}
        std::cout<<std::endl;

	return 0;

}

