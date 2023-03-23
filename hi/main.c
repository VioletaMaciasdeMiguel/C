#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define x 10
#define N 5

void leervec(int vecto[]);
void funcionvectpistas(int v[], int numerodeelementsdevec, int *y);
void generarvector (int y, int vector[]);
int buscarEnVect (int v[], int nElem, int num);
int generaeimprime(int vee[], int v2[]);
void escribirsecreta(int ve[]);

void main()
{
    int vec[N]={0}, v[N]={0}, poscorrect=0, cont=0;
    generarvector(N, vec);
    while(poscorrect!=5 && cont<x)
    {
        leervec(v);
        poscorrect=generaeimprime(vec, v);
        cont++;
    }
    if (cont==10)
    {
        printf("Has agotado los %d intentos\nLa combinacion secreta es: ", cont);
        escribirsecreta(vec);
    }
    else
        printf("Has acertado");
}
void leervec(int vecto[])
{
    int c=1, u=0;
    printf("introduce 5 numeros del 1 al 9 no repetidos: ");
    while(c<=N && u==0)
    {
        funcionvectpistas(vecto, c, &u);
    }

    if (u==1)
    {
        printf("Combinacion no válida, intentalo otra vez\n");
        leervec(vecto);
    }
}
int buscarEnVect (int v[], int nElem, int num)
{
    int i=0, y=0;
    while(i<nElem && y==0)
    {
        if (v[i]==num)
        {
            y=1;
        }
        i++;
    }
    if (y==0)
    {
        i=-1;
    }
    return i;
}

void funcionvectpistas (int v[], int numerodeelementsdevec, int *y)
{
 int i=0, num;
 *y=0;
 while(i<numerodeelementsdevec && *y==0)
    {
        scanf("%d",&num);
        if (buscarEnVect(v, numerodeelementsdevec, num)!=-1)
        {
            *y=1;
        }
        else if(num>9 || num<1)
        {
            *y=1;
        }
        v[i]=num;
        i++;
    }
}


void generarvector (int y, int vector[])
{
  int num, h=0, va=0, i;
  for(i=0; i<y; i++)
  {
      srand(time(NULL));
      num=rand()%9+1;
      if  (buscarEnVect (vector, N, i)==-1)
      {
          vector[i]=num;
      }
      else
      {
          while(h<x && va==0)
          {
              if  (buscarEnVect (vector, N, i)==-1)
              {
                  vector[i]=num;
                  va=1;
              }
              else if(num==9)
              {
                  num=1;
              }
              else
              {
                  num=num+1;
              h++;
              }
          }
      }

  }
}
int generaeimprime(int vee[], int v2[])
{
    int j, asterisc=0, mas=0;
    for(j=0; j<N; j++)
    {
        if(buscarEnVect(vee, N, v2[j])==-1)
        {
           if (vee[j]==v2[j])
           {
               mas=mas+1;
           }
            else
                asterisc=asterisc+1;
        }
    }
    printf("Pistas: ");
    for(j=0;j<mas;j++)
    {
        printf("+");
    }
     for(j=0;j<asterisc;j++)
    {
        printf("*");
    }
    return mas;
}
void escribirsecreta(int ve[])
{
    int j;
    for(j=0; j<N; j++)
    {
        printf("%d ", ve[j]);
    }
}
