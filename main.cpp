#include <iostream>
#include "2nd/11. 盛最多水的容器.h"

int main() {


    Solution solution;
    vector<int> vec2{1,3,2,5,25,24,5};
    vector<string> vecStr{"leet","code"};
    auto result = solution.maxArea(vec2);
    cout<<result<<endl;

//    for (int i = 0; i < result.size(); ++i){
//        cout<<result[i]<<endl;
//    }


    return 0;
}
