// --- DECLARACIÓNES ---

#include <iostream>
#include "Bienvenida.h"
#include "Archivo.h"

// --- FUNCIÓNES ---

int Bienvenida(char seleccion)
{
	do
	{
		std::cout << "Seleccione una opcion de la que se les propone para acceder a lo que necesite: \n\n";

		// --- MENU ---

		std::cout << "# - - - - - - - - - - - - - - - - - - - - #" << std::endl;
		std::cout << "| 1. Entrar en el archivo.                |" << std::endl;
		std::cout << "| 2. Entrar al archivo borrando conversa  |" << std::endl;
		std::cout << "| 3. Salir del programa.                  |" << std::endl;
		std::cout << "# - - - - - - - - - - - - - - - - - - - - #" << std::endl;
		std::cout << "Opcion: ";
		std::cin >> seleccion;

		if ((seleccion >= 1) && (seleccion <= 3))
		{
			switch (seleccion)
			{
			case 1:
				std::cout << "\nSe abrira el archivo...";
				abrirFichero(seleccion);
			case 2:
				std::cout << "\nSe abrira el archivo borrando el contenido de la conversa...";
				abrirFichero(seleccion);
			case 3:
				std::cout << "Se va a cerrar el programa...";
			}
		}
		else
		{
			std::cout << "\nLa opcion que ha seleccionado no es valida, por favor seleccione una que este dentro del rango.";
		}
	} while (seleccion < 1 && seleccion > 3);
	return 0;
}