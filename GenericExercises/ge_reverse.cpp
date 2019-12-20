#include <iostream>
#include <string>
#include <cstring> // memcpy()
#include <iterator>


using byte = unsigned char;

void print ( int *f, int *l){

	while(f != l){
		std::cout << *f ++ << " ";
	}
	std::cout << std::endl;
}



void reverse (void * first, void *last, size_t size){
	// converter para byte para permitir a aritmetica de ponteiros.
	byte *f = (byte *) first;
	byte *l = (byte *) last;

	auto n = (l - f) / size; // # de elementos no vetor.
	byte aux[size]; //variavel auxiliar para viabilizar as trocas.
	auto offset = 0u;
	for (auto i = 0u ; i < n/2 ; i++){

		memcpy (aux, f+(i*size), size); // aux = V[i]
		memcpy( f+offset, f+(n-i-1)*size, size); // V[i] = v[n-i-1];
		memcpy(f+(n-i-1)*size, aux, size); // V[n-i-1] = aux;
		offset += size;
	}

	std::cout << ">>>" << n << std::endl;
}
int main(void){

	int V[] = {1, 2, 3, 4, 5};

	print (std::begin(V), std::end(V));
	reverse(std::begin(V), std::end(V), sizeof(int));
	print(std::begin(V), std::end(V));

	return EXIT_SUCCESS;
}