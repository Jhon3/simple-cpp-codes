VECTOR
======

### O PROJETO
O objetivo do projeto é implementar uma classe vector similar a da stl. Basicamente os vectors são recipientes de seqüência que representam arrays que podem mudar de tamanho.
Assim como os arrays, os vetores usam locais de armazenamento contíguos para seus elementos, o que significa que seus elementos também podem ser acessados usando deslocamentos em ponteiros regulares para seus elementos e com a mesma eficiência que em arrays. Mas ao contrário de array, seu tamanho pode mudar dinamicamente, com seu armazenamento sendo manipulado automaticamente pelo recipiente.

### COMPILAR E EXECUTAR

**Para compilar use:**	
[Opção 1] $ -Wall -std=c++11 ./src/*.cpp -o ./bin/main -I ./include		
[Opção 2] $ make	

**Para executar use:**		
[Opção 1] $ ./bin/main	
[Opção 2] $ make run

### POSSÍVEIS ERROS
Foram feitos inúmeros testes a fim de evitar erros, porém ainda pode haver algum erro que não tenha sido previsto antes.

### AUTORES
**Jhonattan Carlos Barbosa Cabral.** 	
Graduando em Tecnologia da Informação. 
Instituto Metrópole Digital (IMD).
Universidade Federal do Rio Grande do Norte (UFRN).

**Daniel Marx Pinto Carvalho**		
Graduando em Tecnologia da Informação. 
Instituto Metrópole Digital (IMD).
Universidade Federal do Rio Grande do Norte (UFRN).

**Natal, 12 de maio de 2017.**

### REFERÊNCIAS
-[Cppreference](http://en.cppreference.com/w/)	
-[Makefile genérico](https://gist.github.com/maurizzzio/de8908f67923091982c8c8136a063ea6)
