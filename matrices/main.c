#include <stdio.h>
#define Tmax 5

void escribirMat (int m[Tmax][Tmax]);
int leerMat (FILE *F, int m[Tmax][Tmax]);
int main()
{
   int matriz[Tmax][Tmax];
   int x;
   FILE *Fich;
   Fich=fopen("datosm.txt","r");
   if(Fich==NULL)
          printf("No se ha podido acceder al fichero");
   else {
             x=leerMat(Fich, matriz);
             if(x==0)
             {
                printf("ERROR: en el fichero hay menos de %d x %d valores", Tmax, Tmax);
             }
             else
             {
                 escribirMat(matriz);
             }
        }
   fclose(Fich);
}

void escribirMat (int m[Tmax][Tmax])
{
    FILE *fichero;
    fichero=fopen("gu.txt","w");
    int fila, columna;
    for(fila=0;fila<Tmax;fila++)
    {
        for(columna=0;columna<Tmax;columna++)
        {
            fprintf(fichero,"%d ", m[fila][columna]);
        }
    }
    fclose(fichero);
}

int leerMat (FILE *F, int m[Tmax][Tmax])
{
    int num, f=0, enc=1, ter=0,cont=0, c=0;
                while (f<Tmax  && ter==0)
                {
                  while(c<Tmax && ter==0)
                    {
                     if(feof(F)!=0)
                      {
                        ter=1;
                      }
                      else
                      {
                          fscanf(F, "%d", &num);
                          m[f][c]=num;
                          cont++;
                          c++;
                      }
                    }
                    c=0;
                    f++;
               }
if(cont<Tmax*Tmax)
{
   enc=0;
}
    return enc;
}
