#include <stdio.h>
#include <stdlib.h>

int sumCifras(int num1);
void funcOpcion2(int num2);
int funcOpcion3(int num3);
int valorCorrecto(int num4);
int esPrimo(int num5);
char menu();
void main()
{
    int num;
    char car;
    car=menu();
    while(car!='0')
    {
    printf("Introducir un numero: ");
    scanf("%d", &num);
    if(valorCorrecto(num)==1)
    {
    switch(car){
    case '1':
         printf("La suma de sus cifras es: %d\n\n\n",sumCifras(num));
          break;
    case '2':
          funcOpcion2(num);
          break;
     default:
         if(funcOpcion3(num)==0)
         {
             printf("No existe un número primo, cuya suma de sus cifras sea menor a 6 cifras\n\n");
         }
         else printf("el primer numero primo menor de 6 cifras que suma %d es: %d\n\n", num, funcOpcion3(num)) ; ;
    }
    fflush( stdin );
    car=menu();
    }
    }
}
int sumCifras(int num1)
{
    int x, y=0;
    x=num1;
    while(x!=0)
    {
        y=y+x%10;
        x=x/10;
    }
    return y;
}
int esPrimo(int num5)
{
     int d=2;
        while(num5%d!=0)
            {
                d++;
            }
    if(num5==d)
            {return 1;}
    else return 0;
}
void funcOpcion2(int num2)
{
    int x2, cont=0;
    x2=num2+1;
    while(cont<3)
    {
        if (esPrimo(x2)==1)
        {
            cont++;
            printf("%dº primo: %d\n", cont, x2);
        }
     x2++;
    }
    printf("\n\n");
}
int funcOpcion3(int num3)
{
    int x3;
    x3=num3+1;
    while(sumCifras(x3)!=num3)
    {
    while(esPrimo(x3)==0)
    {
        x3++;
    }
        if(sumCifras(x3)!=num3)
        {x3++;}
    }
    int zip, zap=0, cont=0;
    zip=x3;
    while(zip!=0)
    {
        zap=zap+zip%10;
        zip=zip/10;
        cont=cont++;
        if (cont=6)
        {
         zip=0;
        }
    }
    if(cont<6)
    {
       return x3;
    }
    else return 0;
}

int valorCorrecto(int num4){
    int nuevo;
while(num4<1){
printf("introduce otro numero, tiene que ser entero positivo:");
scanf("%d",nuevo);
num4=nuevo;
}
return 1;
}
char menu()
{
    char num6;
    printf(" 1. Calcular la suma de as cifras de un número.\n 2. Calcular los tres primeros números primos mayores que num.\n 3. Escribir el primer número primo cuyas cifras sumen num.\n 0. Salir.\nIntroduce un número correspondiente a una opcion: ");
    scanf("%c",&num6);
    while(num6!='1' && num6!='2' && num6!='3' && num6!='3'){
            fflush( stdin );
            printf("Numero no valido, introduce otro: ");
            scanf("%c",&num6);
    }
}
