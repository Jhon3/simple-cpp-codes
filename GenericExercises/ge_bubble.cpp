#include<iostream>
#include<iterator>
#include<cstring>
#include<functional>

using byte = unsigned char;

bool comp_min(const void *a, const void *b){
	const int *A = (const int *)a;
	const int *B = (const int *)b;

	return *B < *A;
}


void bubble_(const void *first, const void *last, std::function<bool(const void*, const void*)>pred, size_t size){
	

	byte *f = (byte *) first;
	byte *l = (byte *) last;
	bool troca = true;
	byte aux[size];


	while(troca){
		troca = false;

		for(auto i = f; i != l; i += size){
			if(pred(i, i+size)){
				memcpy(aux, i, size);
				memcpy(i, i+size, size);
				memcpy(i+size, aux, size);
				troca = true;
			}
		}
	}
}


int main(){
	int vetor[] ={ 10, 1, 9, 5, 3, 6, 2, 7, 4, 8};



	std::cout << "Vetor antes da ordenacao: " <<std::endl;
	for (auto i = std::begin(vetor); i != std::end(vetor); ++i){
		std::cout << *i << " ";
	}
	std::cout<<std::endl;


	bubble_(std::begin(vetor), std::end(vetor), comp_min, sizeof(int));


	std::cout << "Vetor depois da ordenacao: " <<std::endl;
	for (auto i = std::begin(vetor); i != std::end(vetor); ++i){
		std::cout << *i << " ";
	}
	std::cout<<std::endl;



	return EXIT_SUCCESS;
}