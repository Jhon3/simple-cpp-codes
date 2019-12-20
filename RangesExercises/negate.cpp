#include <iostream>
#include <iterator>
using namespace std;

void Negate( int *first, int *last);

int main(){
	int Vet[]= {1, 2, -3, -4, 5, -6};

	std::cout << "Vetor antes do negate! " <<std::endl;
	
	for(auto i =std::begin(Vet); i!= std::end(Vet); ++i){
		std::cout << *i << " ";
	}
	std::cout<<std::endl;

	// Nega todo o vetor
	//Negate( std::begin(Vet), std::end(Vet));

	// Nega do 3ro até o ultimo elemento do vetor
	//Negate( std::begin(Vet)+2, std::end(Vet));

	//Nega apenas o 4to elemento do vetor
	Negate( std::begin(Vet)+3, std::begin(Vet)+4);
	std::cout << "Vetor depois do negate! "<<std::endl;
	for (auto i= std::begin(Vet); i!= std::end(Vet); ++i){
		std::cout << *i << " ";
	}
	std::cout << std::endl;


	return 0;
}

void Negate( int *first, int *last){


	for(auto i = first; i!= last; ++i){
		*i *= -1;
		
	}

}