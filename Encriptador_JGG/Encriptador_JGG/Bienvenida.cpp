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

		if (entrada.length() == 1 && entrada[VALOR_PREDETERMINADO] >= '1' && entrada[VALOR_PREDETERMINADO] <= '3')
		{
			seleccion = entrada[VALOR_PREDETERMINADO] - '0';
		}
		else
		{
			seleccion = VALOR_PREDETERMINADO;
			//Como el valor que ha introducido no es valido vuelve a preguntar
		}

		//Seleccion de que se quiere hacer
		if ((seleccion >= 1) && (seleccion <= 3))
		{
			switch (seleccion)
			{
			case 1:
				if (existeArchivo())
				{
					bool cerrarTodo = abrirArchivo(1, historial);
					if (cerrarTodo)
					{
						seleccion = 3;
						// Solo si es true cerramos
					}
					else
					{
						seleccion = VALOR_PREDETERMINADO;
						// Si es false vuelvo
						system("cls");
					}
				}
				else
				{
					std::cout << "\nEl archivo no existe, se abrira uno nuevo...\n";
					if (abrirArchivo(2, historial))
					{	
						seleccion = 3;
					}
					else
					{
						seleccion = VALOR_PREDETERMINADO;
						system("cls");
					}
				}
				break;
			case 2:
				historial.clear();
				std::cout << "\nSe abrira el archivo borrando los mensajes...\n";
				if (abrirArchivo(2, historial)) 
				{
					seleccion = 3;
				}
				else
				{
					seleccion = VALOR_PREDETERMINADO;
					system("cls");
				}
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