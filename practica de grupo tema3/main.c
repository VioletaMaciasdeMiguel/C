#include <stdio.h>
#include <stdlib.h>
int main()
{
int num, primo = 0, factor = 2;
printf("Introduce una secuencia de numeros enteros positivos en una linea, separados por blancos y acaba con un 0 y pulsa intro:\n");
scanf("%d", &num);
while(num != 0)
{
while(factor < num)
{
if(num % factor != 0)
factor++;
else
factor = num + 1;
}
if(primo == 0 && num / factor == 1)
{
primo = num;
}
factor = 2;
scanf("%d", &num);
}
if(primo == 0)
printf("\nNo hay ningun primo.\n");
else
printf("\n %d es el primer primo.\n", primo);
return 0;
}
