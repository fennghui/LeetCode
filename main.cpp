#include <iostream>
#include "Solutions/Solution0763.h"

int main() {
//    vector<vector<int>> board{vector<int>{1,0}};
    Solution solution;
    vector<vector<char>> vec1{{'A', 'B', 'C', 'E'},
                              {'S', 'F', 'C', 'S'},
                              {'A', 'D', 'E', 'E'}};
    vector<int> vec2{1, 2, 3};
    string s = "ababcbacadefegdehijhklij";
    auto result = solution.partitionLabels(s);
//    cout << result << endl;
    for (int i = 0; i < result.size(); ++i){
        cout<<result[i]<<endl;
    }




    return 0;
}
