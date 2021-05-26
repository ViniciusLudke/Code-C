#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	
	int n, p;
	long int soma = 1;
	long int soma_two = 1;
	cout << "Valor de n: ";
	cin >> n;
	cout << endl;
	cout << "Valor de p: ";
	cin >> p;
	cout << "Calculando..." << endl;
	
	int soma2;
	
	int aux = n - p;

	for(int x = n;x > 0;x--){
		
		soma = soma * x;
		
	}
	
	//cout << "valor 1 = "<<soma << endl;   	ok

	for(int y = aux;y > 0;y--){
		
		soma_two = soma_two * y;
		
	}
	//cout << "valor 2:" << soma_two << endl;		ok
	
	
	long long int somatotal = soma / soma_two;
	
	
	cout << "Fatorial: " << somatotal;

	

	
	return 0;
}