#include <stdio.h>
#include <rpc/rpc.h>
#include <stdlib.h>
#include <string.h>
#define cadprog ((u_long)150000)
#define cadver    ((u_long)1)
#define cadproc ((u_long)1)

main(argc, argv)
   int argc;
   char *argv[];
{
   char* innumber = malloc(64);
   char* outnumber = malloc(64);
   int error;
   int on = 1;
   while(on ==1){
        printf("Selecione a opcao desejada \n");
        printf("1 - Armazenar / Atualizar \n");
        printf("2 - Remover um registro \n");
        printf("3 - Acessar um registro \n");
        printf("4 - Finalizar aplicacao \n");
        int opcao;
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
            {
                setbuf(stdin, NULL);
                char nome[50];
                char telefone[50];
                char final[100];
                printf("\n\n Opcao escolhida: Armazenar / Atualizar um registro \n");
                printf("Entre com o nome do contato ");
                scanf("%[^\n]s", nome);
                setbuf(stdin, NULL);
                strcat(nome,"#");
                strcpy(final,nome);
                printf("Entre com o telefone do contato ");
                scanf("%[^\n]",telefone);
                setbuf(stdin, NULL);
                strcat(telefone,"#");
                strcat(final,telefone);
                puts(final);
                innumber = final;
                puts(innumber);
                callrpc(argv[1],cadprog,cadver,cadproc,xdr_wrapstring,&innumber,xdr_wrapstring,&outnumber);
                printf("value sent: %s   value received: %s\n", innumber, outnumber);
                break;
            }

            case 2:
            {
                printf("\n\n Opcao escolhida: Remover um registro\n");
                break;
            }
            case 3:
            {
                printf("\n\n Opcao escolhida: Acessar um registro\n");
                break;
            }
            case 4:
            {
                printf("\n\n Opcao escolhida: Finalizar Aplicacao\n");
                exit(0);
                on = 0;
                break;

            }

        }

   }

}

