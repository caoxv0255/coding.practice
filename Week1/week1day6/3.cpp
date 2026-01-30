#include<iostream>
#include<list>
#include<unordered_map>
#include<string>

class LRUCache{
	private:
		std::list<std::pair<int,std::string> > cacheList;
		std::unordered_map<int,std::list<std::pair<int,std::string> >::iterator>cacheMap;
		int capacity;
	public:
		LRUCache(int cap):capacity(cap){
			if(cap<0){
				cap=0;
			}
			capacity=cap;
		}
		std::string get(int key);
		void put(int key,const std::string &value);
		void printCache();
};

std::string LRUCache::get(int key){
	if(capacity==0){
                return "";
        }
	auto maplt = cacheMap.find(key);
	if(maplt == cacheMap.end()){
		return "";
	}
	auto listlt = maplt->second;
	cacheList.splice(cacheList.begin(),cacheList,listlt);
	return listlt->second;
}

void LRUCache::put(int key,const std::string &value){
	//容量为0
	if(capacity==0){
                return;
        }
	//key存在
	auto maplt = cacheMap.find(key);
        if(maplt != cacheMap.end()){
		maplt->second->second=value;
		cacheList.splice(cacheList.begin(),cacheList,maplt->second);
	return;
	}
	//key不存在
	//容量满
	if(cacheList.size()>=capacity){
		auto last = cacheList.back();
		int lastkey = last.first;
		cacheList.pop_back();
		cacheMap.erase(lastkey);
	}
	//插入头部
	cacheList.emplace_front(key,value);
	cacheMap[key]=cacheList.begin();
	
}

void LRUCache::printCache(){
	std::cout<<"[";
	for(auto it = cacheList.begin();it!=cacheList.end();it++){
		std::cout<<it->first<<":"<<it->second;
		if(std::next(it)!=cacheList.end()){
			std::cout<<",";
		}
	}
	std::cout<<"]"<<std::endl;
}

		 
int main() {
    std::cout << "创建LRU缓存（容量=3）" << std::endl;
    LRUCache lru(3); // 创建容量为3的缓存

    // --- 步骤1: put(1,"A") ---
    std::cout << "put(1,\"A\") -> ";
    lru.put(1, "A");
    std::cout << "缓存: ";
    lru.printCache();

    // --- 步骤2: put(2,"B") ---
    std::cout << "put(2,\"B\") -> ";
    lru.put(2, "B");
    std::cout << "缓存: ";
    lru.printCache();

    // --- 步骤3: put(3,"C") ---
    std::cout << "put(3,\"C\") -> ";
    lru.put(3, "C");
    std::cout << "缓存: ";
    lru.printCache();

    // --- 步骤4: get(1) ---
    std::cout << "get(1) -> ";
    std::string result = lru.get(1);
    if (result != "") {
        std::cout << "返回\"" << result << "\"，";
    } else {
        std::cout << "键不存在，";
    }
    std::cout << "缓存: ";
    lru.printCache();

    // --- 步骤5: put(4,"D") ---
    std::cout << "put(4,\"D\") -> ";
    lru.put(4, "D");
    std::cout << "缓存: ";
    lru.printCache();

    return 0;
}
