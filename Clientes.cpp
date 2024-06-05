#include "Clientes.h"
#include "Funciones.h"

Clientes::Clientes(){}
Clientes::Clientes(std::string nya, std::string nacion, int dni, int fecha_nac,
				   int pago, const std::vector<Productos>&compra,int articulos_comprados, std::string metodo_pago,int cuotas):Personas(nya,nacion,dni,fecha_nac){
	m_cod_compra=(fecha_nac+obtenerFechaDeHoy()+rand()%10);
	m_pago=pago;
	m_compra=compra;
	m_cant_articulos_comprados=articulos_comprados;
	m_metodo_pago=metodo_pago;
	m_fecha_compra=obtenerFechaDeHoy();
	if(m_metodo_pago!="Credito"){
		m_num_cuotas=0; m_interes=0;
	}else{
		if(m_metodo_pago=="Credito"){
			switch(cuotas){
				case 3:
					m_num_cuotas=3;
					m_interes=6;
				break;
				case 6:
					m_num_cuotas=6;
					m_interes=9;
				break;
				case 12:
					m_num_cuotas=12;
					m_interes=13;
				break;
			}
		}	
	}
}
int Clientes::verCodCompra(){return m_cod_compra;}
std::string Clientes::verMetodoPago(){return m_metodo_pago;}
int Clientes::verPago(){return m_pago;}
int Clientes::verArctComprados(){return m_cant_articulos_comprados;}
std::vector<Productos> Clientes::verCompra(){return m_compra;}
Productos Clientes::verProducto(int pos){return m_compra[pos];}
float Clientes::verCuotaDelMes(){
	float a=m_pago/m_num_cuotas,b=m_interes*m_pago,c=b/100;
	return a+c;
}
int Clientes::verCuotas(){return m_num_cuotas;}
int Clientes::verInteres(){return m_interes;}
int Clientes::verFecha_Compra(){return m_fecha_compra;}
bool Clientes::verEstado(){return m_activo;}
void Clientes::modCodCompra(int n_cod_compra){m_cod_compra=n_cod_compra;}
void Clientes::modMetodoPago(std::string n_metodo_pago){m_metodo_pago=n_metodo_pago;}
void Clientes::modCompra(const std::vector<Productos>&n_compra){m_compra=n_compra;}
void Clientes::modCantArtComprados(int n_cant_articulos_comprados){m_cant_articulos_comprados=n_cant_articulos_comprados;}
void Clientes::modFecha_Compra(int n_fecha_compra){m_fecha_compra=n_fecha_compra;}
void Clientes::agregarProducto(Productos n_prod){m_compra.push_back(n_prod);}
void Clientes::eliminarProducto(int pos){
	auto it=m_compra.begin();
	std::advance(it,pos);
	m_compra.erase(it);
}
void Clientes::modPago(int n_pago){m_pago=n_pago;}
void Clientes::modCuotas(int n_cuotas){
	switch(n_cuotas){
	case 3:
		m_num_cuotas=3;
		m_interes=6;
		break;
	case 6:
		m_num_cuotas=6;
		m_interes=9;
		break;
	case 12:
		m_num_cuotas=12;
		m_interes=13;
		break;
	}
}	
void Clientes::modInteres(float n_interes){m_interes=n_interes;}
void Clientes::modEstado(bool n_estado){m_activo=n_estado;}
