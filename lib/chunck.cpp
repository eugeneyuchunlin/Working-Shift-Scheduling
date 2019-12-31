#include "./chunck.h"
#include "def.h"
#include "outputer_parameter.h"
#include <ostream>
#include <string>



template<class T>
chunck<T>::chunck(void):content(),data(){
}

template<class T>
chunck<T>::chunck(T d): data(){
	content = d;
	setUpData();
}

template<class T>
void chunck<T>::setData(T d){
	content = d;
	setUpData();
}

template<class T>
void chunck<T>::setUpData(){
	using namespace std;
	data = to_string(content);
}

template<class T>
std::string chunck<T>::Data(){
	using namespace par;
	using namespace std;
	int fist_space = (CHUNK_SIZE - 	data.length()) / 2;
	string s = SPACE * fist_space;
	s += data;
	s += SPACE * (CHUNK_SIZE - s.length());
	return s;
}

template<class T>
std::ostream & operator<<(std::ostream & out, chunck<T> c){
	return out<<c.Data();
}


//template class chunck<int>;


//int main(){
//	using namespace std;
//	chunck<int> a(5);
//	cout<<a<<endl;
//}
