#ifndef PERSONAS_H
#define PERSONAS_H
#include <string>

class Personas{
protected:
	std::string m_nya="NN";
	std::string m_nacionalidad; 
	int m_dni;
	int m_fecha_nac; 
public:
	Personas();
	Personas(std::string nya,std::string nacion,int dni,int fecha_nac);
	std::string verNombreYApellido();
	std::string verNacionalidad();
	int verDNI();
	int verFecha_Nac();
	void modNombreYApellido(std::string n_nomb);
	void modNacionalidad(std::string n_nacion);
	void modDNI(int n_dni);
	void modFecha_Nac(int n_fecha_nac);
};

#endif

