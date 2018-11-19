#include "lab5.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha_interface.h"
#include "pilha_privado.h"

void estacionamento(const char *arquivo, void (*entrada)(carro_t *), void (*saida)(carro_t *))
{
    if( arquivo == NULL ) return;

    FILE *arq = fopen(arquivo, "r");
    if( arq == NULL ) return;

    pilha_t *estacionamento = pilha_cria(10, sizeof(carro_t), NULL);
    pilha_t *estacionamento_aux = pilha_cria(10, sizeof(carro_t), NULL);
    char *ler = (char*)malloc(8*sizeof(char)); //ler a placa
    carro_t *a = (carro_t*)malloc(sizeof(carro_t)); //recebe o carro

    do{

    	fscanf(arq, "%s", ler);    	

    	if ( ler[0] == 'E' )
    	{    		
    		fscanf(arq, "%s", ler);    		    		
    		strcpy(a->placa, ler);        		 		

    		if( pilha_cheia(estacionamento) == 1 )
    		{    			
    			saida(a);    			
    			break;   			  			
    		}

    		a->manobras = 0;
    		entrada(a);
    		pilha_empilha(estacionamento, a);   					
    	}	 	  	 	     		     	   	 	  	  	 	


    	else if ( ler[0] == 'S' )
    	{    		
    		fscanf(arq, "%s", ler);    		  		

    		for( ; ; )
    		{    			
    			pilha_desempilha(estacionamento, a);

    			if ( strcmp(a->placa, ler) == 0 )
    			{
    				saida(a);    				
    				break;
    			}    			
    			
    			saida(a);
    			a->manobras += 1;
    			pilha_empilha(estacionamento_aux, a);   			  			
    		}

    		while( estacionamento_aux->topo != 0 )
    		{    			 
    			pilha_desempilha(estacionamento_aux, a);
    			entrada(a);
    			pilha_empilha(estacionamento, a);   			
    		}    		
    	}    	

    }while( strcmp(ler, "FIM") != 0 );

    pilha_destroi(&estacionamento);
    pilha_destroi(&estacionamento_aux);
    free(ler);
    fclose(arq);
    free(a);
	return;
}	 	  	 	     		     	   	 	  	  	 	