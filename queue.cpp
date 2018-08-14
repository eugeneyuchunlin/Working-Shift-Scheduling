#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;


template<class T>//這是樣板，可以讓Queue這個資料結構存不一樣型態的資料
class Queue:public vector<T>{//繼承vector來擴充vector的功能，Queue裡所有的功能都是用vector原有的功能再去加新的功能
public:
    void push(T ob){
        vector<T>::push_back(ob);
    }
    void pop(unsigned int num){
        if (num< vector<T>::size()){
            for(int i=0;i<num;i++)
                vector<T>::erase(vector<T>::begin());
        }
    }
    T pop(){
        T re;
        re=*(vector<T>::begin());
        vector<T>::erase(vector<T>::begin());
        return(re);
    }
    bool isEmpty(){
        return vector<T>::empty();
    }
};

int main(){
    Queue<int>queque;//可以把它想像是一個陣列，記憶體大小無限,使用方式為Queue<型態> 變數名稱;型態可以是int float double任意一種，也可以是自定義的其他形態
    int value=0;
    int i=0,n=0;
    char c;
    printf("請輸入需要的資料數目:\n");
    scanf("%d%c",&n,&c);
    printf("請依序輸入%d比資料:\n",n);
    for(i=0; i<n; i++){
        scanf("%d%c",&value,&c);
        queque.push(value);//這裡做push的動作
    }
    printf("====================\n");
    printf("觀察前端數值為%d\n",queque[0]); 
    while(!queque.isEmpty()){
        printf("佇列彈出的依序為:%d\n",queque.pop());
    }
    return 0;
}