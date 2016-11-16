#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define TAM 32
#define PATH_ESTRUCTURA_LIBROS "DatosLibros.txt"


	typedef struct libro_t{
		char titulo[TAM];
		char autor [TAM];
		char genero [TAM];
		int anio;
	}libro;
	
		typedef struct nodo_t{
		libro *datoslibro;
		struct nodo_t *next;
	}nodo;

nodo* CargarDatosLista (char *);
void MostrarDatosLista (nodo *);

int main (void)
{
  nodo *nodoprimero;
  
  nodoprimero = CargarDatosLista(PATH_ESTRUCTURA_LIBROS);
    
  MostrarDatosLista(nodoprimero);
  
  return 0;
}


nodo* CargarDatosLista (char *pathestructuralibros)
{
  int fd_datoslibros;
  nodo *nodonuevo, *nodoprimero, *nodoultimo;
  libro libroaux;
  
  if ( ( fd_datoslibros = open(pathestructuralibros,O_RDONLY) )== -1 )	
  {
    perror("Open");
    return 0;
  }
  
  nodoultimo = nodoprimero = (nodo *) malloc (sizeof(nodo));
  nodoprimero->datoslibro = (libro *) malloc (sizeof(libro));
  
  read(fd_datoslibros, nodoprimero->datoslibro, sizeof(libro));
  nodoprimero->next = NULL;

  
  while( read(fd_datoslibros, &libroaux, sizeof(libro) ) )
  {
    nodonuevo = (nodo *) malloc (sizeof(nodo));
    nodonuevo->datoslibro = (libro *) malloc (sizeof(libro));

    *(nodonuevo->datoslibro) = libroaux;
    nodonuevo->next = NULL;
    nodoultimo->next = nodonuevo;
    nodoultimo = nodonuevo;
  }
  
  close(fd_datoslibros); 
  return nodoprimero;
}


void MostrarDatosLista (nodo *nodoprimero)
{
  nodo *nodoaux;
  nodoaux = nodoprimero;
  
  while (nodoaux != NULL)
  {
    printf(" %s %s %s %d\n", nodoaux->datoslibro->titulo,nodoaux->datoslibro->autor,nodoaux->datoslibro->genero,nodoaux->datoslibro->anio); 
    nodoaux = nodoaux->next;
  }
}

