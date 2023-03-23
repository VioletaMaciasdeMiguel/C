#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define I  4

void generar_capital(FILE *c, char cap[10], char pa[10]);
void cargar_fichero(FILE *continente, int n);
void intentar_adivinar(char cap[10], char pa[10]);
int comparar(char capit[10], char capus[10]);

void main()
{
    int num, op, variable=0;
    char capital[10], pais[10];
    FILE *contin;
    printf("-----MENU-----\nElige continente\n");
    printf("        1 Europa\n");
    printf("        2 Asia\n");
    printf("        3 Africa\n");
    printf("        4 America\n");
    printf("        5 Oceania\n");
    printf("OPCION: ");
    scanf("%d", &num);
    while(num<1 || num>5)
        {
            printf("No se corresponde con ninguna opcion\nVuelvelo a intentar: ");
            scanf("%d", &num);
        }

    cargar_fichero(contin, num);
    while(contin==NULL)
    {
        printf("Esa opcionn no esta disponible\nIntroduce otra: ");
            scanf("%d", &num);
            cargar_fichero(contin, num);
    }
    generar_capital(contin, capital, pais);
    intentar_adivinar(capital, pais);

    while(variable=0)
    {
        printf("1. Mismo Continente\n2. Cambiar de continente\n0. Finalizar\n\nOPCION: ");
        scanf("%d", &op);
        while(op!=1 && op!=2 && op!=0)
        {
            printf("No se corresponde con ninguna opcion\nVuelvelo a intentar: ");
            scanf("%d", &op);
        }
        switch(op)
        {
        case 0:
            variable=1;
            break;
        case 1:
             generar_capital(contin, capital, pais);
             intentar_adivinar(capital, pais);
            break;
        case 2:
             printf("-----MENU-----\nElige continente\n");
             printf("        1 Europa\n");
             printf("        2 Asia\n");
             printf("        3 Africa\n");
             printf("        4 America\n");
             printf("        5 Oceania\n");
             printf("OPCION: ");
             scanf("%d", &num);
             while(num<1 || num>5)
                 {
                     printf("No se corresponde con ninguna opcion\nVuelvelo a intentar: ");
                     scanf("%d", &num);
                 }

             cargar_fichero(contin, num);
             while(contin==NULL)
            {
                printf("Esa opcionn no esta disponible\nIntroduce otra: ");
                scanf("%d", &num);
                cargar_fichero(contin, num);
            }
            generar_capital(contin, capital, pais);
            intentar_adivinar(capital, pais);
            break;
        default:
            printf("No se corresponde con ninguna opcion");
            break;
        }
    }
}

void cargar_fichero(FILE *continente, int n)
{
    switch(n)
    {
    case 1:
        continente=fopen("Europa.txt", "r");
        break;
    case 2:
        continente=fopen("Asia.txt", "r");
        break;
    case 3:
        continente=fopen("Africa.txt", "r");
        break;
    case 4:
        continente=fopen("America.txt", "r");
        break;
    case 5:
        continente=fopen("Oceania.txt", "r");
        break;
    }
}

void generar_capital(FILE *c, char cap[10], char pais[10])
{
    char matriz[50][10];
    int i=0, var;
    while(i<50 && !feof(c))
    {
        fscanf(c, "%s", matriz[i]);
        i++;
    }
    srand(time(NULL));
    var=rand()%i+0;
    if(var%2!=0)
    {
        var=var-1;
    }
    pais=matriz[var];
    cap=matriz[var+1];
}

void intentar_adivinar(char cap[10], char pa[10])
{
    printf("%s", pa);
    int p=1, comp=0;
    char usuario[10];
    while(p<=I && comp==0)
    {
        printf("Capital...               ");
        scanf("%s", usuario);
        comp=comparar(cap, usuario);
        if(comp==0)
        {
            printf("Respuesta incorrecta (%d/%d intentos realizados)", I, p);
        }
        p++;
    }
    if(comp==1)
    {
        printf("Felicidades!!! capital %s", cap);
    }
}

int comparar(char capit[10], char capus[10])
{
    int y=0, acaba=0, devol=0;
    while(y<10 && capit[y]==capus[y] && acaba==0)
    {
        if(capit[y]=='\0' || capus[y]=='\0')
        {
            acaba=1;
        }
        else
            y++;
    }
    if(capit[y]=='\0' && capus[y]=='\0')
    {
         devol=1;
    }
    return devol;
}
