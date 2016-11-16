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
	int fd_lista, i, cant;
	
	libro lectura;
	if ( ( fd_lista = open("lista.txt",O_RDONLY) )== -1 )	
	{
		perror("Open");
		return 0;
	}
	
	printf("Cuantos libros quiero mostrar?");
	scanf("%d",&cant);
	
	for(i = 0 ; i < cant ; i++)
	{
	  read(fd_lista, &lectura, sizeof(libro));
	  printf("%s\n", lectura.titulo);
	  printf("%s\n", lectura.autor);
	  printf("%s\n", lectura.genero);
	  printf("%d\n", lectura.anio);
	  printf("%s\n", lectura.path);
	}
	  
	close(fd_lista);
	
	return 0;
}