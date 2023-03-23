#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define N 10
void borraElem (int v[], int pos, int *longi);
int buscarMax (int v[], int longi);
void llenaVect (int v[N]);
int main()
{
    int vecorig[N], i, n, posicion, j, max;
    llenaVect (vecorig);
    printf("vector original: ");
    for(i=0; i<N; i++)
    {
        printf("%d", vecorig[i];
    }
    n=N
    max=buscarMax(vecorig, N);
    while(j<n)
    {
        j=0
        if(vecorig[j]==max)
        {
            posicion=j;
            borraElem(vecorig, posicion, *n)
        }
        j++
    }

    return 0;
}

void borraElem (int v[], int pos, int *longi)
{
    int w;
    v[pos]={ };
    for(w=0; w<N; w++)
    {
        v[pos+w]=v[pos+w+1]
    }
    *longui= N-1
}

int buscarMax (int v[], int longi)
{
    int k, variable=0;
    for(k=0; k<longi; k++)
    {
        if(variable<v[k])
        {
            variable=v[k];
        }
    }
    return variable;
}

void llenaVect (int v[N])
{
    int i, num;
    for(i=0; i<N; i++)
    {
        srand(time(NULL));
        num=rand()%30+1;
        v[i]=num
    }
}
