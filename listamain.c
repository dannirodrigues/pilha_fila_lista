#include "lista_privado.h"
#include "lista_interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compara_int(const void *a, const void *b) {
	if (*((int*)a) == *((int*)b)) return  0;
	if (*((int*)a) <  *((int*)b)) return -1;
	return  1;
}

void imprime_int(const void *a) {
	printf(" %d ",*((int*)a));
}

void destroi_int(void *a) {
	free((int*)a);
}

int main() {
	lista_t *l1;
	(void) l1;
	l1 = lista_cria(imprime_int, destroi_int, compara_int);
  //lista_t *lista_cria(void (*imp)(const void *), void (*libera)(void *), int (*comparar)(const void *, const void *))
	//l1 = lista_cria(destroi_int,imprime_int,compara_int);
	/*int *intptr ;
	intptr = (int*) malloc(sizeof(int));
	*intptr = 70;
	lista_insere_cauda(l1,intptr);
	lista_imprime(l1);*/

/*
	int *dani ;
	dani = (int*) malloc(sizeof(int));
	*dani = 10;
	celula_t *rudi = lista_cauda(l1);
	printf("\n insere prox a cauda  \n");
	lista_insere_proximo(l1, rudi, dani);
	//meuuuuuuulista_insere_proximo(lista_t *l, celula_t *c, const void *elem)
	//lista_insere_apos(l1,res,intptr);
	lista_imprime(l1);
	printf ("insere posicao");

	int *flor = (int*) malloc(sizeof(int));
	*flor= 755;

	const  unsigned int d = 2;
	//lista_insere_cauda(l1,intptr);
		lista_insere_posicao(l1,d, flor);
	lista_imprime(l1);
*/


  int *h;
	for (int i=0; i<10; i++) {
		 h = (int*) malloc(sizeof(int));
		*h = 10*i;

		//int lista_insere_cauda(lista_t *l, const void *elem)

		lista_insere_cauda(l1,h);


	}
	lista_imprime(l1);
	lista_t *l2;

	l2 = lista_cria(imprime_int, destroi_int, compara_int);
	int elem = 30;




	printf ("-----------------saindo l2 ------------------");
	lista_imprime( lista_separa(l1,&elem));
	printf("\n -------------------0 saindoooooo l1-------------------------------------- \n");
	lista_imprime(l1);
	/*
	int *nete ;
	nete = (int*) malloc(sizeof(int));
	*nete = 50;
	lista_separa(l1, nete);
	lista_imprime(l2);

 /*
 int *nete ;
 nete = (int*) malloc(sizeof(int));
 *nete = 50;
	//lista_insere_cabeca(l1,nete);
	lista_insere_ordenado(l1, nete);
	lista_imprime(l1);*/

/*
	int *elem = (int *)malloc(sizeof(int ));
	celula_t *d1 = lista_cauda(l1);
	printf ("removendo" );
	//int lista_remove(lista_t *l, celula_t *c, void **elem)
	lista_remove(l1, d1,(void*)&elem);
	lista_imprime(l1);
/*

	intptr = (int*) malloc(sizeof(int));
	*intptr = 70;
	no *res = lista_encontra(l1,intptr);
	if(res == NULL)
		printf("Nao achou");
	else
		imprime_int(res->dado);

	printf("\n");*/






/*
	*intptr = 15;
	celula_t *dani = lista_cauda(l1);
	printf("\n insere anterior a cauda  \n");
	lista_insere_anterior(l1, dani, intptr);
	//meuuuuuuulista_insere_proximo(lista_t *l, celula_t *c, const void *elem)
	//lista_insere_apos(l1,res,intptr);
	lista_imprime(l1);
	/*
	*intptr = 75;
	celula_t *res = lista_cauda(l1);
	printf("\n insere proximo a cauda \n");
	lista_insere_anterior(l1, res, intptr);
	//meuuuuuuulista_insere_proximo(lista_t *l, celula_t *c, const void *elem)
	//lista_insere_apos(l1,res,intptr);
	lista_imprime(l1);*/
/*
	lista_remove_cabeca(l1,(void*)&intptr);
	lista_imprime(l1);

	printf("Elemento removido: %d\n",*intptr);
	free(intptr);

	lista_remove_cauda(l1,(void*)&intptr);
	lista_imprime(l1);

	printf("Elemento removido: %d\n",*intptr);
	free(intptr);
*/
	//lista_destroi(&l1);


	return 0;
}
