#include <iostream>
#include "2nd/16. 最接近的三数之和.h"

int main() {


    Solution solution;
    vector<int> vec2{2,3,8,9,10};
    vector<string> vecStr{"leet","code"};
    auto result = solution.threeSumClosest(vec2, 16);
    cout<<result<<endl;

//    for (int i = 0; i < result.size(); ++i){
//        cout<<result[i]<<endl;
//    }


    return 0;
}
