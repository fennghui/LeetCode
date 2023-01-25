#include <iostream>
#include "2nd/18. 四数之和.h"

int main() {


    Solution solution;
    vector<int> vec2{1000000000,1000000000,1000000000,1000000000,-1000000000,-1000000000,-1000000000,-1000000000};
    vector<string> vecStr{"leet","code"};
    auto result = solution.fourSum(vec2, 0);
//    cout<<result<<endl;

//    for (int i = 0; i < result.size(); ++i){
//        cout<<result[i]<<endl;
//    }

    for (int i = 0; i < result.size(); ++i){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}
