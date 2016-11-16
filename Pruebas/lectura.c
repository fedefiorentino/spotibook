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

void MostrarDatosLibros(int fd_libro);
	
int main(void)
{
	int fd_libro;
	
	if ( ( fd_libro = open("libros.txt",O_RDONLY) )== -1 )	
	{
		perror("Open");
		return 0;
	}
	
	MostrarDatosLibros (fd_libro);
	  
	close(fd_libro);
	
	return 0;
}

void MostrarDatosLibros (fd_libro)
{  
	  libro lectura;
	  int final = 1;
	  while(final)
	  {
	    if ( read(fd_libro, &lectura, sizeof(libro)) )  //SE TERMINÓ EL ARCIVHO? CREO QUE CUANDO PASA ESO DEVUELVE NULL PERO AVERIGUAR
	    {
	      printf("%s\n", lectura.titulo);
	      printf("%s\n", lectura.autor);
	      printf("%s\n", lectura.genero);
	      printf("%d\n", lectura.anio);
	      printf("%s\n", lectura.path);
	    }
	    else
	    {
	      return;
	    }
	  }
	  return;
}