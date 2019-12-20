#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

//======================================================================================//
//BUSCA SEQUENCIAL ITERATIVA

long int busca_si(const std::vector<long int> &amostra, std::size_t l,  std:: size_t r, const long int &key){	
	for(auto i = l; i != r ; i++){
		if(amostra[i] == key){
		  return 1;
		}
	}
	return -1;
}
//======================================================================================//
//BUSCA SEQUENCIAL RECURSIVA
long int busca_sr(const std::vector<long int> &amostra, std::size_t l,  std:: size_t r, const long int &key){

	if(r > l){
		if(amostra[l] == key){
			return 1;
		}
		else{			

			return busca_sr(amostra, l+1, r, key);

		}
	}
	return -1;
}
//===============================================================================================//
//BUSCA BINARIA ITERATIVA
long int busca_bi (const std::vector<long int> &amostra, std::size_t l,  std:: size_t r, const long int &key) {
	int mid;
	while (l <= r){
		mid = (l+r)/2;
		
		if (amostra[mid] == key)
			return 1; 
		if (amostra[mid] < key)
			l = mid + 1;
		else
			r = mid - 1;
	}

	return -1;
}

//===============================================================================================//
//BUSCA BINARIA RECURSIVA
long int busca_br (const std::vector<long int> &amostra, std::size_t l,  std:: size_t r, const long int &key) {

	if (l > r)
		return -1;
	else{
		auto mid = (l+r)/2;
		if(amostra[mid] == key)
			return 1;
		if(amostra[mid] < key)
			return busca_br(amostra, mid+1, r, key);
		else
			return busca_br(amostra, l, mid-1, key);
	}
}
//===============================================================================================//
//BUSCA TERNARIA ITERATIVA

long int busca_ti(const std::vector<long int> &amostra, std::size_t l,  std:: size_t r, const long int &key) {
	
	int mid1, mid2;

	while (l <= r) {

        	mid1 = l + (r-l)/3;
        	mid2 = r - (r-l)/ 3;

        	if (key == amostra[mid1] or key == amostra[mid2])
                return 1;
        	if (key < amostra[mid1])
				r = mid1 - 1;
        	else if (key > amostra[mid2])
				l = mid2 + 1;
        	else if (key > amostra[mid1] and key < amostra[mid2]){
				l = mid1 + 1;
				r = mid2 - 1;
			}
		}		
	
	return -1;
}

//===============================================================================================//
//BUSCA TERNARIA RECURSIVA
long int busca_tr(const std::vector<long int> &amostra, std::size_t l,  std:: size_t r, const long int &key) {
	   
    auto mid1 = l + (r-l)/3;
    auto mid2 = r - (r-l)/ 3;
        
        if (l >= r) {
			return -1;
		} 
        if (key == amostra[mid1] or key == amostra[mid2])
            return 1;
        if (key < amostra[mid1])
			return busca_tr(amostra, l, mid1-1, key);
        else if (key > amostra[mid2])
			return busca_tr(amostra, mid2+1, r, key);
        else if (key > amostra[mid1] and key < amostra[mid2])
        	return busca_tr(amostra, mid1+1, mid2-1, key);		
	return -1;
}

//===============================================================================================//
//BUSCA binary_search()

long int busca_bs(const std::vector<long int> &amostra, std::size_t l,  std:: size_t r, const long int &key){
	auto first = amostra.begin();
	auto last = amostra.begin()+r;

	if(std::binary_search(first, last, key)){
		return 1;
	}
	else{
		return -1;
	}
}
//=========================================================================================//
//BUSCA std::find().

long int busca_find(const std::vector<long int> &amostra, std::size_t l,  std:: size_t r, const long int &key){
	auto first = amostra.begin();
	auto last = amostra.begin()+r;

	auto it = std::find(first, last, key);

	if(*it == key){
		return 1;
	} 
	else{
		return -1;
	}
}