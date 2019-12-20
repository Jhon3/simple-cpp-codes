#include <iostream>
#include <iterator>
#include <cstring>
#include <string>
#include <functional>

using byte = unsigned char;

void * copy_(const void *first, const void *last, size_t size, const void *d_first){


	byte *f = ( byte *) first;
	byte *l = ( byte *) last;
	byte *f_d = ( byte *) d_first;

	
	for(; f != l; f += size, f_d += size){
	
		memcpy(f_d, f, size);

	}

	return (void *) f_d;
}


int main(){

	int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int vetor_copy [15];

	
	
	

	std::cout << "Vetor normal:" <<std::endl;
	for(auto i = std::begin(vetor); i!= std::end(vetor); ++i){
		std::cout << *i << " ";
	}
	std::cout << std::endl;


	int *fim = (int *)copy_(std::begin(vetor), std::end(vetor), sizeof(int), std::begin(vetor_copy));
	
	std::cout << "Vetor copia:" <<std::endl;
	for(auto i = std::begin(vetor_copy); i!= fim ; ++i){
		std::cout << *i << " ";
	}
	std::cout << std::endl;

return EXIT_SUCCESS;
}