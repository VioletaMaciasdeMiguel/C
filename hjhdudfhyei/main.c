#include<stdio.h>
void pasarAMayusc(char *c);
int main()
{
char min;
    FILE *FE;
    FILE *FM;
    FE = fopen(entrada.txt, r);
    FM = fopen(salida.txt, w);
    fscanf(FE, "%c", &min);
    while(!feof(FE))
        {
            pasarAMayusc(&min);
            fprintf( FM,"%c",min);
            fscanf(FE, "%c", &min);
         }
    fclose(FE);
    fclose(FM);
return 0;
}

void pasarAMayusc(char *c)
{
if (*c>='a' || *c<='z')
  {
      switch(*c){
    case 'a': *c='A';
    break;
    case 'b': *c='B';
    break;
    case 'c': *c='C';
    break;
    case 'd': *c='D';
    break;
    case 'e': *c='E';
    break;
    case 'f': *c='F';
    break;
    case 'g': *c='G';
    break;
    case 'h': *c='H';
    break;
    case 'i': *c='I';
    break;
    case 'j': *c='J';
    break;
    case 'k': *c='K';
    break;
    case 'l': *c='L';
    break;
    case 'm': *c='M';
    break;
    case 'n': *c='N';
    break;
    case '�': *c='�';
    break;
    case 'o': *c='O';
    break;
    case 'p': *c='P';
    break;
    case 'q': *c='Q';
    break;
    case 'r': *c='R';
    break;
    case 's': *c='S';
    break;
    case 't': *c='T';
    break;
    case 'u': *c='U';
    break;
    case 'v': *c='V';
    break;
    case 'w': *c='W';
    break;
    case 'x': *c='X';
    break;
    case 'y': *c='Y';
    break;
    default: *c='Z';
    }
  }
}

