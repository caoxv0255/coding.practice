#include<iostream>
#include<deque>
#include<vector>

std::vector<int> maxSlidingWindow(std::vector<int>&nums,int k){
	if(nums.empty()||k<0||k>nums.size()){
		return {};
	}
	std::deque<int>dq;
	std::vector<int>result;
	for(int i=0;i<nums.size();i++){
		while(!dq.empty()&&nums[dq.back()]<=nums[i]){
			dq.pop_back();
		}
		dq.push_back(i);
		if(dq.front()<=i-k){
			dq.pop_front();
		}
		if(i>=k-1){
			result.push_back(nums[dq.front()]);
		}
	}
	return result;
}
int main(){
	std::vector<int>nums = {1,3,-1,-3,5,3,6,7};
	int k = 3;
	std::cout<<"输入: nums = [";
	for(auto it = nums.begin();it!=nums.end();it++){
		std::cout<<*it;
		if(std::next(it)!=nums.end()){
			std::cout<<",";
		}
	}
	std::cout<<"],k = "<<k<<std::endl;
	std::vector<int>result=maxSlidingWindow(nums,k);
	std::cout<<"输出: ";
        for(auto it = result.begin();it!=result.end();it++){
                std::cout<<*it;
                if(std::next(it)!=result.end()){
                        std::cout<<",";
                }
        }
	std::cout<<std::endl;
	return 0;
}

