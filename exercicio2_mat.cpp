/*Exercício 2) Faça um programa como no Exercício 1, mas utilizando a combinação
            n!
        ----------
C(n, p) = p!(n-p)! */

#include <stdio.h>
//Função que retorna n!
long long int fat_1(int n){
    if (n){
        return n * fat_1(n - 1);
    }else{
        return 1;
    }
}
//Função que retorna p!(n-p)!
long long int fat_2(int n, int p){
    long long int sub = 0, valor = 0, total = 0 , valor_p = 0;
    valor_p = fat_1(p);
    sub = n - p;
    valor =  fat_1(sub);
    total = valor_p * valor;
    return total; 
}

int main()
{
    long long int n = 0, p = 0, valor_n = 0, valor_p = 0, result = 0;
    printf("\n\nDigite um valor para n: ");
    //Exemplo entrada 5
    scanf("%lld", &n);
    printf("\n\nDigite um valor para p: ");
    //Exemplo entrada 4
    scanf("%lld", &p);
    valor_n = fat_1(n);
    valor_p = fat_2(n, p);
    result = valor_n / valor_p;
    //Saida 120
    printf("\nO valor do aranjo de %lld e %lld é %lld\n", n, p, result);
    return 0;
}