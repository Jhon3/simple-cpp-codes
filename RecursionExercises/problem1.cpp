#include <iostream>
#include <cmath>


using namespace std;

int count(int tamanho);

int main(){


int altura;
int quantidade;

std::cout <<"Qual a altura da piramide? " << std::endl;
std::cin >> altura;

if (altura >= 0 ){
	quantidade = count(altura);
	std::cout << "O resultado eh: " << quantidade <<std::endl;
}
else{
	std::cout << "Desculpe, valor invalido..." << std::endl;
}

return 0;

}

int count(int tamanho){

if( tamanho == 1){  //condição de parada, quando o tamanho for 1 ele ira retornar 1 pois 1² = 1.
		return 1;
	}
	else{

		return pow(tamanho,2) + count(--tamanho);	// O tamanho atual elevado ao quadrado sempre será somado
													// ao tamanho anterior ate chegar a tamanho =1.


	}
}	
