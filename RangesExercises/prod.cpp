#include <iostream>
#include <iterator>
using namespace std;
int dot_prod ( int *first, int *last, int *first_b);

int main(){
	//desejamos multiplicar a=[1, 3, -5] b=[4, -2, -1].
int A[]= {1, 3, -5, 4, -2, -1}; //os dois vetores armazenados em um mesmo arranjo.	
auto result = dot_prod( std::begin(A), std::begin(A)+3, std::begin(A)+3);

//O caminho abaixo deveria imprimir 3.
std::cout << ">> O resultado é: " << result << std::endl;
return 0;

}

int dot_prod ( int *first, int *last, int *first_b){

	auto prod=0;

	for( auto i = first; i!= last; ++i){
		prod += *i * *(i+3);
	}

	return prod;
}