#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int mdcEuclid(int x, int y) //retorna o mdc
{
    for (int resto = 1; resto!=0;resto = resto)
    {
        resto = x % y;
        x = y;
        y = resto;
    }
    return x;
}


int Ciclos(int x, int y) // retorna o tamanho do array
{
    int acumulador;
    for (int resto = 1; resto!=0;resto = resto)
    {
        resto = x % y;
        x = y;
        y = resto;
        acumulador++;
    }
    return acumulador;
}

int coeficientes(int x, int y, int ciclos, int q[])
{
    int m, s, t; 
    //executa uma vez fora do loop, sem precisar do m, no caso é um set da "tabela".
    if (x % y != 0)
    {
        s = 1;
        t = q[ciclos-1];
    }       
    else //caso seja multiplo, n precisa executar
    {
        s = 0;
        t = 1;
        printf("s = %d, t  = %d\n", t, s); 
    }
    

    //pra evitar rodar o codigo em cima de q[0], checa antes
    if (ciclos - 1 != 0) 
    {
        for (int i = ciclos-1; i > 0; i--)
        {
            m = s + t*q[i-1];
            s = t;
            t = m;
            printf("s = %d, t  = %d\n", s, t); 
        }
    }

    if (mdcEuclid(x, y) == x*s - y*t)
    {
        printf("Equacao linear: %d = %dx%d - %dx%d\n", mdcEuclid(x, y), x, s, y, t);
    }
    else
    {
        printf("Equacao linear: %d = %dx%d - %dx%d\n", mdcEuclid(x, y), y, t, x, s);
    }
    
}

int main()
{
    int n1, n2, n1a, n2a, cicles;

    scanf("%d %d", &n1, &n2);
    if (n2 > n1)
    {
        int troca = n2;
        n2 = n1;
        n1 = troca;
        n1a = n1;
        n2a = n2;
    }
    else
    {
        n1a = n1;
        n2a = n2;
    }
    

    cicles = Ciclos(n1, n2);
    cicles = cicles-1;
    int quo[cicles-1];
    int resto;
    for (int i = 0; i < cicles;i++) //preenchendo o array de quocientes.
    {
        quo[i] = n1a / n2a;
        resto = n1a % n2a;
        n1a = n2a;
        n2a = resto;
    }

    coeficientes(n1, n2, cicles, quo);

    return 0;
}