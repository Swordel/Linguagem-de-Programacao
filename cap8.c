#include<stdio.h>
#include<locale.h>

/*OBS.: Todos os programa devem ser finalizados pelo usuario.*/
#define ex2

#ifdef ex1
/*1 - Escreva um programa que receba via teclado usando ponteiros um char,
    int, long, unsigned, float, double, unsigned long e unsigned char,
    e imprima-os no video utilizando ponteiros no seguinte formato:

            10        20        30        40        50        60
    123456789012345678901234567890123456789012345678901234567890
        int                 long                unsigned
                  float               double              char
             unsigned long       unsigned char */

main(){

    char c,*pc,opcao;
    int i,*pi;
    long l,*pl; /*Inteiro longo -> long int ou long*/
    unsigned u,*pu; /*inteiro Sem sinal -> unsigned int ou unsigned*/
    float f,*pf;
    double d,*pd;
    unsigned long ul,*pul;
    unsigned char uc,*puc;

    pc = &c;
    pi = &i;
    pl = &l;
    pu = &u;
    pf = &f;
    pd = &d;
    pul = &ul;
    puc = &uc;

    do{

    printf("Char: ");
    scanf("%c",pc);
    printf("Inteiro: ");
    scanf("%d",pi);
    printf("Long: ");
    scanf("%ld",pl);
    printf("Unsigned: ");
    scanf("%u",pu);
    printf("Float: ");
    scanf("%f",pf);
    printf("Double: ");
    scanf("%lf",pd);
    printf("Unsigned Long: ");
    scanf("%lu",pul);
    getchar();
    printf("Unsigned Char: ");
    scanf("%c",puc);


    printf("\n");

    printf("         10        20        30        40        50        60        70\n");
    printf("1234567890123456789012345678901234567890123456789012345678901234567890123456789\n");
    printf("    %-11d         %-11ld         %-10u\n",*pi,*pl,*pu);
    printf("              %-9.1e           %-9.1e           %c\n",*pf,*pd,*pc);
    printf("         %-10lu          %c\n",*pul,*puc);

    printf("\nDeseja tentar novamente? Pressione S para continuar ou qualquer tecla para finalizar: ");
    scanf(" %c",&opcao);
    getchar();

    printf("\n");

    }while(opcao == 's' || opcao == 'S');
}
#endif // ex1

#ifdef ex2

/*2 - Escreva um programa que receba via teclado numeros inteiros positivos usando
    ponteiros. Quando o numero digitado for negativo o programa deve parar e calcula
    a media dos valores digitados e mostrar o resultado. Todos os calculos devem ser
    feitos usando ponteiro.
 */

int main() {

    setlocale(LC_ALL,"Portuguese");
    int num,*ponteiroNum;
    int soma, *ponteiroSoma;
    int cont, *ponteiroCont;
    float media, *ponteiroMedia;
    char c;

    // Inicialização dos ponteiros
    ponteiroNum = &num;
    ponteiroSoma = &soma;
    ponteiroCont = &cont;
    ponteiroMedia = &media;

    do{
        *ponteiroSoma = 0;
        *ponteiroCont = 0;

        printf("Digite um número (digite um número negativo para parar)\n");

        for( ; ; ){
            printf("Número: ");
            scanf("%d", ponteiroNum);

            if (*ponteiroNum < 0) {
                break;  // Sai do loop se for negativo
            }


            *ponteiroSoma = *ponteiroSoma + *ponteiroNum;
            *ponteiroCont = *ponteiroCont + 1;
        }

    // Verifica se pelo menos um número positivo foi digitado
        if (*ponteiroCont > 0) {

            *ponteiroMedia = (float)(*ponteiroSoma)/(*ponteiroCont);
            printf("\nMédia dos números positivos: %.2f\n", *ponteiroMedia);
        }else {
            printf("\nNenhum número positivo foi digitado.\n");
        }

        printf("\nDeseja realizar outra operação? Pressione S para continuar ou qualquer tecla para encerrar: ");
        scanf(" %c",&c);
        printf("\n");

    }while(c == 'S' || c == 's');
}

#endif // ex2

#ifdef ex3
/* 3 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faca uma
    funcao para compara-las usando ponteiros e retorne como resultado se
    sao IGUAIS 1 ou se sao DIFERENTES 0 para a funcao main().
    Imprima o resultado na funcao main(). Declare os vetores como variavel global */

char string1[11];
char string2[11];

int comparar(){

     char *p1,*p2;
     p1 = &string1[0]; // ou p1 = string1
     p2 = &string2[0]; // ou p2 = string2

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

    int resultado;
    char opcao;
    setlocale(LC_ALL,"Portuguese");


    do{

        printf("Digite a primeira string (até 10 caracteres): ");
        gets(string1);

        printf("Digite a segunda string (até 10 caracteres): ");
        gets(string2);

        resultado = comparar();

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


#endif // ex3

#ifdef ex4
/* 4 - Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva
    uma funcao que pesquise esta letra existe no vetor abaixo usando ponteiros.
    Imprima o resultado da pesquisa no video na funcao main(). Passe como
    informacao para a funcao a letra digitada. (utilize o comando return).
    O vetor deve ser declarado como variavel global.

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y */

char vetor[13]= {'b','d','f','h','j','k','m','o','q','s','u','w','y'};

int pesquisar(char *pletra){

    int i;
    char *pv;

    pv = &vetor[0]; // ou pv = vetor

    for(i=0;i<13;i++){
       if (*pletra == *(pv+i))
            return 1;
    }

    return 0;
}

main(){

    char letra, *pL,opcao;
    int resultado;
    setlocale(LC_ALL,"Portuguese");

    pL = &letra;

    do{
        printf("Digite uma letra: ");
        scanf("%c",pL);

        resultado = pesquisar(pL);

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
/* 5 - Com a estrutura abaixo, defina um vetor de estruturas de 4 elementos.
    Receba os dados via teclado numa funcao usando ponteiros. Imprima os dados
    recebidos no video numa funcao usando ponteiros. Utilize um comando de loop.
    O vetor de estruturas de ser declarado como variavel global
       estrutura: nome, end, cidade, estado, cep */

    struct dados{
		    char nome[20];
		    char end[20];
		    char cidade[20];
		    char estado[20];
		    char cep[11];
            };

    struct dados destinatario[4],*pd;

    void receber(){

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


    void imprimir(){

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
            receber();
            break;

         case 2:
            imprimir();
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
/* 6 - Escreva um programa com a estrutura abaixo. Receba 2 datas via teclado
    usando ponteiros. Calcule e exiba o numero de dias entre as duas datas
    usando ponteiros. Utilize um vetor de estruturas.
    	estrutura: dia, mes e ano */

 struct dados {
    int dia;
    int mes;
    int ano;
};

struct dados data [2],*p;

int Bissexto(int ano) {

   return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);

} //retorna 1 ou 0


int totalDias(){

    int i,c; //ano de referência, sendo 1583 o primeiro ano completo do calendario gregoriano
    int total[2];
    int diasPorMes[12] = { 31, 28, 31, 30, 31, 30,
                         31, 31, 30, 31, 30, 31 };

    for(c=0;c<2;c++)
    {
        total[c]= p[c].dia;

        for(i=1583; i < p[c].ano; i++){  //adiciona os dias dos anos completos
            total[c]+= Bissexto(i) ? 366 : 365; //verifica se for bissexto, se sim soma 366.
        }

        //adiciona os dias dos meses anteriores, por isso mes -1
        for(i=0; i< (p[c].mes)-1; i++){
            total[c] += diasPorMes[i];
            int Bissexto = (p[c].ano % 4 == 0 && p[c].ano % 100 != 0) || (p[c].ano % 400 == 0);
            if(i == 1 && Bissexto){ //mes == 1 é fevereiro
                total[c] +=1;
            }
        }
    }//fim for do vetor global

    return total[1]-total[0];
}

int main(){

    int cont,sub,*psub;
    char c;
    setlocale(LC_ALL,"Portuguese");

    p = data;
    psub = &sub;

   do{
        for(cont=0;cont<2;cont++){
            printf("Digite dia mês ano %s :", (cont==0) ? "inicial" : "final");
            scanf("%d %d %d",&(p+cont)->dia,&(p+cont)->mes,&(p+cont)->ano);
        }

        *psub = totalDias();

        printf("A diferença é de %d %s", *psub, (*psub<=1) ? "dia" : "dias" );

        printf("\nDeseja realizar outra operação? Pressione S para continuar ou qualquer tecla para encerrar: ");
        scanf(" %c",&c);
        printf("\n");

   }while(c == 'S' || c == 's');
}
#endif // ex6
