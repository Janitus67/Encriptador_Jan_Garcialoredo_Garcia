// --- DECLARACIÓNES ---

#include "Encriptador.h"
#include <fstream>
#include <string>
#include <iostream>

// --- FUNCIÓNES ---

//Encripta letra a letra cada palabra en el documento menos los prefijos y checksum para lectura facil
std::string encriptadoCesar(std::string mensaje)
{
	std::string resultado = mensaje;
	//Excepciones de a - z y z - a y transformacion de cesar normal (Todo en bocabulario ingles)
	for (short i = 0; i < resultado.length(); i++)
	{
		if (resultado[i] == 90)
		{
			resultado[i] = 65;
		}
		else if (resultado[i] == 122)
		{
			resultado[i] = 97;
		}
		else if (resultado[i] == 32)
		{
			resultado[i] = resultado[i];
		}
		else if (resultado[i] == 57)
		{
			resultado[i] = 48;
		}
		else
		{
			resultado[i] = resultado[i] + 1;
		}
	}
	return resultado;
}
std::string desencriptadoCesar(std::string mensaje)
{
	std::string resultado = mensaje;
	//Hace lo mismo que el encriptado pero al reves, desencripta, z - a y a - z
	for (short i = 0; i < resultado.length(); i++)
	{
		if (resultado[i] == 65)
		{
			resultado[i] = 90;
		}
		else if (resultado[i] == 97)
		{
			resultado[i] = 122;
		}
		else if (resultado[i] == 32)
		{
			resultado[i] = resultado[i];
		}
		else if (resultado[i] == 48)
		{
			resultado[i] = 57;
		}
		else
		{
			resultado[i] = resultado[i] - 1;
		}
	}
	return resultado;
}

void calcularCheckSum(std::vector<std::string>& historial, short checksumArchivo)
{
	short valorCalculado = generarCheckSum(historial);

	if (checksumArchivo == valorCalculado)
	{//Calculo satisfactorio del checksum
		std::cout << "\n[CHECKSUM VERIFICADO]: Los datos estan intactos." << std::endl;
		std::cout << "Se esperaba: " << checksumArchivo << " | Se ha calculado: " << valorCalculado << std::endl;
	}
	else
	{
		//En caso de que los checksums no coincidan se dira y ofrecera que quiere hacer el usuario
		std::cout << "\n[CHECKSUM VERIFICADO]: ALERTA, los datos han estado vulnerados!!!" << std::endl;
		std::cout << "Se esperaba: " << checksumArchivo << " | Se ha calculado: " << valorCalculado << std::endl;
		std::cout << "El archivo podria haber sido manipulado." << std::endl;
	}
}

int generarCheckSum(std::vector<std::string>& historial)
{
	//Generacion del checksum calculado letra a letra
	short suma = 0;
	for (const std::string& mensaje : historial)
	{
		for (char c : mensaje)
		{
			suma += (short)c;
		}
	}
	return suma;
}