// Define All of the Data Structure's prototype


#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <memory>

using namespace std;

#ifndef __DS_HPP__
#define __DS_HPP__



namespace DS
{
    template<class T>
    class deque : public vector<T>{
    public:
        void push_front(const T & object);
        void push_back(const T & object);
        T operator=(T & obj);
        T pop_back();
        T pop_front();
    };

    template<class T1, class T2>
    class Map : public map<T1, T2>{

    };

    class String : public string{
    public:

        //Constructor overloading
        String(const char chr);
        String(int i);
        String();
        String(const char * str);
        String(string &);
        String(size_t n, char c);
        String(const string & str, size_t pos, size_t len);

        // Copy Constructor
        String(const String & ns);

        // operator= overloading
        String operator=(const char * s);
        String operator=(const string& str);
        String operator=(const char);
        // String operator=(const String& str);

        // operator== overloading
        int operator==(const char * s);
        int operator==(const string & str);
        int operator==(const String& str);
        int operator==(const char);

        string sData();
        deque<String> split(const char * sub); 

    };

    typedef String str;

    String to_String(int i){
        String s = i;
        return s;
    }

    
} // DS


#endif