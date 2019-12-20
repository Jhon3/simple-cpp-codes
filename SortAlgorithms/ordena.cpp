#include <iostream>

using namespace std;


int compara ( int a, int b){
	if( a < b) return -1;
	else if (a == b) return 0;
	else return 1;
}


//================================================================================================//

void insercao_ordenada (int A[], int & len, int N, int new_element){
	if( len == N) return;

	auto i =  len -1;

	while(i >=0 and new_element < A[i]){ // abrindo o buraco

		A[i+1] = A[i];

		i--;

	}

		A[i+1] = new_element; //aloca o new elemente uma posicao acima.

		len ++; //atualiza o tamanho logico
	}

//================================================================================================//

void insert_sort (int A[], int len){

		auto tamanho_logico_sub = 1;


		for(auto i = 1;  i < len; ++i){
			auto target = A[i];
			insercao_ordenada(A, tamanho_logico_sub, len, target);

		}
	}


//================================================================================================//

void selecton_sort (int A[], int len){

	for(auto j = 0 ; j < len-1 ; ++j){
		auto menor = j;
		for(auto i = j+1; i<len; ++i){

			if( A[i] < A[menor]){
				menor = i;
			}
		}
		std::swap(A[j], A[menor]);


	}
}


//================================================================================================//

void bubble_sort (int A[], int len){

	bool troca = true;

	while (troca){
		troca = false;


		for( auto i = 0; i < len-1; ++i){

			if(compara(A[i],A[i+1]) > 0){
				std::swap(A[i], A[i+1]);
				troca = true;
			}
		}
	}
}

	

//================================================================================================//

void print (int A[], size_t len){

	std::cout  << ">> A [";
	for( auto i(0u) ; i < len ; ++i)
		std::cout << A[i] << " ";
	std::cout << "], tamanho = " << len << "\n";

} 
int main(){



	int A[20] = {5, 9, 3, 2, 4, 7, 6, 10, 1, 8};

	int len = 10; //tamanho logico
	int N = 10; // tamanho fisico


	std::cout << "Vetor desordenado >>>" << std::endl;
	print(A, len);

	bubble_sort( A, len);
	std::cout << "Vetor ordenado >>>" << std::endl;
	print( A, len);



	

}