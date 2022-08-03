#include <iostream>
#include "Solutions/Solution0491.h"

int main() {
//    vector<vector<int>> board{vector<int>{1,0}};
    Solution solution;
    vector<vector<char>> vec1{{'A', 'B', 'C', 'E'},
                              {'S', 'F', 'C', 'S'},
                              {'A', 'D', 'E', 'E'}};
    vector<int> vec2{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 1, 1, 1, 1};
    auto result = solution.findSubsequences(vec2);
    for (int i = 0; i < result.size(); ++i){
        for(int j = 0; j < result[i].size(); ++j)
            cout << result[i][j] << ", ";
        cout<<endl;
    }




    return 0;
}
