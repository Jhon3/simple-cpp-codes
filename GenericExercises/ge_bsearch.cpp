#include <iostream>
#include <iterator>
#include <cstring>
#include <functional>

using byte = unsigned char;

int compare (const void* a, const void *b){
	const int *A = (const int *) a;
	const int *B = (const int *) b;

	if(*A < *B) return -1;
	else if (*A == *B) return 0;
	else return 1;

}


void * bsearch_(const void * first, const void *last, std::function<int(const void*, const void*)>pred,
																 size_t size, const void *target){
	byte *f = (byte *) first;
	byte *l = (byte *) last;

	byte *mid;

	

	while(f <= l){
		auto N = std::distance(f, l);
		auto aux = N / size;
		mid = f + ((aux/2) * size);


		auto teste = pred(mid, target);


		if(teste == 0)
			return (void *) mid;

		else if(teste < 0)
			f = mid + size;
		
		else if(teste > 0)
			l = mid - size;
		
	}

	return (void *) l;

	
}

int main(){

	int vetor [] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int key = 3;

	int *result = (int *) bsearch_(std::begin(vetor), std::end(vetor), compare, sizeof(int), &key);

	std::cout << ">>>Resultado: " << *result << ". >>>Na posicao: " << result << std::endl;

	return EXIT_SUCCESS;
}