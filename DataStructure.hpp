#ifndef __DataStructure_hpp__
#define __DataStructure_hpp__
#include<iostream>
#include<vector>
#include<map>
using namespace std;


template <class T>
class Queue : public vector<T>
{
  public:
    void enqueue(T ob)
    {
        vector<T>::push_back(ob);
    }
    void dequeue(unsigned int num)
    {
        if (num < vector<T>::size())
        {
            for (int i = 0; i < num; i++)
                vector<T>::erase(vector<T>::begin());
        }
    }

    void pop_back(unsigned int num)
    {
        if(num < vector<T>::size()){
            for(int i = 0;i<num;i++){
                vector<T>::pop_back();
            }
        }
    }

    T dequeue()
    {
        T re;
        re = *(vector<T>::begin());
        vector<T>::erase(vector<T>::begin());
        return (re);
    }

};

template <class T1, class T2>
class Map : public map<T1, T2>
{
public:
    // Map<T1,T2> operator +=(Map<T1,T2> &data);
};

// template <class T1, class T2>
// Map<T1,T2> Map<T1,T2>::operator +=(Map<T1,T2> &data){
    
// }

#endif