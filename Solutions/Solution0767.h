//
// Created by hpf on 22-6-10.
//

#ifndef FH_A01_SOLUTION0767_H
#define FH_A01_SOLUTION0767_H

#include "../Common.h"

//767. 重构字符串 mid
//给定一个字符串 s ，检查是否能重新排布其中的字母，使得两相邻的字符不同。
//
//返回 s 的任意可能的重新排列。若不可行，返回空字符串 "" 。
//输入: s = "aab"
//输出: "aba"

/**
 * 贪心算法：
 *
 * 统计字符串中每个字符出现的次数，如果次数最多的字符的出现频率大于(s.size() + 1) / 2，那一定不存在
 * 使用大顶堆每次统计剩余字符的频率，每次从中取两个放入结果字符串中
 *
 * 1. 学会使用大顶堆，元素为pair，自己写比较器
 * 2. 熟练使用 unordered_map统计字符出现次数
 */
class Solution {
public:
    // 按照pair的第二个元素进行排序，大的放在前面
    struct cmp {
        inline bool operator()(const pair<char, int> &a, const pair<char, int> &b) {
            if (a.second < b.second)
                return true;
            return false;
        }
    };

    string reorganizeString(string s) {
        if (s.length() < 2) {
            return s;
        }
        string result = "";
        unordered_map<char, int> letterNumMap;
        for (const auto &letter: s) {
            ++letterNumMap[letter];
        }
        // 使用map完成初始化
        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp>
                letterHeap(letterNumMap.begin(), letterNumMap.end());
        // 优化，提前判断是否可以成功
        if (letterHeap.top().second > (s.size() + 1) / 2)
            return "";
        while (letterHeap.size() >= 2) {
            // 每次取两个字符
            auto letterA = letterHeap.top();
            letterHeap.pop();
            auto letterB = letterHeap.top();
            letterHeap.pop();
            result += letterA.first;
            result += letterB.first;

            // 再插入进去
            if (--letterA.second != 0)
                letterHeap.push(letterA);
            if (--letterB.second != 0)
                letterHeap.push(letterB);
        }
        //判断字符被剩下的这一个
        if (!letterHeap.empty()) {
            auto letter = letterHeap.top();
            result += letter.first;
        }
        return result;
    }
};


#endif //FH_A01_SOLUTION0767_H
