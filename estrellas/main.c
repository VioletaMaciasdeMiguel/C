#include <stdio.h>
#include <stdlib.h>
#define N 20

void rellenaMatriz(FILE *F, int matriz[N][N]);
void creaEstrellas(int mat[N][N], char machar[N][N]);
void dibujaCielo(char mchar[N][N]);
int sionofichero(FILE *F);
void main()
{
FILE *fich;
fopen("intensidades.txt", "r");
int m[N][N];
char mc[N][N];
if(sionofichero(fich)==1)
{
    printf("introduce numeros de una matriz %d x %d", N, N);
    rellenaMatriz(fich, m);
    creaEstrellas(m, mc);
    dibujaCielo(mc);
    fclose(fich);
}
}
int sionofichero(FILE *F)
{
    int son;
    if(F==NULL)
   {
       printf("el fichero no se ha podido abrir");
       son=0;
   }
   else
   {
       son=1;
   }
return son;
}
void rellenaMatriz(FILE *F, int m[N][N])
{
int i, num, j;
for(i=0; i<N; i++)
{
for(j=0; j<N; j++)
{
fscanf(F, "%d", &num);
m[i][j]=num;
}
}
}
void creaEstrellas(int mat[N][N], char machar[N][N])
{
int esestrella=0, i, n, j, suma=0;
for(i=0; i<N; i++)
{
for(j=0; j<N; j++)
{
n=mat[i][j];
if(n!=0)
{
if(i==1 && j==1)
{
    suma=mat[2][1]+mat[2][2]+mat[1][2];
}
    else if(i==N && j==N)
    {
        suma=mat[N][N-1]+mat[N-1][N]+mat[N-1][N-1];
    }
        else if(i==1 && j==N)
        {
            suma=mat[1][N-1]+mat[2][N-1]+mat[2][N];
        }
           else if(i==N && j==1)
           {
               suma=mat[N-1][1]+mat[N-1][2]+mat[N][2];
           }
              else if(i==1)
              {
                 suma=mat[1][j-1]+mat[1][j+1]+mat[2][j-1]+mat[2][j]+mat[2][j+1];
              }
                 else if(j==1)
                 {
                      suma=mat[i][2]+mat[i-1][2]+mat[i+1][2]+mat[i-1][1]+mat[i+1][1];
                 }
                    else if(i==N)
                    {
                         suma=mat[N][j-1]+mat[N][j+1]+mat[N-1][j]+mat[N-1][j+1]+mat[N-1][j-1];
                    }
                       else if(j==N)
                       {
                            suma=mat[i-1][N]+mat[i+1][N]+mat[i-1][N-1]+mat[i][N-1]+mat[i+1][N-1];
                       }
                          else
                          {
                              suma=mat[i][j-1]+mat[i][j+1]+mat[i-1][j]+mat[i+1][j]+mat[i-1][j-1]+mat[i+1][j+1]+mat[i+1][j-1]+mat[i-1][j+1];
                          }
}
if(suma<n)
{
esestrella=1;
}

if(esestrella==1)
{
machar[i][j]='*';
}
else
{
machar[i][j]=' ';
}
}
}

}
void dibujaCielo(char mchar[N][N])
{
int i, j;
for(i=0;i<N;i++)
{
for(j=0;j<N;j++)
{
printf("%c ",mchar[i][j]);
}
printf("\n");
}
}
