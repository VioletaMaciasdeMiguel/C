#include <stdio.h>
#define TAM 10
void leerVect ( int v[TAM], int *lon);
void escribirVect (int v[TAM], int lon);
void main()
{
   int vector[TAM]={0}, longitud, variable;
   leerVect (vector, &longitud);
   variable=longitud ;
   escribirVect (vector, variable);
}

void leerVect ( int v[TAM], int *lon)
{
    int num;
    printf("Introduce numeros enteros positivos(%d como maximo) y un 0: ", TAM);
    int i=0, cont=0;
    scanf("%d", &num);
    while(num>0 && i<TAM)
        {
             v[i]=num;
             cont++;
             scanf("%d", &num);
             i++;
        }
        *lon=cont;
}
void escribirVect (int v[TAM], int lon)
{
    int j;
    printf("Has introducido estos valores:\n");
    for (j=0; j<lon; j++)
    {
        printf("%d\n",v[j]);
    }
}
