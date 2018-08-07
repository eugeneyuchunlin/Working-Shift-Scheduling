#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<map>
using namespace std;

template<class T>
class Queue:public vector<T>{
public:
    void enqueue(T ob){
        vector<T>::push_back(ob);
    }
    void dequeue(unsigned int num){
        for(int i=0;i<num;i++)
            vector<T>::erase(vector<T>::begin());
    }
    T dequeue(){
        T re;
        re=*(vector<T>::begin());
        vector<T>::erase(vector<T>::begin());
        return(re);
    }
};
void ReWrite(const char* File_name,Queue<string> date,Queue<string>day){
    ofstream file(File_name);
    if(file.is_open()){
        for(unsigned int i=0;i<date.size();++i){
            file<<date[i]<<" "<<day[i]<<'\n';
        }
    }else{
        printf("%s cannot be writen\n",File_name);
    }
}
Queue<Queue<string> > FileProcess(const char *File_name){
    ifstream file(File_name);
    string linestr;
    string spread;
    Queue<string> linedata;
    Queue<Queue<string> > data;
    char str[100];
    char *pch;
    int i=0;
    if(file.is_open()){
        while(!file.eof()){
            getline(file,linestr,'\n');
            strcpy(str,linestr.c_str());
            pch=strtok(str,",");
            while(pch!=NULL){
                spread.assign(pch);
                linedata.enqueue(spread);
                pch=strtok(NULL,",");
            }
            data.enqueue(linedata);
            linedata.clear();
        }
    }
    return data;
}
int main(){
    Queue<Queue<string> > test;
    test=FileProcess("specialholiday.csv");
    for(unsigned int i=0;i<test.size();i++){
        for(unsigned int j=0;j<test[i].size();j++){
            cout<<test[i][j];
        }
        cout<<endl;
    }
}