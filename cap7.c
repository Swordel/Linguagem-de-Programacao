#include <stdio.h>
#include <locale.h>

//OBS.: Todos os programa devem ser finalizados pelo usuario.

#define ex3

#ifdef ex1
/*1 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estruturas de 4 elementos. Receba os dados pelo teclado em uma funcao
    e imprima-os no video em uma funcao. Utilize vetor de estruturas.
    Faca um menu com uma opcao para saida do programa.
		estrutura: nome, end, cidade, estado, cep*/


		struct dados{
		    char nome[20];
		    char end[20];
		    char cidade[20];
		    char estado[20];
		    char cep[11];
            };

    struct dados destinatario[4];



    void receber(){

    int cont;
    for(cont=0;cont<4;cont++)
    {
        printf("Nome: ");
        gets(destinatario[cont].nome);
        printf("Endereço: ");
        gets(destinatario[cont].end);
        printf("Cidade: ");
        gets(destinatario[cont].cidade);
        printf("Estado: ");
        gets(destinatario[cont].estado);
        printf("CEP: ");
        gets(destinatario[cont].cep);
        printf("\n");

    }

    }

     void imprimir(){

    int cont;
    for(cont=0;cont<4;cont++)
    {
        printf("\n\nNome: %s",destinatario[cont].nome);
        printf("\nEndereço: %s",destinatario[cont].end);
        printf("\nCidade: %s",destinatario[cont].cidade);
        printf("\nEstado: %s",destinatario[cont].estado);
        printf("\nCEP: %s",destinatario[cont].cep);
    }

    }

    main(){

         int opcao;
         setlocale(LC_ALL,"Portuguese");

         for(;;){

         printf("\n\nEscolha uma opção: \n");
         printf("1 - Digitar Dados \n2 - Imprimir Dados \n3 - Finalizar\n");
         scanf("%d",&opcao);
         getchar();

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

#endif // ex1


#ifdef ex2

/*2 - Escreva um programa com a estrutura de dados abaixo. Receba 2 datas via
    teclado na funcao main(). Faca uma funcao que calcule o numero de dias
    entre elas e mostre o resultado no video na funcao main().
    Utilize vetor de estruturas.
                estrutura: dia, mes, ano*/
struct dados {

    int dia;
    int mes;
    int ano;

};

struct dados data [2];

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
        total[c]=data[c].dia;
        //adiciona os dias dos anos completos
        for(i=1583; i < data[c].ano; i++){
            total[c]+= Bissexto(i) ? 366 : 365; //verifica se for bissexto, se sim soma 366.
        }

        //adiciona os dias dos meses anteriores, por isso mes -1
        for(i=0; i< data[c].mes-1; i++){
            total[c] += diasPorMes[i];
            int Bissexto = (data[c].ano % 4 == 0 && data[c].ano % 100 != 0) || (data[c].ano % 400 == 0);
            if(i == 1 && Bissexto){ //mes == 1 é fevereiro
                total[c] +=1;
            }
        }
    }//fim for do vetor global

    return total[1]-total[0];
}

int main(){

    int cont;
    char c;
    setlocale(LC_ALL,"Portuguese");

   do{
        for(cont=0;cont<2;cont++){

        printf("Digite dia mês ano %s :", (cont==0) ? "inicial" : "final");
        scanf("%d %d %d",&data[cont].dia,&data[cont].mes,&data[cont].ano);

    }

        int sub = totalDias();

        printf("A diferença é de %d %s", sub, (sub<=1) ? "dia" : "dias" );

        printf("\nDeseja realizar outra operação? Pressione S para continuar ou qualquer tecla para encerrar: ");
        scanf(" %c",&c);
        printf("\n");

   }while(c == 'S' || c == 's');
}





#endif // ex2


#ifdef ex3

/*
3 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    Receba dados via teclado em uma funcao e imprima estes conteudos no video,
    em outra funcao, no seguinte formato.
     estrutura: char, int, long, float, double, unsigned char, unsigned int,
                unsigned long

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long*/

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

struct estrutura regua;

void receber_dados(){

        printf("Char: ");
        scanf("%c",&regua.caractere);
        printf("Int: ");
        scanf("%d",&regua.inteiro);
        printf("Long: ");
        scanf("%ld",&regua.longo);
        printf("Float: ");
        scanf("%f",&regua.flutuante);
        printf("Double: ");
        scanf("%lf",&regua.duplo);
        printf("Unsigned Char: ");
        scanf("%u",&regua.uncaractere);
        getchar();
        printf("Unsigned Int: ");
        scanf("%u",&regua.uninteiro);
        printf("Unsigned Long: ");
        scanf("%lu",&regua.unlongo);
        printf("\n");

    }

     void imprimir_dados(){

     printf("         10        20        30        40        50        60        70\n");
     printf("1234567890123456789012345678901234567890123456789012345678901234567890123456789\n");
     printf("    %c         %-11d   %-11ld     %-9.1e           %-9.1e\n",regua.caractere,regua.inteiro,regua.longo,regua.flutuante,regua.duplo);
     printf("          %-3u                 %-10u          %-10lu\n",regua.uncaractere,regua.uninteiro,regua.unlongo);

    }

     main(){

      int opcao;
         setlocale(LC_ALL,"Portuguese");

         for(;;){

         printf("\n\nEscolha uma opção: \n");
         printf("1 - Digitar Dados \n2 - Imprimir Dados \n3 - Finalizar\n");
         scanf("%d",&opcao);
         getchar();

         switch (opcao){

         case 1:
            receber_dados();
            break;

         case 2:
            imprimir_dados();
            break;

         case 3:
            exit(0);

         default:
            printf("Opção inválida");
            break;
         }
         }
    }

#endif // ex3

#ifdef ex4

struct infos{
    char nome[20];
    float peso;
    float altura;
};

struct infos IMC[4];

void entrada_dados() {

    int i;
    for (i = 0; i < 4; i++) {
        printf("\nNome: ");
        gets(IMC[i].nome);
        printf("Peso: ");
        scanf("%f",&IMC[i].peso);
        printf("Altura (metros): ");
        scanf("%f",&IMC[i].altura);
        getchar();
    }

}

void listar_dados() {

    int i;
    for (i = 0; i < 4; i++) {
        printf("Nome: %s\n",IMC[i].nome);
        printf("Peso: %.2f\n",IMC[i].peso);
        printf("Altura: %.2f\n\n",IMC[i].altura);


}
}

void calcular(){

int i;
float imc;

    for (i = 0; i < 4; i++) {
        imc = IMC[i].peso/((IMC[i].altura)*(IMC[i].altura));
        printf("IMC [%s] = %.2f\n",IMC[i].nome,imc);


}
}

main() {
    setlocale(LC_ALL,"Portuguese");
    int opcao;

    for( ; ; ){
        printf("\nMenu:\n");
        printf("1 - Entrada de dados\n");
        printf("2 - Listar todos os dados\n");
        printf("3 - Calcular IMC\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();
        printf("\n");


        switch (opcao) {
            case 1: entrada_dados();
            break;
            case 2: listar_dados();
            break;
            case 3: calcular();
            break;
            case 4: printf("Saindo...\n");
            exit(0);
            default: printf("Opção inválida!\n");
        }
    }

}

#endif // ex4
