#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> VecInt;
    for(int i=0;i<=10;i++)
        VecInt.push_back(i);
    VecInt.pop_back();
    for (int i=0;i<VecInt.size();i++)
        cout<<VecInt[i]<<endl;
}