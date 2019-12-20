#include <iostream>
#include <iterator>
#include <functional>
#include <cstring>
#include <string>


using byte = unsigned char;

void print(int *first, int *last){
	std::cout<< "[";
	for (auto i = first; i != last; ++i){
		std::cout << *i << " ";
	}
	std::cout << "]" << std::endl;
}


bool predicado( const void *A){

	const int *B = (const int *) A;

	if(*B > 0){
		return true;
	}
	else 
		return false;
}


unsigned char* compacta(void *first, void *last, std::function<bool(const void *)>Pred, size_t size){
	
	byte *f = (byte *) first;
	byte *l = (byte *) last;

	auto slow = l;

	for(auto fast = f; fast != l; fast+=size){
		if(Pred(fast)){
			memcpy(slow, fast, size);
			slow+=size;
		}
	}
	return slow;
}

int main(){
	int A[] = {10, 20, -2, -3, -5, 40, 50, 25, 13, -9};

	std::cout<<"Vetor antes do compacta";
	print(std::begin(A), std::end(A));

	auto left = compacta(std::begin(A), std::end(A), predicado, sizeof(int));

	std::cout<<"Vetor depois do compacta";
	print(std::begin(A), std::end(A));


	std::cout << compacta(std::begin(A), std::end(A), predicado, sizeof(int)) << std::endl;




	return 0;
}