#define CANTIDADDELIBROS 10

void BuscaLibro (char* campo, char *eleccion, nodo *nodoBuscaLibro)
{
  
  switch (campo)
    case "Titulo":
      for (i = 0 ; i < CANTIDADDELIBROS ; i++)
      {
	if ( !(nodoBuscaLibro.libro->titulo == eleccion) ) //Quiere decir que son igules
	  printf("%s\n", nodoBuscaLibro.libro.titulo );
	
	nodoBuscaLibro = nodoBuscaLibro->next;
      }
      break;
      
    case "Autor":
      for (i = 0 ; i < CANTIDADDELIBROS ; i++)
      {
	if ( !(nodoBuscaLibro.libro->autor == eleccion) ) //Quiere decir que son igules
	  printf("%s\n", nodoBuscaLibro.libro.autor );
	
	nodoBuscaLibro = nodoBuscaLibro->next;
      }
      break;
    
    case "Genero":
      for (i = 0 ; i < CANTIDADDELIBROS ; i++)
      {
	if ( !(nodoBuscaLibro.libro->genero == eleccion) ) //Quiere decir que son igules
	  printf("%s\n", nodoBuscaLibro.libro.genero );
	
	nodoBuscaLibro = nodoBuscaLibro->next;
      }
      break;
      
          case "Anio":
      for (i = 0 ; i < CANTIDADDELIBROS ; i++)
      {
	if ( !(nodoBuscaLibro.libro->anio == eleccion) ) //Quiere decir que son igules
	  printf("%s\n", nodoBuscaLibro.libro.anio );
	
	nodoBuscaLibro = nodoBuscaLibro->next;
      }
      break;
}
      
    