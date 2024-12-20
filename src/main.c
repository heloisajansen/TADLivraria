#define FALSE 0
#define TRUE 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "livraria.h"

typedef struct Livro {
	char titulo[100];
	int qntdPags;
	float preco;
} Livro;


void livrariaShowElm(Livraria * l){
	Livro *livro = NULL;
	if (l != NULL){
		for (int i = 0; i < returnTam(l); i++){
			livro = (Livro*) returnNext(l);
			while (livro != NULL){
				printf("%s\n", livro -> titulo);
				printf("%d\n", livro -> qntdPags);
				printf("%.2f\n", livro -> preco);
				fflush(stdout);

				livro = (Livro*) returnNext(l);
			}
		}
	}
	else{
		printf("Não foi possível mostrar os livros\n");
		fflush(stdout);
	}
}

int cmp(void * item, void * key){
	Livro * ptrItem = (Livro*) item;
	Livro * ptrKey = (Livro*) key;
	if (ptrItem != NULL && ptrKey != NULL){
		if (strcmp(ptrItem -> titulo, ptrKey -> titulo) == 0){
			return TRUE;
		}
	}
	return FALSE;
}


int main(void){
	Livro * livro = NULL;
	Livro * keyLivro = NULL;
	Livraria * l = NULL;
	int escolha, maxItens, key;
	int continuar = TRUE;

	while(continuar ==  TRUE){
		printf("---------------------\n");
		printf("1 - Criar livraria\n");
		printf("2 - Inserir livro\n");
		printf("3 - Remover livro\n");
		printf("4 - Buscar livro\n");
		printf("5 - Destruir libraria\n");
		printf("6 - Listar todos os livros\n");
		printf("7 - Esvaziar livraria\n");
		printf("8 - Sair\n");
		printf("---------------------\n");
		fflush(stdout);

		scanf("%d", &escolha);

		if (escolha == 1){
			printf("Num. de livros:\n");
			fflush(stdout);

			scanf("%d", &maxItens);
			l = livrariaCreate(maxItens);
		}

		if (escolha == 2){
			livro = (Livro *)malloc(sizeof(Livro));
			printf("Digite o título do livro:\n");
			fflush(stdout);
			scanf("%s", livro -> titulo);
			fflush(stdout);

			printf("Digite qntd. de páginas:\n");
			fflush(stdout);
			scanf("%d", &livro -> qntdPags);
			fflush(stdout);

			printf("Digite o preço do livro:\n");
			fflush(stdout);
			scanf("%f", &livro -> preco);
			fflush(stdout);

			livroInsert(l, livro);
		}

		if (escolha == 3){
			printf("Digite o índice do livro que deseja remover:\n");
			fflush(stdout);

			scanf("%d", &key);
			livroRemove(l, key);
		}

		if (escolha == 4){
			keyLivro = (Livro*) malloc(sizeof(Livro));
			printf("Digite o título do livro que deseja procurar:\n");
			fflush(stdout);
			scanf("%s", keyLivro -> titulo);
			fflush(stdout);

			keyLivro -> qntdPags = 0;
			keyLivro -> preco = 0;

			Livro * keyLivroAchou = (Livro*) livrariaQuery(l, keyLivro, cmp);
			if (keyLivroAchou != NULL){
				printf("%s\n", keyLivroAchou -> titulo);
				printf("%d\n", keyLivroAchou -> qntdPags);
				printf("%f\n", keyLivroAchou -> preco);
			}
		}

		if (escolha == 5){
			livrariaDestroy(l);
		}

		if (escolha == 6){
			livrariaShowElm(l);
		}

		if (escolha == 7){
			livrariaClear(l);
		}

		if (escolha == 8){
			continuar = FALSE;
		}
	}
	return 0;
}
