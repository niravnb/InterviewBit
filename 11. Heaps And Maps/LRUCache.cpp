/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least recently used item before inserting the new item.
The LRUCache will be initialized with an integer corresponding to its capacity. Capacity indicates the maximum number of unique keys it can hold at a time.

Definition of “least recently used” : An access to an item is defined as a get or a set operation of the item. “Least recently used” item is the one with the oldest access time.

 NOTE: If you are using any global variables, make sure to clear them in the constructor. 
Example :

Input : 
         capacity = 2
         set(1, 10)
         set(5, 12)
         get(5)        returns 12
         get(1)        returns 10
         get(10)       returns -1
         set(6, 14)    this pushes out key = 5 as LRU is full. 
         get(5)        returns -1 

LINK: https://www.interviewbit.com/problems/lru-cache/
*/
#include <list>
unordered_map<int, list<pair<int,int>>::iterator > m;
list<pair<int,int>> lst;
int cap;

LRUCache::LRUCache(int capacity) {
    m.clear();
    lst.clear();
    cap = capacity;
}

int LRUCache::get(int key) {
    if(m.find(key)!=m.end()){
        int val = m[key]->second;
        lst.erase(m[key]);
        lst.push_front(make_pair(key,val));
        m[key] = lst.begin();
        return val;
    }else return -1;

}

void LRUCache::set(int key, int value) {
    
    if(m.find(key)!=m.end()){
        lst.erase(m[key]);
        lst.push_front(make_pair(key,value));
        m[key] = lst.begin();
    }else{
        if(lst.size()==cap){
            int lastKey = lst.back().first;
            m.erase(lastKey);
            lst.pop_back();
        }
        lst.push_front(make_pair(key,value));
        m[key] = lst.begin();
    }
    
    
}
