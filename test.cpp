//
// Created by hpf on 22-6-1.
//

#include <iostream>
#include <set>

using namespace std;

int main ()
{
    set<int> myset;
    set<int>::iterator it;

    myset = {10, 20, 30, 40};

    cout<<"删除元素之前: \n";
    for (it=myset.begin(); it!=myset.end(); ++it){
        cout << *it<< '\n';
    }

    cout <<"删除" <<myset.erase (40) << endl;//删除指定值

    cout<<"\n删除元素之后: \n";
    for (it=myset.begin(); it!=myset.end(); ++it){
        cout << *it<< '\n';
    }

    return 0;
}