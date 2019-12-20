#include <iostream>
#include <iterator>
#include <cstring>
#include <functional>


using byte = unsigned char;


bool pred_equal(const void *a, const void *b){
	const int *A = (const int *) a;
	const int *B = (const int *) b;

	return *A == *B;
}

void * unique_(const void *first, const void *last, std::function<bool(const void*, const void*)>pred, size_t size){
	byte *f = (byte *) first;
	byte *l = (byte *) last;

	auto fast = f;
	auto slow = f;
	byte aux[size];


	for (/*empty*/; fast != l; fast += size){
		bool repeat = false;		
		for( auto i = f; i != slow; i += size){
			if(pred(fast, i)){
				repeat = true;
			}
		}
		if (repeat == false){
			memcpy(aux, fast, size);
			memcpy(fast, slow, size);
			memcpy(slow, aux, size);
			slow += size;
		}
	}

	return (void *) slow;
}




int main(){

int vetor[] = {1, 1, 2, 2, 3, 4, 4, 4, 5, 6, 7, 7, 8, 9, 10, 11};


std::cout << "Vetor antes do unique: " << std::endl;
for(auto i = std::begin(vetor); i != std::end(vetor); ++i){
	std::cout << *i << " ";
}
std::cout << std::endl;


int *limite = (int *) unique_(std::begin(vetor), std::end(vetor), pred_equal, sizeof(int));


std::cout << "Vetor depois do unique: " << std::endl;
for(auto i = std::begin(vetor); i != limite; ++i){
	std::cout << *i << " ";
}
std::cout << std::endl;


	return EXIT_SUCCESS;
}