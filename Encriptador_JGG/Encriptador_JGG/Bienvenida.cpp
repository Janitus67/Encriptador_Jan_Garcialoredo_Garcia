// --- DECLARACIÓNES ---

#include <iostream>
#include "Bienvenida.h"
#include "Archivo.h"

// --- FUNCIÓNES ---

int Bienvenida(short seleccion, std::vector<std::string> & historial)
{
	do
	{
		std::cout << "Seleccione una opcion de la que se les propone para acceder a lo que necesite: \n\n";

		// --- MENU ---

		std::cout << "# - - - - - - - - - - - - - - - - - - - - - - #" << std::endl;
		std::cout << "| 1. Entrar en el archivo.                    |" << std::endl;
		std::cout << "| 2. Entrar al archivo borrando mensajes      |" << std::endl;
		std::cout << "| 3. Salir del programa.                      |" << std::endl;
		std::cout << "# - - - - - - - - - - - - - - - - - - - - - - #" << std::endl;
		std::cout << "Opcion: ";
		std::cin >> seleccion;

		if ((seleccion >= 1) && (seleccion <= 3))
		{
			switch (seleccion)
			{
			case 1:
				if (existeArchivo() == true)
				{
					std::cout << "\nSe abrira el archivo...\n";
					abrirArchivo(seleccion, historial);
				}
				else
				{
					std::cout << "\nEl archivo no se ha abierto porque no existe, se abrira uno nuevo...\n";
					abrirArchivo(2, historial);
				}
				break;
			case 2:
				std::cout << "\nSe abrira el archivo borrando los mensajes...\n";
				abrirArchivo(seleccion, historial);
				break;
			case 3:
				std::cout << "\nSe va a cerrar el programa...\n";
				break;
			}
		}
		else
		{
			system("cls");
			std::cout << "\nLa opcion que ha seleccionado no es valida, por favor seleccione una que este dentro del rango.";
		}
	}while (seleccion < 1 || seleccion > 3);
	return 0;
}