#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;

typedef struct strLista
{
	int Numero;
	strLista *Proximo, *Anterior;
} Lista;
void imprimir(Lista *);
void ordem_crescente(Lista *);
Lista *head(Lista *);
int soma = 0, qtde = 0;
float media;



void imprimir(Lista *p)
{
	Lista *anterior;
	anterior = p->Anterior;
	if(p->Proximo != NULL)
	{
		imprimir(p->Proximo);
	}
	printf("Atual %d - p %p - ", p->Numero, p);
	if(anterior)
		printf("Anterior: %d", anterior->Numero);
	printf("\n");
	soma += p->Numero;
	qtde++;
}

Lista *head(Lista *li)
{

	while(li != NULL)
	{

		if(li->Anterior == NULL)
		{
			cout << "head: " << li->Numero;
			return li;
		}
		li = li->Anterior;
	}



}






int main()
{
	Lista *Raiz;
	Lista *PosicaoAtual;
	Raiz = (Lista *)malloc(sizeof(Lista));
	Raiz->Numero = 1;
	Raiz->Proximo = NULL;
	Raiz->Anterior = NULL;
	PosicaoAtual = Raiz;
	Lista * Temp;
	int valor;
	cout << "Quantos valores deseja adicionar?" << endl;
	int qntidade;
	cin >> qntidade;
	for(int i = 0; i < qntidade; i++)
	{
		Temp = (Lista *)malloc(sizeof(Lista));
		cout << "Digite um valor...\n";
		cin >> valor;
		Temp->Numero = valor;
		Temp->Proximo = NULL;
		Temp->Anterior = PosicaoAtual;
		PosicaoAtual->Proximo = Temp;
		PosicaoAtual = Temp;
	}
	printf("Chamando funcao recursiva\n\n");
	imprimir(Raiz);
	media = (float) (soma / qtde);
	printf("\n\nRetornou da funcao\n");
	printf("A media eh: %.2f\n", media);
	system("PAUSE");
	cout << "Head";
	head(Raiz);

	cout << "Ordem crescente...\n\n";
	ordem_crescente(Raiz);
	return 0;
}

void ordem_crescente(Lista *p)
{

	Lista *aux = head(p);
	cout << "Head 1:" << aux->Numero << endl;

	Lista *aux2 = head(p);
	cout << "Head 2:" << aux2->Numero << endl;

	int new_num;
	//verifica se é null
	if(p == NULL && p->Anterior == NULL && p->Proximo == NULL && p->Numero == NULL)
	{

		cout << "Lista vazia...";

	}

	else
	{

		cout << "Ordenando lista em ordem crescente(MENOR PARA O MAIOR)";
		while(aux)
		{
			
			aux2 = aux->Proximo;
			while(aux2)
			{

				if(aux->Numero > aux2->Numero)
				{
					new_num = aux->Numero;
					aux->Numero = aux2->Numero;
					aux2->Numero = new_num;
				}

				aux2 = aux2->Proximo;
			}

			cout << "Valor:" << aux->Numero << endl;

			aux = aux->Proximo;
		}

	}//else

}


