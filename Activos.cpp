#include "Activos.h"
#include <algorithm>

Activos::Activos(){}
Activos::Activos(double dinero_caja,double dinero_banco,double dinero_credito){
	m_dinero_caja=dinero_caja;
	m_dinero_banco=dinero_banco;
	m_dinero_credito=dinero_credito;
}
double Activos::verDineroCaja(){return m_dinero_caja;}
double Activos::verDineroBanco(){return m_dinero_banco;}
double Activos::verDineroCredito(){return m_dinero_credito;}
void Activos::modDineroCaja(double n_dinero_caja){m_dinero_caja=n_dinero_caja;}
void Activos::modDineroBanco(double n_dinero_banco){m_dinero_banco=n_dinero_banco;}
void Activos::modDineroCredito(double n_dinero_credito){m_dinero_credito=n_dinero_credito;}
void Activos::Depositar(double cant){m_dinero_banco+=cant; m_dinero_caja-=cant;}
void Activos::Retiro(double cant){m_dinero_caja+=cant; m_dinero_banco-=cant;}
bool operator==(const Inventario& inv1, const Inventario& inv2) {
	return inv1.cod_prod == inv2.cod_prod;
}
