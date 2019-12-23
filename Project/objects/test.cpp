#include <iostream>
#include <random>
#include <string>
#include <stdlib.h>
using namespace std;

int main(int argc, char const * argv[]){
	default_random_engine generator;
	uniform_int_distribution<int> dist(0,9);
	int seed = atoi(argv[1]);
	generator.seed(seed);
	for(int i = 0; i < 10; ++i){
		cout<<dist(generator)<<endl;
	}
}
