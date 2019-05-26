#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int selecionaVotoOpcao(A,B,C,entrevistado,param){
    int op = 0;
    system("cls");
    printf("1-%s;\n",A);
    printf("2-%s;\n",B);
    printf("3-%s;\n",C);
    printf("4-%s e %s;\n",A,B);
    printf("5-%s e %s;\n",A,C);
    printf("6-%s e %s;\n",B,C);
    printf("7-%s e %s e %s ;\n",A,B,C);
    printf("Qual das op��es de voto %s escolheu? ",entrevistado);

    scanf("%d",&op);
    if((op<1) || (op>7)){
            printf("\n\n");
            printf("Essa n�o era uma das op��es disponiveis...\n");
            system("pause");
    }
    return op;

}
int selecionaOperacaoOpcao(){
    int op = 0;
    system("cls");
    printf("1-Intercess�o\n");
    printf("2-Uni�o\n");
    printf("3-Diferen�a\n");
    printf("4-Complemento\n");
    printf("5-Sair\n\n");
    printf("Qual opera��o voc� deseja realizar?  ");
    scanf("%d",&op);
    system("cls");
    if((op<1) || (op>5)){
       printf("\n\n");
       printf("Essa n�o era uma das op��es disponiveis...\n");
       system("pause");
    }
    return op;

}

int main(void)
{
    setlocale(LC_ALL,"portuguese");
    int op,op1,total,it,aux1,aux2,aux3,i1,i2,cont;
    char ** conj1 = malloc(sizeof(char *) * 100);
    char ** conj2 = malloc(sizeof(char *) * 100);
    char ** conj3 = malloc(sizeof(char *) * 100);
    char entrevistado[100];
    char A[100];
    char B[100];
    char C[100];

    it=0;
    aux1=0;
    aux2=0;
    aux3=0;
    cont=1;

    printf("Informe o total de entrevistados?(m�x.100) ");
    scanf("%d",&total);
    printf("\n");
    printf("Qual o nome do primeiro cojunto?(m�x.100) ");
    fflush(stdin);
    gets(A);
    printf("\n");
    printf("Qual o nome do segundo cojunto?(m�x.100) ");
    fflush(stdin);
    gets(B);
    printf("\n");
    printf("Qual o nome do terceiro cojunto?(m�x.100) ");
    fflush(stdin);
    gets(C);

    while (it != total)
    {
        system("cls");
        printf("Qual o nome do %d� entrevistado?(m�x.100) ",cont);
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
                conj1[aux1] = malloc(sizeof(char *) * 100);
                strcpy(conj1[aux1],entrevistado);
                aux1++;
                break;

            case 2:
                conj2[aux2] = malloc(sizeof(char *) * 100);
                strcpy(conj2[aux2],entrevistado);
                aux2++;
                break;

            case 3:
                conj3[aux3] = malloc(sizeof(char *) * 100);
                strcpy(conj3[aux3],entrevistado);
                aux3++;
                break;
            case 4:
                conj1[aux1] = malloc(sizeof(char *) * 100);
                conj2[aux2] = malloc(sizeof(char *) * 100);
                strcpy(conj1[aux1],entrevistado);
                strcpy(conj2[aux2],entrevistado);
                aux1++;
                aux2++;
                break;

            case 5:
                conj1[aux1] = malloc(sizeof(char *) * 100);
                conj3[aux3] = malloc(sizeof(char *) * 100);

                strcpy(conj1[aux1],entrevistado);
                strcpy(conj3[aux3],entrevistado);
                aux1++;
                aux3++;
                break;

            case 6:
                conj2[aux2] = malloc(sizeof(char *) * 100);
                conj3[aux3] = malloc(sizeof(char *) * 100);

                strcpy(conj2[aux2],entrevistado);
                strcpy(conj3[aux3],entrevistado);
                aux2++;
                aux3++;
                break;
            case 7:
                conj1[aux1] = malloc(sizeof(char *) * 100);
                conj2[aux2] = malloc(sizeof(char *) * 100);
                conj3[aux3] = malloc(sizeof(char *) * 100);
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
        switch (op)
        {
        case 1:
            processaIntercessao(A,B,C,conj1,conj2,conj3,aux1,aux2,aux3);

            system("pause");

            break;

        case 2:

            system("pause");

            break;

        case 3:
            {
                break;
            }

            default:
            {
                printf("N�o e possivel realizar uma das opera��es com esse valor...\n");
                system("pause");
                break;
            }
        }
    } while (op!=3);

    system("cls");
    printf("Fim da execu��o\n\n");
    printf("Foi um prazer trabalhar com voc�,at� nosso proximo encontro!");
    printf("\n\n\n");

    return 0;

}

void processaIntercessao(char* A,char* B,char* C,char** conj1,char** conj2,char** conj3,int aux1,int aux2,int aux3){
    printf("Intercess�o de %s e %s \n\n",A,B);
    for(int i1=0; i1<aux1; i1++)
    {
        for(int i2=0; i2<aux2; i2++)
        {
            if(strcmp(conj2[i2],conj1[i1])==0)
            {
                printf("%s", conj1[i1]);
                printf("\n");
            }
        }
    }
    printf("\n\n\n");

    printf("Intercess�o de %s e %s\n\n",A,C);
    for(int i1=0; i1<aux1; i1++)
    {
        for(int i2=0; i2<aux3; i2++)
        {
            if(strcmp(conj3[i2],conj1[i1])==0)
            {
                printf("%s",conj1[i1]);
                printf("\n");
            }
        }
    }
    printf("\n\n\n");

    printf("Intercess�o de %s e %s\n\n",B,C);
    for(int i1=0; i1<aux2; i1++)
    {
        for(int i2=0; i2<aux3; i2++)
        {
            if(strcmp(conj3[i2],conj2[i1])==0)
            {
                printf("%s",conj2[i1]);
                printf("\n");
            }
        }
    }

    printf("Intercess�o de %s e %s  e %s \n\n",A,B,C);
    for(int i1=0; i1<aux1; i1++)
    {
        for(int i2=0; i2<aux2; i2++)
        {
            if(strcmp(conj2[i2],conj1[i1])==0)
            {
                for(int i3=0; i3<aux3; i3++)
                {
                    if(strcmp(conj3[i3],conj2[i2])==0)
                    {
                        printf("%s",conj1[i1]);
                        printf("\n");
                    }
                }
            }
        }
    }
    printf("\n\n\n");
}

