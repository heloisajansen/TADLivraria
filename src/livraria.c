#ifndef __LIVRARIA_C_
#define __LIVRARIA_C_

#define FALSE 0
#define TRUE 1

#include <stdio.h>
#include <stdlib.h>

typedef struct _Livraria_ {
    int maxItens;
    int tamAtual;
    void ** item;
} Livraria;

Livraria *livrariaCreate(int maxItens){
	Livraria * l;
	if (maxItens > 0){
		l = (Livraria*)malloc(sizeof(Livraria));
		if (l != NULL){
			l -> maxItens = maxItens;
			l -> tamAtual = 0;
			l -> item = (void **)malloc(sizeof(void *) * maxItens);
			if (l -> item != NULL){
				printf("Livraria criada com sucesso!\n");
				fflush(stdout);

				return l;
			}
			free(l);
		}
	}
	printf("Não foi possível criar livraria\n");
	fflush(stdout);

	return NULL;
}

int livroInsert(Livraria * l, void * livro){
	if (l != NULL){
		if (l -> tamAtual < l -> maxItens){
			l -> item[l -> tamAtual] = livro;
			l -> tamAtual++;
			printf("Livro inserido com sucesso!\n");
			fflush(stdout);

			return TRUE;
		}
	}
	printf("Não foi possível inserir livro\n");
	fflush(stdout);

	return FALSE;
}

void * livroRemove(Livraria * l, int key){
	void * livroRemovido;
	if (l != NULL && l -> tamAtual > 0){
		if (key >= 0 && key < l -> maxItens){
			livroRemovido = l -> item[key];
			for (int i = key; i < l -> tamAtual - 1; i++){
				l -> item[i] = l -> item[i + 1];
			}
			l -> item[l -> tamAtual] = NULL;
			l -> tamAtual--;
			printf("Livro removido com sucesso!\n");
			fflush(stdout);

			return livroRemovido;
		}
	}
	printf("Não foi possível remover livro\n");
	fflush(stdout);

	return NULL;
}

int livrariaQuery(Livraria * l, int key){
	if (l != NULL && l -> tamAtual > 0){
		if (key >= 0 && key < l -> maxItens){
			if (l -> item[key] != NULL){
				printf("Livro encontrado\n");
				fflush(stdout);

				return TRUE;
			}
		}
	}
	printf("Não foi possível encontrar livro\n");
	fflush(stdout);

	return FALSE;
}

int livrariaDestroy(Livraria * l){
	if (l != NULL){
		if (l -> tamAtual == 0){
			free(l -> item);
			free(l);
			printf("Livraria destruída com sucesso!\n");
			fflush(stdout);

			return TRUE;
		}
	}
	printf("Não foi possível destruir livraria\n");
	fflush(stdout);

	return FALSE;
}

int livrariaClear(Livraria *l){
	if (l != NULL){
		if (l -> tamAtual > 0){
			l -> tamAtual = 0;

			printf("Livros esvaziados com sucesso!\n");
			fflush(stdout);
			return TRUE;
		}
	}
	printf("Não foi possível esvaziar os elementos\n");
	fflush(stdout);
	return FALSE;
}

int returnTam(Livraria *l){
	if (l != NULL){
		return l -> tamAtual;
	}
	return FALSE;
}

void *returnNext(Livraria * l){
	static int counter = 0;
	if (l -> tamAtual - 1 <= counter){
		counter = 0;
	}
	int aux = counter;
	if (l != NULL){
		if (counter < l -> tamAtual){
			counter++;
			return l -> item[aux];
		}
	}
	return NULL;
}

#endif // LIVRARIA_C_



