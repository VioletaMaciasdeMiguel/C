#include <stdio.h>
#include <stdlib.h>

#define F 10
#define C 5


void de_fichero_a_matriz(char mat[F][C]);
int iguales(int cadcar1[C],int cadcar2[C]);


int main()
{
    int num, goout, k;
    char matriz[F][C], codigo[C];
    de_fichero_a_matriz(matriz);
    printf("Introduce un numero entero del 0 al 9: ");
    scanf("%s", codigo);
    while(goout==0 && k<F)
    {
        if(iguales(matriz[k][C], codigo[C])==1)
        {
            printf("El codigo morse se corresponde con el número %d", k);
            goout=1;
        }
        k++;
    }
    if(goout==1)
    {
        printf("El codigo morse no se corresponde con ningún número");
    }
    return 0;
}


void de_fichero_a_matriz(char mat[F][C])
{
    FILE *fichero;
    fichero=fopen("morse.txt", "r");
    int i, j;
    for(i=0; i<F; i++)
    {
        for(j=0; j<C; j++)
        {
            fscanf(fichero, "%c", mat[i][j]) ;
        }
    }
    fclose(fichero);
}

int iguales(int cadcar1[C],int cadcar2[C])
{
    int igual;
    int r=0, parar=0;
    while(parar==0 && r<C-1)
    {
        if(cadcar1[r]!=cadcar2[r])
        {
            parar=1;
        }
        r++;
    }
    if(cadcar1[r]==cadcar2[r] && parar==0)
    {
        igual=1;
    }
    else
    {
        igual=0;
    }
    return igual;
}
