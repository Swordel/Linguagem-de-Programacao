#include<stdio.h>
#include <locale.h>

#define ex3

#ifdef ex1
/*Escreva um programa que receba via teclado uma data (dia, mes, e ano).
    Determine o dia da semana desta data.*/

int Bissexto (int ano){
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0); //o ano � bissexto se � divis�vel por 4 mas n�o por 100. Tbm se for divis�vel por 400.
}

main(){
setlocale(LC_ALL,"Portuguese");
int dia,mes,ano,i,total,diaSemana;
int refAno = 1582; // Data de refer�ncia do calend�rio gregoriano (15/10/1582 foi uma sexta-feira)
int diasMeses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char c;

do{
    total = 0;

    do{
    printf("- Insira a data -\n");
    printf("Dia: ");
    scanf("%d",&dia);
    printf("M�s: ");
    scanf("%d",&mes);
    printf("Ano: ");
    scanf("%d",&ano);

    if (ano < 1582 || (ano == 1582) && (mes < 10) || (mes == 10) && (dia < 15))
        printf("O calend�rio gregoriano s� come�ou em 15/10/1582.\n\n");
    }while(ano < 1582 || (ano == 1582) && (mes < 10) || (mes == 10) && (dia < 15));

    for (i = refAno; i < ano; i++) {  // contando dias dos anos completos desde 1582 at� o ano anterior ao informado
        total += Bissexto(i) ? 366 : 365;
    }

    if(ano>1582){
        total -= 287; //subtraindo os dias que passaram de 1582 at� 15/10

        for (i = 0; i < mes - 1; i++) { // Contar dias dos meses completos do ano informado
            total += diasMeses[i];

            if (i == 1 && Bissexto(ano)) // Ajuste para fevereiro em ano bissexto
            total += 1;
        }

    total += dia;
    }

    else if(ano == 1582)
                if (mes == 10)
                    total += dia - 14; //soma o dia informado e subtrai os 14 dias que j� se passaram em outubro de 1582

                else{ // Somar os dias de outubro (a partir do dia 15) e os meses seguintes
                    total += 17; // De 15 a 31 de outubro

                    for (i = 10; i < mes - 1; i++) {
                        total += diasMeses[i];
                    }

                    total += dia;

                }

    //printf("%d",total); //teste pra ver os dias que passaram

    diaSemana = total % 7;

    printf("A data %02d/%02d/%04d ---> ", dia, mes, ano);

    if(diaSemana==1)
        printf("Sexta-feira");
    else if(diaSemana==2)
        printf("S�bado");
    else if(diaSemana==3)
        printf("Domingo");
    else if(diaSemana==4)
        printf("Segunda-feira");
    else if(diaSemana==5)
        printf("Ter�a-feira");
    else if(diaSemana==6)
        printf("Quarta-feira");
    else
        printf("Quinta-feira");


printf("\n\nDeseja realizar outra opera��o? Pressione S para continuar ou qualquer tecla para encerrar: ");
scanf(" %c",&c);
printf("\n");
}while(c == 'S' || c == 's');

}
#endif // ex1



#ifdef ex2
/* Escreva um programa para determinar a idade de uma pessoa, em anos, meses e
    dias, recebendo via teclado a data (dia, mes e ano) do seu nascimento e a
    data (dia, mes e ano) atual.*/


int Bissexto (int ano){

return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);

}
main(){
setlocale(LC_ALL,"Portuguese");
int diaN,mesN,anoN;
int dia,mes,ano;
int anos,meses,dias;
char c;

do{
    printf("- Data de nascimento -\n");
    printf("Dia: ");
    scanf("%d",&diaN);
    printf("M�s: ");
    scanf("%d",&mesN);
    printf("Ano: ");
    scanf("%d",&anoN);
    printf("\n");
    printf("- Data de hoje -\n");
    printf("Dia: ");
    scanf("%d",&dia);
    printf("M�s: ");
    scanf("%d",&mes);
    printf("Ano: ");
    scanf("%d",&ano);


    anos = ano - anoN;
    meses = mes - mesN;
    dias = dia - diaN;

    if (dias < 0){
        meses -= 1;

        if (mes == 03)   // Se o m�s atual for mar�o, o anterior � fevereiro
            dias += Bissexto(ano) ? 29 : 28;
        else if (mes == 05 || mes == 07 || mes == 10 || mes == 12)
            dias += 30;  // sempre em rela��o ao anterior -> Meses de 30 dias (abril, junho, setembro, novembro)
        else
            dias += 31;  // Meses de 31 dias (janeiro, mar�o, maio, julho, agosto, outubro, dezembro)
        }

    if (meses < 0){
        anos -= 1; //ainda nao completei a idade
        meses += 12; //se passaram tantos meses desde o meu anivers�rio
    }


    printf("\n");
    printf("- Sua idade -\n");
    printf("%d anos, %d meses e %d dias!\n",anos,meses,dias);


printf("\nDeseja realizar outra opera��o? Pressione S para continuar ou qualquer tecla para encerrar: ");
scanf(" %c",&c);
printf("\n");
}while(c == 'S' || c == 's');
}


#endif // ex2

#ifdef ex3
/*
Escreva um programa que receba via teclado 2 numeros inteiros e execute
    as operacoes logicas bit a bit AND, OU, OU EXCLUSIVO e imprima-os no
    video no formato decimal e hexadecimal.*/

main(){
setlocale(LC_ALL,"Portuguese");
int a,b;
char c;

do{

printf("Digite o primeiro n�mero: ");
scanf("%d",&a);

printf("Digite o segundo n�mero: ");
scanf("%d",&b);

printf("AND               a & b --> %3d  0x%x\n",a & b,a & b);
printf("OU                a | b --> %3d  0x%x\n",a | b,a | b);
printf("OU EXCLUSIVO      a ^ b --> %3d  0x%x\n",a ^ b,a ^ b);

printf("\nDeseja realizar outra opera��o? Pressione S para continuar ou qualquer tecla para encerrar: ");
scanf(" %c",&c);
printf("\n");
}while(c == 'S' || c == 's');
}
#endif

#ifdef ex4
/*Escreva um programa que receba via teclado 2 numeros inteiros e
    imprima-os no video com o resultado das 4 operacoes aritmeticas.*/

main(){
setlocale(LC_ALL,"Portuguese");
int a,b;
char c;

do{

printf("Digite o primeiro n�mero: ");
scanf("%d",&a);

printf("Digite o segundo n�mero: ");
scanf("%d",&b);

printf("Soma               %d + %d --> %-4d\n",a,b,a+b);
printf("Subtra��o          %d - %d --> %-4d\n",a,b,a-b);
printf("Multiplica��o      %d * %d --> %-4d\n",a,b,a*b);
printf("Divis�o            %d / %d --> %-4.2f\n",a,b,(float)a/b);

printf("\nDeseja realizar outra opera��o? Pressione S para continuar ou qualquer tecla para encerrar: ");
scanf(" %c",&c);
printf("\n");
}while(c == 'S' || c == 's');
}
#endif

#ifdef ex5
/*Reescreva o exercicio anterior utilizando operadores de atribuicao
    composta.*/

main(){
setlocale(LC_ALL,"Portuguese");
int a,b,R;
float D;
char c;

do{

printf("Digite o primeiro n�mero: ");
scanf("%d",&a);

printf("Digite o segundo n�mero: ");
scanf("%d",&b);

R = a;
printf("Soma               %d + %d --> %-4d\n",a,b,R+=b);

R = a;
printf("Subtra��o          %d - %d --> %-4d\n",a,b,R-=b);

R = a;
printf("Multiplica��o      %d * %d --> %-4d\n",a,b,R*=b);

D = a;
printf("Divis�o            %d / %d --> %-4.2f\n",a,b,D/=b);

printf("\nDeseja realizar outra opera��o? Pressione S para continuar ou qualquer tecla para encerrar: ");
scanf(" %c",&c);
printf("\n");
}while(c == 'S' || c == 's');
}

#endif // ex5
