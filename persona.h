
class Persona {
protected:
    char _Nombre[50];
    char _Apellido[50];
    char _DNI[12];
    char _Telefono[20];
    char _Email[50];
    bool _Estado;

public:
    Persona();

    // Métodos comunes
    void Cargar();
    void Mostrar();

    // Getters
     char *getNombre() ;
     char* getApellido() ;
     char *getDni() ;
     char *getTelefono() ;
     char *getEmail() ;
    bool getEstado() ;

    // Setters
    void setNombre( char* nombre);
    void setApellido( char *apellido);
    void setDni( char* dni);
    void setTelefono( char* tel);
    void setEmail( char *email);
    void setEstado(bool est);


};

