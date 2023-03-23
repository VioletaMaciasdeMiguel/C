#include <stdio.h>

#define N 5
#define M 7


void mostrar_sopa(char matriz[N][M]);
int buscar_palabra_horizontal(char cadenadecaracteres[M], char letras[N][M], int *cuenta);
/*se deben utilizar más funciones: */
int contar_caracteres(char p[M]);
int veces_repetida(int f, int c, int sentido);
void cambiar_minusculas_por_mayusculas(char letras[M]);

int main()
{
    int cuanto, existe;
    char sopa[N][M] ={{'A', 'A', 'P', 'E', 'P', 'A', 'P'},
                      {'B', 'N', 'O', 'T', 'R', 'P', 'Y'},
                      {'P', 'E', 'P', 'E', 'P', 'E', 'W'},
                      {'A', 'P', 'E', 'P', 'I', 'T', 'A'},
                      {'E', 'T', 'O', 'P', 'E', 'P', 'Y'},};
    mostrar_sopa(sopa);
    char palabra[M];
    printf("\nIntroduce una palabra, de %d caracteres como maximo: ", M);
    scanf("%s", palabra);//lee la palabra que hay que buscar en la sopa
    if('a'<=palabra[0]<='z')
    {
        cambiar_minusculas_por_mayusculas(palabra);
    }
    existe=buscar_palabra_horizontal(palabra, sopa, &cuanto);
    if(existe==0)
    {
        printf("No se ha encontrado la palabra");
    }
    else
    {
        printf("La palabra esta %d veces repetida en total", cuanto);
    }
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


//Funcion que pasa de minusculas a mayusulas todas o alguna letra de la palabra pasada a la funcion
void cambiar_minusculas_por_mayusculas(char letras[M])
{
    int y, longui;
    longui=contar_caracteres(letras);
    for(y=0; y<longui; y++)
    {
        if('a'<=letras[y]<='z')
        {
            letras[y]= letras[y]-'a'+'A';
        }
        else
            letras[y]=letras[y];
    }
}


//Funcion que cuenta los caracteres de una palabra
int contar_caracteres(char p[M])
{
    int counter=0, fin=0, l=0;
    while(l<M && fin==0)
    {
        counter++;
        if(p[l+1]=='\0')
        {
            fin=1;
        }
        else
            l++;
    }
    return counter;
}


//Busca la palabra horizontalmente
//Devuelve 0 si no la ha encontrado y 1 si la encuentra
int buscar_palabra_horizontal(char cadenadecaracteres[M], char letras[N][M], int *cuenta)
{
    int encontrado=0, sal, w=0, g, h, num;
    *cuenta=0;
    num=contar_caracteres(cadenadecaracteres);
        for(g=0; g<N; g++)
        {
            sal=0;
            h=0;
            while(h<M && sal==0)
            {
                   if(letras[g][h]==cadenadecaracteres[w])
                   {
                       if(cadenadecaracteres[w+1]=='\0')
                       {
                           *cuenta=*cuenta+veces_repetida(g+1, h+1, 1);
                           encontrado=1;
                           h=h-num+1;
                       }
                       w++;
                   }
                   else
                   {
                       if(M-h<num)
                       {
                           sal=1;
                       }
                       w=0;
                   }
                   h++;
            }
        }
        for(g=0; g<N; g++)
        {
            sal=0;
            h=M-1;
            while(h>=0 && sal==0)
            {
                if(letras[g][h]==cadenadecaracteres[w])
                {
                     if(cadenadecaracteres[w+1]=='\0')
                    {
                        *cuenta=*cuenta+veces_repetida(g+1, h+1, 0);
                        encontrado=1;
                        h=h+num-1;
                    }
                    w++;
                }
                else
                {
                    if(h<num)
                    {
                        sal=1;
                    }
                    w=0;
                }
                h--;
            }
            g++;
        }
    return encontrado;
}

//Funcion que escribe donde esta arepetida la palabra y el sentido y devuelve 1 cada vez que se ejecuta.
int veces_repetida(int f, int c, int sentido)
{
    int cont=1;
    if(sentido==1)
    {
        printf("La palabra esta en la fila %d, hasta la columna %d, de izquierda a derecha\n", f, c);
    }
    else
    {
        printf("La palabra esta en la fila %d, hasta la columna %d, de derecha a izquierda\n", f, c);
    }
    return cont;
}
