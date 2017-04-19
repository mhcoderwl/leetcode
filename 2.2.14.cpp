/*LRU Cache 
 * 实现细节:使用hash表和双向链表.*/
#include<iostream>
#include<unordered_map>
#include<iterator>
#include<list>
using namespace std;
class LRUCache{
	struct CacheNode{
		int key;
		int value;
		CacheNode(int k,int v):key(k),value(v){}
	};
	int capacity;
	unordered_map<int,list<CacheNode>::iterator> CacheMap;
	list<CacheNode> cacheList;
public:
	LRUCache(int Capacity){
		this->capacity=Capacity;
	}
	int get(int key){
		if(this->CacheMap.find(key)==CacheMap.end())return -1;
		//把当前访问的节点移到链表头部,并且更新map中该节点的地址.
		cacheList.splice(cacheList.begin(),cacheList,CacheMap[key]);
		CacheMap[key]=cacheList.begin();
		return CacheMap[key]->value;

	}
	void sey(int key,int value){
		if(this->CacheMap.find(key)==CacheMap.end()){
			if(cacheList.size()==capacity){//删除链表尾部节点(最少访问的节点)
				CacheMap.erase(cacheList.back().key);
				cacheList.pop_back();
			}
				cacheList.push_front(CacheNode(key,value));
				CacheMap[key]=cacheList.begin();
			}else{
				//更新节点的值,把当前访问的节点移到链表头部,并且更新map中该节点的地址.
				CacheMap[key]->value=value;
				cacheList.splice(cacheList.begin(),cacheList,CacheMap[key]);
				CacheMap[key]=cacheList.begin();
			}
		}
};

int main(){}


				

				



	
