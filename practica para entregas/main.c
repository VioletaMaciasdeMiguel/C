#include<stdio.h>
int main()
{
    char min;
    FILE *FE;
    FILE *FM;
    FE = fopen("D:\\entrada.txt.txt", "r");
    FM = fopen("D:\\salida.txt", "w");
    fscanf(FE, "%c", &min);
    while(!feof(FE))
        {
              if(min>='a' || min<='z' || min>='A' || min<='Z')
               {fprintf(FM,"%c",min);}
               else while(min<'a' || min>'z' || min<'A' || min>'Z')
               {fprintf( FM," ");}
         fscanf(FE, "%c", &min);
         }
    fclose(FE);
    fclose(FM);
    return 0;
}
