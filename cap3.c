#include <stdio.h>
#include <locale.h>

#define ex2

#ifdef ex1
/*1 - Escreva um programa que receba dois numeros inteiros e execute as seguintes
    funçoes:
    - Verificar se o numero digitado e' positivo ou negativo. Sendo que o valor de
      retorno sera' 1 se positivo, 0 se negativo ou -1 se for igual a 0.
    - Se os 2 numeros sao positivos, retorne a soma dos N numeros existentes entre
      eles.
    - Se os 2 numeros sao negativos, retorne a multiplicacao dos N numeros existente
      entre eles.
    - Se 1. numero for positivo e o 2. negativo faca a divisao entre eles.*/

    //Se o número 1 for negativo e o número 2 positivo, o que faz?

    int pos_ou_neg(int x)
    {
        if(x<0)
            return 0;
            else if(x==0)
                return -1;
            else
                return 1;
    }//fim função que verifica se numero digitado e' positivo ou negativo

    int dois_positivos(int x, int y)
    {
        int soma=0;
        if(x<y){
                for(x=x+1;x<y;x++)
                {
                    soma+=x;
                }}//fim if->for
        else{
            for(x=x-1;y<x;x--)
                {
                    soma+=x;
                }}//fim else->for
        return soma;
    }//fim função que soma numeros existentes entre os positivos

    int dois_negativos(int x, int y)
    {
        int mult=1;
        if(x<y){
                for(x=x+1;x<y;x++)
                {
                    mult=mult*x;
                }}//fim if->for
        else{
            for(x=x-1;y<x;x--)
                {
                    mult=mult*x;
                }}//fim else->for
        return mult;
    }//fim função que soma numeros existentes entre os negativos

    float div_pos_neg(int x, int y)
    {
        float resultado;
        resultado=x/y;
        return resultado;

    }//fim função que divide a por b

    main()
    {
        int a, b;
        char retorna;
        setlocale(LC_ALL,"");

        do{ //laço 1 para deixar que usuário decida quando encerrar o programa ou não.
        do{ //laço 2 para exigir que usuário digite apenas negativos ou positivos
        printf("Informe dois números inteiros:\n");
        scanf("%d %d",&a,&b);
        if(pos_ou_neg(a)==-1||pos_ou_neg(b)==-1)
            printf("Você informou o número 0. Favor informar apenas números positivos ou negativos.\n\n");
        }while(pos_ou_neg(a)==-1||pos_ou_neg(b)==-1); //fim laço 2

        if(pos_ou_neg(a)&&pos_ou_neg(b))//Se os dois == 1 (positivos)
            printf("A soma entre os números positivos %d e %d é %d.\n",a,b,dois_positivos(a,b));
        else if(!(pos_ou_neg(a))&&!(pos_ou_neg(b))) //Se os dois ==0 (negativos)
            printf("A multiplicação entre os números negativos %d e %d é %d.\n",a,b,dois_negativos(a,b));
        else if(pos_ou_neg(a)&&!pos_ou_neg(b)) //Se a==1 e b==0
            printf("A divisão entre %d e %d é %.2f.\n",a,b,div_pos_neg(a,b));


        printf("Você quer inserir novos dados? Digite 'S' ou 's' para sim ou pressione qualquer outra tecla para encerrar.\n");
        scanf(" %c",&retorna);
        }while(retorna=='S'||retorna=='s');//fim laço 1

    }
#endif // ex1

#ifdef ex2
/*2 - Escreva um programa que receba um numero N via teclado. Escreva uma funcao
     que retorne a soma dos algarismos do resultado de N!. O resultado deve ser
     mostrado na funcao main().
     Ex: se N = 4, N! = 24. Logo, a soma de seus algarismos e´ 2 + 4 = 6.
*/

int fatorialSoma(int num){
    int soma=0,i;
    unsigned long fat=1;

    for(i=1;i<=num;i++){
        fat*=i;
    }

    while(fat>0){
        soma += fat%10;
        fat = fat/10;
    }
    return soma;
}


int main(){

    setlocale(LC_ALL,"Portuguese");

    char continuar;
    do{
        int num;

        do{
            printf("Digite um número inteiro e positivo (até 12):");
            scanf("%d", &num);

            if(num <= 0 || num>=13){
                printf("Número inválido. Digite um número positivo e inteiro.\n");
            }
        }while(num <=0 || num>=13);

        printf("A soma dos algorismos do fatorial do número %d é: %d\n", num, fatorialSoma(num));

        printf("\nDeseja reiniciar o programa? (S para continuar, qualquer outra tecla para sair): ");
        scanf(" %c", &continuar);

    }while(continuar == 'S' || continuar == 's');
}


#endif // ex2

#ifdef ex3
/*Escreva um programa que receba na funcao main() 2 valores inteiro. Escreva
     uma funcao para cada operacoes aritmeticas e passe como parametro os 2
     valores recebidos na funcao main(). Retorne os resultados usando o comando
     return e imprima os 4 resultados no video na funcao main().*/


     int soma(int a,int b){
        return a+b;
     }

     int sub(int a, int b){
        return (a - b);
     }

     int multi(int a, int b){
        return a*b;
     }
     float divi(int a,int b){
     return (float)a/b;
     }

     main(){

     setlocale(LC_ALL,"");
     int a,b;
     char C;

     do{
     do{
     printf("\nDigite dois numeros inteiros: \n");
     scanf("%d %d", &a,&b);

     if (b==0)
        printf("O segundo número não pode ser nulo. Tente novamente!\n");
     }while(b==0);

      printf("%d + %d = %d\n",a,b,soma(a,b));
      printf("%d - %d = %d\n",a,b,sub(a,b));
      printf("%d * %d = %d\n",a,b,multi(a,b));
      printf("%d / %d = %.2f\n",a,b,divi(a,b));

    printf("\nDeseja tentar novamente? Pressione 'S' para continuar ou qualquer tecla para finalizar: ");
    scanf(" %c",&C);

     }while(C == 'S' || C == 's');
     }

#endif // ex3

#ifdef ex4

/*4 - Reescreva o programa do exercicio anterior para receber via teclado n
     valores. Os n valores nao sao definidos previamente.
 */

 int func_soma (int x, int y){

        return x+y;
    }

    int func_sub(int x, int y){

        return x-y;
    }

    int func_mult(int x, int y){

        return x*y;
    }

    float func_div(float x, int y){

        return x/y;
    }


 int main(){

    setlocale(LC_ALL, "Portuguese");
    char continuar, reiniciar;

do{
    int x, cont = 0, soma = 0, sub = 0, mult = 1;
    float div = 1.0;

 do{

    do{
        volta:
        printf("Digite um número inteiro (não pode ser zero): ");
        scanf("%d", &x);

        if (x == 0) {
            printf("Erro: O número não pode ser zero. Tente novamente.\n");
        }
    }while (x == 0);

    //incrementa o valor do contador, para saber quantos números o usuário vai digitar e também para inicializar as variáveis;
    cont++;

    if(cont == 1){
        soma = x;
        sub = x;
        mult = x;
        div = x;

        goto volta;
    }


    else if(cont >= 2){

        soma = func_soma(soma, x);
        sub = func_sub(sub, x);
        mult = func_mult(mult, x);
        div = func_div(div, x);

        printf("Quantidade de números digitados: %d\n", cont);
        printf("Soma: %d\n", soma);
        printf("Subtração: %d\n", sub);
        printf("Multiplicação: %d\n", mult);
        printf("Divisão: %f\n", div);

    }

        printf("Deseja informar novos números? Pressione 's' para sim. Caso contrário, pressione qualquer outra tecla.\n");
            scanf(" %c",&continuar);


    }while(continuar =='S'|| continuar =='s');

    printf("Quantidade total de números: %d\n", cont);
    printf("Soma final: %d\n", soma);
    printf("Subtração final: %d\n", sub);
    printf("Multiplicação final: %d\n", mult);
    printf("Divisão final: %.2f\n", div);

    printf("Deseja reiniciar o programa? Pressione 'y' para sim. Caso contrário, pressione qualquer outra tecla.\n");
            scanf(" %c",&reiniciar);

    }while(reiniciar == 'y' || reiniciar == 'Y');
}



#endif // ex4

#ifdef ex5

 int func_soma (float x, int y){

        return x+y;
    }

    int func_sub(float x, int y){

        return x-y;
    }

    int func_mult(float x, int y){

        return x*y;
    }

    float func_div(float x, int y){
        if(y == 0){
            printf("Operação inválida\n");
            return x;
        }else{
            return x/y;
        }
    }


 int main(){

    setlocale(LC_ALL, "Portuguese");
    char continuar, reiniciar;

do{
    int x, cont = 0;
    char op;
    float resultado;

        printf("Digite um número inteiro: ");
        scanf("%d", &x);

        resultado = x;


    while(1){

    do{

        printf("\n(+) Soma | (-) Subtração | (*) Multiplicação | (/) Divisão | (=) Igual para mostrar o resultado\n");
        printf("Escolha uma operação válida: ");
        scanf(" %c", &op);

    }while(op!= '+' && op!= '-' && op!= '*' && op!= '/' && op != '=');

     if(op == '=')
        break;

   if(cont >= 1){

        printf("Resultados: %.2f\n", resultado);
    }

        printf("Digite um número inteiro: ");
        scanf("%d", &x);

        cont++;


     switch(op) {
                case '+':
                    resultado = func_soma(resultado, x);
                    break;
                case '-':
                    resultado = func_sub(resultado, x);
                    break;
                case '*':
                    resultado = func_mult(resultado, x);
                    break;
                case '/':
                    resultado = func_div(resultado, x);
                    break;
                }


        }


    printf("RESULTADO FINAL: %f\n", resultado);


    printf("Deseja reiniciar o programa? Pressione 'y' para sim. Caso contrário, pressione qualquer outra tecla.\n");
            scanf(" %c",&reiniciar);

    }while(reiniciar == 'y' || reiniciar == 'Y');
}




#endif // ex5


