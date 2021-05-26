#include <iostream>
#include <list>
#include <algorithm>//find
#include <stack>//pilha

using namespace std;

// v = vertices

//1

class Grafo
{

	int v;//num vertices
	list<int> *adj;//declaro ponteiro para array contendo minha lista de adjacencia

public:
	Grafo(int v);//construtor
	void adicionaAresta(int v1, int v2);//nome ja diz...adiciona aresta no meu grafo
	void dfs(int v);//faz uma dfs a partir de um vertice(busca em profundidade)
};

Grafo::Grafo(int v)
{

	this->v = v;
	adj = new list<int>[v];

}
//finl do 1
//2
void Grafo::adicionaAresta(int v1, int v2)
{
	//Adiciona v�rtice v2 � lista de vertices adjacente de v1

	adj[v1].push_back(v2);//adiciona depois de v1(push_BACK)

}

//final 2

//3
void Grafo::dfs(int v)
{
	stack<int> pilha;//usa-se pilha para fazer (a volta)
	bool visitados[v]; // vetor de visitados, para saber quais ja foram...


	//dfs, caso true
	while(true)
	{
  
		if(visitados[v] == false)//se n�o foi visitado
		{
			cout << "visitando vertice " << v << "...\n";
			visitados[v] = true;//indico como visitado...
			pilha.push(v);//insere valor na pilha
		}

		bool achou = false;
		list<int>::iterator it;


		//busca por um ramo(vizinho) n visitado
		for(it = adj[v].begin(); it != adj[v].end(); it++)//lista minha = adj[]
		{
			if(visitados[*it] == false)//se n foi visitado
			{

				achou = true;
				break;
			}
		}

		if(achou == true) //se achou = true
		{
			v = *it;//atualiza o "v" vertice
		}

		else
		{
			//se todos os vizinhos est�o vizitados ou n existe mais vertices vizinhos
			pilha.pop();


			//testo se as pilha ficar vazia, acaba a busca
			if(pilha.empty())
				break;//se ta vazia sai do loop

			//se chegou ate aqui posso pegar o elem do topo
			v = pilha.top();
		}
	}

}

//final 3


int main(int argc, char *argv[])
{

	int V = 8;
	//cria grafo
	Grafo grafo(V);

	//insere arestar no grafo



	grafo.adicionaAresta(0, 1);
	grafo.adicionaAresta(0, 2);
	grafo.adicionaAresta(1, 3);
	grafo.adicionaAresta(1, 4);
	grafo.adicionaAresta(2, 5);
	grafo.adicionaAresta(2, 6);
	grafo.adicionaAresta(6, 7);




	grafo.dfs(0);



	return 0;
}
