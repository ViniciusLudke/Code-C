#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;
void LimpaTela()
{
	system("Pause");
	system("cls");
}


int main(int argc, char *argv[])
{


	int opc = 1;
	do
	{
		LimpaTela();
		cout << "Escolha a opcao de exercicio:" << endl;
		cout << "1 - Para exercicio 1!" << endl;
		cout << "2 - Para exercicio 2!" << endl;
		cout << "3 - Para exercicio 3!" << endl;
		cout << "0 - Para sair!" << endl;
		cout << "Digite uma opcao:";
		cin >> opc;
		LimpaTela();

		switch(opc)
		{
		case 1:
			int n, a_um, q;
			float resultado;
			cout << "QUANTIDADE DE TERMOS DO PRODUTORIO (n): ";
			cin >> n;
			cout << "DIGITE O VALOR DO PRIMEIRO TERMO (a1): ";
			cin >> a_um;
			cout << "DIGITE O VALOR DA RAZAO (q): ";
			cin >> q;
			resultado = pow(a_um, n) * pow(q, (n * (n - 1)) / 2);
			cout << "Valores escolhidos:" << endl;
			cout << "N:" << n << " | A1 :" << a_um << " | Razao:" << q << endl;
			cout << "O VALOR " << resultado << " REPRESENTA O PRODUTORIO DE " << n << " TERMOS NA PG" << endl;
			break;
		case 2:

			int a, c;
			cout << "EXERCIO 2" << endl;
			cout << "DIGITE O VALOR DO TERMO ANTECESSOR (A): ";
			cin >> a;
			cout << "DIGITE O VALOR DO TERMO SUCESSOR (C): ";
			cin >> c;
			system("cls");
			cout << "Valores escolhidos:" << endl;
			cout << "Termo A:" << a << " | Termo C:" << c << endl;
			cout << "O TERMO MEDIO (B) ENTRE " << a << " E " << c << " eh: " << sqrt(a * c) << endl;

			break;
		case 3:
			n = 0;
			resultado = 0;
			a_um = 0;
			int an;
			cout << "EXERCIO 3" << endl;
			cout << "DIGITE O VALOR DO PRIMEIRO TERMO (a1): ";
			cin >> a_um;
			cout << "QUANTIDADE DE TERMOS DA SOMA (n): ";
			cin >> n;
			cout << "DIGITE O N-ESIMO TEMO DA P.A (an): ";
			cin >> an;

			cout << "Valores:" << endl;
			cout << "A1: " << a_um << " | N: " << n << " | An: " << an << endl;
			resultado = (n * (a_um + an)) / 2;
			cout << "SOMA DOS " << n << " PRIMEIROS TERMOS DA P.A: " << resultado << endl;

			break;

		case 0:
			cout << "Volte sempre!!!" << endl;
			break;
		default:
			cout << "Opcao nao reconhecida!Tente novamente!!" << endl;
			break;
		}
	}
	while(opc != 0);

	return 0;
}
