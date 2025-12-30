// --- DECLARACIÓNES ---

#pragma once
#include <vector>
#include <string>
#include "Bienvenida.h"

#define PREFIJO

void abrirArchivo(char seleccion, std::vector<std::string> & historial);
void recuperarDatos(std::vector<std::string> & historial);
void leerLinea();
void escribirLinea();
void guardarDatos();
#define VALOR_PREDETERMINADO 0