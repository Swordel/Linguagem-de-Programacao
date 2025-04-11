#include <stdio.h>
#include <locale.h>

//OBS.: Todos os programa devem ser finalizados pelo usuario.

#define ex1

#ifdef ex1

/*1 - Escreva um programa para adivinhar um numero entre 1 e 99 que o usuario
    pensou. Digite via teclado os simbolos =, > ou < a cada pergunta. Utilize o
    comando if-else.*/

    main(){

    char C, continuar;
    int min, max, N;
    setlocale(LC_ALL,"Portuguese");

    do
    {
    printf("Vou adivinhar seu n�mero (entre 1 e 99)!\n");

    min=1;
    max=99;

    while (min <= max){
    N = (min+max)/2;

    printf("� %d?\n",N);
    printf("Informe se � >, < ou =: ");
    scanf(" %c", &C);

    if(C == '='){
         printf("Acertei! � %d.\n", N);
         break;
        }

    else if(C == '>')
        min = N+1;

    else if (C == '<')
        max = N-1;

    else
        printf("Op��o inv�lida.\n");

      }

      if (min>max)
      {
        printf("Ocorreu um erro. Voc� trocou o n�mero? Deseja tentar novamente?\n");
        goto encerra;
      }

        printf("Quer jogar novamente?\n");
        encerra:
        printf("Digite 'S' ou 's' para continuar ou pressione qualquer tecla para encerrar o programa.\n");
        scanf(" %c",&continuar);

    }while(continuar=='S'||continuar=='s');

    }
    #endif

    #ifdef ex2

    /*  Reescreva o programa do exercicio anterior agora utilizando o comando switch.
    Conte o n. de tentativas e imprima o resultado no video.*/

    int main(){

    char C,continuar;
    int min, max, N, cont;
    setlocale(LC_ALL,"Portuguese");

    do
    {
    printf("Jogo da adivinha��o de n�meros entre 1 a 99. Ap�s cada tentativa, escreva se o n�mero � igual, maior ou menor.\n");

    min=1;
    max=99;
    cont=0;

    while(min <= max){

        N = (min + max) / 2;
        cont++; // adicionado o contador para mostrar quantas tentativas foram feitas

        printf("Tentativa: %d\n", N);

        printf("Digite =, > ou <: ");
        scanf(" %c", &C);

    switch(C){
        case '=':
            printf("Correto!\n");
            printf("N�mero de tentativas: %d\n", cont);
            goto encerra;

        case '>':
            min = N + 1;
            break;

        case '<':
            max = N -1;
            break;

        default:
            printf("Op��o inv�lida.\n");
            cont--;

        }

        if (min>max)
        {
            printf("Ocorreu um erro. Voc� trocou o n�mero? Deseja tentar novamente?\n");
            goto encerra;
        }
    }

    printf("Quer jogar novamente?\n");
        encerra:
        printf("Digite 'S' ou 's' para continuar ou pressione qualquer tecla para encerrar o programa.\n");
        scanf(" %c",&continuar);

    }while(continuar=='S'||continuar=='s');
}

    #endif // ex2


    #ifdef ex3

    /*3 - Escreva um programa que receba via teclado numeros inteiros positivos.
    Quando o numero digitado for negativo o programa deve parar e calcula a
    media dos valores positivos digitados.*/

    main()
    {
        int A, cont;
        float media;
        char continuar;
        setlocale(LC_ALL,"Portuguese");

        do{

        cont=0;
        media=0;

        do
        {
           printf("Informe um n�mero: ");
           scanf("%d",&A);
           if(A<0&&cont==0)
           {
                printf("N�mero positivo n�o informado para c�lculo de m�dia.\n\n");
                break;
           }

           else if(A>=0)
            {
                media=media+A;
                cont++;
            }

        }while(A>=0);

        if(cont>0)
        {
            media=media/cont;
            printf("A m�dia dos n�meros informados � %.2f.\n\n",media);
        }
        printf("Deseja reiniciar o programa?\n");
        printf("Digite 'S' ou 's' para continuar ou pressione qualquer tecla para encerrar.\n");
        scanf(" %c",&continuar);

    }while(continuar=='S'||continuar=='s');

   }
    #endif // ex3

    #ifdef ex4

/*  As ligacoes telefonicas s�o cobradas pela sua duracao. O sistema registra os
    instantes em que a ligacao foi iniciada e concluida.
    Escreva um programa que recebe via teclado dois instantes dados em
    horas, minutos e segundo e determina o intervalo de tempo
    (em horas, minutos e segundos) decorrido entre eles.*/

    int main(){

    //inicializa as vari�veis para entrar no loop while
    int hs_inicial, min_inicial, seg_inicial;
    int hs_final, min_final, seg_final;
    int inicial_seg, final_seg, dif;
    char continuar;
    setlocale(LC_ALL,"Portuguese");

    do{ //la�o para perguntar se usuario deseja executar programa novamente ou nao
        hs_inicial=-1;
        min_inicial=-1;
        seg_inicial=-1;
        hs_final=-1;
        min_final=-1;
        seg_final=-1;


    //garante que s� valores correspondentes as horas, minutos e segundos sejam aceitas
    while(hs_inicial < 0 || hs_inicial > 23 || min_inicial < 0 || min_inicial > 59 || seg_inicial < 0 || seg_inicial > 59){

        printf("Digite o hor�rio inicial (hora minuto segundo): ");
        scanf("%d %d %d", &hs_inicial, &min_inicial, &seg_inicial);

        if (hs_inicial < 0 || hs_inicial > 23 || min_inicial < 0 || min_inicial > 59 || seg_inicial < 0 || seg_inicial > 59){

            printf("Instantes inv�lidos. Digite novamente.\n");
        }
    }

    while(hs_final < 0 || hs_final > 23 ||  min_final < 0 ||  min_final > 59 || seg_final < 0 || seg_final > 59){

        printf("Digite o hor�rio final (hora minuto segundo):");
        scanf("%d %d %d", &hs_final, &min_final, &seg_final);

        if (hs_final < 0 || hs_final > 23 ||  min_final < 0 ||  min_final > 59 || seg_final < 0 || seg_final > 59){

             printf("Instantes inv�lidos. Digite novamente.\n");
        }
    }

    //transformar os valores em segundo, para facilitar a contagem da diferen�a
    inicial_seg = (hs_inicial*3600) + (min_inicial*60) + seg_inicial;


    final_seg = (hs_final*3600)+(min_final*60)+ seg_final;

    //Subtrai para saber quanto ser� a dura��o

    if(inicial_seg > final_seg) //Se virar o dia
    {
        dif = 86400 - inicial_seg + final_seg;
    }
    else // se n�o virar o dia
    {
          dif = final_seg - inicial_seg;
    }

    //transformar de volta em horas, minutos e segundos

    int dif_hs, dif_min, dif_seg;

    dif_hs = dif/3600; //divide para saber a quantidade inteira de horas
    dif = dif % 3600;  //calcula o resto que ser� transformado em minutos
    dif_min = dif/60; //resto das horas sendo transformado em minutos
    dif_seg = dif % 60; // calcula o resto dos minutos que ser�o os segundos


    printf("O intervalo foi de %d h %d min %d s\n\n", dif_hs, dif_min, dif_seg);

    pergunta: //volta a perguntar se usu�rio digital algo diferente de S, s, N ou n.
    printf("Se deseja um novo c�lculo digite 'S' ou 's'. Caso contr�rio, digite 'N' ou 'n'.\n");
    scanf(" %c",&continuar);
    if(continuar!='S'&&continuar!='s'&&continuar!='N'&&continuar!='n')
    {
        printf("A op��o escolhida � inv�lida.\n");
        goto pergunta;
    }

    }while(continuar=='S'||continuar=='s');

}


#endif // ex4


    #ifdef ex5

    /*Receba via teclado a distancia em km e a quantidade de litros de gasolina
    consumidos por um carro em um percurso.
    Calcule o consumo em km/l e escreva uma mensagem de acordo com a tabela
    abaixo:
    CONSUMO (km/l) MENSAGEM
    menor que 8    Venda o carro!
    entre 8 e 14   Economico!
    maior que 14   Super economico!*/

    main()
    {
    float km,gasolina,consumo;
    char continuar;
    setlocale(LC_ALL,"Portuguese");

    do{

    do
    {
    printf("Insira a km rodada: ");
    scanf("%f",&km);
    if(km<=0)
    printf("Valor inv�lido. Tente novamente.\n");
    }while(km<=0);

    do
    {
    printf("Insira a gasolina (L) consumida:");
    scanf("%f",&gasolina);
    if(gasolina<=0)
    printf("Valor inv�lido. Tente novamente.\n");
    }while(gasolina<=0);

    consumo=km/gasolina;

    if(consumo<8)
        printf("\nO consumo � %.2f. Venda o carro!\n\n",consumo);

    else
    if(consumo<=14)
        printf("\nO consumo � %.2f. Econ�mico.\n\n",consumo);

    else
    printf("\nO consumo � %.2f. Super econ�mico!\n\n",consumo);

    confirma:
    printf("Quer realizar um novo c�lculo? Digite 'S' ou 's' para sim. Caso contr�rio, digite 'N' ou 'n'.\n");
    scanf(" %c",&continuar);
    if(continuar!='S'&&continuar!='s'&&continuar!='N'&&continuar!='n')
    {
        printf("A op��o escolhida � inv�lida.\n");
        goto confirma;
    }

    }while(continuar=='S'||continuar=='s');

    }


    #endif // ex5
