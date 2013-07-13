#include <rpc/rpc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Cadastra
#define cadprog   ((u_long)150000)
#define cadver    ((u_long)1)
#define cadproc   ((u_long)1) 
//Atualiza
#define atuaprog  ((u_long)150100)
#define atuaver   ((u_long)1)
#define atuaproc  ((u_long)1)
//Deleta
#define delprog   ((u_long)150200)
#define delver    ((u_long)1)
#define delproc   ((u_long)1)
//Consulta
#define conprog   ((u_long)150300)
#define conver    ((u_long)1)
#define conproc   ((u_long)1)


main()
{
   char **cadastro(char**);
   char **atualiza(char**);
   char **deleta(char**);
   char **consulta(char**);
   //Cadastro
   registerrpc(cadprog,cadver,cadproc,cadastro,xdr_wrapstring,xdr_wrapstring);
   //Atualiza
   registerrpc(atuaprog,atuaver,atuaproc,atualiza,xdr_wrapstring,xdr_wrapstring);
   //Deleta
   registerrpc(delprog,delver,delproc,deleta,xdr_wrapstring,xdr_wrapstring);
   //Consulta
   registerrpc(conprog,conver,conproc,consulta,xdr_wrapstring,xdr_wrapstring);

   printf("String Registration with Port Mapper completed\n");
   svc_run();
   printf("Error:svc_run returned!\n");
   exit(1);
}

char **
cadastro(in)
   char **in;
{
   char *out = malloc(64);
   char manipula[500];
   int limitenome;
   int limitetelefone;
   char nome[500];
   char telefone[500];
   printf("string received: %s\n",*in);
   char *ptr;
   strcpy(out, "sucesso");
   strcpy(manipula, *in);
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
   for(i = 0 ; i < limitenome ; i++){
         char letra = manipula[i];
         nome[i]=letra;
         
   }

   for(j = 0 ; j < limitetelefone - limitenome - 1  ; j++){
         char numero = manipula[limitenome + j + 1];
         telefone[j]=numero;
         
   }
   printf("Nome: %s \n",nome);
   printf("Telefone: %s \n",telefone);
   return (&out);
}

char **
atualiza(in)
   char **in;
{
   char *out = malloc(64);
   strcpy(out, "sucesso");
   return (&out);

}

char **
deleta(in)
   char **in;
{
   char *out = malloc(64);
   strcpy(out, "sucesso");
   return (&out);

}

char **
consulta(in)
   char **in;
{
   char *out = malloc(64);
   strcpy(out, "sucesso");
   return (&out);

}

