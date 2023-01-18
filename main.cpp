#include <iostream>
#include "2nd/3. 无重复字符的最长子串.h"

int main() {


    Solution solution;
    vector<int> vec2{1,5,11,5};
    vector<string> vecStr{"leet","code"};
    auto result = solution.lengthOfLongestSubstring("abba");
    cout<<result<<endl;

//    for (int i = 0; i < result.size(); ++i){
//        cout<<result[i]<<endl;
//    }


    return 0;
}
