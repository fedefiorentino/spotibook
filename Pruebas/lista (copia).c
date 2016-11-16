#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define TAM 20

	typedef struct libro_t{
		char titulo[TAM];
		char autor [TAM];
		char genero [TAM];
		int anio;
		char path [TAM];
	}libro;	
	
	typedef struct nodo_t{
		libro *libro;
		struct nodo_t* next;
	}nodo;
	
void CargarDatos (nodo * ,int );

int main(void)
{
	int fd_lista, flagcargar = 1;	
	nodo *nodonuevo, *nodoprimero, *nodoultimo;
	
	if ( ( fd_lista = open("lista.txt",O_WRONLY|O_CREAT) )== -1 )	
	{
		perror("Open;");
		return 0;
	}
	printf("fd: %d\n", fd_lista);
	
	nodonuevo = nodoultimo = NULL;
	
	while(flagcargar)
	{	
	  nodonuevo = (nodo *) malloc (sizeof(nodo));
	  nodonuevo->libro = (libro *) malloc (sizeof(libro));
	  CargarDatos (nodonuevo,fd_lista);
	  
	  if(nodoultimo != NULL)
	  {
	  nodoultimo->next = nodonuevo;
	  nodoultimo = nodonuevo;	 
	  }
	  
	  printf("Desea seguir cargando libros? 1/0?\n");
	  scanf("%d", &flagcargar);
	}
	
	close(fd_lista);
	
	return 0;
}

void CargarDatos (nodo* nodo1,int fd_lista)
{
	printf("Ingresar titulo autor genero ano path:\n");
	scanf(" %s", (nodo1->libro->titulo) );
	scanf(" %s", (nodo1->libro->autor) );
	scanf(" %s", (nodo1->libro->genero) );
	scanf(" %d", &(nodo1->libro->anio) );
	scanf(" %s", (nodo1->libro->path) );
	
	nodo1->next = NULL;
	
	if ( (write(fd_lista, nodo1->libro, sizeof(libro) ) ) == -1 )
	{
		perror("write");
		return ;
	}
}