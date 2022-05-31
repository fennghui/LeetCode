//
// Created by hpf on 22-5-30.
//

#ifndef FH_A01_SOLUTION0146_H
#define FH_A01_SOLUTION0146_H

#include "../Common.h"

/**
 * 数据结构 ：哈希链表, java中是LinkedHashMap, 哈希表 + 双向链表
 * 哈希表 : 用来快速找到数据
 * 双向链表 ： 用来保证数据插入的时序
 */

class LRUCache {
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> uMap;
    list<pair<int, int>> myList;
public:
    LRUCache(int capacity) : capacity(capacity) {
    }

    bool isFull() {
        return this->myList.size() == this->capacity;
    }

    int get(int key) {
        auto iter = this->uMap.find(key);
        if (iter != this->uMap.end()) {
            // 更换位置
            this->myList.splice(this->myList.begin(), this->myList, iter->second);
            return iter->second->second;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        auto iter = this->uMap.find(key);
        if (iter != this->uMap.end()) {
            // key已存在，变更其数据值，再移位
            iter->second->second = value;
            this->myList.splice(this->myList.begin(), this->myList, iter->second);
        } else {
            // key未存在
            if(isFull()) {
                // 逐出
                int key_temp = this->myList.back().first;
                this->myList.pop_back();
                this->uMap.erase(this->uMap.find(key_temp));
            }
            this->myList.push_front(make_pair(key,value));
            this->uMap[key] = this->myList.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#endif //FH_A01_SOLUTION0146_H
