#include <iostream>
#include "Solutions/Solution0763.h"

class A {
public:
    int a;

    A() {
        a = 0;
        cout << "无参构造函数" << endl;
    }

    explicit A(int b) {
        a = b;
        cout << "有参构造函数" << endl;
    }

//    A(const A &b) {
//        a = b.a;
//        cout << "复制构造函数" << endl;
//    }
};

int main() {
    vector<A> test(3, A(1));
    for(int i = 0; i < test.size(); ++i){
        cout<<test[i].a <<endl;
    }





//    Solution solution;
//    vector<int> vec2{1, 2, 3};
//    string s = "ababcbacadefegdehijhklij";
//    auto result = solution.partitionLabels(s);
//    for (int i = 0; i < result.size(); ++i){
//        cout<<result[i]<<endl;
//    }


    return 0;
}
