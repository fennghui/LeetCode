#include <iostream>
#include "Solutions/Solution0045.h"

int main() {
//    vector<vector<int>> board{vector<int>{1,0}};
    Solution solution;
    vector<vector<char>> vec1{{'A', 'B', 'C', 'E'},
                              {'S', 'F', 'C', 'S'},
                              {'A', 'D', 'E', 'E'}};
    vector<int> vec2{1,2,3};
    auto result = solution.jump(vec2);
    cout << result <<endl;
//    for (int i = 0; i < result.size(); ++i){
//        for(int j = 0; j < result[i].size(); ++j)
//            cout << result[i][j] << ", ";
//        cout<<endl;
//    }




    return 0;
}
