#include <iostream>


using namespace std;
int poder(int ope, int pot);

int main(){

int n;
int k;


std::cout << "insira o valor de n e k: " <<std::endl;
cin >> n >> k;

auto result = poder(n, k);


std::cout << "o resultado eh: " << result <<std::endl;

	return 0;
}

int poder(int ope, int pot){
	if(pot == 0){
		return 1;
	}

	else{

		return ope * poder(ope, --pot);
	}
}