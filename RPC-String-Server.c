#include <rpc/rpc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define intrcvprog ((u_long)150000)
#define intvers    ((u_long)1)
#define intrcvproc ((u_long)1)

main()
{
   char **intrcv(char**);

   registerrpc(intrcvprog,intvers,intrcvproc,intrcv,xdr_wrapstring,xdr_wrapstring);
   printf("String Registration with Port Mapper completed\n");
   svc_run();
   printf("Error:svc_run returned!\n");
   exit(1);
}

char **
intrcv(in)
   char **in;
{
   char *out = malloc(64);
   char manipula[101];
   char arrumando[101];
   int limitenome;
   int limitetelefone;
   char nome[50];
   char telefone[50];
   printf("string received: %s\n",*in);
   char *ptr;
   strcpy(out, *in);
   strcpy(manipula, *in);
   strcpy(arrumando, manipula);
   ptr = strchr(manipula, '#');
   if (*ptr)
      {
        printf("\n");
        limitenome = ptr - manipula;
      }
   ptr = strrchr(manipula, '#');
   if (*ptr)
      {
        printf("\n");
        limitetelefone = ptr - manipula;
      }

   int i;
   int j;
   for(i = 1 ; i < limitenome ; i++){
      printf("Posicao: %d \n",i);
      printf("Fazendo letra: %c \n",arrumando[i]);
      for(j = 0 ; j < limitenome - 1 ; j++){
         nome[j] = arrumando[i];
      }
   }
   printf("NOME: ");
   puts(nome);

   //printf("A primeira ocorrência de # é na posição %d\n",limitenome);
   //printf("Manipula: %c \n",manipula[limitenome]);
   //printf("A última ocorrência de # é na posição %d\n",limitetelefone);
   //printf("Manipula: %c \n",manipula[limitetelefone]);
   return (&out);
}


