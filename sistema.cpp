#include <stdio.h>
#include <string>
#include <iostream>

//#include "Class_Cliente.h"
//#include "Class_Representante.h"
//#include "Class_Produtos.h"
#include "Class.h"
//#include "Class_Pedido.h"

using namespace std;

#include <iostream>

using namespace std;


int main(int argc, char *argv[])
{

	Cliente *cli = new Cliente;
	Representante *rep = new Representante;
	Produto *prod = new Produto;
	Pedido *ped = new Pedido;

	cli->inicia(cli, "Vinicius", 19);
	cli->inserir(cli, "Lorenzo", 11);
	cli->inserir(cli, "Marcio", 47);
	cli->inserir(cli, "Marivane", 43);
	cli->inserir(cli, "Rebeca", 19);
	cli->imprime(cli);

	cout << endl;
	rep->inicia(rep, "Edenei", 8.2);
	rep->inserir(rep, "Cassol", 8.5);
	rep->inserir(rep, "Adelar", 8.9);
	rep->inserir(rep, "Alecio", 8.1);
	rep->imprimir(rep);
	cout << endl;
	prod->inicia(prod, 8081, 36.80, "bsc term gola red", 99);
	prod->inserir(prod, 5136, 65.90, "Calca montaria", 15);
	prod->inserir(prod, 7344, 109.90, "Parka classica", 66);
	prod->inserir(prod, 3344, 34.90, "Basica term masc", 34);
	prod->imprimir(prod);


	cout << endl;
	ped->inicia(ped, cli, rep, prod, 1, 2);
	ped->inserir(ped, cli, rep, prod, 4, 1,1);
	//ped->inserir(ped, cli, rep, prod, 5, 3,1);
	//ped->inserir(ped, cli, rep, prod, 3, 4,1);
	//ped->inserir(ped, cli, rep, prod, 2, 2,1);

	ped->imprime(ped);
	
	
	rep->imprimir(rep);
	//cout << "Ultimo: " << ped->tail(ped)->cli_nome << endl;
	//cout << "Primeiro: " << ped->head(ped)->cli_nome << endl;



	return 0;
}
