#define ex5
#include "stdio.h"
#include <locale.h>

#ifdef ex1
/* Escreva um programa que permute o conteúdo de duas variáveis sem utilizar uma
     variável auxiliar. */

     main()
{
    int a,b;
    setlocale(LC_ALL,"Portuguese");

    printf("Digite o primeiro número (a): \n");
    scanf("%d",&a);

    printf("Digite o segundo número (b): \n");
    scanf("%d",&b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("a = %d | b = %d",a,b);

}

#endif // ex1

#ifdef ex2 //perguntar do float negativo
/*Escreva um programa que receba dados via teclado para variaveis do tipo short,
     long, int, float, double e um char e imprima-os no video no seguinte
     formato:
              10       20        30        40        50        60
     12345678901234567890123456789012345678901234567890123456789012345
         short               long                int
                   float               double              char */

    main() {

    short a;
    long b;
    int c;
    float d;
    double e;
    char f;

    scanf("%hd %ld %d %f %lf %c", &a, &b, &c, &d, &e, &f);

    printf("         10       20        30        40        50        60\n");
    printf("12345678901234567890123456789012345678901234567890123456789012345\n");
    printf("    %-6hd              %-11ld         %-11d\n",a,b,c);
    printf("              %-9.1e           %-9.1e           %c\n",d,e,f);

    }

#endif // ex2

#ifdef ex3 //multiplo de negativo? usar modulo

/*Escreva um programa que determine o menor multiplo de um numero inteiro. Este
     multiplo deve ser maior que o limite minimo recebido. Recebe os 2 numeros via
     teclado.
    Ex: menor multiplo de 13 maior que 100. Resultado: 104.*/

    main() {

    int num, limite,A;
    setlocale(LC_ALL,"Portuguese");

    printf("Digite um número: \n");
    scanf("%d",&num);
    if(num<0)
    {
        num=num*-1;
    }

    do{
        printf("Qual é o limite mínimo que deseja?\n");
        scanf("%d",&limite);
        if(limite<num)
        {
           printf("O limite mínimo não pode ser menor que %d.\n",num);
        }
        }while(limite<num);

    A = num;
    while(A <= limite){
        A = A + num;
    }

    printf("O menor múltiplo de %d maior que %d é %d",num,limite,A);

    }


#endif // ex3

#ifdef ex4
/* Escreva um programa que receba via teclado um tempo em segundos e converta
   para horas, minutos e segundos.
   Ex.: recebe 3850 segundos que converte para 1h 4min 10s.*/

main() {
     int segundos, hora, minuto, s2;

     printf("Digite os segundos: ");
     scanf("%d",&segundos);

     hora = segundos/3600;
     minuto = (segundos - (hora * 3600)) / 60;
     s2 = segundos - (hora * 3600) - (minuto * 60);

     printf("%d segundos = %dh %dmin %ds",segundos,hora,minuto,s2);
}


#endif // ex4

#ifdef ex5
/*Faça um programa para ler um numero inteiro, positivo de tres digitos, e gerar
  outro número formado pelos dígitos invertidos do número lido.
     Ex: NúmeroLido = 123
         NúmeroGerado = 321*/
main() {

    int num,centena,dezena,unidade,resultado;
    setlocale(LC_ALL,"");

    do{
    printf("Digite um número positivo com 3 dígitos: \n");
    scanf("%d", &num);

    if(num < 100 || num > 999)
        printf("O número deve ser positivo e conter 3 dígitos. Tente novamente!\n\n");
    }while(num < 100 || num > 999) ;

    centena = num / 100;
    dezena = (num - (centena * 100))/10;
    unidade = num - (centena * 100) - (dezena * 10);

    resultado = (unidade*100) + (dezena*10) + centena;

    printf("O número %d invertido é %d", num,resultado);
}
#endif // ex5
