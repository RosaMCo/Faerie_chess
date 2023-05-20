#include "Reglas.h"

int Reglas::Inicializa()
{
    unsigned char bufer[TAMANIO_BUFER];
    FILE* archivo;
    const char* ReglasAjedrez = "bin/ReglasAjedrez.txt";
    size_t bytesLeidos;

    archivo = fopen(ReglasAjedrez, "r"); // Abrir en modo read
    // Si es NULL, entonces no existe, o no se pudo abrir
    if (!archivo) {
        printf("�No se pudo abrir el archivo %s!", ReglasAjedrez);
        
    }

    // Mientras no alcancemos el EndOfLine del archivo...
   while (!feof(archivo)) {
        // Leer dentro del b�fer; fread regresa el n�mero de bytes le�dos
      bytesLeidos = fread(bufer, sizeof(char), sizeof(bufer), archivo);
        // Para depurar, se imprime la cantidad de bytes le�dos (se puede quitar esa parte)
        //printf("\nSe han leido %lu bytes:\n", bytesLeidos);
        // Y el contenido del b�fer tambi�n es impreso
        fwrite(bufer, sizeof(char), bytesLeidos, stdout);
      
   }
    // Al final, se cierra el archivo
   
   exit(0);
    
    
}