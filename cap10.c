#include <stdio.h>
#include <locale.h>

#define ex4
//OBS.: Todos os programa devem ser finalizados pelo usuario.

#ifdef ex1
/*1 - Escreva um programa para criar e abrir um arquivo. Receba via
    teclado diversos caracteres (um por vezes) e escreva-os nesse arquivo.
    O caracter '0' finaliza a entrada de dados. Abra o arquivo novamente,
    leia e imprima na tela todos os caracteres armazenados no
    arquivo (um por vezes).*/

    main()
    {
        FILE *pontarq;
        char caracter,opcao;

        do{//laço para reiniciar o programa ou não

        if((pontarq = fopen("cap10ex1","w"))==NULL){
            printf("erro na abertura do arquivo \n");
            exit(0);}

        printf("Digite um caracter por vez. Para encerrar, digite 0:\n");

        while(1){
        caracter = getchar();
        getchar();

            if(caracter=='0')
                break;
            else
                putc(caracter,pontarq);


        }

        fclose(pontarq);

        if((pontarq = fopen("cap10ex1","r"))==NULL){
            printf("erro na abertura do arquivo \n");
            exit(0);}

        printf("Dados no arquivo: \n");

        while ((caracter = getc(pontarq)) != EOF) {//enquanto o char verificado for diferente do finalizador do arquivo
            putchar(caracter);//imprime na tela por caracter apenas, pois getc já pegou o valor do arquivo e jogou na variável na condição do while
            putchar('\n');}

        fclose(pontarq);

        printf("Deseja reiniciar? Digite 'S'. Caso contrário, pressione qualquer outra tecla para encerrar.\n");
        scanf(" %c",&opcao);
        getchar();

        }while(opcao =='S' || opcao =='s');
   }

#endif // ex1

#ifdef ex2
/*2 - Escreva um programa para gerenciar uma agenda de contatos. Para cada contato
    armazene o nome, o telefone e o aniversario (dia e mes) em uma estrutura de
    dados. Utilize um vetor de estrutura de 4 elementos como variavel LOCAL na
    funcao main(). Utilize ponteiros para passar o vetor de estrutura para
    as funcoes. Sempre que o programa for encerrado, os contatos devem ser
    escritos no arquivo e quando o programa iniciar os contatos devem ser lidos
    do arquivo.
    O programa deve ter as seguintes opcoes:(cada opcao do menu e' um funcao)
    1 - inserir contato
    2 - listar todos os contatos
    3 - pesquisar um contato pelo nome completo
    4 - listar os contatos cujo nome inicia com uma letra digitada
    5 - imprimir os aniversariantes do mês.
    6 - altera contato pesquisando pelo nome completo
    7 - exclui contato pesquisando pelo nome completo
    8 - saida*/

struct dados{
		    char nome[20];
		    char telefone[13];
		    int dia;
		    int mes;

};

void inserir(struct dados *pd, int tamanho){

    FILE *arquivo = fopen("contatos","w");

    int cont;
    for(cont=0;cont<4;cont++)
    {
        printf("Nome: ");
        gets((pd+cont) -> nome);
        printf("Telefone: ");
        gets((pd+cont) -> telefone);
        printf("Dia de Aniversário: ");
        scanf("%d",&(pd+cont) -> dia);
        printf("Mês de Aniversário: ");
        scanf("%d",&(pd+cont) -> mes);
        getchar();
        printf("\n");
    }

    fwrite(pd, tamanho,1,arquivo);

    fclose(arquivo);
}

void imprimir(struct dados *pd, int tamanho){

    FILE *arquivo = fopen("contatos","r");
    fread(pd, tamanho,1,arquivo);

    int cont;

    for(cont=0;cont<4;cont++)
    {
        if(pd[cont].nome[0] != '*'){
            printf("Nome: %s",(pd+cont) -> nome);
            printf("\nTelefone: %s",(pd+cont) -> telefone);
            printf("\nDia: %d",(pd+cont) -> dia);
            printf("\nMês: %d\n\n",(pd+cont) -> mes);
        }
    }

    fclose(arquivo);
}


int procurar(struct dados *pd, int tamanho){

    FILE *arquivo = fopen("contatos","r");
    fread(pd, tamanho,1,arquivo);

    char busca[20];
    int l,c; // l - > linha (os 4 nomes) e c -> coluna (letras do vetor nome)

    printf("Digite o nome que deseja: ");
    gets(busca);

    for(l=0;l<4;l++){
        for(c=0;busca[c]!='\0';c++){
            if (busca[c] != pd[l].nome[c])
                break;
        } //fim for coluna

        if(busca[c] == '\0' && pd[l].nome[c] == '\0'){
            printf("\nNome: %s",(pd+l)-> nome);
            printf("\nTelefone: %s",(pd+l) -> telefone);
            printf("\nDia: %d",(pd+l) -> dia);
            printf("\nMês: %d\n\n",(pd+l) -> mes);
            return l;
        }//retorna o índice

    }// fim for linha~estrutura

    if(l==4){
        printf("Contato não encontrado!\n\n");
        return -1; //retorna o 4 para ser excluído
    }

    fclose(arquivo);
}

void listar_letra(struct dados *pd, int tamanho){

    FILE *arquivo = fopen("contatos","r");
    fread(pd, tamanho,1,arquivo);

    int l,cont=0;
    char busca;

    printf("Digite a primeira letra do contato que deseja: ");
    busca=getchar();
    printf("\n");

    for(l=0;l<4;l++){
            if (busca == pd[l].nome[0]){
                printf("Nome: %s",(pd+l)-> nome);
                printf("\nTelefone: %s",(pd+l) -> telefone);
                printf("\nDia: %d",(pd+l) -> dia);
                printf("\nMês: %d\n\n",(pd+l) -> mes);
            }
            else
                cont++;
    }

    if(cont==4)
        printf("Nenhum contato inicia com a letra '%c' informada. \n\n",busca);

    fclose(arquivo);
}

void aniversariantes(struct dados *pd, int tamanho){

    FILE *arquivo = fopen("contatos","r");
    fread(pd, tamanho,1,arquivo);

    int l,busca,cont=0;

    printf("Informe o mês de aniversário: ");
    scanf("%d",&busca);
    printf("\n");

    for(l=0;l<4;l++){
            if (busca == pd[l].mes){
                printf("Nome: %s",(pd+l)-> nome);
                printf("\nTelefone: %s",(pd+l) -> telefone);
                printf("\nDia: %d",(pd+l) -> dia);
                printf("\nMês: %d\n\n",(pd+l) -> mes);
            }

            else
                cont++;
    }

    if(cont==4)
        printf("Nenhum contato faz aniversário no mês %d!\n\n",busca);

    fclose(arquivo);
}

void alterar(struct dados *pd, int tamanho){

    int indice;

    printf("- ALTERAR DADOS -\n");
    indice = procurar(pd,tamanho);

    if(indice != -1){
            printf("Nome Atualizado: ");
            gets((pd+indice) -> nome);
            printf("Telefone: ");
            gets((pd+indice) -> telefone);
            printf("Dia de Aniversário: ");
            scanf("%d",&(pd+indice) -> dia);
            printf("Mês de Aniversário: ");
            scanf("%d",&(pd+indice) -> mes);
            printf("\n");
    }

    FILE *arquivo = fopen("contatos","w");
    fwrite(pd, tamanho,1,arquivo);

    fclose(arquivo);
}

void excluir(struct dados *pd, int tamanho){

    int indice;

    printf("- EXCLUIR-\n");
    indice = procurar(pd,tamanho);

    if(indice != -1){
            pd[indice].nome[0]='*';
            printf("Dados do contato acima excluídos com sucesso!\n\n");
    }

    FILE *arquivo = fopen("contatos","w");
    fwrite(pd, tamanho,1,arquivo);

    fclose(arquivo);
}

main(){
         struct dados contato[4];
         struct dados *pc;
         int opcao;
         int tamanho;

         setlocale(LC_ALL,"Portuguese");

         pc = &contato[0];
         tamanho = sizeof(contato);


         for(;;){

         printf("-------------\n");
         printf("\t* MENU *\n");
         printf("1 - Inserir Contato \n2 - Listar todos os contatos \n3 - Pesquisar um contato pelo nome completo \n4 - Listar os contatos cujo nome inicia com uma letra digitada \n5 - Imprimir os aniversariantes do mês. \n6 - Alterar contato pesquisando pelo nome completo. \n7 - Excluir contato pesquisando pelo nome completo. \n8- Sair\n");
         printf("Escolha uma opção: ");
         scanf("%d",&opcao);
         getchar();
         printf("-------------");
         printf("\n\n");

         switch (opcao){

         case 1:
            inserir(pc,tamanho);
            break;

         case 2:
            imprimir(pc,tamanho);
            break;

         case 3:
            procurar(pc,tamanho);
            break;

         case 4:
            listar_letra(pc,tamanho);
            break;

         case 5:
            aniversariantes(pc,tamanho);
            break;

         case 6:
            alterar(pc,tamanho);
            break;

         case 7:
            excluir(pc,tamanho);
            break;

         case 8:

            printf("Saindo...\n");
            exit(0);

         default:
            printf("Opção inválida");
            break;
         }
         }//fim loop infinito
}
#endif // ex2


#ifdef ex3
/*3 - Escreva um programa para controle de um cadastro de clientes. Para cada
    registro sera' armazenado nome, email e celular numa estrutura de dados.
    A unica estrutura de dados e' uma variavel LOCAL na funcao main().
    Escreva os registros direto no arquivo. (utilize a funcao fseek quando
    necessario). NAO pode usar vetor de estruturas. Utilize ponteiros para
    passar parametros para as funcoes.
    O programa deve ter as seguintes opcoes: (cada opcao do menu e' um funcao)
    1 - inclui registros
    2 - listar todos os registros
    3 - pesquisar registro pelo nome
    4 - altera registro
    5 - exclui registro
    6 - saida*/


     struct dados{
		    char nome[20];
		    char email[30];
		    char celular[13];
		   };

void receber(struct dados *pd){

FILE *arquivo;
if((arquivo = fopen("contatoscap10ex3","a"))==NULL){
	printf("erro na abertura do arquivo \n");
	exit(0);}

	printf("- Inclusão de Registros -\n");
    printf("Nome: ");
    gets(pd->nome);
    printf("Email: ");
    gets(pd->email);
    printf("Celular: ");
    gets(pd->celular);
    printf("\n");

    fwrite(pd,sizeof(*pd),1,arquivo);
    fclose(arquivo);
}

void imprimir(struct dados *pd){

    printf("- Listar Dados -\n");

    FILE *arquivo;
    if((arquivo = fopen("contatoscap10ex3","r"))==NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);}

     while(fread(pd,sizeof(*pd),1,arquivo)== 1){//Enquanto fread retornar que leu dados do arquivo com sucesso
        if(pd->nome[0] != '*'){
            printf("-----------------------\n");
            printf("Nome: %s",pd->nome);
            printf("\nEmail: %s",pd -> email);
            printf("\nCelular: %s",pd -> celular);
            printf("\n-----------------------\n");}}

        fclose(arquivo);
    }

long procurar (struct dados *pd){
    char busca[20];
    int c;
    long registro=0; // número do indice para retornar em outras funções e calcular deslocamento para usar em fseek

    FILE *arquivo = fopen("contatoscap10ex3","r");

    printf("Digite o nome que deseja: ");
    gets(busca);

    while (fread(pd,sizeof(*pd),1,arquivo)== 1){
            for(c=0;busca[c]!='\0';c++){
                if (busca[c] != pd->nome[c]){
                    break;}} //fim laço comparação letra a letra

            if(busca[c] == '\0' && pd->nome[c] == '\0'){
                printf("-----------------------\n");
                printf("Nome: %s",pd->nome);
                printf("\nEmail: %s",pd -> email);
                printf("\nCelular: %s",pd -> celular);
                printf("\n-----------------------\n");

                fclose(arquivo);
                return registro;//volta para a função que chamou se achar o nome e retorna o índice/registro
                }

            //se não achar o nome, acrescenta na numeração do índice/registro
                registro++;

        }
    //se não encontrou o nome no if, não retorna para a main, então na saída do laço vem para cá
    printf("Contato não encontrado!\n");
    fclose(arquivo);
    return -1;
}

void alterar(struct dados *pd){

    long indice,deslocamento;


    printf("- Alterar Dados -\n");
    indice = procurar(pd);

    FILE *arquivo;
    if((arquivo = fopen("contatoscap10ex3","r+"))==NULL){ //não usar a pois adiciona um novo registro, ao invés de alterar
                printf("erro na abertura do arquivo \n");
                exit(0);}


    if(indice != -1){

            printf("\n");
            printf("Nome Atualizado: ");
            gets(pd->nome);
            printf("Email: ");
            gets(pd->email);
            printf("Celular: ");
            gets(pd->celular);
            printf("\n");

            //Posiciona o ponteiro no início do registro para escrever no arquivo
            deslocamento = indice * sizeof(*pd);
            fseek(arquivo,deslocamento,0);
            fwrite(pd,sizeof(*pd),1,arquivo);
    }
    fclose(arquivo);
}

void excluir(struct dados *pd){

    long indice,deslocamento;

    printf("- Excluir Dados -\n");
    indice = procurar(pd);

    FILE *arquivo;
    if((arquivo = fopen("contatoscap10ex3","r+"))==NULL){
                printf("erro na abertura do arquivo \n");
                exit(0);}

    if(indice != -1){

            deslocamento = indice * sizeof(*pd);

            fseek(arquivo,deslocamento,0);
            fread(pd,sizeof(*pd),1,arquivo);
            pd->nome[0]='*';

            fseek(arquivo,deslocamento,0);
            fwrite(pd,sizeof(*pd),1,arquivo);
            printf("Dados do contato acima excluídos com sucesso!\n\n");
        }
    fclose(arquivo);
}

main(){

         struct dados clientes, *pcli;
         int opcao;
         setlocale(LC_ALL,"Portuguese");

         pcli = &clientes;

         for(;;){
         printf("\n\n- MENU PRINCIPAL (e único)-\n");
         printf("1 - Incluir Registros \n2 - Listar todos os registros \n3 - Pesquisar registro pelo nome \n4 - Alterar registro \n5 - Excluir registro \n6 - Sair\n");
         printf("Escolha uma opção: ");
         scanf("%d",&opcao);
         getchar();
         printf("\n");

         switch (opcao){

         case 1:
            receber(pcli);
            break;

         case 2:
            imprimir(pcli);
            break;

         case 3:
            procurar(pcli);
            break;

         case 4:
            alterar(pcli);
            break;

         case 5:
            excluir(pcli);
            break;

         case 6:
            printf("Saindo...\n");
            exit(0);

         default:
            printf("Opção inválida");
            break;
         }
         }//fim loop infinito
}

#endif // ex3

#ifdef ex4
/*4 - Escreva um programa para o controle de mercadorias em uma dispensa
    domestica. Para cada produto sera' armazenado um codigo numerico, nome
    do produto e quantidade atual numa estrutura de dados. A unica estrutura
    de dados deve ser declarada como variavel LOCAL na funcao main(). Escreva
    os itens das mercadorias direto no arquivo. (utilize a funcao fseek quando
    necessario). NAO pode usar vetor de estruturas. Utilize ponteiros.
    O programa deve ter as seguintes opcoes: (cada opcao do menu e' um funcao)
    1 - inclui produtos
    2 - listar todos os produtos
    3 - pesquisar uma mercadoria pela descrição
    4 - listar os produtos não disponíveis.
    5 - alterar a quantidade atual
    6 - altera produtos
    7 - exclui produtos
    8 - saida*/



struct dados{
		    char codigo_num[5];
		    char nome_prod[30];
		    int quantidade;
		   };

void receber(struct dados *pd){

FILE *arquivo;
if((arquivo = fopen("produtoscap10ex3","a"))==NULL){
	printf("erro na abertura do arquivo \n");
	exit(0);}

	printf("- Inclusão de Produtos -\n");
    printf("Código numérico: ");
    gets(pd->codigo_num);
    printf("Nome do Produto: ");
    gets(pd->nome_prod);
    printf("Quantidade: ");
    scanf("%d",&pd->quantidade);
    getchar();
    printf("\n");

    fwrite(pd,sizeof(*pd),1,arquivo);
    fclose(arquivo);
}

void imprimir(struct dados *pd){

    printf("- Listar os Produtos -\n");

    FILE *arquivo;
    if((arquivo = fopen("produtoscap10ex3","r"))==NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);}

     while(fread(pd,sizeof(*pd),1,arquivo)== 1){
        if(pd->nome_prod[0] != '*'){
            printf("-----------------------\n");
            printf("Código: %s",pd->codigo_num);
            printf("\nNome do Produto: %s",pd -> nome_prod);
            printf("\nQuantidade: %d",pd -> quantidade);
            printf("\n-----------------------\n");}}

        fclose(arquivo);
    }

long procurar (struct dados *pd){
    char busca[20];
    int c;
    long registro=0; // número do indice para retornar em outras funções e calcular deslocamento para usar em fseek

    FILE *arquivo = fopen("produtoscap10ex3","r");

    printf("Digite o nome do produto que deseja: ");
    gets(busca);

    while (fread(pd,sizeof(*pd),1,arquivo)== 1){
            for(c=0;busca[c]!='\0';c++){
                if (busca[c] != pd->nome_prod[c]){
                    break;}}

            if(busca[c] == '\0' && pd->nome_prod[c] == '\0'){
                printf("-----------------------\n");
                printf("Código: %s",pd-> codigo_num);
                printf("\nNome do Produto: %s",pd -> nome_prod);
                printf("\nQuantidade: %d",pd -> quantidade);
                printf("\n-----------------------\n");

                fclose(arquivo);
                return registro;//volta para a função que chamou se achar o nome e retorna o índice/registro
                }

            //se não achar o nome, acrescenta na numeração do índice/registro
                registro++;

        }
    //se não encontrou o nome no if, não retorna para a main, então na saída do laço vem para cá
    printf("Produto não encontrado!\n");
    fclose(arquivo);
    return -1;
}

void imprimir_indisponivel(struct dados *pd){

     int encontrou = 0;

    printf("- Listar os Produtos Não Disponíveis -\n");

    FILE *arquivo;
    if((arquivo = fopen("produtoscap10ex3","r"))==NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);}

     while(fread(pd,sizeof(*pd),1,arquivo)== 1){
        if(pd->quantidade == 0 && pd->nome_prod[0] !='*'){
            printf("-----------------------\n");
            printf("Código: %s",pd->codigo_num);
            printf("\nNome do Produto: %s",pd -> nome_prod);
            printf("\nQuantidade: %d",pd -> quantidade);
            printf("\n-----------------------\n");
            encontrou = 1;
            }
        }
         if(!encontrou) {
        printf("Todos os produtos estao disponiveis!\n");
        }

        fclose(arquivo);
    }

void alterar_quant(struct dados *pd){

    long indice,deslocamento;
    int valor;

    printf("- Alterar Quantidade Atual -\n");
    indice = procurar(pd);

    FILE *arquivo;
    if((arquivo = fopen("produtoscap10ex3","r+"))==NULL){
                printf("erro na abertura do arquivo \n");
                exit(0);}

    if(indice != -1){

            printf("\n");
            printf("Digite um número positivo para entrada e um número negativo para saída:");
            scanf("%d", &valor);
            printf("\n");

            pd->quantidade +=valor;

            //Posiciona o ponteiro no início do registro para escrever no arquivo
            deslocamento = indice * sizeof(*pd);
            fseek(arquivo,deslocamento,0);
            fwrite(pd,sizeof(*pd),1,arquivo);
            printf("Quantidade alterada com sucesso!\n");
    }
    fclose(arquivo);
}

void alterarProduto(struct dados *pd){

    long indice,deslocamento;

    printf("- Alterar Produto -\n");
    indice = procurar(pd);

    FILE *arquivo;
    if((arquivo = fopen("produtoscap10ex3","r+"))==NULL){ //não usar a pois adiciona um novo registro, ao invés de alterar
                printf("erro na abertura do arquivo \n");
                exit(0);}

    if(indice != -1){

            printf("\n");
            printf("Código do Produto: ");
            gets(pd->codigo_num);
            printf("Nome do Produto:");
            gets(pd->nome_prod);
            printf("Quantidade:");
            scanf("%d",&pd->quantidade);
            getchar();
            printf("\n");

            //Posiciona o ponteiro no início do registro para escrever no arquivo
            deslocamento = indice * sizeof(*pd);
            fseek(arquivo,deslocamento,0);
            fwrite(pd,sizeof(*pd),1,arquivo);
    }
    fclose(arquivo);
}

void excluir(struct dados *pd){

    long indice,deslocamento;

    printf("- Excluir Produto -\n");
    indice = procurar(pd);

    FILE *arquivo;
    if((arquivo = fopen("produtoscap10ex3","r+"))==NULL){
                printf("erro na abertura do arquivo \n");
                exit(0);}

    if(indice != -1){

            deslocamento = indice * sizeof(*pd);

            fseek(arquivo,deslocamento,0);
            fread(pd,sizeof(*pd),1,arquivo);
            pd->nome_prod[0]='*';

            fseek(arquivo,deslocamento,0);
            fwrite(pd,sizeof(*pd),1,arquivo);
            printf("Dados do produto acima excluídos com sucesso!\n\n");
        }
    fclose(arquivo);
}

int main(){

         struct dados produtos, *pprod;
         int opcao;
         setlocale(LC_ALL,"Portuguese");

         pprod = &produtos;

         for(;;){
         printf("\n\n- MENU PRINCIPAL -\n");
         printf("1 - Incluir Produto \n2 - Listar todos os produtos \n3 - Pesquisar uma mercadoria pela descrição \n4 - listar os produtos não disponíveis \n5 - Alterar a quantidade atual \n6 - Altera um produto \n7 - Excluir um produto \n8 - Sair \n ");
         printf("Escolha uma opção: ");
         scanf("%d",&opcao);
         getchar();
         printf("\n");

         switch (opcao){

         case 1:
            receber(pprod);
            break;

         case 2:
            imprimir(pprod);
            break;

         case 3:
            procurar(pprod);
            break;

         case 4:
            imprimir_indisponivel(pprod);
            break;

         case 5:
            alterar_quant(pprod);
            break;

         case 6:
            alterarProduto(pprod);
            break;

         case 7:
             excluir(pprod);
             break;
         case 8:
            printf("Saindo...\n");
            exit(0);


         default:
            printf("Opção inválida");
            break;
         }
         }//fim loop infinito
}

#endif // ex4
