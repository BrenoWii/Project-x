#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int selecionaVotoOpcao(A,B,C,entrevistado, param){
    int op = 0;
    system("cls");
    printf("1-%s;\n",A);
    printf("2-%s;\n",B);
    printf("3-%s;\n",C);
    printf("4-%s e %s;\n",A,B);
    printf("5-%s e %s;\n",A,C);
    printf("6-%s e %s;\n",B,C);
    printf("7-%s e %s e %s ;\n",A,B,C);
    if(param){
        printf("Em qual conjunto deseja aplica a operacao???");
    }
    printf("Qual das opções de voto %s escolheu? ",entrevistado);
    scanf("%d",&op);
    if((op<1) || (op>7)){
            printf("\n\n");
            printf("Essa não era uma das opções disponiveis...\n");
            system("pause");
    }
    return op;

}
int selecionaOperacaoOpcao(){
    int op = 0;
    system("cls");
    printf("1-Intercessão\n");
    printf("2-União\n");
    printf("3-Diferença\n");
    printf("4-Complemento\n");
    printf("5-Sair\n\n");
    printf("Qual operação você deseja realizar?  ");
    scanf("%d",&op);
    system("cls");
    if((op<1) || (op>5)){
       printf("\n\n");
       printf("Essa não era uma das opções disponiveis...\n");
       system("pause");
    }
    return op;

}

int main(void)
{
    setlocale(LC_ALL,"portuguese");

    int op,op1,total,it,aux1,aux2,aux3,i1,i2,cont;
    char conj1[100][100];
    char conj2[100][100];
    char conj3[100][100];
    char entrevistado[100];
    char A[100];
    char B[100];
    char C[100];

    it=0;
    aux1=0;
    aux2=0;
    aux3=0;
    cont=1;

    printf("Informe o total de entrevistados?(máx.100) ");
    scanf("%d",&total);
    printf("\n");
    printf("Qual o nome doprimeiro cojunto?(máx.100) ");
    fflush(stdin);
    gets(A);
    printf("\n");
    printf("Qual o nome do segundo cojunto?(máx.100) ");
    fflush(stdin);
    gets(B);
    printf("\n");
    printf("Qual o nome do terceiro cojunto?(máx.100) ");
    fflush(stdin);
    gets(C);

    while (it != total)
    {
        system("cls");
        printf("Qual o nome do %d° entrevistado?(máx.100) ",cont);
        fflush(stdin);
        gets(entrevistado);
        printf("\n");

        do
        {
            op = selecionaVotoOpcao(A,B,C,entrevistado,0);
        } while ((op<1) || (op>7));

            switch (op)
            {
            case 1:

                strcpy(conj1[aux1],entrevistado);
                aux1++;
                break;

            case 2:

                strcpy(conj2[aux2],entrevistado);
                aux2++;
                break;

            case 3:

                strcpy(conj3[aux3],entrevistado);
                aux3++;
                break;
            case 4:

                strcpy(conj1[aux1],entrevistado);
                strcpy(conj2[aux2],entrevistado);
                aux1++;
                aux2++;
                break;

            case 5:

                strcpy(conj1[aux1],entrevistado);
                strcpy(conj3[aux3],entrevistado);
                aux1++;
                aux3++;
                break;

            case 6:

                strcpy(conj2[aux2],entrevistado);
                strcpy(conj3[aux3],entrevistado);
                aux2++;
                aux3++;
                break;
            case 7:
                strcpy(conj1[aux1],entrevistado);
                strcpy(conj2[aux2],entrevistado);
                strcpy(conj3[aux3],entrevistado);
                aux1++;
                aux2++;
                aux3++;
                break;
            }

        cont++;
        it++;
    }

    do
    {
        op = selecionaOperacaoOpcao();
        op1 = selecionaVotoOpcao(A,B,C,entrevistado,1);
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
