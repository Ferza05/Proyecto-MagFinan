#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Personas.h"

struct EmpleadoBin{
	char nya[30];
	int dni;
	int fecha_nac;
	char nacionalidad[1];
	char ocupacion[30];
	int salario;
	int fecha_ingreso;
	char correo[30];
	char telefono[20];
	bool activo;
};

class Empleado : public Personas {
private:
	std::string m_ocupacion;
	int m_salario;
	int m_fecha_ingreso;
	std::string m_telefono;
	std::string m_correo;
	bool m_activo=true;
public:
	Empleado();
	Empleado(std::string nya,std::string nacion,int dni,int fecha_nac,std::string ocupacion,int fecha_ingreso,std::string tel,std::string mail);
	std::string verOcupacion();
	int verSalario();
	int verFechaIngreso();
	std::string verTelefono();
	std::string verCorreo();
	bool verEstado();
	void modOcupacion(std::string n_ocupacion);
	void modSalario(int n_salario);
	void modFechaIngreso(int n_fecha_ingreso);
	void modTelefono(std::string n_telefono);
	void modCorreo(std::string n_correo);
	void modEstado(bool n_estado);
};

#endif

