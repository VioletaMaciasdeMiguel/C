#include <stdio.h>
#define N 5
int buscarEnVect (int v[], int nElem, int num);
int main ()
{
    int vect[] = {3, 4, 2, 1, 9};
    int num = 7;
    if (buscarEnVect(vect, N, num)== -1)
        printf ("El numero %d no existe en el vector", num);
    else printf ("El numero %d existe en el vector", num);
    return 0;
}
int buscarEnVect (int v[], int nElem, int num)
{
    int i=0, x=0;
    while(i<nElem && x==0)
    {
       if (v[i]==num)
       {
          x=1;
       }
       i++;
    }
    if (x==0)
    {
        i=-1;
    }
    return i;
}


