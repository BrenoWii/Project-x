#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int main(void)

{
    setlocale(LC_ALL,"portuguese");

    int op,total,it,aux1,aux2,i1,i2,cont;
    char conj1[100][100];
    char conj2[100][100];
    char ne[100];
    char A[100];
    char B[100];

    it=0;
    aux1=0;
    aux2=0;
    cont=1;

    printf("Informe o total de entrevistados?(máx.100) ");
    scanf("%d",&total);
    printf("\n");
    printf("Qual a primeira opção de voto?(máx.100) ");
    fflush(stdin);
    gets(A);
    printf("\n");
    printf("Qual a segunda opção de voto?(máx.100) ");
    fflush(stdin);
    gets(B);

    while (it != total)
    {
        system("cls");
        printf("Qual o nome do %d° entrevistado?(máx.100) ",cont);
        fflush(stdin);
        gets(ne);
        printf("\n");

        do
        {
            system("cls");
            printf("1-%s;\n",A);
            printf("2-%s;\n",B);
            printf("3-%s e %s.\n",A,B);
            printf("Qual das opções de voto %s escolheu? ",ne);
            scanf("%d",&op);

            if((op<1) || (op>3))
               {
                   printf("\n\n");
                   printf("Essa não era uma das opções disponiveis...\n");
                   system("pause");

               }

        } while ((op<1) || (op>3));

            switch (op)
            {
            case 1:

                strcpy(conj1[aux1],ne);
                aux1++;
                break;

            case 2:

                strcpy(conj2[aux2],ne);
                aux2++;
                break;

            case 3:

                strcpy(conj1[aux1],ne);
                strcpy(conj2[aux2],ne);
                aux1++;
                aux2++;
                break;
            }


        cont++;
        it++;
    }

    do
    {
        system("cls");
        printf("1-Intercessão\n");
        printf("2-União\n");
        printf("3-Sair\n\n");
        printf("Qual operação você deseja realizar?  ");
        scanf("%d",&op);
        system("cls");

        switch (op)
        {
        case 1:
            printf("Intercessão de %s e %s\n\n",A,B);
            for(i1=0; i1<aux1; i1++)
            {
                for(i2=0; i2<aux2; i2++)
                {
                    if(strcmp(conj2[i2],conj1[i1])==0)
                    {
                        printf("%s",conj1[i1]);
                        printf("\n");
                    }
                }
            }
            printf("\n\n\n");
            system("pause");

            break;

        case 2:
            printf("União de %s e %s\n\n",A,B);
                for(i1=0;i1<aux1;i1++)
                {
                    printf("%s",conj1[i1]);
                    printf("\n");
                }

                for(i2=0;i2<aux2;i2++)
                {
                    for(i1=0;i1<=aux1;i1++)
                    {
                        if (strcmp(conj1[i1],conj2[i2])==0)
                        {
                            break;
                        }
                        else if(i1==aux1)
                        {
                            printf("%s",conj2[i2]);
                            printf("\n");
                        }
                    }
                }
            printf("\n\n\n");
            system("pause");

            break;

        case 3:
            {
                break;
            }

            default:
            {
                printf("Não e possivel realizar uma das operações com esse valor...\n");
                system("pause");
                break;
            }
        }
    } while (op!=3);

    system("cls");
    printf("Fim da execução\n\n");
    printf("Foi um prazer trabalhar com você,até nosso proximo encontro!");
    printf("\n\n\n");

    return 0;
}
