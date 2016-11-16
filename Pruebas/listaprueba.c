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

void CargarDatos (libro*, int);

int main(void){
  
	int fd_lista, flagtermine;

	nodo nodo1;
	libro libro1;
	nodo *nodoprimero, *nodonuevo, *nodoultimo;

	if ( ( fd_lista = open("listaprueba.txt",O_WRONLY|O_CREAT) )== -1 )	
	{
		perror("Open");
		return 0;
	}

	nodo1.libro = &libro1;
	nodoprimero = nodoultimo = &nodo1;

	CargarDatos(nodoprimero->libro, fd_lista);

	nodoprimero->next = NULL;

	printf("Seguir cargando libros? 1/0\n");
	scanf("%d", &flagtermine);

	while(flagtermine){
	  nodonuevo = (nodo *) malloc (sizeof(nodo));
	  nodonuevo->libro = (libro *) malloc (sizeof(libro));
  
	  CargarDatos(nodonuevo->libro, fd_lista);
	  nodonuevo->next = NULL;
	  
	  nodoultimo->next = nodonuevo;
	  nodoultimo = nodonuevo;
	
	  printf("Seguir cargando libros? 1/0\n");
	  scanf("%d", &flagtermine);
	} 
	
	close(fd_lista);
	return 0;
}

void CargarDatos (libro* libro1,int fd_lista)
{
	printf("Ingresar titulo, autor, genero, anio y path:\n");
	scanf(" %s", (libro1->titulo) );
	scanf(" %s", (libro1->autor) );
	scanf(" %s", (libro1->genero) );
	scanf(" %d", &(libro1->anio) );
	scanf(" %s", (libro1->path) );
	
	if ( (write(fd_lista, &libro1, sizeof(libro) ) ) == -1 )
	{
		perror("Write");
		return ;
	}
	
	return;
}