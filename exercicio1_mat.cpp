#include <iostream>
using namespace std;

int fat(long int n)
{

	if(n != 0)
	{
		return n * fat(n - 1);

	}
	else return 1;

}

int main(int argc, char *argv[])
{
	long int n,p;
	cout << "Digite o valor para n:";
	cin >> n;
	cout << "Digite o valor para p:";
	cin >> p;
	cout << "Valores salvo com sucesso!!";
	cout << "\nCalculando... " << endl;

	long long int value = fat(n) / fat(n - p);
	cout << "\nArranjo simples: " << value;

	return 0;
}
