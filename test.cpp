// #include<iostream>
// using namespace std;

// class point{
// public:
//     int a;
//     void f(int b){
//         cout<<"In f The Value of b is  "<<b<<endl;
//     }
//     void f2(int b){
//         cout<<"In f2 the Value of b is "<<b<<endl;
//     }
//     void (point::*p)(int);
//     void ((point::*ar[10]))(int);
//     point(){
//         p = &point::f;
//         ar[0] = &point::f;
//         ar[1] = &point::f2;
//     }

// };

// int main(){
//     // int point::*p;
//     point pp;
//     (pp.*(pp.p))(10);
//     for(int i = 0;i<2;i++){
//         pp.*(pp.ar[i])(i);
//     }
//     return 0;
// }

#include<stdio.h>

int main(){
    // int pf = 0;
    // pf = printf("H\n");
    // printf("pf = %d\n",pf);
    return 100;
}