#include <stdio.h>
#include <stdlib.h> // libreria para el uso de rand()
#include <time.h> // libreria para el uso de time()
int main()
{
srand((int) time(NULL));
int num, max=100, min=0, con=1, SECRETO= rand()%100 + 1;
printf("introduce un numero entero entre %d y %d: ", min, max);
scanf ("%d",&num);
while(con<10)
{
if(num<SECRETO)
{
min=num;
printf("El numero es menor que %d \n", num);
con=con+1;
printf("introduce un numero entero entre %d y %d: ", min, max);
scanf ("%d",&num);
}
else if(num>SECRETO)
     {
     max=num;
     printf("El numero es mayor que %d\n", num);
     con=con+1;
     printf("introduce un numero entero entre %d y %d: ", min, max);
     scanf ("%d",&num);
    }
     else {printf("El número es %d has acertado al %d intento", num, con);
     con=14;
      }
if(con==10) printf("no has acertado");
}
return 0;
}
