
#ifndef _BUSCAS_H_
#define _BUSCAS_H_


long int busca_si(const std::vector<long int> &amostra, std::size_t l,  std:: size_t r, const long int &key);
long int busca_sr(const std::vector<long int> &amostra, std::size_t l,  std:: size_t r, const long int &key);
long int busca_bi(const std::vector<long int> &amostra, std::size_t l,  std:: size_t r, const long int &key);
long int busca_br(const std::vector<long int> &amostra, std::size_t l,  std:: size_t r, const long int &key);
long int busca_ti(const std::vector<long int> &amostra, std::size_t l,  std:: size_t r, const long int &key);
long int busca_tr(const std::vector<long int> &amostra, std::size_t l,  std:: size_t r, const long int &key);
long int busca_bs(const std::vector<long int> &amostra, std::size_t l,  std:: size_t r, const long int &key);
long int busca_find(const std::vector<long int> &amostra, std::size_t l,  std:: size_t r, const long int &key);

#endif