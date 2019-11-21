#include "./chunck.cpp"

#include <iostream>
#include "stringlib.h"
using namespace std;

int main(){
	chunck<int> a(9);
	chunck<int> b(8);
	chunck<int> c(7);
	cout<<a<<b<<c<<endl;
	//cout<<a<<endl;

	//cout<<c<<endl;
}
