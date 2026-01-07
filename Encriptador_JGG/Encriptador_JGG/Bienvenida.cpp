// --- DECLARACIÓNES ---

#include <iostream>
#include "Bienvenida.h"
#include "Archivo.h"

// --- FUNCIÓNES ---

void Bienvenida(short seleccion, std::vector<std::string> & historial)
{
	std::string entrada;
	seleccion = VALOR_PREDETERMINADO;
	while (seleccion != 3)
	{
		// Menu de bienvenida
		std::cout << "Seleccione una opcion de la que se les propone para acceder a lo que necesite: \n\n";

		// --- MENU ---

		std::cout << "# - - - - - - - - - - - - - - - - - - - - - - #" << std::endl;
		std::cout << "| 1. Entrar en el archivo.                    |" << std::endl;
		std::cout << "| 2. Entrar al archivo borrando mensajes      |" << std::endl;
		std::cout << "| 3. Salir del programa.                      |" << std::endl;
		std::cout << "# - - - - - - - - - - - - - - - - - - - - - - #" << std::endl;
		std::cout << "Opcion: ";
		std::cin >> entrada;

		if (entrada.length() == 1 && entrada[0] >= '1' && entrada[0] <= '3')
		{
			seleccion = entrada[0] - '0';
		}
		else
		{
			seleccion = 0;
			//Como el valor que ha introducido no es valido vuelve a preguntar
		}

		//Seleccion de que se quiere hacer
		if ((seleccion >= 1) && (seleccion <= 3))
		{
			switch (seleccion)
			{
			case 1:
				if (existeArchivo() == true)
				{
					// Si abrirArchivo devuelve true
					if (abrirArchivo(seleccion, historial))
					{
						seleccion = 3;
					}
					else
					{
						seleccion = VALOR_PREDETERMINADO;
					}
					/*std::cout << "\nSe abrira el archivo...\n";
					//Apertura del documento
					abrirArchivo(seleccion, historial);
					seleccion = VALOR_PREDETERMINADO;
					if (abrirArchivo(seleccion, historial) == true)
					{
						seleccion = 3;
					}*/
				}
				else
				{
					std::cout << "\nEl archivo no se ha abierto porque no existe, se abrira uno nuevo...\n";
					//Creacion del documento
					if (abrirArchivo(2, historial))
					{	
						seleccion = 3;
					}
					else
					{
						abrirArchivo(seleccion, historial);
						seleccion = VALOR_PREDETERMINADO;
					}
				}
				break;
			case 2:
				std::cout << "\nSe abrira el archivo borrando los mensajes...\n";
				//Borrado de archivos borrando datos
				abrirArchivo(seleccion, historial);
				seleccion = VALOR_PREDETERMINADO;
				break;
			case 3:
				std::cout << "\nSe va a cerrar el programa...\n";
				//Cerrado del programa
				return;
			}
		}
		else
		{
			//Orden no valida
			system("cls");
			std::cout << "\nLa opcion que ha seleccionado no es valida, por favor seleccione una que este dentro del rango.";
		}
	}
}