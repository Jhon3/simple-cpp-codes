#include <iostream>
#include <iterator>
#include <cstring> //memcpy()
#include <functional>

using byte = unsigned char;



bool predicade(const void *a){
	const int *A = (const int *) a;

	return *A > 0;
}


void * remove_(void *first, void *last, std::function<bool(const void*)>pred, size_t size){

	byte *f = (byte *) first;
	byte *l = (byte *) last;

	auto fast = f;
	auto slow = f;
	byte aux [size];


	for(/*empty*/; fast != l; fast +=size){
		if(pred(fast)){
			memcpy(aux, fast, size); //aux = fast;
			memcpy(fast, slow, size); //fast = slow;
			memcpy(slow, aux, size); //slow = aux;

			slow += size;
		}
	}

	return (void *) slow;

}


int main(){

int vetor [] = {-2, 3, 4, 5, -1, -10, -30, 13, 90, -21};


std::cout << "Vetor normal: " <<std::endl;
for(auto i = std::begin(vetor); i != std::end(vetor); ++i){
	std::cout << *i << " ";
}
std::cout<<std::endl;


int *fim = (int *) remove_(std::begin(vetor), std::end(vetor), predicade, sizeof(int)); 

std::cout << "Vetor depois do compacta: " <<std::endl;
for(auto i = std::begin(vetor); i != fim; ++i){
	std::cout << *i << " ";
}
std::cout<<std::endl;


return EXIT_SUCCESS;
}