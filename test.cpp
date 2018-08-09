#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
    vector<int>vint;
    map<int,int*>mintintp;
    for(int i=0;i<10;i++){
        vint.push_back(i);
        mintintp[i]=&vint[i];
        cout<<*mintintp[i]<<endl;
    }
    cout<<"=================="<<endl;
    /*
    for(map<int,int*>::iterator mit=mintintp.begin();mit!=mintintp.end();mit++){
        cout<<"{"<<mit->first<<","<<*mit->second<<"}"<<endl;
    }
    */
   cout<<*mintintp[3]<<endl;
}