#include <bits/stdc++.h>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Cliente
{

public:
	int idade;
	int cod;
	string nome;
	Cliente *prox;
	Cliente *ant;


	Cliente()
	{

		this->nome = "";
		this->idade = 0;
		this->cod = 0;
		this->prox = 0;
		this->ant = 0;

	}

	~Cliente()
	{
		cout << "Cliente excluido!!" << endl;
	}


	bool vazia(Cliente *cli)
	{

		if(cli->nome == "" && cli->idade == 0 && cli->cod == 0)
		{

			return true;

		}

		return false;

	}

	void inicia(Cliente *cli, string nome, int idade)
	{
		if(cli->vazia(cli) == true)
		{
			cli->nome = nome;
			cli->idade = idade;
			cli->cod = 1;
		}

		else
		{
			cli->inserir(cli, nome, idade);
		}
	}

	Cliente *head(Cliente *cli)
	{
		while(cli != NULL)
		{
			if(cli->ant == NULL)
			{
				return cli;
			}

			cli = cli->ant;

		}
		return cli;
	}

	Cliente *tail(Cliente *cli)
	{
		while(cli)
		{
			if(cli->prox == NULL)
			{
				return cli;
			}
			cli = cli->prox;
		}
		return cli;
	}

	void inserir(Cliente *cli, string nome, int idade)//insere na seuqencia da lista
	{

		if(cli->vazia(cli) == false) //se n esta vazia
		{

			Cliente *novo = new Cliente;
			Cliente *fim = cli->tail(cli);

			novo->nome = nome;
			novo->idade = idade;
			novo->cod = fim->cod + 1;

			fim->prox = novo;
			novo->ant = fim;

			cli->verifica_cod(cli);


			//novo->cod = valor;
		}
		else
		{
			cli->inicia(cli, nome, idade);
		}
	}
	//funcao para teste - cod no meio
	void inserir2(Cliente *cli, string nome, int idade, int cod)//insere na seuqencia da lista
	{
		if(cli->vazia(cli) == false) //se n esta vazia
		{

			Cliente *novo = new Cliente;
			Cliente *fim = cli->tail(cli);

			novo->nome = nome;
			novo->idade = idade;
			novo->cod = cod;

			fim->prox = novo;
			novo->ant = fim;

			cli->verifica_cod(cli);

		}
	}

	void verifica_cod(Cliente *cli)
	{
		bool verificacao = false;

		Cliente* aux = cli->head(cli);
		Cliente* fim = cli->tail(cli);//cod que quero pesquisar = ultimo;
		while(aux != fim)
		{
			if(aux->cod == fim->cod && aux != fim)
			{
				cout << "O cod :" << fim->cod << ", ja tem dono!" << endl;
				cout << "Alterando...!" << endl;
				verificacao = true;
				break;
			}

			aux = aux->prox;
		}

		if(verificacao == true)
		{
			fim->cod = fim->cod + 1;
			cli->verifica_cod(cli);

		}

	}

	void imprime(Cliente *cli)
	{
		cli = cli->head(cli);
		cout << "Lista de clientes:" << endl;
		while(cli)
		{

			cout << "Nome:" << cli->nome << " | idade: " << cli->idade << " | cod: " << cli->cod << endl;
			cli = cli->prox;
		}

	}

};//Class principal
//--Class cliente fim-----------------------------------------------------------------------------------------

class Representante
{

public:

	int cod;
	float comissao;
	float valor;
	string nome;
	Representante *prox;
	Representante *ant;

	Representante()
	{
		this->nome = "";
		this->cod = 0;
		this->valor = 0;
		this->comissao = 0;
		this->prox = 0;
		this->ant = 0;
	}

	~Representante()
	{
		cout << "Objeto destruido!" << endl;
	}

	bool vazia(Representante *rep)
	{

		if(rep->cod == 0 && rep->comissao == 0)
		{

			return true;//eh vazia...

		}

		else
		{
			return false;
		}

	}

	Representante *tail(Representante *rep)
	{

		while(rep)
		{
			if(rep->prox == NULL)
			{
				return rep;
			}
			rep = rep->prox;
		}
		return rep;
	}
	Representante *head(Representante *rep)
	{

		while(rep)
		{
			if(rep->ant == NULL)
			{
				return rep;
			}
			rep = rep->ant;
		}
		return rep;
	}

	void inicia(Representante *rep, string nome, float comissao)
	{

		if(rep->vazia(rep) == true)
		{

			rep->nome = nome;
			rep->comissao = comissao;
			rep->cod = 1;

		}

		else
		{
			rep->inserir(rep, nome, comissao);
		}

	}

	void inserir(Representante *rep, string nome, float comissao)
	{
		Representante *novo = new Representante;
		Representante *fim = rep->tail(rep);

		if(rep->vazia(rep) == false)
		{

			novo->nome = nome;
			novo->comissao = comissao;
			novo->cod = fim->cod + 1;

			fim->prox = novo;
			novo->ant = fim;

		}
	}

	void imprimir(Representante *rep)
	{
		cout << "Listando representantes:" << endl;
		rep = rep->head(rep);
		while(rep)
		{
			cout << "Nome: " << rep->nome << " | comissao: " << rep->comissao <<  " % | cod: " << rep->cod <<
			 " Valor de comissao total:" <<  rep->valor << endl;

			rep = rep->prox;
		}
	}


};
//FIM REPRESENTANTE --------------------------------------------------------------------------------------------------------

class Produto
{

public:
	int ref;
	float valor;
	string modelo;
	int quantidade;
	Produto *prox;
	Produto *ant;

	Produto()
	{
		this->ref = 0;
		this->valor = 0;
		this->modelo = "";
		this->quantidade = 0;
		this->prox = 0;
		this->ant = 0;

	}

	~Produto()
	{
		cout << "Objeto destruido!" << endl;
	}

	bool vazia(Produto *prod)
	{

		if(prod->ref == 0 && prod->valor == 0 && prod->quantidade == 0)
		{

			return true;//eh vazia...

		}

		else
		{
			return false;
		}

	}

	Produto *tail(Produto *prod)
	{

		while(prod)
		{
			if(prod->prox == NULL)
			{
				return prod;
			}
			prod = prod->prox;
		}
		return prod;
	}
	Produto *head(Produto *prod)
	{

		while(prod)
		{
			if(prod->ant == NULL)
			{
				return prod;
			}
			prod = prod->ant;
		}
		return prod;
	}

	void inicia(Produto *prod, int ref, float valor, string modelo, int quantidade)
	{

		if(prod->vazia(prod) == true)
		{

			prod->ref = ref;
			prod->valor = valor;
			prod->modelo = modelo;
			prod->quantidade = quantidade;

		}

		else
		{
			prod->inserir(prod, ref, valor, modelo, quantidade);
		}

	}

	void inserir(Produto *prod, int ref, float valor, string modelo, int quantidade)//insere na seuqencia da lista
	{

		if(prod->vazia(prod) == false)
		{

			Produto *novo = new Produto;
			Produto *fim = prod->tail(prod);
			novo->ref = ref;
			novo->valor = valor;
			novo->modelo = modelo;
			novo->quantidade = quantidade;
			novo->ant = fim;
			fim->prox = novo;
		}

		else
		{

		}
	}


	void imprimir(Produto *prod)
	{
		cout << "Listando os produtos:" << endl;
		prod = prod->head(prod);
		while(prod)
		{
			cout << "Referencia: " << prod->ref << " | Valor R$: " << prod->valor <<  " | modelo: " << prod->modelo << " | Quantidade: " << prod->quantidade << endl;

			prod = prod->prox;
		}
	}

	void imprime_saldo(Produto *prod)
	{
		prod = prod->head(prod);
		cout << "Produtos com saldo:" << endl;
		while(prod)
		{
			if(prod->quantidade > 0)
			{
				cout << "Referencia: " << prod->ref << " | Valor R$: " << prod->valor <<  " | modelo: "
					 << prod->modelo << " | Quantidade: " << prod->quantidade << endl;
			}
			prod = prod->prox;
		}
	}




};
//FIM CLASS PRODUTO--------------------------------------------------------------------------------------------------


class Pedido
{

public:
	int cli_pedido;
	int rep_pedido;
	int quantidade;
	int total_ref;
	int cod;
	float valor;
	string cli_nome;
	string rep_nome;
	int produtos[20];
	int quantidade_item[20];
	float valor_item[20];
	float valor_vezes[20];
	float valor_total;
	Pedido *prox;
	Pedido *ant;

	Pedido()
	{
		this->cli_pedido = 0;
		this->rep_pedido = 0;
		this->quantidade = 0;
		this->valor = 0;
		this->cod = 0;
		this->total_ref = 0;
		this->produtos = {};
		this->quantidade_item = {};
		this->valor_item = {};
		this->valor_vezes = {};
		this->cli_nome = "";
		this->rep_nome = "";
		this->valor_total = 0;
		this->prox = 0;
		this->ant = 0;
	}

	~Pedido()
	{
		cout << "objeto destruido!!" << endl;
	}

	bool vazio(Pedido *ped)
	{

		if(ped->quantidade == 0 && ped->cli_pedido == 0 && ped->cod == 0)
		{

			return true;//vazio

		}
		else
		{
			return false;
		}
	}

	Pedido *head(Pedido *ped)
	{
		while(ped != NULL)
		{
			if(ped->ant == NULL)
			{
				return ped;
			}

			ped = ped->ant;

		}
		return ped;
	}

	Pedido *tail(Pedido *ped)
	{
		while(ped)
		{
			if(ped->prox == NULL)
			{
				return ped;
			}
			ped = ped->prox;
		}
		return ped;
	}

	void inicia(Pedido *ped, Cliente *cli, Representante *rep, Produto *prod, int cli_pedido, int rep_pedido)
	{
		if(ped->vazio(ped) == true)
		{
			ped->cod = 1;
			ped->verifica_cli(ped, cli, cli_pedido);
			ped->verifica_rep(ped, rep, rep_pedido);
			ped->insere_produtos(ped, prod);
			ped->rep_comissao(ped, rep);
		}

	}

	void inserir(Pedido *ped, Cliente *cli, Representante *rep, Produto *prod, int cli_pedido, int rep_pedido, int cod)
	{

		if(ped->vazio(ped) == false)
		{
			Pedido *novo = new Pedido;
			Pedido *fim = ped->tail(ped);
			//novo->quantidade = quantidade;
			novo->cli_pedido = cli_pedido;
			novo->rep_pedido = rep_pedido;
			novo->cod = fim->cod + 1;

			fim->prox = novo;
			novo->ant = fim;


			ped->verifica_cli(novo, cli, cli_pedido);
			ped->verifica_rep(novo, rep, rep_pedido);
			ped->verifica_cod(ped);
			ped->insere_produtos(novo, prod);
			ped->rep_comissao(novo, rep);



		}

	}

	void verifica_cod(Pedido* ped)
	{
		Pedido *aux = ped->head(ped);
		Pedido *fim = ped->tail(ped);
		bool verificacao = false;
		while(aux)
		{
			if(aux->cod == fim->cod && aux != fim)
			{
				cout << "O cod :" << fim->cod << ", ja tem dono!" << endl;
				cout << "Alterando...!" << endl;
				verificacao = true;
				break;
			}

			aux = aux->prox;
		}

		if(verificacao == true)
		{
			fim->cod = fim->cod + 1;
			ped->verifica_cod(ped);

		}
	}


void insere_produtos(Pedido *ped, Produto *prod)
{

	char resp = 's';
	int pos = 0;
	int ref;
	int qntd;
	// quantidade;
	//Pedido *ped = ped->tail(ped);
	Produto *aux = prod->head(prod);
	cout << "Pedido de:" << ped->cli_nome << endl;
	while(resp == 's')
	{
		LimpaTela();
		cout << "Deseja adicionar algum item?" << endl;
		cout << "s/n" << endl;
		cin >> resp;
		if(resp == 's')
		{
			prod->imprime_saldo(prod);
			cout << "Digite a referencia do produto:";
			cin >> ref;
			cout << "Digite a quantidade:";
			cin >> qntd;
			pos++;
			ped->verifica_produto(aux, ped, ref, pos, qntd);

			//pode inserir

		}
		if(resp == 'n')
		{
			system("cls");
		}

		if(resp != 'n' && resp != 's')
		{
			cout << "Resposta nao valida!Tente novamente!" << endl;
			ped->insere_produtos(ped, prod);
		}

	}

}

void verifica_produto(Produto *prod, Pedido *ped, int ref, int pos, int qntd)
{
	//Produto *aux = prod->head(prod);
	Produto *aux = prod->head(prod);
	//Pedido *ped = ped->head(ped);
	float valor_un;
	float valor_tot;
	while(aux)
	{

		if(aux->ref == ref && aux->quantidade >= qntd)
		{
			cout << "\nProd de escolha escontrado: " << aux->ref;

			valor_un = aux->valor;
			valor_tot = valor_un * qntd;

			ped->produtos[pos] = ref;
			ped->quantidade_item[pos] = qntd;
			ped->valor_item[pos] = valor_un;
			ped->valor_vezes[pos] = valor_tot;
			ped->valor_total += valor_tot;
			aux->quantidade -= qntd;
			//quantidade = pos;
			ped->quantidade = ped->quantidade + qntd;
			ped->total_ref = pos;
			return;
		}
		
		if(aux->ref == ref && aux->quantidade < qntd)
		{
			system("cls");
			cout << "Quantidade maior do que o estoque atual!" << endl;
		}

		aux = aux->prox;
	}

	cout << "Sinto muito!Referencia nao encontrada!" << endl;
	return;
}


/*
void inicia_produto(Pedido *ped, Representante *rep)
{

Produto *prod = prod->tail(prod);

char resp = 's';
int pos = 0;
int cod;

while(resp == 's')
{
	Produto *prod = prod->tail(prod);
	cout << "Deseja adicionar algum item?" << endl;
	cout << "s/n" << endl;
	cin >> resp;


	ped->itens[pos] = cod;
	ped->totalprod = pos;
	pos++;

}*/
void rep_comissao(Pedido *ped, Representante *rep)
{
	Representante *aux = rep->head(rep);
	
	while(aux)
	{
		
		if(aux->nome == ped->rep_nome)
		{
			aux->valor = aux->valor + ((ped->valor_total * aux->comissao) / 100);
			break;
		}
		
		aux = aux->prox;
	}
	
}

void verifica_cli(Pedido * ped, Cliente * cli, int cli_pedido)
{
	Cliente *aux = cli->head(cli);
	bool verifica = false;
	int novo_id;
	while(aux)
	{
		//cout << "BUSCANDO:" << aux->cod << endl;
		//cout << "VALOR QUE TENHO: " <<  cli_pedido << endl;
		//cout << "entrou" << endl;
		if(cli_pedido == aux->cod)
		{
			ped->cli_pedido = cli_pedido;
			ped->cli_nome = aux->nome;
			verifica = true;
			break;
		}
		aux = aux->prox;
	}

	if(verifica == false)
	{
		cout << "Cliente nao encontrado!" << endl;
		LimpaTela();
		cli->imprime(cli);
		cout << "Digite um codigo existente de cliente:";
		cin >> novo_id;
		//ped->cli_pedido = novo_id;
		ped->verifica_cli(ped, cli, novo_id);

	}

}

void verifica_rep(Pedido * ped, Representante * rep, int rep_pedido)
{
	Representante * aux = rep->head(rep);
	bool verifica = false;
	int novo_id;

	while(aux)
	{
		//cout << "Buscando: " << aux->cod << endl;
		//cout << "valor que tenho: " << rep_pedido << endl;
		if(aux->cod == rep_pedido)
		{
			ped->rep_pedido = rep_pedido;
			ped->rep_nome = aux->nome;
			verifica = true;
		}
		aux = aux->prox;
	}
	if(verifica == false)
	{
		cout << "Representante nao encontrado!" << endl;
		LimpaTela();
		rep->imprimir(rep);
		cout << "Digite um codigo existente de Representante:";
		cin >> novo_id;
		//ped->cli_pedido = novo_id;
		ped->verifica_rep(ped, rep, novo_id);
	}
}



/*
		void verifica_cod(Cliente *cli)
	{
		bool verificacao = false;

		Cliente* aux = cli->head(cli);
		Cliente* fim = cli->tail(cli);//cod que quero pesquisar = ultimo;
		while(aux != fim)
		{
			if(aux->cod == fim->cod && aux != fim)
			{
				cout << "O cod :" << fim->cod << ", ja tem dono!" << endl;
				cout << "Alterando...!" << endl;
				verificacao = true;
			}

			aux = aux->prox;
		}

		if(verificacao == true)
		{
			fim->cod = fim->cod + 1;
			cli->verifica_cod(cli);

		}

	}*/


void imprime(Pedido * ped)
{
	int j = 1;
	int i = 0;
	float valor_pedidos;
	int qntd_pecas = 0;
	ped = ped->head(ped);
	LimpaTela();
	while(ped)
	{
		i = ped->total_ref;
		cout << "Codigo do pedido: " << ped->cod << endl;
		cout << "Cod cliente: " << ped->cli_pedido << " | Nome cliente: " << ped->cli_nome << endl;
		cout << "Cod rep: " << ped->rep_pedido << " | Nome representante: " << ped->rep_nome << endl;
		cout << "Quantidade: " << ped->quantidade  << " Referencias: " << ped->total_ref << endl;
		for(j = 1; j <= i; j++)
		{
			cout << "Produtos: " << ped->produtos[j] << " Quantidade: " << ped->quantidade_item[j] <<
				 " Valor un:" << ped->valor_item[j] << "Valor itens: " << ped->valor_vezes[j] << endl;
		}
		cout << "Valor pedido total: " << ped->valor_total << endl << endl;
		valor_pedidos +=ped->valor_total;
		qntd_pecas += ped->quantidade;
		ped = ped->prox;
	}
	cout << "Valor de todas as vendas: " << valor_pedidos << endl;
	cout << "Valor pecas vendidas: " << qntd_pecas << endl;
}

void LimpaTela()
{
	system("pause");
	system("cls");
}



};
