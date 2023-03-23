#include <stdio.h>

#define N 5
#define M 7


void mostrar_sopa(char matriz[N][M]);
int buscar_palabra_horizontal();
/*se deben utilizar más funciones: */


int main()
{
    char sopa[N][M] ={{'A', 'A', 'P', 'E', 'P', 'A', 'P'},
                      {'B', 'N', 'O', 'T', 'R', 'P', 'Y'},
                      {'P', 'E', 'P', 'E', 'P', 'E', 'W'},
                      {'A', 'P', 'E', 'P', 'I', 'T', 'A'},
                      {'E', 'T', 'O', 'P', 'E', 'P', 'Y'},};
    mostrar_sopa(sopa);
    char palabra[M];
    printf("\nIntroduce una palabra, de %d caracteres como maximo: ", M);
    scanf("%s", palabra);//lee la palabra que hay que buscar en la sopa
}


//Función que permiteal usuario mostrar la sopa de letrascentrada
void mostrar_sopa(char matriz[N][M])
{
    int i, j, k;
    for(k=0; k<(80+2-2*M)/2; k++)
    {
        printf(" ");
    }
    printf("SOPA DE LETRAS\n\n");
    for(k=0; k<(80+2*2-2*M)/2; k++)
    {
        printf(" ");
    }
    for(j=0; j<M; j++)
    {
        printf("%d ", j+1);
    }
    printf("\n");
    for(i=0; i<N; i++)
    {
        for(k=0; k<(80-2*M)/2; k++)
        {
            printf(" ");
        }
        printf("%d ", i+1);
        for(j=0; j<M; j++)
        {
          printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}


//Busca la palabra horizontalmente
//Devuelve 0 si no la ha encontrado y 1 si la encuentra
int buscar_palabra_horizontal( )
{

}
