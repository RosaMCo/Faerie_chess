#include "Reglas.h"

void Reglas::Inicializa()
{
    unsigned char bufer[TAMANIO_BUFER];
    FILE* archivo;
    const char* ReglasAjedrez = "bin/ReglasAjedrez.txt";
    size_t bytesLeidos;

    archivo = fopen(ReglasAjedrez, "r"); // Abrir en modo read
    // Si es NULL, entonces no existe, o no se pudo abrir
    if (!archivo) {
        printf("¡No se pudo abrir el archivo %s!", ReglasAjedrez);
        
    }

    // Mientras no alcancemos el EndOfLine del archivo...
   while (!feof(archivo)) {
        // Leer dentro del búfer; fread regresa el número de bytes leídos
      bytesLeidos = fread(bufer, sizeof(char), sizeof(bufer), archivo);
        // Para depurar, se imprime la cantidad de bytes leídos (se puede quitar esa parte)
        //printf("\nSe han leido %lu bytes:\n", bytesLeidos);
        // Y el contenido del búfer también es impreso
        fwrite(bufer, sizeof(char), bytesLeidos, stdout);
      
   }
    // Al final, se cierra el archivo
   system("pause");
pregunta1: 
   cout << "Desea salir? Pulse Y/N: ";
   cin >> opcion;
   switch (opcion)
   {
   case 'Y':exit(0) ; break;
   case'y':exit(0); break;
   case 'N': system("pause");  goto pregunta1; break;
   case'n':system("pause"); goto pregunta1; break;
   default: goto pregunta1; break;
      
   }
       

    
}
