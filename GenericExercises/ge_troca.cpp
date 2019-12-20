#include <iostream>
#include <cstring> //memcpy
#include <string>


using byte = unsigned char;

void swap_(void *a, void *b, size_t size){

	byte aux[size];

	memcpy(aux, a, size); //aux = a;
	memcpy(a, b, size); //a = b;
	memcpy(b, aux, size); //b = aux;
}


int main(){

int a = 1996, b = 2000;
std::string name1 = "Jhon", name2 = "Viny";


std::cout << ">>>Dois inteiros antes da troca: " << "A = " << a << " | " << "B = " << b <<std::endl;
swap_(&a, &b, sizeof(a));
std::cout << ">>>Dois inteiros com valores trocados: " << "A = " << a << " | " << "B = " << b <<std::endl;
std::cout<<std::endl;


std::cout << ">>>Duas strings antes da troca: " << "Nome 1: " << name1 << " | " << "Nome 2: " << name2 <<std::endl;
swap_(&name1, &name2, sizeof(&name1));
std::cout << ">>>Duas strings com nomes trocados: " << "Nome 1: " << name1 << " | " << "Nome 2: " << name2 <<std::endl;
std::cout<<std::endl;




	return EXIT_SUCCESS;
}


