#include <random>
#include <vector>
#include <iostream>
#include <exception>

using namespace std;

int main(int argc,char const * argv[] ){
	int dimension = atoi(argv[1]);	int times = atoi(argv[2]);
	srand(time(NULL));
	default_random_engine generator(rand());
	uniform_int_distribution<int> distZ(0, dimension - 1);
	uniform_int_distribution<int> distW(0, dimension - 1);

	vector<vector<int> >result;
	vector<int> temp;
	temp.reserve(dimension);
	result.reserve(dimension);
	for(int i = 0; i < dimension; ++i){
		temp.clear();
		for(int j = 0; j < dimension; ++j){
			temp.push_back(0);
		}
		result.push_back(temp);
	}
	int x;
	int y;
	for(int i = 0; i < times; ++i){
		x = distZ(generator);
		y = distW(generator);
		try{
			result.at(x).at(y) += 1;
		}catch(std::out_of_range e){
			cout<<"X = "<<x<<" Y = "<<y<<endl;
			cout<<e.what()<<endl;
		}
	}
	// cout<<"[";
	for(unsigned int i = 0; i < result.capacity(); ++i){
		for(unsigned int j = 0; j < result[i].capacity(); ++j){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;;
	}
	
}
