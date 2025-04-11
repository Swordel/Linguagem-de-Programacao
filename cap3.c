#include <stdio.h>
#include <locale.h>

#define ex2

#ifdef ex1
/*1 - Escreva um programa que receba dois numeros inteiros e execute as seguintes
    fun�oes:
    - Verificar se o numero digitado e' positivo ou negativo. Sendo que o valor de
      retorno sera' 1 se positivo, 0 se negativo ou -1 se for igual a 0.
    - Se os 2 numeros sao positivos, retorne a soma dos N numeros existentes entre
      eles.
    - Se os 2 numeros sao negativos, retorne a multiplicacao dos N numeros existente
      entre eles.
    - Se 1. numero for positivo e o 2. negativo faca a divisao entre eles.*/

    //Se o n�mero 1 for negativo e o n�mero 2 positivo, o que faz?

    int pos_ou_neg(int x)
    {
        if(x<0)
            return 0;
            else if(x==0)
                return -1;
            else
                return 1;
    }//fim fun��o que verifica se numero digitado e' positivo ou negativo

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
    }//fim fun��o que soma numeros existentes entre os positivos

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
    }//fim fun��o que soma numeros existentes entre os negativos

    float div_pos_neg(int x, int y)
    {
        float resultado;
        resultado=x/y;
        return resultado;

    }//fim fun��o que divide a por b

    main()
    {
        int a, b;
        char retorna;
        setlocale(LC_ALL,"");

        do{ //la�o 1 para deixar que usu�rio decida quando encerrar o programa ou n�o.
        do{ //la�o 2 para exigir que usu�rio digite apenas negativos ou positivos
        printf("Informe dois n�meros inteiros:\n");
        scanf("%d %d",&a,&b);
        if(pos_ou_neg(a)==-1||pos_ou_neg(b)==-1)
            printf("Voc� informou o n�mero 0. Favor informar apenas n�meros positivos ou negativos.\n\n");
        }while(pos_ou_neg(a)==-1||pos_ou_neg(b)==-1); //fim la�o 2

        if(pos_ou_neg(a)&&pos_ou_neg(b))//Se os dois == 1 (positivos)
            printf("A soma entre os n�meros positivos %d e %d � %d.\n",a,b,dois_positivos(a,b));
        else if(!(pos_ou_neg(a))&&!(pos_ou_neg(b))) //Se os dois ==0 (negativos)
            printf("A multiplica��o entre os n�meros negativos %d e %d � %d.\n",a,b,dois_negativos(a,b));
        else if(pos_ou_neg(a)&&!pos_ou_neg(b)) //Se a==1 e b==0
            printf("A divis�o entre %d e %d � %.2f.\n",a,b,div_pos_neg(a,b));


        printf("Voc� quer inserir novos dados? Digite 'S' ou 's' para sim ou pressione qualquer outra tecla para encerrar.\n");
        scanf(" %c",&retorna);
        }while(retorna=='S'||retorna=='s');//fim la�o 1

    }
#endif // ex1

#ifdef ex2
/*2 - Escreva um programa que receba um numero N via teclado. Escreva uma funcao
     que retorne a soma dos algarismos do resultado de N!. O resultado deve ser
     mostrado na funcao main().
     Ex: se N = 4, N! = 24. Logo, a soma de seus algarismos e� 2 + 4 = 6.
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
            printf("Digite um n�mero inteiro e positivo (at� 12):");
            scanf("%d", &num);

            if(num <= 0 || num>=13){
                printf("N�mero inv�lido. Digite um n�mero positivo e inteiro.\n");
            }
        }while(num <=0 || num>=13);

        printf("A soma dos algorismos do fatorial do n�mero %d �: %d\n", num, fatorialSoma(num));

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
        printf("O segundo n�mero n�o pode ser nulo. Tente novamente!\n");
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
        printf("Digite um n�mero inteiro (n�o pode ser zero): ");
        scanf("%d", &x);

        if (x == 0) {
            printf("Erro: O n�mero n�o pode ser zero. Tente novamente.\n");
        }
    }while (x == 0);

    //incrementa o valor do contador, para saber quantos n�meros o usu�rio vai digitar e tamb�m para inicializar as vari�veis;
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

        printf("Quantidade de n�meros digitados: %d\n", cont);
        printf("Soma: %d\n", soma);
        printf("Subtra��o: %d\n", sub);
        printf("Multiplica��o: %d\n", mult);
        printf("Divis�o: %f\n", div);

    }

        printf("Deseja informar novos n�meros? Pressione 's' para sim. Caso contr�rio, pressione qualquer outra tecla.\n");
            scanf(" %c",&continuar);


    }while(continuar =='S'|| continuar =='s');

    printf("Quantidade total de n�meros: %d\n", cont);
    printf("Soma final: %d\n", soma);
    printf("Subtra��o final: %d\n", sub);
    printf("Multiplica��o final: %d\n", mult);
    printf("Divis�o final: %.2f\n", div);

    printf("Deseja reiniciar o programa? Pressione 'y' para sim. Caso contr�rio, pressione qualquer outra tecla.\n");
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
            printf("Opera��o inv�lida\n");
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

        printf("Digite um n�mero inteiro: ");
        scanf("%d", &x);

        resultado = x;


    while(1){

    do{

        printf("\n(+) Soma | (-) Subtra��o | (*) Multiplica��o | (/) Divis�o | (=) Igual para mostrar o resultado\n");
        printf("Escolha uma opera��o v�lida: ");
        scanf(" %c", &op);

    }while(op!= '+' && op!= '-' && op!= '*' && op!= '/' && op != '=');

     if(op == '=')
        break;

   if(cont >= 1){

        printf("Resultados: %.2f\n", resultado);
    }

        printf("Digite um n�mero inteiro: ");
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


    printf("Deseja reiniciar o programa? Pressione 'y' para sim. Caso contr�rio, pressione qualquer outra tecla.\n");
            scanf(" %c",&reiniciar);

    }while(reiniciar == 'y' || reiniciar == 'Y');
}




#endif // ex5


