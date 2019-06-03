#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>//necessária para usar as funções matemáticas


int selecionaVotoOpcao(int ***opcoesGeradas,int tam_v, int param)
{
    system("cls");
    int op = 0;
    double dtam_v = tam_v;
    double numero = 2.0;
    double possibilidades = pow(numero,dtam_v);

    printf("Em qual conjunto esse participante votou?");
    for (int i = 0; i < possibilidades-1; i++)
    {
        printf("\n %i - ", i+1);
        for (int j = 0; j < *opcoesGeradas[i][0]; j++)
        {
            printf("%s ", *opcoesGeradas[i][j+1]);
        }


    }
    printf("\n");
    scanf("%d",&op);
    if((op<1) || (op>7))
    {
        printf("\n\n");
        printf("Essa não era uma das opções disponiveis...\n");
        system("pause");
    }
    return op;

}
void comb(char **conjuntos,int ***opcoesGeradas, int v_bool[] , int i, int tam_v,int *contador)
{
    if (i == tam_v)
    {
        opcoesGeradas[*contador] = malloc(tam_v*sizeof(int *));
        int salvos = 0;
        for (int x =0;x<tam_v;x++)
        {
            if(v_bool[x] == 1 )
            {
                salvos++;
            }
        }
        int contadorJ = 0 ;
        for (int j = 0; j<tam_v;j++)
        {
            if(j == 0)
            {
                opcoesGeradas[*contador][contadorJ] = malloc(sizeof(int));
                *opcoesGeradas[*contador][contadorJ] = salvos;
            }

            if (v_bool[j] == 1 )
            {

                opcoesGeradas[*contador][contadorJ+1] = &conjuntos[j];
                contadorJ++;
            }

        }
        *contador = *contador+1;
    }
    else
    {
        v_bool[i] = 1;
        comb(conjuntos,opcoesGeradas,v_bool,i+1,tam_v,contador);

        v_bool[i] = 0;
        comb(conjuntos,opcoesGeradas,v_bool,i+1,tam_v,contador);

    }
}
int ***gerarOpcoes (char** conjuntos,int numeroConjuntos)
{
    double numero = 2;
    double DnumeroConjuntos = numeroConjuntos;
    double teste =  pow(numero,DnumeroConjuntos);
    int ***opcoesGeradas = malloc((teste -1) * sizeof(int)) ;
    int contador = 0;
    int *ponteiro = &contador;
    int v_bool[(int)numeroConjuntos];
    for (int i = 0;  i< numeroConjuntos; i++ )
    {
        v_bool[i] = 0;
    }
    comb(conjuntos,opcoesGeradas,v_bool,0,numeroConjuntos,ponteiro);

    return opcoesGeradas;
}
int selecionaOperacaoOpcao()
{
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
    if((op<1) || (op>5))
    {
        printf("\n\n");
        printf("Essa não era uma das opções disponiveis...\n");
        system("pause");
    }
    return op;

}

char **getConjuntos(int numeroConjuntos)
{
    char **conjuntos = malloc(sizeof(char *) * 100);
    for (int i = 0; i < numeroConjuntos; i++)
    {
        char nome[100];
        int count = 0;
        printf("Digite o nome do %d conjunto:\n",i+1);
        fflush(stdin);
        gets(nome);
        for(count = 0; nome[count] != '\0'; ++count);
        conjuntos[i] = malloc(sizeof(char *)* count);
        conjuntos[i] = strcpy(conjuntos[i], nome);

    }
    return conjuntos;
}
void processaSelecaoConjunto (int op,int ***resultados,char entrevistado,char **conjuntos,int ***opcoesGeradas,int numeroConjuntos)
{
    int posicoes = *opcoesGeradas[op-1][0];
    resultados = malloc(sizeof(conjuntos)* numeroConjuntos);
    for(int i= 0; i<numeroConjuntos; i++ )
    {
        resultados[i] = malloc(sizeof(conjuntos)* numeroConjuntos);
        for (int j = 0 ; j < posicoes; j++)
        {
            if(j == 0)
            {
                resultados[i][j] = malloc(sizeof(conjuntos)* numeroConjuntos);
                *resultados[i][j] = 0;
            }
            if(conjuntos[i] == *opcoesGeradas[op-1][j+1])
            {

                *resultados[i][0] = *resultados[i][0] + 1;
                *resultados[i][*resultados[i][0]] = entrevistado;
                printf("%s", conjuntos[i]);
                printf("%s", *opcoesGeradas[op-1][j+1]);



            }
        }
        resultados[i] = malloc(sizeof(char *)* numeroConjuntos);
    }



}
int main(void)
{
    setlocale(LC_ALL,"portuguese");
    int op,total,it,aux1,aux2,aux3,cont;
    int ***resultados;
    char entrevistado[100];
    int  numeroConjuntos = 0;

    it=0;
    aux1=0;
    aux2=0;
    aux3=0;
    cont=1;

    printf("Informe o total de entrevistados?(máx.100) ");
    scanf("%d",&total);
    printf("\n");
    printf("Quantos cojuntos você irá trabalhar??(máx.100) ");
    fflush(stdin);
    scanf("%d",&numeroConjuntos);
    printf("\n");
    char **conjuntos = getConjuntos(numeroConjuntos);
    int ***opcoesGeradas = gerarOpcoes(conjuntos,numeroConjuntos);

    double numero = 2;
    double DnumeroConjuntos = numeroConjuntos;
    double combinacoes =  pow(numero,DnumeroConjuntos) -1;


    while (it != total)
    {
        system("cls");
        printf("Qual o nome do %d° entrevistado?(máx.100) ",cont);
        fflush(stdin);
        gets(entrevistado);
        printf("\n");

        do
        {

            op = selecionaVotoOpcao(opcoesGeradas,numeroConjuntos,0);
        }
        while ((op<1) || (op > combinacoes));
        processaSelecaoConjunto(op,resultados,entrevistado,conjuntos,opcoesGeradas,numeroConjuntos);
    }

    do
    {
        op = selecionaOperacaoOpcao();

    }
    while (op!=3);

    system("cls");
    printf("Fim da execução\n\n");
    printf("Foi um prazer trabalhar com você,até nosso proximo encontro!");
    printf("\n\n\n");

    return 0;

}

void processaIntercessao(char* A,char* B,char* C,char** conj1,char** conj2,char** conj3,int aux1,int aux2,int aux3)
{
    printf("Intercessão de %s e %s \n\n",A,B);
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

    printf("Intercessão de %s e %s\n\n",A,C);
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

    printf("Intercessão de %s e %s\n\n",B,C);
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

    printf("Intercessão de %s e %s  e %s \n\n",A,B,C);
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

void processaUniao(char* A,char* B,char* C,char** conj1,char** conj2,char** conj3,int aux1,int aux2,int aux3)
{
    printf("União de %s e %s\n\n",A,B);
    for(int i1=0; i1<aux1; i1++)
    {
        printf("%s",conj1[i1]);
        printf("\n");
    }

    for(int i2=0; i2<aux2; i2++)
    {
        for(int i1=0; i1<=aux1; i1++)
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
}
