#ifndef CLIENTES_H
#define CLIENTES_H
#include "Personas.h"
#include <vector>
struct Productos{
	bool activo=true;
	int cod_prod;
	int cant_comp;
	int client_id;
	int precio;
	char marca[30];
	char tipo[30];
};
struct ClientesBin{
	char nya[30];
	char nacionalidad[1];
	int dni;
	int fecha_nac;
	int pago;
	int cant_art_comprados;
	char metodo_pago[10];
	int num_cuotas;
	float interes;
	int fecha_compra;
	int cod_compra;
	bool activo=true;
};
class Clientes:public Personas {
private:
	int m_cod_compra;
	int m_pago=0;
	std::vector<Productos> m_compra;
	int m_cant_articulos_comprados=0;
	std::string m_metodo_pago;
	int m_num_cuotas=0;
	float m_interes=0;
	int m_fecha_compra;
	bool m_activo=true;
public:
	Clientes();
	Clientes(std::string nya, std::string nacion, int dni, int fecha_nac,int pago, const std::vector<Productos>&a,int articulos_comprados, std::string metodo_pago, int cuotas);
	int verCodCompra();
	std::string verMetodoPago();
	int verPago();
	int verArctComprados();
	std::vector<Productos> verCompra();
	Productos verProducto(int pos);
	float verCuotaDelMes();
	int verCuotas();
	int verInteres();
	int verFecha_Compra();
	bool verEstado();
	void modCodCompra(int n_cod_compra);
	void modMetodoPago(std::string n_metodo_pago);
	void modCompra(const std::vector<Productos>&n_compra);
	void modCantArtComprados(int n_cant_articulos_comprados);
	void modFecha_Compra(int n_fecha_compra);
	void agregarProducto(Productos n_prod);
	void eliminarProducto(int pos);
	void modPago(int n_pago);
	void modCuotas(int n_cuotas);
	void modInteres(float n_interes);
	void modEstado(bool n_estado);
};

#endif

