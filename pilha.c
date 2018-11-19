#include "pilha_privado.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"



pilha_t *pilha_cria(int cap, int tam_elemento, void (*imp)(const void *))
{
	if( cap <= 0 || tam_elemento <= 0 ) return NULL;

	pilha_t *p = (pilha_t*)malloc(sizeof(pilha_t));
	if( p == NULL ) return NULL;
	
	p->elementos = malloc(cap*tam_elemento);
	p->tamanho_elemento = tam_elemento;
	p->topo = 0;
	p->capacidade = cap;
	p->imprime = imp;

	return p;
}




void pilha_destroi(pilha_t **p)
{
	if( p == NULL || *p == NULL ) return;

	free((*p)->elementos);
	free((*p));
	*p = NULL;

	return;
}



int pilha_vazia(pilha_t *p)
{	 	  	 	     		     	   	 	  	  	 	
	if ( p == NULL ) return -1;

	if( p->topo == 0 ) return 1;
	else return 0;
}



int pilha_cheia(pilha_t *p)
{
	if ( p == NULL ) return -1;

	if( p->topo == p->capacidade ) return 1;
	else return 0;
}



int pilha_tamanho(pilha_t *p)
{
	if ( p == NULL ) return -1;

	else return p->topo;
}


//void * memcpy ( void * destination, const void * source, size_t num );
int pilha_empilha(pilha_t *p, void *elem)
{
	if( p == NULL || elem == NULL || pilha_cheia(p) == 1 ) return 0;

	char *elemento = (char*)p->elementos;		
	
	memcpy(&elemento[p->topo*p->tamanho_elemento], elem, p->tamanho_elemento);	
	p->topo++;
	return 1;
}



int pilha_desempilha(pilha_t *p, void *elem)
{	 	  	 	     		     	   	 	  	  	 	
	if ( p == NULL || elem == NULL || pilha_vazia(p) == 1 ) return 0;

	char *elemento = (char*)p->elementos;
	
	p->topo--;
	memcpy(elem, &elemento[p->topo*p->tamanho_elemento], p->tamanho_elemento);		
	return 1;
}



int pilha_topo(pilha_t *p, void *elem)
{
	if ( p == NULL || elem == NULL || pilha_vazia(p) == 1 ) return 0;

	char *elemento = (char*)p->elementos;
	p->topo--;
	memcpy(elem, &elemento[p->topo*p->tamanho_elemento], p->tamanho_elemento);
	p->topo++;
	return 1;
}



void pilha_imprime(pilha_t *p)
{	
    if( p == NULL || p->imprime == NULL ) return;

    pilha_t *p_aux = pilha_cria(p->capacidade, p->tamanho_elemento, p->imprime);
    int *elemento = (int*)malloc(p->tamanho_elemento);

    while( p->topo != 0 )
    {
    	pilha_topo(p, elemento);
    	p->imprime(elemento);     	
    	pilha_desempilha(p, elemento);    	
    	pilha_empilha(p_aux, elemento);     	 		
    }

    while( p_aux->topo != 0 )
    {
    	pilha_desempilha(p_aux, elemento);    	
    	pilha_empilha(p, elemento);    	
    }

    pilha_destroi(&p_aux);
    free(elemento);

    return;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
