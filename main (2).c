#include <stdio.h>
#define Tmax 5

void escribirMat (int m[Tmax][Tmax]);
void leerMat (FILE *F, int m[Tmax][Tmax]);
int sumaColumna(int param, int m[Tmax][Tmax]);
int main()
{
   int matriz[Tmax][Tmax], i, var;

   FILE *Fich;
   Fich=fopen("datosm.txt","r");
   if(Fich==NULL)
          printf("No se ha podido acceder al fichero");
   else {
             leerMat (Fich, matriz);
             escribirMat (matriz);
        }
   fclose(Fich);
   printf("\n");
   for(i=0;i<Tmax;i++)
    {
        var=sumaColumna(i,matriz);
        printf("Suma de la columna %d: %d\n", i, var);
    }
    var=sumaColumna(i,matriz);
    printf("Suma de la columna %d: %d\n", i, var);
}

void escribirMat (int m[Tmax][Tmax])
{
    int fila, columna;
    for(fila=0;fila<Tmax;fila++)
    {
        printf("\n");
        for(columna=0;columna<Tmax;columna++)
        {
            printf("%d ", m[fila][columna]);
        }
    }
}

void leerMat (FILE *F, int m[Tmax][Tmax])
{
    int num, f, c;
    for (f=0; f<Tmax; f++)
    {
        for(c=0; c<Tmax; c++)
        {
            fscanf(F, "%d", &num);
            m[f][c]=num;
        }
    }
}

int sumaColumna(int param, int m[Tmax][Tmax])
{
    int i, suma=0;
    for(i=0;i<Tmax;i++)
    {
            suma=suma+m[i][j];
    }
    return suma;
}
