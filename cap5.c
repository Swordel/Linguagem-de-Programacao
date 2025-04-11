#include <stdio.h>
#include <locale.h>

//OBS.: Todos os programa devem ser finalizados pelo usuario.

#define ex2

#ifdef ex1

/*1 - Escreva um programa para receber 5 nomes, com até 7 caracteres, via teclado
     e imprima-os no video no seguinte formato:(Declare os 5 vetores como variaveis
     globais)

              10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      nome1                                   nome5
                nome2               nome4
                          nome3*/

char nome[5][8];

main()
{
    char reiniciar,letra;
    int l,c,invalido;
    setlocale(LC_ALL,"");
    do{
            //Inicializando os vetores com finalizador para caso usuário decidir reiniciar o programa, os valores anteriores são "apagados".
            nome[0][0]='\0';
            nome[1][0]='\0';
            nome[2][0]='\0';
            nome[3][0]='\0';
            nome[4][0]='\0';

            for(l=0;l<5;l++)
            {
                printf("Informe nome%i: \n",l+1);
                invalido = 1;
                while(invalido){
                    c=0;
                    while((letra=getchar())!= '\n' && c<7){ //Enquanto o caractere digitado for diferente de 'Enter' (\n) E o índice/contador for menor que 7
                        nome[l][c]=letra;//vai colocando em cada índice do vetor uma letra, de 0 a 6
                        c++;}

                    nome[l][c] = '\0'; // Coloca finalizador no último índice, 7

                    if(c<=7 && letra=='\n')
                        invalido=0; // se inválido = F -> Válido = T -> não precisa mesagem de limite e sai do while
                    else{
                        printf("Favor informar um nome com no máximo 7 caracteres.\n");
                        while(letra!='\n')
                        {letra=getchar();} //limpa o buffer até encontrar o 'Enter'
                        }
                    }//fim while de validação 7 caracteres
            }//fim laço para inserir nome

            //régua

            printf("        10        20        30        40        50        \n");
            printf("12345678901234567890123456789012345678901234567890\n");
            printf("  %-7s                                 %-7s\n",nome[0],nome[4]);
            printf("            %-7s             %-7s\n",nome[1],nome[3]);
            printf("                      %-7s\n",nome[2]);

            //pergunta usuário
            printf("Se quer informar novos nomes digite 'S'. Caso contrário, pressione qualquer outra tecla para encerrar.\n");
            scanf(" %c",&reiniciar);
            getchar();
        }while(reiniciar=='S'||reiniciar=='s');

}

#endif // ex1

#ifdef ex2
/*2 - Escreva um programa que receba uma string (40) na funcao main(). Faca uma funcao que
     calcula o comprimento de uma string recebida via teclado. Mostre o valor do
     comprimento na funcao main().
     (Declare o vetor como variavel global) (nao pode usar funcao de biblioteca)*/

     char A[41];

     int comprimento()
     {
         int valor=0,cont;
         for(cont=0;cont==valor;cont++)
         {
             if(A[cont]!='\0')
                 valor++;
         }
        return valor;
     }

     main()
     {
         char reiniciar;
         setlocale(LC_ALL,"");

         do{
                printf("Informe uma string: ");
                digitar:
                gets(A); //usando gets para que os espaços sejam considerados (se houver)

                if(comprimento()<=40)
                    printf("O comprimento da string digitada é de %i caracteres.\n\n",comprimento());
                else{
                    printf("Foram digitados %i caracteres sendo que o limite é 40. Favor digitar string novamente.\n",comprimento());
                    goto digitar;}//volta para gets

        //pergunta usuário
            printf("Digite 'S' para informar nova string. Caso contrário, pressione qualquer outra tecla para encerrar.\n");
            scanf(" %c",&reiniciar);
            getchar();
        }while(reiniciar=='S'||reiniciar=='s');

     }

#endif // ex2

#ifdef ex3
/*3 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
     para letras maiusculas. (nao pode usar funcao de biblioteca)*/


     main()
     {
         char reiniciar, A[11];
         int c;
         setlocale(LC_ALL,"");

         do{
                A[0]='\0';
                printf("Digite caracteres: ");
                gets(A);


             system("cls");//limpa a tela

             printf("Você digitou os seguintes caracteres: %s\n\n",A);
             for(c=0;A[c]!='\0';c++)
                {
                    if(A[c]>='a' && A[c]<='z')//converte para maiúscula apenas se for minúscula
                        A[c] = A[c]-32;
                }

             printf("Os caracteres em letras maiúsculas são: %s\n",A);

        //pergunta usuário
            printf("Deseja reiniciar? Digite 'S'. Caso contrário, pressione qualquer outra tecla para encerrar.\n");
            scanf(" %c",&reiniciar);
            getchar();
        }while(reiniciar=='S'||reiniciar=='s');
     }

#endif // ex3

#ifdef ex4
/*4 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
     para letras minusculas. (nao pode usar funcao de biblioteca)*/


     main()
     {
         char reiniciar, A[11];
         int c;
         setlocale(LC_ALL,"");

         do{
                A[0]='\0';
                printf("Digite caracteres: ");
                gets(A);

             system("cls");//limpa a tela

             printf("Você digitou os seguintes caracteres: %s\n\n",A);
             for(c=0;A[c]!='\0';c++)
                {
                    if(A[c]>='A' && A[c]<='Z')//converte para minúscula apenas se for maiúscula
                        A[c] = A[c]+32;
                }

             printf("Os caracteres em letras minúsculas são: %s\n",A);

        //pergunta usuário
            printf("Deseja reiniciar? Digite 'S'. Caso contrário, pressione qualquer outra tecla para encerrar.\n");
            scanf(" %c",&reiniciar);
            getchar();
        }while(reiniciar=='S'||reiniciar=='s');
     }

#endif // ex4

#ifdef ex5

/*5 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faça uma
     funcao para compara-las e retorne como resultado se são IGUAIS 1 ou se
     DIFERENTES 0 para a funcao main(). Imprima o resultado na funcao main().
     (Declare os vetores como variavel global) (nao pode usar funcao de biblioteca)
*/


char string1[11];
char string2[11];

// Função para comparar as strings
int compararStrings() {
    int i = 0;


    while (string1[i] != '\0' && string2[i] != '\0') {
        if (string1[i] != string2[i]) {
            return 0; // Strings são diferentes
        }
        i++;
    }

    // Verifica se as duas strings terminaram ao mesmo tempo
    // (se uma terminou antes, elas têm tamanhos diferentes e são diferentes)
    if (string1[i] == '\0' && string2[i] == '\0') {
        return 1; // Strings são iguais
    } else {
        return 0; // Strings são diferentes (tamanhos diferentes)
    }
}

int main() {
    int resultado;
    char reiniciar;
    setlocale(LC_ALL,"Portuguese");

    do{

    // Recebe a primeira string
    printf("Digite a primeira string (até 10 caracteres): ");
    gets(string1);

    // Recebe a segunda string
    printf("Digite a segunda string (até 10 caracteres): ");
    gets(string2);

    // Chama a função para comparar as strings
    resultado = compararStrings();

    // Imprime o resultado
    if (resultado == 1) {
        printf("Resultado: 1 (IGUAIS)\n");
    } else {
        printf("Resultado: 0 (DIFERENTES)\n");
    }


        printf("Deseja reiniciar? Digite 'S'. Caso contrário, pressione qualquer outra tecla para encerrar.\n");
        scanf(" %c",&reiniciar);
        getchar();

    }while(reiniciar=='S'||reiniciar=='s');
}



#endif // ex5
