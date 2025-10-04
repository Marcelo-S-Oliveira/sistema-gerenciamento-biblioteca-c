#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define AMARELO  "\033[33m"
#define AZUL    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define VERDE   "\033[32m"
#define RESET   "\033[0m"

#define MAX 100


typedef struct Livro{
	
	int id;
	int status;
	char titulo[MAX];
	char autor[MAX];
	int edicao;
	int ano_lancamento;
	
} TLivro;

// funções:

void menu(){
	
	printf(MAGENTA"-------------------------------"RESET);
	printf(MAGENTA"\n*********   MENU   **********"RESET);
	printf(MAGENTA"\n-------------------------------"RESET);
	printf(MAGENTA"\n1 - Adicionar livro"RESET);
	printf(MAGENTA"\n2 - Lista dos livros"RESET);
	printf(MAGENTA"\n3 - Buscar por livro"RESET);
	printf(MAGENTA"\n4 - Atualizar livro"RESET);
	printf(MAGENTA"\n5 - Remover livro"RESET);
	printf(MAGENTA"\n6 - Sair"RESET);
	printf(MAGENTA"\n-------------------------------"RESET);
	printf(MAGENTA"\n-------------------------------"RESET);
	
}

void adicionar(TLivro vetor[], int posicao) {
	
	printf(AMARELO"-------------------------------"RESET);
	printf(AMARELO"\n       ADICIONAR LIVRO       "RESET);
	printf(AMARELO"\n-------------------------------\n"RESET);
	
	vetor[posicao].id = posicao;
	vetor[posicao].status = 1;
	
	printf(AMARELO"\nDigite o título do livro: "RESET);
	fgets(vetor[posicao].titulo, MAX-1, stdin);
	
	printf(AMARELO"\nDigite o nome do autor: "RESET);
	fgets(vetor[posicao].autor, MAX-1, stdin);
	
	printf(AMARELO"\nDigite a edição do livro: "RESET);
	scanf("%d", &vetor[posicao].edicao);
	
	printf(AMARELO"\nDigite o ano de lançamento: "RESET);
	scanf("%d", &vetor[posicao].ano_lancamento);
	
}

void lista (TLivro vetor[], int n) {
	
	int i;
	
	printf(AMARELO"-------------------------------"RESET);
	printf(AMARELO"\n       LISTA DOS LIVROS       "RESET);
	printf(AMARELO"\n-------------------------------\n"RESET);
	
	for(i=0; i < n; i++) {
		
		if (vetor[i].status == 1) {
			
			printf(AMARELO"Id: %d"RESET, vetor[i].id);
			printf(AMARELO"\nTitulo: %s"RESET, vetor[i].titulo);
			printf(AMARELO"\nAutor: %s"RESET, vetor[i].autor);
			printf(AMARELO"\nEdição: %d"RESET, vetor[i].edicao);
			printf(AMARELO"\nLançado em: %d"RESET, vetor[i].ano_lancamento);
			
		}
		
	printf(AMARELO"\n-------------------------------"RESET);
	
	}
	
}

void buscar (TLivro vetor[], int n) {
	
	int i;
	char titulo[MAX];
	int encontrou = 0;
	
	printf(AMARELO"-------------------------------"RESET);
	printf(AMARELO"\n        BUSCAR LIVROS        "RESET);
	printf(AMARELO"\n-------------------------------\n"RESET);
	
	printf(AMARELO"\nQual o titulo do livro: "RESET);
	fgets(titulo, MAX-1, stdin);
	
	for (i=0; i < n; i++) {
		
		if( strcmp(vetor[i].titulo, titulo) == 0 && vetor[i].status == 1) { //strcmp titulo com titulo == 0 comparacao de strings
			
			encontrou = 1;
			
			printf(AMARELO"\nId: %d"RESET, vetor[i].id);
			printf(AMARELO"\nTitulo: %s"RESET, vetor[i].titulo);
			printf(AMARELO"\nAutor: %s"RESET, vetor[i].autor);
			printf(AMARELO"\nEdicao: %d"RESET, vetor[i].edicao);
			printf(AMARELO"\nAno: %d"RESET, vetor[i].ano_lancamento);
			printf(AMARELO"-------------------------------"RESET);			
		}	
	}
	
	if (!encontrou) {
		printf(AMARELO"----------------------------------\n"RESET);
		printf(AMARELO"     Livro nao encontrada!\n"RESET);
		printf(AMARELO"----------------------------------\n"RESET);
		}
	
}

void atualizar (TLivro vetor[], int n) {
	
	int i, id_alterar;
	int encontrou = 0;
	int opcao;
	
	printf(AMARELO"-------------------------------"RESET);
	printf(AMARELO"\n       ATUALIZAR LIVRO        "RESET);
	printf(AMARELO"\n-------------------------------\n"RESET);
	
	//perguntar o que quer atualizar
	printf("\nQual id do livro:");
	scanf("%d", &id_alterar);
	
	for (i=0; i < n; i++){
		
		if (id_alterar == vetor[i].id && vetor[i].status == 1) {
			
			encontrou = 1;
			
			printf(AMARELO"-------------------------------"RESET);
			printf(AMARELO"\n       Livro encontrado      "RESET);
			printf(AMARELO"-------------------------------"RESET);
			printf(AMARELO"Id: %d"RESET, vetor[i].id);
			printf(AMARELO"Titulo: %s"RESET, vetor[i].titulo);
			printf(AMARELO"Autor: %s"RESET, vetor[i].autor);
			printf(AMARELO"Edicao: %d"RESET, vetor[i].edicao);
			printf(AMARELO"Lançado: %d"RESET, vetor[i].ano_lancamento);
			printf(AMARELO"-------------------------------"RESET);
	    }
	
	
		do{
				
				printf(AMARELO"\nO que deseja alterar"RESET);
				printf(AMARELO"\n1 - Titulo"RESET);
				printf(AMARELO"\n2 - Autor"RESET);
				printf(AMARELO"\n3- Edicao"RESET);
				printf(AMARELO"\n4 - Ano de lancamento"RESET);
				printf(AMARELO"\n5 - Voltar ao menu"RESET);
				printf(AMARELO"-------------------------------"RESET);
				
				printf("\nDigite a opcao");
				scanf("%d", &opcao);
				getchar();
				
				switch(opcao) {
					
					case 1 : 
						printf(AMARELO"Qual o novo titulo:"RESET);
						fgets(vetor[i].titulo, MAX-1, stdin);
						printf(AMARELO"Titulo alterado!"RESET);
						break;
					
					case 2 : 
						printf(AMARELO"Qual o novo nome do Autor:"RESET);
						fgets(vetor[i].autor, MAX-1, stdin);
						printf(AMARELO"Nome do autor alterado!"RESET);
						break;
					
					case 3 : 
						printf(AMARELO"Qual numero da edição:"RESET);
						scanf("%d", &vetor[i].edicao);
						printf(AMARELO"Numero de edicao alterado!"RESET);
						break;
										
					case 4 : 
						printf(AMARELO"Qual o novo ano de lançamento:"RESET);
						scanf("%d", &vetor[i].ano_lancamento);
						printf(AMARELO"Lançamento alterado!"RESET);
						break;
										
					case 5 : 
			
						printf(AMARELO"Alteracoes Salvas!"RESET);
						break;
										
					default : 
						printf(AMARELO"Opcao invalida!"RESET);
						break;
										
				  }		
				  
		} while(opcao != 5);
				
		break;
		}
		
		if(!encontrou) {
			printf(AMARELO"Livro com id %d não encontrado!"RESET, id_alterar);
		}
    }
	
void remover (TLivro vetor[], int n) {
	
	int id;
	
	printf(AMARELO"-------------------------------"RESET);
	printf(AMARELO"\n       REMOVER LIVRO         "RESET);
	printf(AMARELO"\n-------------------------------\n"RESET);
	
	printf(AMARELO"Digite o id do livro: "RESET);
	scanf("%d", &id);
	getchar();
	printf(AMARELO"\n-------------------------------\n"RESET);
	
	if (id < 0 || id >= n) {
		printf(AMARELO"\nO id %d e invalido!"RESET, id);
		printf(AMARELO"\n-------------------------------\n"RESET);
		return;
	}
	
	if(vetor[id].status == 1){
		
		vetor[id].status = 0;
		printf(AMARELO"Livro removido com sucesso!"RESET);
		printf(AMARELO"\n-------------------------------\n"RESET);
	}
		
}	
	
int main() {
	
	TLivro *vetor;
	int n, opcao;
	n=0;
	
	do{
		
		menu();
		
		printf(VERDE"\nEntre com a opcao: "RESET);
		scanf("%d", &opcao);
		getchar();
		
		switch(opcao){
			
			case 1:
				
				n++;
				
				if(n == 1) {
					vetor = (TLivro*) malloc(sizeof(TLivro));
				}
				else{
					vetor = (TLivro*) realloc(vetor, n*sizeof(TLivro));
				}
				
				adicionar(vetor, n-1);
				
				printf(VERDE"\nCadastro realizado com sucesso!\n"RESET);
				
				break;
						
			case 2: 
				
				lista(vetor, n);
				break;
			
		
			case 3: 
				
				buscar(vetor, n);
				break;
			
			
			case 4: 
				
				atualizar(vetor, n);
				break;
			
			case 5: 
				
				remover(vetor, n);
				break;
			
			
			case 6: 
				
				break;
			
			
			default: 
				
				printf(VERDE"Opcao invalida!"VERDE);
				break;
		}
		
	} while (opcao != 6);

}
