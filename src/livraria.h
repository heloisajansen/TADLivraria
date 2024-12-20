/*------------------------------------------------
livraria.h
Arquivo com a especificação para o TAD Livraria
Curso: Estrutura de Dados
Autora: Heloísa Jansen Ferreira Ribeiro
Dezembro - 2024
---------------------------------------------------*/

#ifndef __LIVRARIA_H_
#define __LIVRARIA_H_

#define FALSE 0
#define TRUE 1

#include <stdio.h>
#include <stdlib.h>

/*-------------------------------------------------
Definicoes locais
-------------------------------------------------*/

typedef struct _livraria_ Livraria;

/*-------------------------------------------------
Funcoes que implementam as operacoes do
TAD Livraria
-------------------------------------------------*/

/*-------------------------------------------------
Cria um novo TAD Livraria
Pre-condicao: maxItems > 0
Pos-condicao: retorna o endereço de um novo TAD
Livraria vazio ou NULL se não conseguir criar
-------------------------------------------------*/

Livraria *livrariaCreate(int maxItens);

/*-------------------------------------------------
Adiciona um livro na Livraria
Pre-condicao : (l é um TAD Livraria criado por uma
chamada a livrariaCreate) e (o TAD livraria nao
esta cheio)
Pos-condicao: item foi adicionado ao TAD Livraria
-------------------------------------------------*/

int livroInsert(Livraria *l, void * livro);

/*-------------------------------------------------
Retira um livro da livraria
Pre-condicao: (l é um TAD Livraria criado por uma
chamada a livrariaCreate) e && (existe pelo menos
um livro no TAD Livraria)
Pos-condicao: livro foi eliminado do TAD Livraria
-------------------------------------------------*/

void * livroRemove(Livraria *l, int key);

/*-------------------------------------------------
Encontra um livro em um TAD Livraria
Pre-condicao: (l é um TAD Livraria criado por uma
chamada a livrariaCreate)
Pos-condicao: retorna TRUE se o livro identificado
por key ele existir no TAD Livraria, ou FALSE caso
contrátrio
-------------------------------------------------*/

int livrariaQuery(Livraria *l, int key, int (*cmp)(void*, void*));

/*-------------------------------------------------
Destroi um TAD Livraria
Pre-condicao: (l é um TAD Livraria criado por uma
chamada a livrariaCreate e que está vazia)
Pos-condicao: a memoria usada pelo TAD foi liberada
-------------------------------------------------*/

int livrariaDestroy(Livraria *l);

/*-------------------------------------------------
Esvazia a livraria
Pre-condicao: (l é um TAD Livraria criado por uma
chamada a livrariaCreate e que possuí pelo menos um
elemento)
Pos-condicao: Retorna TRUE se a operação pôde ser
realizada, FALSE caso contrário
-------------------------------------------------*/

int livrariaClear(Livraria *l);

/*-------------------------------------------------
Retorna o tamanho atual da Livraria
Pre-condicao: (l é um TAD Livraria criado por uma
chamada a livrariaCreate e que possuí pelo menos um
elemento)
Pos-condicao: Retorna l -> tamAtual se a operação
pôde ser realizada, FALSE caso contrário
-------------------------------------------------*/

int returnTam(Livraria *l);

/*-------------------------------------------------
Retorna o próximo elemento de l -> item
Pre-condicao: (l é um TAD Livraria criado por uma
chamada a livrariaCreate)
Pos-condicao: l -> item[aux] se a operação
pôde ser realizada, NULL caso contrário
-------------------------------------------------*/

void *returnNext(Livraria * l);

#endif // LIVRARIA_H_
