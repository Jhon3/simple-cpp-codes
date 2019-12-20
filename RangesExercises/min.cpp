#include <iostream>
#include <iterator>
using namespace std;

int* Min(const int *first, const int *last);
int main(){
	
	int A[] = {1, 2,-3, -4, 5, -6};

	//Deveria imprimir -6.
	auto result = Min(std::begin(A), std::end(A));
	std::cout<< *result <<std::endl;


	//Deveria imprimir -4.
	result = Min(std::begin(A)+1, std::begin(A) + 5);
	std::cout<< *result <<std::endl;

	//std::cout << Min(std::begin(A), std::end(A));

	return 0;
}

int* Min(const int *first, const int *last){

	auto minimo = first;


	for(auto i= first; i!= last; ++i){
		if (*i < *minimo){
			minimo = i;
		}
	}
	

	

	return (int *) minimo;
}