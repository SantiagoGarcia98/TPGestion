#pragma once
#include "Fecha.h"
#include <string>

std::string cargarCadena();

bool quiereCancelar(std::string mensaje = "Ingrese 0 para cancelar o 1 para continuar: ");
int validarPositivo(int num);
void validarCarga(bool resultado);
void validarModificacion(bool resultado);
void validarBaja(bool resultado);
void validarAlta(bool resultado);
///bool confirmarAccion(std::string mensaje);

bool validarDNI( char *dni);
bool esTelefonoValido( char* tel);
bool confirmarAccion(const char* mensaje);
bool Volver(const char* texto);

int ingresarOpcion(int minimo, int maximo);

int ingresarEntero(std::string mensaje, int minimo, int maximo);
float ingresarFloat(std::string mensaje, float minimo);
