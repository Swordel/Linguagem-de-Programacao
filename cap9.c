#include <stdio.h>
#include<locale.h>

#define ex3
/* OBS.: Todos os programa devem ser finalizados pelo usuario. */

#ifdef ex1
/* 1 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    A estrutura e' uma variavel LOCAL na funcao main(). Receba via teclado o
    conteudo de cada um dos membros numa funcao e imprima-os no video no
    seguinte formato, tambem numa funcao.

    estrutura: char, int, long, float, double, unsigned char, unsigned int,
    unsigned long

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long */

  struct estrutura{

        char caractere;
        int inteiro;
        long longo;
        float flutuante;
        double duplo;
        unsigned char uncaractere;
        unsigned int uninteiro;
        unsigned long unlongo;
    };

void receber_dados(struct estrutura *dados){

        printf("Char: ");
        scanf(" %c",&dados->caractere);
        printf("Int: ");
        scanf("%d",&dados->inteiro);
        printf("Long: ");
        scanf("%ld",&dados->longo);
        printf("Float: ");
        scanf("%f",&dados->flutuante);
        printf("Double: ");
        scanf("%lf",&dados->duplo);
        getchar();
        printf("Unsigned Char: ");
        scanf("%c",&dados->uncaractere);
        printf("Unsigned Int: ");
        scanf("%u",&dados->uninteiro);
        printf("Unsigned Long: ");
        scanf("%lu",&dados->unlongo);
        printf("\n");

    }

    void imprimir_dados(struct estrutura *dados){

     printf("         10        20        30        40        50        60        70\n");
     printf("1234567890123456789012345678901234567890123456789012345678901234567890123456789\n");
     printf("    %c         %-11d   %-11ld     %-9.1e           %-9.1e\n",dados->caractere,dados->inteiro,dados->longo,dados->flutuante,dados->duplo);
     printf("          %c                   %-10u          %-10lu\n",dados->uncaractere,dados->uninteiro,dados->unlongo);

    }

int main(){

    struct estrutura regua;
    struct estrutura *dados;
    char c;

    setlocale(LC_ALL,"Portuguese");
    dados = &regua;

    do{

    receber_dados(dados);
    imprimir_dados(dados);

        printf("\nDeseja realizar outra operação? Pressione S para continuar ou qualquer tecla para encerrar: ");
        scanf(" %c",&c);
        printf("\n");

   }while(c == 'S' || c == 's');


}
#endif // ex1

#ifdef ex2
/* Escreva um programa que receba em uma funcao 2 strings de ate' 10 caracteres
    passando como parametro ponteiro.
    Os vetores devem ser declarados como variaveis LOCAIS na funcao main().
    Escreva uma funcao para comparar as 2 strings. Passe como parametros para
    a funcao as 2 strings usando ponteiros e retorne como resultado se IGUAIS 1
    ou se DIFERENTES 0. Mostre o resultado no video na funcao main(). */


void receber (char *p1,char *p2){

        printf("Digite a primeira string (até 10 caracteres): ");
        gets(p1);

        printf("Digite a segunda string (até 10 caracteres): ");
        gets(p2);
}

int comparar(char *p1,char *p2){

     int i = 0;

     while (p1[i] != '\0' && p2[i] != '\0') {

        if (p1[i] != p2[i])
            return 0; // Strings são diferentes

        i++;
     }

    // Verifica se as duas strings terminaram ao mesmo tempo
    // (se uma terminou antes, elas têm tamanhos diferentes e são diferentes)
    if (p1[i] == '\0' && p2[i] == '\0')
        return 1; // Strings são iguais
    else
        return 0; // Strings são diferentes (tamanhos diferentes)
}

main (){

    char string1[11];
    char string2[11];
    char *p1,*p2, opcao;
    int resultado;
    setlocale(LC_ALL,"Portuguese");

    p1 = &string1[0]; // ou p1 = string1
    p2 = &string2[0]; // ou p2 = string2


    do{
        receber(p1,p2);

        resultado = comparar(p1,p2);

        if (resultado == 1)
            printf("Resultado: 1 (IGUAIS)\n");
        else
            printf("Resultado: 0 (DIFERENTES)\n");

        printf("\nDigite 'S' para tentar novamente ou pressione qualquer outra tecla para encerrar.\n");
        scanf(" %c",&opcao);
        getchar();
        printf("\n");

    }while(opcao == 'S' || opcao == 's');
}

#endif // ex2

#ifdef ex3
/* 3 - Escreva um programa que receba n valores via teclado e receba tambem a
    operacao a ser executada. Quando for digitado "=" o programa deve mostrar
    o resultado acumulado dos n valores. As operacoes aritmeticas e a entrada
    de dados devem ser funcoes que recebe os valores usando ponteiros.
    As variaveis sao LOCAIS na funcao main().*/


    void soma (float *pN, float *pR){

        *pR = *pR + *pN;
    }

    void sub(float *pN, float *pR){

        *pR = *pR - *pN;
    }

    void mult(float *pN, float *pR){

        *pR = (*pR) * (*pN);
    }

    void div(float *pN, float *pR){
        if (*pN == 0)
            printf("Operação inválida!\n");
        else
            *pR = (*pR) / (*pN);
    }

    void entrada(float *pN){
        printf("Digite um número: ");
        scanf("%f",pN);
    }

main(){

    setlocale(LC_ALL,"Portuguese");
    char opcao,reiniciar;
    float N,*pN,resultado,*pR;

    pN = &N;
    pR = &resultado;

    do{

    entrada(pN);

    *pR = *pN;

    for(;;){

        do{
        printf("\n(+) Soma | (-) Subtração | (*) Multiplicação | (/) Divisão | (=) Igual para mostrar o resultado\n");
        printf("Escolha uma operação válida: ");
        scanf(" %c", &opcao);
        printf("\n");
        }while(opcao!= '+' && opcao!= '-' && opcao!= '*' && opcao!= '/' && opcao != '=');

        if(opcao == '=')
            break;

        entrada(pN);

        switch (opcao){

         case '+':
            soma(pN,pR);
            break;

         case '-':
            sub(pN,pR);
            break;

         case '*':
            mult(pN,pR);
            break;

         case '/':
            div(pN,pR);
            break;
         }

    }

    printf("RESULTADO = %f\n", *pR);

    printf("\nDigite 'S' para tentar novamente ou pressione qualquer outra tecla para encerrar.\n");
    scanf(" %c",&reiniciar);
    getchar();
    printf("\n");

    }while(reiniciar == 'S' || reiniciar == 's');

}
#endif // ex3

#ifdef ex4
/* 4 - Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva
    uma funcao que pesquise se esta letra existe no vetor abaixo usando ponteiros.
    Imprima o resultado da pesquisa no video na funcao main(). Passe como informacao
    para a funcao a letra digitada e o vetor usando ponteiros e faca a pesquisa
    usando ponteiros.(utilize o comando return).
    O vetor deve ser declarado como variavel LOCAL na funcao main().

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y */


int pesquisar(char *pletra, char *pv){

    int i;

    for(i=0;i<13;i++){
       if (*pletra == *(pv+i)) //pv[i]
            return 1;
    }

    return 0;
}

main(){

    char vetor[13]= {'b','d','f','h','j','k','m','o','q','s','u','w','y'};
    char *pv;
    char letra, *pL,opcao;
    int resultado;
    setlocale(LC_ALL,"Portuguese");

    pL = &letra;
    pv = &vetor[0]; // ou pv = vetor

    do{
        printf("Digite uma letra: ");
        scanf("%c",pL);

        resultado = pesquisar(pL,pv);

        if (resultado == 1)
            printf("A letra '%c' existe no vetor!",*pL);
        else
            printf("A letra '%c' NÃO existe no vetor!",*pL);

        printf("\n\nDeseja realizar outra operação? Pressione S para continuar ou qualquer tecla para encerrar: ");
        scanf(" %c",&opcao);
        getchar();
        printf("\n");

   }while(opcao == 'S' || opcao == 's');

}
#endif // ex4

#ifdef ex5
/* 5 - Escreva um programa com a estrutura abaixo. Defina um vetor de estruturas
    de 4 elementos como variavel LOCAL na funcao main(). Receba os 4 registros
    sequencialmente pelo teclado numa funcao e imprima todos os registros no
    video em outra funcao. Faca um menu. Utilize ponteiros nas funcoes.
    Coloque no menu a opcao de sair tambem. Utilize o comando switch.
    (vetor de estruturas)
     estutura: nome, end, cidade, estado, cep */

struct dados{
		    char nome[20];
		    char end[20];
		    char cidade[20];
		    char estado[20];
		    char cep[11];
            };

void receber(struct dados *pd){

    int cont;
    for(cont=0;cont<4;cont++)
    {
        printf("Nome: ");
        gets((pd+cont) -> nome);
        printf("Endereço: ");
        gets((pd+cont) -> end);
        printf("Cidade: ");
        gets((pd+cont) -> cidade);
        printf("Estado: ");
        gets((pd+cont) -> estado);
        printf("CEP: ");
        gets((pd+cont) -> cep);
        printf("\n");
    }
    }


    void imprimir(struct dados *pd){

    int cont;

    for(cont=0;cont<4;cont++)
    {
        printf("\nNome: %s",(pd+cont) -> nome);
        printf("\nEndereço: %s",(pd+cont) -> end);
        printf("\nCidade: %s",(pd+cont) -> cidade);
        printf("\nEstado: %s",(pd+cont) -> estado);
        printf("\nCEP: %s\n\n",(pd+cont) -> cep);
    }

    }

    main(){

         struct dados destinatario[4];
         struct dados *pd;

         int opcao;
         setlocale(LC_ALL,"Portuguese");

         pd = &destinatario[0]; //ou simplificado: pd = destinatario

         for(;;){

         printf("Escolha uma opção: \n");
         printf("1 - Digitar Dados \n2 - Imprimir Dados \n3 - Finalizar\n");
         scanf("%d",&opcao);
         getchar();
         printf("\n");

         switch (opcao){

         case 1:
            receber(pd);
            break;

         case 2:
            imprimir(pd);
            break;

         case 3:
            exit(0);

         default:
            printf("Opção inválida");
            break;
         }
         }//fim loop infinito
}
#endif // ex5

#ifdef ex6
/* 6 - Acrescente ao menu do exercicio anterior as funcoes de procura, altera e
    exclui um registro sempre usando ponteiros.*/

struct dados{
		    char nome[20];
		    char end[20];
		    char cidade[20];
		    char estado[20];
		    char cep[11];
};

void receber(struct dados *pd){

    int cont;
    for(cont=0;cont<4;cont++)
    {
        printf("Nome: ");
        gets((pd+cont) -> nome);
        printf("Endereço: ");
        gets((pd+cont) -> end);
        printf("Cidade: ");
        gets((pd+cont) -> cidade);
        printf("Estado: ");
        gets((pd+cont) -> estado);
        printf("CEP: ");
        gets((pd+cont) -> cep);
        printf("\n");
    }
}

void imprimir(struct dados *pd){

    int cont;

    for(cont=0;cont<4;cont++)
    {
        if(pd[cont].nome[0] != '*'){
            printf("Nome: %s",(pd+cont) -> nome);
            printf("\nEndereço: %s",(pd+cont) -> end);
            printf("\nCidade: %s",(pd+cont) -> cidade);
            printf("\nEstado: %s",(pd+cont) -> estado);
            printf("\nCEP: %s\n\n",(pd+cont) -> cep);
        }
    }
}


int procurar (struct dados *pd){
    char busca[20];
    int l,c; // l - > linha (os 4 nomes) e c -> coluna (letras do vetor nome)

    printf("Digite o nome que deseja: ");
    gets(busca);

    for(l=0;l<4;l++){
        for(c=0;busca[c]!='\0';c++){
            if (busca[c] != pd[l].nome[c])
                break;
        } //fim for coluna

        if(busca[c] == '\0' && pd[l].nome[c] == '\0'){
            printf("\nNome: %s",(pd+l)-> nome);
            printf("\nEndereço: %s",(pd+l) -> end);
            printf("\nCidade: %s",(pd+l) -> cidade);
            printf("\nEstado: %s",(pd+l) -> estado);
            printf("\nCEP: %s\n\n",(pd+l) -> cep);
            return l;
        }//retorna o índice

    }// fim for linha~estrutura

    if(l==4){
        printf("Destinatário não encontrado!\n\n");
        return -1; //retorna o 4 para ser excluído
    }
}

void alterar(struct dados *pd){

    int indice;

    printf("- ALTERAR DADOS -\n");
    indice = procurar(pd);

    if(indice != -1){
            printf("Nome Atualizado: ");
            gets((pd+indice) -> nome);
            printf("Endereço: ");
            gets((pd+indice) -> end);
            printf("Cidade: ");
            gets((pd+indice) -> cidade);
            printf("Estado: ");
            gets((pd+indice) -> estado);
            printf("CEP: ");
            gets((pd+indice) -> cep);
            printf("\n");
    }
}

void excluir(struct dados *pd){

    int indice;

    printf("- EXCLUIR-\n");
    indice = procurar(pd);

    if(indice != -1){
            pd[indice].nome[0]='*';
            printf("Dados do destinatário acima excluídos com sucesso!\n\n");
    }
}

main(){

         struct dados destinatario[4];
         struct dados *pd;
         int opcao;
         setlocale(LC_ALL,"Portuguese");

         pd = &destinatario[0]; //ou simplificado: pd = destinatario

         for(;;){

         printf("1 - Digitar Dados \n2 - Imprimir Dados \n3 - Procurar nome \n4 - Alterar dados \n5 - Excluir Dados \n6 - Finalizar\n");
         printf("Escolha uma opção: ");
         scanf("%d",&opcao);
         getchar();
         printf("\n");

         switch (opcao){

         case 1:
            receber(pd);
            break;

         case 2:
            imprimir(pd);
            break;

         case 3:
            procurar(pd);
            break;

         case 4:
            alterar(pd);
            break;

         case 5:
            excluir(pd);
            break;

         case 6:
            printf("Saindo...\n");
            exit(0);

         default:
            printf("Opção inválida");
            break;
         }
         }//fim loop infinito
}
#endif // ex6
