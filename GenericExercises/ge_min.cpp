#include <iostream>
#include <iterator>
#include <cstring>
#include <functional>

using byte = unsigned char;


bool pred_menor ( const void *a, const void *b){
	const int *A = (const int *) a;
	const int *B = (const int *) b;

	return *A < *B;
}


void* min_(const void *first, const void *last, std::function<bool(const void*, const void*)>pred, size_t size){
	const byte *f = (const byte *) first;
	const byte *l = (const byte *) last;

	auto min = f;

	for (auto i = f; i != l; i += size){
		if (pred(i, min))
			min = i;
	}

	return (void *) min;
}

int main(){


	int vetor[] = {34, 45, 67, 12, 6, 90, 21, 10, 18, 56};


	const int *Menor = (const int *) min_(std::begin(vetor), std::end(vetor), pred_menor, sizeof(int));


	std::cout << ">>O menor elemento eh: "<< *Menor << std::endl;



	return EXIT_SUCCESS;
}