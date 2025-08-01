#include <stdio.h>
#include <locale.h>

struct dados {
    char nome[30];
    char autor[30];
    int estoque;
    float preco;
};

void receber(struct dados *pd){

FILE *arquivo;

if((arquivo = fopen("musicas","a"))==NULL){
	printf("erro na abertura do arquivo \n");
	exit(0);}

	printf("- Entrada de Dados da Música -\n");
    printf("Música: ");
    gets(pd->nome);
    printf("Autor: ");
    gets(pd->autor);
    printf("Quantidade em estoque: ");
    scanf("%d", &pd->estoque);
    getchar();
    printf("Preço: ");
    scanf("%f", &pd->preco);
    getchar();
    printf("\n");

    fwrite(pd,sizeof(*pd),1,arquivo);
    fclose(arquivo);
}

void imprimir(struct dados *pd){

    printf("- Lista de Músicas -\n");

    FILE *arquivo;
    if((arquivo = fopen("musicas","r"))==NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);}

     while(fread(pd,sizeof(*pd),1,arquivo)== 1){
        if(pd->nome[0] != '*'){
            printf("-----------------------\n");
            printf("Música: %s",pd->nome);
            printf("\nAutor: %s",pd -> autor);
            printf("\nQuantidade: %d",pd -> estoque);
            printf("\nPreço: %.2f",pd -> preco);
            printf("\n-----------------------\n");}}

        fclose(arquivo);
    }

long procurar (struct dados *pd){

    char busca[20];
    int c;
    long registro=0;

    FILE *arquivo = fopen("musicas","r");

    printf("Digite o nome completo da música: ");
    gets(busca);

    while (fread(pd,sizeof(*pd),1,arquivo)== 1){
            for(c=0;busca[c]!='\0';c++){
                if (busca[c] != pd->nome[c]){
                    break;}}

            if(busca[c] == '\0' && pd->nome[c] == '\0'){
                printf("-----------------------\n");
                printf("Música: %s",pd-> nome);
                printf("\nAutor: %s",pd -> autor);
                printf("\nQuantidade: %d",pd -> estoque);
                printf("\nPreço: %.2f",pd -> preco);
                printf("\n-----------------------\n");

                fclose(arquivo);
                return registro;
                }

              registro++;

        }

    printf("Música não encontrada!\n");
    fclose(arquivo);
    return -1;
}

void pesquisar_autor(struct dados *pd){

    char letra;
    int encontrou = 0;

    printf("Digite a primeira letra do autor: ");
    letra = getchar();
    getchar();

    FILE *arquivo;
    if((arquivo = fopen("musicas","r"))==NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);}

     while(fread(pd,sizeof(*pd),1,arquivo)== 1){
        if(pd->autor[0] == letra && pd->nome[0] !='*'){
            printf("-----------------------\n");
            printf("Música: %s",pd->nome);
            printf("\nAutor: %s",pd -> autor);
            printf("\nQuantidade: %d",pd -> estoque);
            printf("\nPreço: %.2f",pd -> preco);
            printf("\n-----------------------\n");
            encontrou = 1;

            }
        }

        if(!encontrou)
            printf("Autor não encontrado!\n");

        fclose(arquivo);
}

void listar_faixa_preco(struct dados *pd) {

    float min, max;
    int encontrou = 0;
    FILE *arquivo;

    if((arquivo = fopen("musicas","r"))==NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);}

    printf("Digite preço mínimo: ");
    scanf("%f", &min);
    printf("Digite preço máximo: ");
    scanf("%f", &max);


    while(fread(pd,sizeof(*pd),1,arquivo)== 1){
        if(pd->preco >= min && pd->preco <= max && pd->nome[0] !='*'){
            printf("-----------------------\n");
            printf("Música: %s",pd->nome);
            printf("\nAutor: %s",pd -> autor);
            printf("\nQuantidade: %d",pd -> estoque);
            printf("\nPreço: %.2f",pd -> preco);
            printf("\n-----------------------\n");
            encontrou = 1;
            }
        }

        if(!encontrou)
            printf("Nenhuma música está nessa faixa de preço!\n");

        fclose(arquivo);
}

void altera_estoque(struct dados *pd){

    long indice,deslocamento;
    int valor;

    printf("- Alterar Quantidade Atual -\n");
    indice = procurar(pd);

    FILE *arquivo;
    if((arquivo = fopen("musicas","r+"))==NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);}

    if(indice != -1){

            printf("\n");
            printf("Digite um número positivo para entrada e um número negativo para saída:");
            scanf("%d", &valor);
            printf("\n");

            pd->estoque +=valor;


            deslocamento = indice * sizeof(*pd);
            fseek(arquivo,deslocamento,0);
            fwrite(pd,sizeof(*pd),1,arquivo);
            printf("Quantidade alterada com sucesso!\n");
    }
    fclose(arquivo);
}

void altera_preco(struct dados *pd){

    long indice,deslocamento;

    printf("- Alterar Preço -\n");
    indice = procurar(pd);

    FILE *arquivo;
    if((arquivo = fopen("musicas","r+"))==NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);}

    if(indice != -1){

            printf("\n");
            printf("Preço Atualizado: ");
            scanf("%f", &pd->preco);
            printf("\n");


            deslocamento = indice * sizeof(*pd);
            fseek(arquivo,deslocamento,0);
            fwrite(pd,sizeof(*pd),1,arquivo);
            printf("Preço alterado com sucesso!\n");
    }
    fclose(arquivo);

}

void altera_dados(struct dados *pd){

    long indice,deslocamento;

    printf("- Alterar Dados da Música -\n");
    indice = procurar(pd);

    FILE *arquivo;
    if((arquivo = fopen("musicas","r+"))==NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);}


    if(indice != -1){

            printf("Música Atualizada: ");
            gets(pd->nome);
            printf("Autor: ");
            gets(pd->autor);
            printf("Quantidade em estoque: ");
            scanf("%d", &pd->estoque);
            getchar();
            printf("Preço: ");
            scanf("%f", &pd->preco);
            getchar();
            printf("\n");


            deslocamento = indice * sizeof(*pd);
            fseek(arquivo,deslocamento,0);
            fwrite(pd,sizeof(*pd),1,arquivo);
    }
    fclose(arquivo);
}

void excluir(struct dados *pd){

    long indice,deslocamento;

    printf("- Excluir Música -\n");
    indice = procurar(pd);

    FILE *arquivo;
    if((arquivo = fopen("musicas","r+"))==NULL){
                printf("erro na abertura do arquivo \n");
                exit(0);}


    if(indice != -1){

            deslocamento = indice * sizeof(*pd);

            fseek(arquivo,deslocamento,0);
            fread(pd,sizeof(*pd),1,arquivo);
            pd->nome[0]='*';

            fseek(arquivo,deslocamento,0);
            fwrite(pd,sizeof(*pd),1,arquivo);
            printf("Dados da música acima excluídos com sucesso!\n\n");
        }
    fclose(arquivo);
}


int main(){

         struct dados musicas, *pm;
         int opcao;
         setlocale(LC_ALL,"Portuguese");

         pm = &musicas;

         for(;;){
        printf("\n\n- MENU PRINCIPAL -\n");
        printf("\n1 - Entrada de dados da música\n");
        printf("2 - Lista todas as músicas\n");
        printf("3 - Pesquisar uma música pelo nome completo\n");
        printf("4 - Pesquisar autor pela 1ª letra\n");
        printf("5 - Listar músicas por faixa de preço\n");
        printf("6 - Altera quantidade em estoque\n");
        printf("7 - Altera preço de uma música\n");
        printf("8 - Altera todos os dados da música\n");
        printf("9 - Exclui a música\n");
        printf("10 - Sair\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);
        getchar();
        printf("\n");

        switch (opcao){

         case 1:
            receber(pm);
            break;
        case 2:
            imprimir(pm);
            break;
        case 3:
            procurar(pm);
            break;
        case 4:
            pesquisar_autor(pm);
            break;
        case 5:
            listar_faixa_preco(pm);
            break;
        case 6:
            altera_estoque(pm);
            break;

        case 7:
            altera_preco(pm);
            break;
        case 8:
            altera_dados(pm);
            break;
        case 9:
            excluir(pm);
            break;
        case 10:
            printf("Saindo...\n");
            exit(0);

        default:
            printf("Opção inválida!\n");
            break;
        }
    }
}


