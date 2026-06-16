#pragma once
#include "Fecha.h"
#include <string>

std::string cargarCadena();

bool quiereCancelar(std::string mensaje = "Ingrese 0 para cancelar o cualquier numero para continuar: ");

int validarPositivo(int num);

bool confirmarAccion(std::string mensaje);
