#include "fila_privado.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct fila fila_t;


fila_t *fila_cria(void (*imp)(const void *), void (*libera)(void *), int (*comparar)(const void *, const void *))
{
    //if(should_i_print(0)) printf("c");
	fila_t *f = (fila_t*)malloc(sizeof(fila_t));
	if(f == NULL) return NULL;
	f->cabeca = f->cauda = NULL;
	f->tamanho = 0;
	f->imprime = imp;
	f->destruir = libera;
	f->compara = comparar;	
	
	return f;
}


void fila_destroi(fila_t **f)
{
    //if(should_i_print(0)) printf("d");
	if( f == NULL ) return;
	
	celula_t *n;	
	while( (*f)->cabeca != NULL)
	{
		n = (*f)->cabeca;
		(*f)->cabeca = (*f)->cabeca->prox;
		if((*f)->destruir == NULL);
		else (*f)->destruir(n->dado);
		free(n);
	}	 	  	 	     		     	   	 	  	  	 	
	free(*f);
	*f = NULL;
	
	return;
}


int fila_vazia(fila_t *f)
{
	if (f == NULL) return -1;
	else if( f->tamanho == 0) return 1;	
	return 0;
}


int fila_tamanho(fila_t *f)
{
	if (f == NULL) return -1;		
	return f->tamanho;
}


int fila_enfileira(fila_t *f, void *elem)
{
	if(f==NULL || elem == NULL) return 0;
	celula_t *c  = (celula_t*)malloc(sizeof(celula_t));
	if( c == NULL )return 0;
	c->dado = elem;
	c->prox = NULL;
	
	//teste fila vazia
	if( fila_vazia(f) == 1 )
	{
		f->cabeca = c;
	}
	
	else
	{	 	  	 	     		     	   	 	  	  	 	
		f->cauda->prox=c;
	}
	
	f->cauda = c;    
	f->tamanho++;	
	return 1;
}



int fila_enfileira_ordenado(fila_t *f, void *elem)
{
	if( f == NULL || elem == NULL )  return 0;
	
	if ( f->compara == NULL || fila_vazia(f) == 1 )
	{
	    fila_enfileira(f, elem);
		return 1; 
	}
   
    celula_t *celula  =  f->cabeca;
    celula_t *aux = (celula_t*)malloc(sizeof(celula_t));
    celula_t *aux2 = (celula_t*)malloc(sizeof(celula_t));
    
    fila_enfileira(f, elem); //enfileirando elemento
    while ( celula != NULL )
    {
        if ( f->compara( elem, celula->dado ) == -1 )
        {
            aux->dado = celula->dado;
            celula->dado = elem;
            while( celula != NULL )
            {
                celula = celula->prox;
                if ( celula != NULL )
                {	 	  	 	     		     	   	 	  	  	 	
                    aux2->dado = celula->dado;
                    celula->dado = aux->dado;
                    aux->dado = aux2->dado;
                }
                else celula = NULL;
            }
            celula = NULL;
        }
        else celula = celula->prox;
    }
    
    /*celula = f->cabeca;
	while ( celula != NULL )
	{
		printf("%d ", *(int*)celula->dado);
		celula = celula->prox;
	}
	printf("\n");*/
	free(aux);
	free(aux2);
	
	return 1;
}


int fila_desenfileira(fila_t *f, void **elem)
{
	if( f == NULL || fila_vazia(f) == 1 || elem == NULL ) return 0;
	
	celula_t *c;	
	c = f->cabeca;
	*elem = c->dado;
	f->cabeca = f->cabeca->prox;
	free(c);
	
	f->tamanho--;
	//caso fila tenha ficado vazia
	if ( fila_vazia(f) == 1 )
	{	 	  	 	     		     	   	 	  	  	 	
		f->cauda = NULL;
	}	
		
	return 1;
}



int fila_cabeca(fila_t *f, void **elem)
{
	if( f == NULL || fila_vazia(f) == 1 || elem == NULL ) return 0;
	
	*elem = f->cabeca->dado;
	return 1;
}


int fila_cauda(fila_t *f, void **elem)
{
	if( f == NULL || fila_vazia(f) == 1 || elem == NULL ) return 0;
	
	*elem = f->cauda->dado;
	return 1;
}


void fila_imprime(fila_t *f)
{
	if( f == NULL || f->imprime == NULL ) return;
	
	celula_t *n = f->cabeca;
	while ( n != NULL )
	{
		f->imprime(n->dado);
		n = n->prox;
	}	 	  	 	     		     	   	 	  	  	 	
	
	return;
}


