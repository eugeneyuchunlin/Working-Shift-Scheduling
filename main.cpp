#include<iostream>
#include<vector>
#include<sched.h>
#include<sys/types.h>
#include<unistd.h>
using namespace std;
int main(){
    pthread_t tid;
    pid_t pid,dead;
    pid=fork();
    
}