#include <iostream>
#include <iterator>
#include <cstring>
#include <functional>


using byte = unsigned char;


bool predicado(const void *A){
	const int *B = (const int *) A;

	return (*B > 5);
}


void *find_if(const void *first, const void *last, std::function<bool(const void *)>pred, size_t size){

	const byte *f = (const byte *) first;
	const byte *l = (const byte *) last;


	for (auto i = f; i != l; i+=size){
		if(pred(i)) return (void *) i;
	}
	return (void *) l;
}

int main(){

int vetor [] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 20};

int *result = (int *)find_if(std::begin(vetor), std::end(vetor), predicado, sizeof(int));

std::cout << ">>>Resultado = " << *result << std::endl;
std::cout << "Na posicao: " << std::distance(std::begin(vetor), result) << std::endl;

return EXIT_SUCCESS;
}