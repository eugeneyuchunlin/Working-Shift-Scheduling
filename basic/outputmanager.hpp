#ifndef __output_manager_hpp__
#define __output_manager_hpp__
#include<iostream>
#include <initializer_list>
using namespace std;
#include"DataStructure.hpp"
#include"basicmenber.hpp"

class outputPackage{
private:
    string Name;
    Queue<Map<int,cDay>::iterator>::iterator Data;
public:
    outputPackage(string name,Queue<Map<int,cDay>::iterator>::iterator data);
};

outputPackage::outputPackage(string name,Queue<Map<int,cDay>::iterator>::iterator data){
    Name = name;
    Data = data;
}



class cOutputManager{

private:
    Queue<outputPackage> OutputData;
public:
	void Output(int count, ... ); 
};

void cOutputManager::Output(int count,...){
    va_list pa;
    int i,cnt;
    
}
#endif
