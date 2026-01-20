// --- DECLARACIÓNES ---

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "Archivo.h"
#include "Encriptador.h"

#define COMIENZA_LINEA_LECTURA 3

// --- FUNCIÓNES ---

bool existeArchivo()
{
	//Comprobacion de la existencia del archivo
	std::ifstream archivo("encriptado.txt");
	return archivo.is_open();
}

void borrarArchivo()
{
	//Borrado de datos en el archivo
	std::ofstream archivo("encriptado.txt", std::ios::out | std::ios::trunc);

	if (archivo.is_open())
	{
		//archivo << "--- Numero Cifrado -------------------\n" << std::endl; //Se insertara en esta misma linea el numero, es una forma que he tenido de debugarlo.
		//Separador en el archivo
		archivo << "--- Historial Mensajes Encriptados ---\n" << std::endl;
		archivo.close();
	}
	else
	{
		//Archivo no disponible
		std::cerr << "No se pudo abrir el archivo." << std::endl;
	}
}

bool abrirArchivo(char seleccion, std::vector<std::string>& historial)
{
	system("cls");
	if (seleccion == 1)
	{
		if (existeArchivo())
		{
			//Recuperacion de datos existentes
			recuperarDatos(historial);
		}

		if (!historial.empty())
		{
			//Decision de que se quiere hacer con los anteriores mnesaajes
			char decision = VALOR_PREDETERMINADO;
			bool entradaValida = false;
			while (entradaValida != true)
			{
				//El usuario introduce lo que quiera hacer para que pueda acceder al menu de mensajeria
				std::cout << "\nExisten mensajes previos. Quieres mantenerlos?";
				std::cout << "\n[M] Mantener | [B] Borrar | [V] Volver: ";
				std::string decision_string;
				std::cin.ignore();
				std::cin >> decision_string;

				if ((decision_string.length() == 1 && decision_string[VALOR_PREDETERMINADO] == 'm') || (decision_string.length() == 1 && decision_string[VALOR_PREDETERMINADO] == 'M') || (decision_string.length() == 1 && decision_string[VALOR_PREDETERMINADO] == 'b') || (decision_string.length() == 1 && decision_string[VALOR_PREDETERMINADO] == 'B') || (decision_string.length() == 1 && decision_string[VALOR_PREDETERMINADO] == 'v') || (decision_string.length() == 1 && decision_string[VALOR_PREDETERMINADO] == 'V'))
				{
					decision = decision_string[VALOR_PREDETERMINADO];
				}
				else
				{
					decision = 'r';
				}

				if (decision == 'M' || decision == 'm')
				{
					//El usuario mantiene los mensajes y entra al chat para hablar
					std::cout << "\nManteniendo mensajes...";
					entradaValida = true;
					leerLinea(historial);
					std::cin.ignore();
					return escribirLinea(historial);
				}
				else if (decision == 'B' || decision == 'b')
				{
					//El usuario borra los mensajes y entra al chat para hablar
					std::cout << "\nBorrando historial...";
					entradaValida = true;
					borrarArchivo();
					historial.clear();
					leerLinea(historial);
					std::cin.ignore();
					return escribirLinea(historial);
				}
				else if (decision == 'V' || decision == 'v')
				{
					//Vuelve al menu
					system("cls");
					return false;
				}
				else
				{
					system("cls");
					std::cout << "\nOpcion no valida.";
				}
			}
		}
		else
		{
			//No existen mensajes anteriores asi que el programa crea un esquema nuevo par esctribir os mensajes nuevos
			std::cout << "\nNo se han encontrado mensajes previos. Preparando archivo...";
			std::cin.ignore();
			bool cerrar = escribirLinea(historial);
			return cerrar;
		}
	}
	else if (seleccion == 2)
	{
		//Se ha seleccionado borrar mensajes
		std::cout << "\nBorrando mensajes...";
		std::cout << "\nSe esta cargando el archivo...";
		borrarArchivo();
		historial.clear();
		bool cerrar = escribirLinea(historial);
		return cerrar;
	}
}

void recuperarDatos(std::vector<std::string>& historial)
//Recupereracion de datos de mensajes y encriptado previos
{
	std::ifstream archivo("encriptado.txt");
	std::string linea;
	int numLinea = VALOR_PREDETERMINADO;
	int checksumArchivo = VALOR_PREDETERMINADO;

	historial.clear();

	while (std::getline(archivo, linea))
	{
		//Printeado de mensajes anteriores en terminal sin encriptar
		numLinea++;

		if (numLinea == 1)
		{
			short valorExtraido = VALOR_PREDETERMINADO;
			for (short i = VALOR_PREDETERMINADO; i < linea.length(); i++)
			{
				if (linea[i] >= '0')
				{
					valorExtraido = (valorExtraido * 10) + (linea[i] - '0');
				}
			}
			//Valoracion de la integridad del archivo mediante checksum y valor extraido del archivo
			checksumArchivo = valorExtraido;
		}
		else if (numLinea >= COMIENZA_LINEA_LECTURA)
		{
			//Supresion de leido de mensajeria que empieze por el prefijo
			if (linea.substr(VALOR_PREDETERMINADO, COMIENZA_LINEA_LECTURA) != PREFIJO)
			{
				historial.push_back(desencriptadoCesar(linea));
			}
		}
	}
	archivo.close();

	if (!historial.empty())
	{
		//Si no existe nada calcula un nuevo checksum
		calcularCheckSum(historial, checksumArchivo);
	}
}

void leerLinea(std::vector<std::string>& historial)
{
	//Empieza la lectura de datos guardados
	std::cout << "\n\n--- Mensajes anteriores ---\n" << std::endl;
	for (const std::string& mensaje : historial)
	{
		//Leera todos los mensajes guardados en el archivo y los desencriptara
		std::cout << "=> " << mensaje << std::endl;
	}
	std::cout << "\n\n--- Nuevos mensajes ---" << std::endl;
	//Empiezan los mensajes que quiera escribir
}

bool escribirLinea(std::vector<std::string>& historial)
{
	//Escribe algo para que te mande hacia cualquier lado
	std::string mensaje;
	bool chatActivo = true;
	//std::cin.ignore();
	std::cout << "\nEscribe tu mensaje o [/] para salir al menu o [exit] para guardar y encriptar el documento:\n";
	while (chatActivo == true)
	{
		//Envellecedor
		std::cout << "Mensaje => ";
		std::getline(std::cin, mensaje);

		if (mensaje == "/")
		{
			//Si el usuario usa el prefijo / el programa le devolvera al menu de inicio
			chatActivo = false;
			system("cls");
			guardarDatos(historial);
			return false;
		}
		else if (mensaje == "exit" || mensaje == "EXIT")
		{
			//Si el usuario usa exit o EXIT el programa se finalizara
			guardarDatos(historial);
			std::cout << "\nCerrando programa...\n\n";
			return true;
		}
		else if (!mensaje.empty())
		{
			//Guardado en el vector
			historial.push_back(mensaje);
		}
	}
}

void guardarDatos(std::vector<std::string>& historial)
{
	//Guardado de datos y posterior generacion de checksum
	std::ofstream archivo("encriptado.txt", std::ios::out | std::ios::trunc);
	if (archivo.is_open())
	{
		int checksumActual = generarCheckSum(historial);
		std::cout << "Este es el numero de checksum generado para este guardado: ";
		archivo << checksumActual << "\n";

		std::cout << checksumActual;

		//Prefijo
		archivo << "--- Historial Mensajes Encriptados ---\n";

		//Mensajes encifrados
		for (const std::string& mensaje : historial)
		{
			archivo << encriptadoCesar(mensaje) << "\n";
		}
		archivo.close();
		std::cout << "\nArchivo actualizado y encriptado." << std::endl;
		return;
	}
}