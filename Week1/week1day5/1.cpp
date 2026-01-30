#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int>a;
	for(int i=0;i<10;i++){
		a.push_back(i+1);
		cout<<"size:"<<a.size()<<endl<<"capacity:"<<a.capacity()<<endl<<endl;
	}
	cout<<a[2]<<endl;
	a.pop_back();
	cout<<a.size()<<endl;
	a.clear();
	cout<<a.empty()<<endl;
	return 0;
}
	
