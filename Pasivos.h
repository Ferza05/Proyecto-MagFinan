#ifndef PASIVOS_H
#define PASIVOS_H
#include <string>

class Pasivos {
private:
	float m_salarios;
	float m_deuda_proveedor;
	float m_servicios_a_pagar;
	float m_impuestos_varios;
public:
	Pasivos();
	Pasivos(float salarios,float deuda_proveedor,float servicios_a_pagar,float impuestos_varios);
	float verSalarios();
	float verDeudaProveedor();
	float verServiciosAPagar();
	float verImpuestosVarios();
	void ActualizarRegistro(std::string nomb_archi);
	void CrearRegistro(std::string nomb_archi);
	void modSalarios(float n_salarios);
	void modDeudaProveedor(float n_deuda_proveedor);
	void modServiciosAPagar(float n_servicios_a_pagar);
	void modImpuestosVarios(float n_impuestos_varios);
};

#endif

