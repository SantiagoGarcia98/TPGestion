  #include "Fecha.h"
  #include <iostream>
  #include <chrono>
   using namespace std;



  Fecha::Fecha() : _dia(0), _mes(0), _anio(0) { }

  Fecha::Fecha(int dia, int mes, int anio) {
      setDia(dia);
      setMes(mes);
      setAnio(anio);
  }

  int Fecha::getDia() { return _dia; }
  void Fecha::setDia(int dia) { _dia = dia; }

  int Fecha::getMes() { return _mes; }
  void Fecha::setMes(int mes) { _mes = mes; }

  int Fecha::getAnio() { return _anio; }
  void Fecha::setAnio(int anio) { _anio = anio; }
  using namespace std;
 /* void Fecha::Cargar() {
      do {
          cout << "Dia: ";
          cin >> _dia;
          cout << "Mes: ";
          cin >> _mes;
          cout << "A" << char(164) << "o:";
          cin >> _anio;

          if (!esFechaValida(_dia, _mes, _anio)) {
              cout << " Fecha invalida. Reingrese.\n\n";
          }
      } while (!esFechaValida(_dia, _mes, _anio));
  }
*/
void Fecha::Cargar()
{
    do
    {
        cout << "Dia: ";
        cin >> _dia;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error. Debe ingresar un numero.\n";
            cout << "Dia: ";
            cin >> _dia;
        }

        cout << "Mes: ";
        cin >> _mes;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error. Debe ingresar un numero.\n";
            cout << "Mes: ";
            cin >> _mes;
        }

        cout << "A" << char(164) << "o: ";
        cin >> _anio;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error. Debe ingresar un numero.\n";
            cout << "A" << char(164) << "o: ";
            cin >> _anio;
        }

        if (!esFechaValida(_dia, _mes, _anio))
        {
            cout << "\nFecha invalida. Reingrese.\n\n";
        }

    } while (!esFechaValida(_dia, _mes, _anio));

    cin.ignore();
}

  bool Fecha::esBisiesto(int anio) {
      return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
  }

  bool Fecha::esFechaValida(int dia, int mes, int anio) {
      if (anio < 1900 || anio > 2100 || mes < 1 || mes > 12 || dia < 1)
          return false;

      int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      if (mes == 2 && esBisiesto(anio))
          diasPorMes[1] = 29;

      return dia <= diasPorMes[mes - 1];
  }
  string Fecha::toString() {
    return to_string(_dia) + "/"+ to_string(_mes) + "/" + to_string(_anio); }

  void Fecha::Mostrar() {
      cout << toString() << endl;
  }

bool Fecha::operator==(const Fecha &otra) const
{
    return _dia == otra._dia && _mes == otra._mes && _anio == otra._anio;
}

bool Fecha::operator<(const Fecha &otra) const
{
    if (_anio < otra._anio) return true;
    if (_anio > otra._anio) return false;
    if (_mes < otra._mes) return true;
    if (_mes > otra._mes) return false;
    return _dia < otra._dia;
}

bool Fecha::operator>(const Fecha &otra) const
{
    return otra < *this;
}

bool Fecha::operator<=(const Fecha &otra) const
{
    return *this < otra || *this == otra;
}

bool Fecha::operator>=(const Fecha &otra) const
{
    return *this > otra || *this == otra;
}
bool Fecha::esMayor(Fecha otra) const
{
    if (_anio != otra._anio)
        return _anio > otra._anio;

    if (_mes != otra._mes)
        return _mes > otra._mes;

    return _dia > otra._dia;
}

void Fecha::setCurrentDate()
{
    // Obtener la fecha actual del sistema
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm* localTime = std::localtime(&now_c);

    // Asignar los valores a la fecha
    _dia = localTime->tm_mday;
    _mes = localTime->tm_mon + 1; // tm_mon va de 0 a 11
    _anio = localTime->tm_year + 1900; // tm_year es el número de años desde 1900
}
