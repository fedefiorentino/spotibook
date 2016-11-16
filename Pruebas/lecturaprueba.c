#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
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

int main(void)
{
	int fd_lista, i;	
	nodo nodolectura;
	nodo *nodoaux;
	
	if ( ( fd_lista = open("lista.txt",O_RDONLY) )== -1 )	
	{
		perror("Open");
		return 0;
	}
	nodoaux = &nodolectura;
	
	printf("Llegue");
	
	for (i = 0 ; i < 1 ; i++)
	{  
	  read(fd_lista, nodolectura.libro, sizeof(libro));
	  printf("%s", nodoaux->libro->titulo);
	  
	  read(fd_lista, nodolectura.libro, sizeof(libro));
	  printf("%s", nodoaux->libro->titulo);
	  printf("Llegue");
	  nodoaux = nodolectura.next;
	  
	  
	} 
	close(fd_lista);
	
	return 0;
}