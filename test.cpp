#include<iostream>
#include<initializer_list>
using namespace std;

template<class T>
T sum(std::initializer_list<T> il){
	T data(0);
	for(T i:il){
		data += i;
	}
	return data;
}

int main(){
	cout<<sum({1,2,3,4,5,6,7,8,9,10})<<endl;
}