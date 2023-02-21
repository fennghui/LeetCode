#include <iostream>
#include "2nd/593. 有效的正方形.h"

int main() {


    Solution solution;
    vector<int> vec2{4, 1, 2, 7, 5, 3, 1};
    vector<string> vecStr{"leet", "code"};
    string num1("123");
    string num2("456");
    vector<vector<int>> vec3{{1, 2, 3},
                             {4, 5, 6},
                             {7, 8, 9}};

    vector<int> p1{0, 0};
    vector<int> p2{1, 1};
    vector<int> p3{1, 0};
    vector<int> p4{0, 1};
    auto result = solution.validSquare(p1,p2,p3,p4);
    cout << result << endl;

//    for (int i = 0; i < result.size(); ++i){
//        cout<<result[i]<<endl;
//    }

//    for (int i = 0; i < result.size(); ++i){
//        for(int j=0;j<result[i].size();j++){
//            cout<<result[i][j]<<" ";
//        }
//        cout<<endl;
//    }


    return 0;
}
