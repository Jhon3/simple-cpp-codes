#include <iostream>
#include <iterator>


using namespace std;

int* unique( int *first, int *last);
int main(){

int A[] = { 1, 2, 1, 2, 3, 3, 1, 2, 4, 5, 3, 4, 5 };

//aplicar unique sobre A.

auto last = unique(std::begin(A), std::end(A));
 
//o comando abaixo deveria imprimir A com o conteudo 1, 2, 3, 4, 5.
for( auto i = std::begin(A); i != last; ++i){
	std::cout << *i << " ";
}

std::cout << endl;

//mostrar o novo tamanho de A, que seria 5.
std:: cout << ">>O comprimento logico de A apos o unique() eh: " << std::distance(std::begin(A), last) << std::endl;


	return 0;
}


int* unique( int *first, int *last){
	int k;
auto slow = first;
	for(auto fast = first; fast != last; ++fast){
		k = 0;
		for (auto i = first; i != slow; ++i){
			if(*fast == *i ){
				k++;
			}
		}
			if(k == 0){
			swap(*slow++, *fast);
		}

	}
	return slow;
}