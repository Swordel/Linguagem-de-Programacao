#include <stdio.h>
#include <locale.h>

//OBS.: Todos os programa devem ser finalizados pelo usuario.

#define ex2

#ifdef ex1

/*1 - Escreva um programa para receber 5 nomes, com at� 7 caracteres, via teclado
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
            //Inicializando os vetores com finalizador para caso usu�rio decidir reiniciar o programa, os valores anteriores s�o "apagados".
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
                    while((letra=getchar())!= '\n' && c<7){ //Enquanto o caractere digitado for diferente de 'Enter' (\n) E o �ndice/contador for menor que 7
                        nome[l][c]=letra;//vai colocando em cada �ndice do vetor uma letra, de 0 a 6
                        c++;}

                    nome[l][c] = '\0'; // Coloca finalizador no �ltimo �ndice, 7

                    if(c<=7 && letra=='\n')
                        invalido=0; // se inv�lido = F -> V�lido = T -> n�o precisa mesagem de limite e sai do while
                    else{
                        printf("Favor informar um nome com no m�ximo 7 caracteres.\n");
                        while(letra!='\n')
                        {letra=getchar();} //limpa o buffer at� encontrar o 'Enter'
                        }
                    }//fim while de valida��o 7 caracteres
            }//fim la�o para inserir nome

            //r�gua

            printf("        10        20        30        40        50        \n");
            printf("12345678901234567890123456789012345678901234567890\n");
            printf("  %-7s                                 %-7s\n",nome[0],nome[4]);
            printf("            %-7s             %-7s\n",nome[1],nome[3]);
            printf("                      %-7s\n",nome[2]);

            //pergunta usu�rio
            printf("Se quer informar novos nomes digite 'S'. Caso contr�rio, pressione qualquer outra tecla para encerrar.\n");
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
                gets(A); //usando gets para que os espa�os sejam considerados (se houver)

                if(comprimento()<=40)
                    printf("O comprimento da string digitada � de %i caracteres.\n\n",comprimento());
                else{
                    printf("Foram digitados %i caracteres sendo que o limite � 40. Favor digitar string novamente.\n",comprimento());
                    goto digitar;}//volta para gets

        //pergunta usu�rio
            printf("Digite 'S' para informar nova string. Caso contr�rio, pressione qualquer outra tecla para encerrar.\n");
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

             printf("Voc� digitou os seguintes caracteres: %s\n\n",A);
             for(c=0;A[c]!='\0';c++)
                {
                    if(A[c]>='a' && A[c]<='z')//converte para mai�scula apenas se for min�scula
                        A[c] = A[c]-32;
                }

             printf("Os caracteres em letras mai�sculas s�o: %s\n",A);

        //pergunta usu�rio
            printf("Deseja reiniciar? Digite 'S'. Caso contr�rio, pressione qualquer outra tecla para encerrar.\n");
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

             printf("Voc� digitou os seguintes caracteres: %s\n\n",A);
             for(c=0;A[c]!='\0';c++)
                {
                    if(A[c]>='A' && A[c]<='Z')//converte para min�scula apenas se for mai�scula
                        A[c] = A[c]+32;
                }

             printf("Os caracteres em letras min�sculas s�o: %s\n",A);

        //pergunta usu�rio
            printf("Deseja reiniciar? Digite 'S'. Caso contr�rio, pressione qualquer outra tecla para encerrar.\n");
            scanf(" %c",&reiniciar);
            getchar();
        }while(reiniciar=='S'||reiniciar=='s');
     }

#endif // ex4

#ifdef ex5

/*5 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Fa�a uma
     funcao para compara-las e retorne como resultado se s�o IGUAIS 1 ou se
     DIFERENTES 0 para a funcao main(). Imprima o resultado na funcao main().
     (Declare os vetores como variavel global) (nao pode usar funcao de biblioteca)
*/


char string1[11];
char string2[11];

// Fun��o para comparar as strings
int compararStrings() {
    int i = 0;


    while (string1[i] != '\0' && string2[i] != '\0') {
        if (string1[i] != string2[i]) {
            return 0; // Strings s�o diferentes
        }
        i++;
    }

    // Verifica se as duas strings terminaram ao mesmo tempo
    // (se uma terminou antes, elas t�m tamanhos diferentes e s�o diferentes)
    if (string1[i] == '\0' && string2[i] == '\0') {
        return 1; // Strings s�o iguais
    } else {
        return 0; // Strings s�o diferentes (tamanhos diferentes)
    }
}

int main() {
    int resultado;
    char reiniciar;
    setlocale(LC_ALL,"Portuguese");

    do{

    // Recebe a primeira string
    printf("Digite a primeira string (at� 10 caracteres): ");
    gets(string1);

    // Recebe a segunda string
    printf("Digite a segunda string (at� 10 caracteres): ");
    gets(string2);

    // Chama a fun��o para comparar as strings
    resultado = compararStrings();

    // Imprime o resultado
    if (resultado == 1) {
        printf("Resultado: 1 (IGUAIS)\n");
    } else {
        printf("Resultado: 0 (DIFERENTES)\n");
    }


        printf("Deseja reiniciar? Digite 'S'. Caso contr�rio, pressione qualquer outra tecla para encerrar.\n");
        scanf(" %c",&reiniciar);
        getchar();

    }while(reiniciar=='S'||reiniciar=='s');
}



#endif // ex5
