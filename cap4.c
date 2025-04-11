#include <stdio.h>
#include <locale.h>
//OBS.: Todos os programa devem ser finalizados pelo usuario.
#define ex4


#ifdef ex1
/*1 - Escreva um programa para receber via teclado em vetores 3 int, 3 long,
    3 unsigned, 3 float e 3 double e imprima-os no video no seguinte formato:

          10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double*/

    main()
    {
        int vet_int[3],cont;
        long vet_long[3];
        unsigned vet_unsigned[3];
        float vet_float[3];
        double vet_double[3];
        char reiniciar;

        do//laço usuário decide reiniciar ou não
        {
            for(cont=0;cont<3;cont++)
            {
                printf("Inteiro [%i]: ",cont+1);
                scanf("%i",&vet_int[cont]);
                printf("Long [%i]: ",cont+1);
                scanf("%ld",&vet_long[cont]);
                printf("Unsigned [%i]: ",cont+1);
                scanf("%u",&vet_unsigned[cont]);
                printf("Float [%i]: ",cont+1);
                scanf("%f",&vet_float[cont]);
                printf("Double [%i]: ",cont+1);
                scanf("%lf",&vet_double[cont]);
                printf("\n");
            }
            //régua
            printf("        10        20        30        40        50        \n");
            printf("123456789012345678901234567890123456789012345678901234567890\n");
            for(cont=0;cont<3;cont++)
            {
                printf("  %-11d         %-11ld         %-10u\n",vet_int[cont],vet_long[cont],vet_unsigned[cont]);
                printf("            %-9.1e           %-9.1e         \n",vet_float[cont],vet_double[cont]);
            }

            printf("Deseja reiniciar? Digite 'S' para sim ou pressionar qualquer outra tecla para encerrar.\n");
            scanf(" %c",&reiniciar);
        }while(reiniciar=='S'||reiniciar=='s');
    }
#endif // ex1

#ifdef ex2
/*2 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o
    decomponha em dois outros vetores. Um tera´ as componentes de ordem impar
    e o outro tera´ as componentes de ordem par.
    Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 9}, o programa
    deve gerar os vetores u = {3, 6, 1, 2, 7} e w = {5, 8, 4, 3, 9}.*/

    main()
    {
        int todos[10],impar[5],par[5],c,ci,cp;
        char reiniciar;
        setlocale(LC_ALL,"Portuguese");

        do{//laço usuário decide reiniciar ou não
                ci=0;
                cp=0;
                for(c=0;c<10;c++)
                {
                    printf("Informe um número inteiro [%i]: ",c + 1);
                    scanf("%i",&todos[c]);
                    if(c%2!=0){
                        impar[ci]=todos[c];
                        ci++;}
                    else{
                        par[cp]=todos[c];
                        cp++;}
                }
                printf("Vetor Todos:\n");
                for(c=0;c<10;c++){
                    printf("[%i] -> %i\n",c,todos[c]);}

                printf("Vetor Ímpares: ");//w
                for(c=0;c<ci;c++){
                printf("| %i |",impar[c]);}
                printf("\n");

                printf("Vetor Pares: "); //u
                for(c=0;c<cp;c++){
                printf("| %i |",par[c]);}
                printf("\n");


            printf("Deseja reiniciar? Digite 'S' para sim ou pressionar qualquer outra tecla para encerrar.\n");
            scanf(" %c",&reiniciar);
        }while(reiniciar=='S'||reiniciar=='s');

    }
#endif // ex2

#ifdef ex3
/*3 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o
    decomponha em dois outros vetores. Um tera´ as componentes de valor impar
    e o outro tera´ as componentes de valor par.
    Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 4} o
    programa deve gerar os vetores u = {3, 5, 1, 3, 7} e w = {6, 8, 4, 2, 4}. */

        main()
    {
        int todos[10],impar[10],par[10],c,ci,cp;
        char reiniciar;
        setlocale(LC_ALL,"Portuguese");

        do{//laço usuário decide reiniciar ou não
                ci=0;
                cp=0;
                for(c=0;c<10;c++)
                {
                    printf("Informe um número inteiro [%i]: ",c+1);
                    scanf("%i",&todos[c]);
                    if(todos[c]%2!=0){
                        impar[ci]=todos[c];
                        ci++;}
                    else{
                        par[cp]=todos[c];
                        cp++;}
                }
                printf("Vetor Todos:\n");
                for(c=0;c<10;c++){
                    printf("[%i] -> %i\n",c+1,todos[c]);}

                if(ci==0)
                    printf("Não foi informado nenhum número ímpar.\n");
                else{
                    printf("Vetor Ímpares: ");
                    for(c=0;c<ci;c++){
                    printf("| %i |",impar[c]);}
                    printf("\n");}

                if(cp==0)
                    printf("Não foi informado nenhum número par.\n");
                else{
                    printf("Vetor Pares: ");
                    for(c=0;c<cp;c++){
                    printf("| %i |",par[c]);}
                    printf("\n");}

            printf("Deseja reiniciar? Digite 'S' para sim ou pressionar qualquer outra tecla para encerrar.\n");
            scanf(" %c",&reiniciar);
        }while(reiniciar=='S'||reiniciar=='s');

    }

#endif // ex3

#ifdef ex4
/*4 - Defina 2 vetores bidimensionais do tipo inteiro de 2x3. Escreva um programa
    que recebe os dados via teclado para esses 2 vetores. Usando o operador
    adicao "+", some os elementos de mesmo indice dos 2 vetores e guarde o
    resultado em um 3. vetor. Imprima na tela o indice, os valores e o resultado
    dos 6 elementos dos vetores.*/

    main()
    {
        int A[2][3],B[2][3],C[2][3],l,c;
        char reiniciar;
        do{
            for(l=0;l<2;l++){
                for(c=0;c<3;c++)
            {
                printf("Informe valor inteiro para A[%d][%d]:",l,c);
                scanf("%d",&A[l][c]);
            }}

            for(l=0;l<2;l++){
                for(c=0;c<3;c++){

                printf("Informe valor inteiro para B[%d][%d]:",l,c);
                scanf("%d",&B[l][c]);

            }}

            for(l=0;l<2;l++)
                for(c=0;c<3;c++)
            {
                C[l][c]=A[l][c]+B[l][c];
                printf("Vetor A[%d][%d] = %d\n",l,c,A[l][c]);
                printf("Vetor B[%d][%d] = %d\n",l,c,B[l][c]);
                printf("Vetor C[%d][%d] = %d\n\n",l,c,C[l][c]);
            }

        printf("\nMatriz A:\n");
        for (l = 0; l < 2; l++) {
            for (c = 0; c < 3; c++) {
                printf("%5d ", A[l][c]);
            }
            printf("\n");
        }

        printf("\nMatriz B:\n");
        for (l = 0; l < 2; l++) {
            for (c = 0; c < 3; c++) {
                printf("%5d ", B[l][c]);
            }
            printf("\n");
        }

        printf("\nMatriz C(A + B):\n");
        for (l = 0; l < 2; l++) {
            for (c = 0; c < 3; c++) {
                printf("%5d ", C[l][c]);
            }
            printf("\n");
        }
            printf("Deseja reiniciar? Digite 'S' para sim ou pressionar qualquer outra tecla para encerrar.\n");
            scanf(" %c",&reiniciar);
        }while(reiniciar=='S'||reiniciar=='s');
    }

#endif // ex4


#ifdef ex5
/*5 - Receba via teclado 10 valores inteiros e ordene por ordem crescente assim
    que sao digitados. Guarde-os em um vetor. Mostre ao final os valores
    ordenados.*/

int main(){

        int vetor[10],j,i, proximo_num;
        char reiniciar;

        do{
            int n=0; //numero total de elementos inseridos

                for(j=0;j<10;j++)
                {
                    printf("Informe um valor inteiro [%d]: ",j);
                    scanf("%d",&proximo_num);

                    //insertion sort
                    i = n - 1; //encontra a posição para inserção, começa a verificação do final do vetor para trás, comparando com proximo_num.
                    while(i>=0 && vetor[i] > proximo_num){
                        vetor[i + 1] = vetor [i];
                        i--;
                    }

                    vetor[i + 1] = proximo_num;
                    n++;


                }
                printf("\nVetor ordenado por ordem crescente\n");
                for(i=0;i<10;i++){
                    printf("Vetor[%d]: %d\n", i, vetor[i]);
                }

            printf("Deseja reiniciar? Digite 'S' para sim ou pressionar qualquer outra tecla para encerrar.\n");
            scanf(" %c",&reiniciar);
        }while(reiniciar=='S'||reiniciar=='s');
    }

    /*Entendendo o insertion sort

    1ª entrada: proximo_num = 5
                n = 0
                i = n - 1 --> i = 0 - 1 --> i = -1 (não entra no while, pois não é verdadeiro i>=0)
                vetor[i + 1] = proximo_num --> vetor [-1 + 1] = 5 --> vetor [0] = 5
                n++; n = 0 + 1 --> n = 1

                vetor [10] = {5,..}


    2ª entrada: proximo_num = 3
                n = 1
                i = 1-1 --> i = 0
                entra no while, pois vetor[0] = 5 e 5 > 3

                while(i>=0 && vetor[i] > proximo_num){
                        vetor[i + 1] = vetor [i]; ----> vetor [0 + 1] = vetor [0] --> vetor [1] = 5
                        i--; ----> i = 0 - 1 --> i = -1 (sai do loop)
                    }

                    vetor[i + 1] = proximo_num; --> vetor[-1+1] = 3 --> vetor[0] = 3
                    n++;
                    n = 1+1 = 2

                    vetor[10] = {3,5..}

    3ª entrada: proximo_num = 8
                n=2
                i = n-1 --> i = 2-1 ---> i = 1
                não entra no while, pois vetor[i] não é maior que proximo_num --> vetor[1] = 5 e 5 < 8
                vetor[1 + 1] = proximo_num --> vetor [2] = 8
                n++; ---> 2+1 ---> n = 3

                vetor[10] = {3,5,8...}

    4ª entrada: proximo_num = 1
                n = 3
                i = n-1 --> i = 3-1 --> i = 2

                entra no while
                    vetor[i] > proximo_num --> vetor[2] > 1 --> 8>1 --> verdadeiro
                    vetor[i + 1] = vetor [i]; --> vetor [2 + 1] = vetor [2] --> vetor[3] = 8 (moveu)
                    i--; --> 2-1 --> i = 1 (continua no loop)

                    vetor[i] > proximo_num --> vetor[1] > 1 --> 5>1 --> verdadeiro
                    vetor[i+1] = vetor[i] --> vetor[2] = vetor[1] --> vetor [2] = 5 (moveu)
                    i--; 1-1 = 0 --> i=0 (continua no loop)

                    vetor[i]>proximo_num --> vetor[0]>1 --> 3>1 ---> verdadeiro
                    vetor[i+1] = vetor[i] --> vetor[0+1] = vetor [0] --> vetor[1] = 3 (moveu)
                    i--; --> 0-1 --> i=-1 (sai do loop)

                    vetor[i + 1] = proximo_num --> vetor [-1 + 1] = 1 --> vetor[0] = 1 (primeira posição)
                    n++; --> n = 3+1 --> n = 4;

                    vetor[10] = {1,3,5,8,...}*/

 #endif // ex5
