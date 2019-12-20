#include <iostream>


using namespace std;

int mdc( int x, int y);

int main(){

int x, y;

std::cout <<"digite dois numero para calcular o mdc: " <<std::endl;
std::cin >> x >> y;


auto result = mdc(x, y);

std::cout << "o resultado eh: " << result << std::endl;


	return 0;
}

int mdc( int x, int y){

if( x % y == 0){
	return y;
}
else{
	auto d = x % y;
	return mdc(y, d);
}
}