#include "lista_vetor.h"

#ifndef _lista_vetor_privado_

#define _lista_vetor_privado_


struct lista {
	void **elementos;
	int  tamanho;
	int  capacidade;
	void (*destruir)(void *);
	void (*imprime)(const void *);
	int  (*compara)(const void *, const void *);

};

#define INCREMENTO_TAMANHO 100

typedef struct lista lista_t;

int lista_realoca_vetor(lista_t *l);
int	lista_cheia(lista_t *l);

#endif
