#include <iostream>
#include <iterator>
using namespace std;

int* Copy( int first, int *last, int *d_first);

int main(){

int A[] = { 1, 2, 3, 4, 5}; //vetor fonte.
int B[] = { 0, 0, 0}; //vetor destino.

//copiar elementos 2, 3 e 4 para o inicio do vetor B.
auto b_last = copy (std::begin(A)+1, std::begin(A)+4, std::begin(B));

//o comando abaixo deveria imprimir B com o conteudo 2, 3 e 4.
for(auto i = std::begin(B) ; i !=b_last ; ++i){
	std::cout << *i << "  ";
}

std::cout <<std::endl;
	return 0;
}

int* Copy( int first, int *last, int *d_first){

	for(auto i = d_first; i != last; ++i){
		
	}
}
