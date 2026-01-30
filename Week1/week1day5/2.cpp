#include<iostream>
#include<deque>
using namespace std;
int main(){
	deque<int> b;
	b.push_back(10);
	b.push_back(20);
	b.push_back(30);
	cout<<"尾部添加后：";
	for(int i:b){
		cout<<i<<' ';
	}
	cout<<endl;

	b.push_front(5);
	b.push_front(3);
	b.push_front(1);
	cout<<"头部添加后：";
        for(int i:b){
                cout<<i<<' ';
        }
        cout<<endl;

	b.pop_front();
	cout<<"删除头部后，新头部：";
        cout<<b.front();
        cout<<endl;

	b.pop_back();
        cout<<"删除尾部后，新尾部：";
        cout<<b.back();
        cout<<endl;

	cout<<"当前deque：";
	for(int i:b){
                cout<<i<<' ';
        }
        cout<<endl;

	cout<<b[2]<<endl;
	b.at(4);
}
