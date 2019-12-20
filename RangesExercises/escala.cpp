#include <iostream>
#include <iterator>
using namespace std;

void escalar( int *first, int *last, int esc);
int main(){

int A[] = {1, 2, -3, -4, 5, -6};
	
std::cout <<"Vetor antes da operação: " <<std::endl;
for(auto i = std::begin(A); i!= std::end(A); ++i){
	std::cout << *i << "  ";
}	
std::cout << std::endl;

escalar(std::begin(A), std::end(A), 3);

std::cout <<"Vetor depois da operação: " <<std::endl;
for(auto i = std::begin(A); i!= std::end(A); ++i){
	std::cout << *i << "  ";
}	
std::cout << std::endl;



	return 0;
}

void escalar( int *first, int *last, int esc){
	for(auto i = first; i != last; ++i){
		*i *= esc;
	}

}