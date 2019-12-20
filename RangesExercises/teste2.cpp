#include <iostream>
#include <iterator>


using namespace std;

int unique( int *first, int *last);
int main(){

int A[] = { 1, 2, 1, 2, 3, 3, 1, 2, 4, 5, 3, 4, 5 };

//aplicar unique sobre A.

auto last = unique(std::begin(A), std::end(A));
 
//o comando abaixo deveria imprimir A com o conteudo 1, 2, 3, 4, 5.
//for( int i = std::begin(A); i != last; ++i){
//	std::cout << *i << " ";
//}

std::cout << endl;

//mostrar o novo tamanho de A, que seria 5.
//std:: cout << ">>O comprimento logico de A apos o unique() eh: " << std::distance(std::begin(A), last) << std::endl;
std::cout << ">>O retorno indica a posição do elemento: " <<last << std::endl;


	return 0;
}


int unique( int *first, int *last){
auto busca = 0;
auto teste = 0;
auto slow = first+5;
	for (auto fast = first; fast != last; ++fast){
		for (auto i = slow; i != first; --i){
			if(*fast != *i ){
				busca ++;
			}
			
		}
		if(teste == busca-1){
			swap(*slow++, *fast);
		}
	
	}
	return busca;//std::distance(first, slow);
}