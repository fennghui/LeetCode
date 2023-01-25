#include <iostream>
#include "2nd/93. 复原 IP 地址.h"

int main() {


    Solution solution;
    vector<int> vec2{1000000000,1000000000,1000000000,1000000000,-1000000000,-1000000000,-1000000000,-1000000000};
    vector<string> vecStr{"leet","code"};
    auto result = solution.restoreIpAddresses("25525511135");
//    cout<<result<<endl;

    for (int i = 0; i < result.size(); ++i){
        cout<<result[i]<<endl;
    }

//    for (int i = 0; i < result.size(); ++i){
//        for(int j=0;j<result[i].size();j++){
//            cout<<result[i][j]<<" ";
//        }
//        cout<<endl;
//    }


    return 0;
}
