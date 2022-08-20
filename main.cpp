#include <iostream>
#include "Solutions/Solution0416.h"

int main() {


    Solution solution;
    vector<int> vec2{1,5,11,5};
    auto result = solution.canPartition(vec2);
    cout<<result<<endl;

//    for (int i = 0; i < result.size(); ++i){
//        cout<<result[i]<<endl;
//    }


    return 0;
}
