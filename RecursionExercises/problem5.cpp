#include <iostream>

using namespace std;

int somadig(int num);
int rootdig(int nume);

int main(){

int numero;


std::cout <<"digite um numero: " << std::endl;

std::cin >> numero;


auto result = rootdig(numero);

std::cout << "o resultado eh: " << result << std::endl;


	return 0;
}


int somadig(int num){
	if(num % 10 == num){
		return num;
	}
	else{

		return (num % 10) + somadig(num /10);
	}


}

int rootdig(int nume){
	if(nume < 10){
		return nume;
	}
	else{

		return rootdig(somadig(nume));
	}


}

