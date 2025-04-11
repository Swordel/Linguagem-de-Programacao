#include <stdio.h>
#include <locale.h>

char nome_musica[3][20];
char nome_autor[3][20];

void entrada_dados();
void listar_dados();
void pesquisar_musica();
void pesquisar_autor();
void alterar_dados();
void excluir_dados();


main() {
    setlocale(LC_ALL,"Portuguese");
    int opcao;



    for( ; ; ){
        printf("\nMenu:\n");
        printf("1 - Entrada de dados\n");
        printf("2 - Listar todos os dados\n");
        printf("3 - Pesquisar por nome da música completo\n");
        printf("4 - Pesquisar por primeira letra do autor\n");
        printf("5 - Alterar dados\n");
        printf("6 - Excluir dados\n");
        printf("7 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();


        switch (opcao) {
            case 1: entrada_dados();
            break;
            case 2: listar_dados();
            break;
            case 3: pesquisar_musica();
            break;
            case 4: pesquisar_autor();
            break;
            case 5: alterar_dados();
            break;
            case 6: excluir_dados();
            break;
            case 7: printf("Saindo...\n");
            exit(0);
            default: printf("Opção inválida!\n");
        }
    }

}

void entrada_dados() {

    FILE *arquivo = fopen("musicas","w");

    int i;
    for (i = 0; i < 3; i++) {
        printf("Nome da música [%d]: ", i + 1);
        gets(nome_musica[i]);
        printf("Nome do autor [%d]: ", i + 1);
        gets(nome_autor[i]);
    }
    fwrite(nome_musica, sizeof(nome_musica),1,arquivo);
    fwrite(nome_autor, sizeof(nome_autor),1,arquivo);

    fclose(arquivo);

}

void listar_dados() {

    FILE *arquivo = fopen("musicas","r");


    fread(nome_musica, sizeof(nome_musica),1,arquivo);
    fread(nome_autor, sizeof(nome_autor),1,arquivo);

    int i;
    for (i = 0; i < 3; i++) {
        if(nome_musica[i][0]!='*')
            printf("Música: %-19s | Autor: %-19s\n", nome_musica[i], nome_autor[i]);
    }

    fclose(arquivo);
}

void pesquisar_musica(){

    FILE *arquivo = fopen("musicas","r");


    fread(nome_musica, sizeof(nome_musica),1,arquivo);
    fread(nome_autor, sizeof(nome_autor),1,arquivo);

    int l,c;
    char busca[20];

    printf("Digite a música que deseja: ");
    gets(busca);

    for(l=0;l<3;l++){
        for(c=0;busca[c]!='\0';c++){
            if (busca[c] != nome_musica[l][c])
                break;} //fim for coluna

        if(busca[c] == '\0' && nome_musica[l][c] == '\0'){
                printf("Música: %-19s | Autor: %-19s\n", nome_musica[l], nome_autor[l]);
                break;}
        }//fim for linha
        if(l==3)
            printf("Música não encontrada.\n");

     fclose(arquivo);
}

void pesquisar_autor(){

    FILE *arquivo = fopen("musicas","r");


    fread(nome_musica, sizeof(nome_musica),1,arquivo);
    fread(nome_autor, sizeof(nome_autor),1,arquivo);

    int l,cont=0;
    char busca;

    printf("Digite a primeira letra do autor que deseja: ");
    busca=getchar();

    for(l=0;l<3;l++){
            if (busca == nome_autor[l][0] && nome_musica[l][0]!='*')
                    printf("Música: %-19s | Autor: %-19s\n", nome_musica[l], nome_autor[l]);
            else
                cont++;
    }

    if(cont==3)
        printf("Autor não encontrado. \n");

     fclose(arquivo);

}

void alterar_dados(){

    FILE *arquivo = fopen("musicas","r");

    fread(nome_musica, sizeof(nome_musica),1,arquivo);
    fread(nome_autor, sizeof(nome_autor),1,arquivo);

    fclose(arquivo);

    int l,c;
    char busca[20];

    printf("Digite a música que deseja alterar: ");
    gets(busca);

    for(l=0;l<3;l++){
        for(c=0;busca[c]!='\0';c++){
            if (busca[c] != nome_musica[l][c])
                break;} //fim for coluna

        if(busca[c] == '\0' && nome_musica[l][c] == '\0'){
                 printf("Digite a nova música: ");
                 gets(nome_musica[l]);
                 printf("Nome do autor: ");
                 gets(nome_autor[l]);
                 break;}

    }//fim for linha
        if(l==3)
            printf("Música não encontrada.\n");

    arquivo = fopen("musicas","w");

    fwrite(nome_musica, sizeof(nome_musica),1,arquivo);
    fwrite(nome_autor, sizeof(nome_autor),1,arquivo);

    fclose(arquivo);
}

void excluir_dados(){

    FILE *arquivo = fopen("musicas","r");

    fread(nome_musica, sizeof(nome_musica),1,arquivo);
    fread(nome_autor, sizeof(nome_autor),1,arquivo);

    fclose(arquivo);

    int l,c;
    char busca[20];

    printf("Digite a música que deseja excluir: ");
    gets(busca);

    for(l=0;l<3;l++){
        for(c=0;busca[c]!='\0';c++){
            if (busca[c] != nome_musica[l][c])
                break;} //fim for coluna

        if(busca[c] == '\0' && nome_musica[l][c] == '\0'){
                 nome_musica[l][0]='*';
                 break;}
    }//fim for linha
        if(l==3)
            printf("Música não encontrada.\n");

    arquivo = fopen("musicas","w");

    fwrite(nome_musica, sizeof(nome_musica),1,arquivo);
    fwrite(nome_autor, sizeof(nome_autor),1,arquivo);

    fclose(arquivo);

}

