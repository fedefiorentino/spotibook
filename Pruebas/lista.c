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
	
void CargarDatos (libro* ,int );

int main(void)
{
	int fd_libro, flagcargar = 1;	
	libro *libronuevo;
	
	if ( ( fd_libro = open("lista.txt",O_WRONLY|O_CREAT) )== -1 )	
	{
		perror("Open;");
		return 0;
	}
	printf("fd: %d\n", fd_libro);
		
	while(flagcargar)
	{	
	  libronuevo = (libro *) malloc (sizeof(libro));
	  CargarDatos (libronuevo,fd_libro);

	  printf("Desea seguir cargando libros? 1/0?\n");
	  scanf("%d", &flagcargar);
	}
	
	close(fd_lista);
	
	return 0;
}

void CargarDatos (libro *libro1,int fd_lista)
{
	printf("Ingresar titulo autor genero ano path:\n");
	scanf(" %s", (libro1->titulo) );
	scanf(" %s", (libro1->autor) );
	scanf(" %s", (libro1->genero) );
	scanf(" %d", &(libro1->anio) );
	scanf(" %s", (libro1->path) );
	
	if ( (write(fd_lista, libro1, sizeof(libro) ) ) == -1 )
	{
		perror("write");
		return ;
	}
}