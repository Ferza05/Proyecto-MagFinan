#include "Utilidades.h"
#include "Funciones.h"
#include <iomanip>
#include <fstream>
#include <ios>
#include <cstring>
#include "Personas.h"
#include <algorithm>
#include <cstdio>
#include "Logs.h"
#include <cstdlib>
using namespace std;

void ConversionYGuardadoBin_Clientes(Clientes &a,std::string nom_archi, int pos){
	std::fstream archi(nom_archi,std::ios::binary|std::ios::in|std::ios::out);
	
	if (!archi.is_open()) {
		archi.open(nom_archi,std::ios::binary|std::ios::out);
		archi.close();
		archi.open(nom_archi,std::ios::binary|std::ios::in|std::ios::out);
	}
	
	ClientesBin x; Clientes z=a; 
	std::strcpy(x.nya,z.verNombreYApellido().c_str()); std::strcpy(x.nacionalidad,z.verNacionalidad().c_str());
	std::strcpy(x.metodo_pago,z.verMetodoPago().c_str());
	x.dni=z.verDNI(); x.fecha_nac=z.verFecha_Nac(); 
	x.num_cuotas=z.verCuotas(); x.interes=z.verInteres(); x.pago=z.verPago(); x.cant_art_comprados=z.verArctComprados();
	x.fecha_compra=z.verFecha_Compra(); x.cod_compra=z.verCodCompra(); x.activo=z.verEstado();
	archi.seekp(pos*sizeof(ClientesBin));
	archi.write(reinterpret_cast<char*>(&x),sizeof(ClientesBin));
	archi.close();
}
void ConversionYGuardadoBin_Empleados(Empleado &a,std::string nom_archi, int pos){
	std::fstream archi(nom_archi,std::ios::binary|std::ios::in|std::ios::out);
	
	if (!archi.is_open()) {
		archi.open(nom_archi,std::ios::binary|std::ios::out);
		archi.close();
		archi.open(nom_archi,std::ios::binary|std::ios::in|std::ios::out);
	}
	
	EmpleadoBin x; Empleado z=a; 
	std::strcpy(x.nya,z.verNombreYApellido().c_str()); std::strcpy(x.nacionalidad,z.verNacionalidad().c_str());
	x.dni=z.verDNI(); x.fecha_nac=z.verFecha_Nac();
	std::strcpy(x.ocupacion,z.verOcupacion().c_str());
	x.salario=z.verSalario(); x.fecha_ingreso=z.verFechaIngreso();
	strcpy(x.correo,z.verCorreo().c_str()); strcpy(x.telefono,z.verTelefono().c_str());
	x.activo=z.verEstado();
	archi.seekp(pos*sizeof(EmpleadoBin));
	archi.write(reinterpret_cast<char*>(&x),sizeof(EmpleadoBin));
	
	archi.close();
}

void ConversionYGuardadoTxt_NomArchivos(const std::vector<std::string> &a,std::string nom_archi,bool escribir_al_final){
	std::ofstream archi;
	if (escribir_al_final) {
		archi.open(nom_archi,std::ios::app);
	}else{archi.open(nom_archi);}
	for(size_t i=0;i<a.size();i++) { 
		std::string s=a[i];
		archi<<s<<std::endl;
	}
	archi.close();
}

Clientes ConversionYLecturaMem_Clientes(std::string nom_archi,int pos){
	std::ifstream archi(nom_archi,std::ios::binary|std::ios::ate);
	Clientes v; ClientesBin x;
	int tamanio=archi.tellg()/sizeof(ClientesBin);
	if(pos>-1 && pos<tamanio){
		archi.seekg(0);
		archi.seekg(pos*sizeof(ClientesBin));
	}else{v.modDNI(-1); return v;}
	archi.read(reinterpret_cast<char*>(&x),sizeof(ClientesBin));
	if (x.activo) {
		v.modNombreYApellido(x.nya); v.modNacionalidad(x.nacionalidad);
		v.modDNI(x.dni); v.modFecha_Nac(x.fecha_nac); v.modPago(x.pago); v.modCantArtComprados(x.cant_art_comprados);
		v.modMetodoPago(x.metodo_pago); v.modCuotas(x.num_cuotas); v.modInteres(x.interes);
		v.modFecha_Compra(x.fecha_compra); v.modCodCompra(x.cod_compra); v.modEstado(x.activo);
		archi.close();
		return v;
	}else{v.modDNI(-2);return v;}
}
Empleado ConversionYLecturaMem_Empleados(std::string nom_archi,int pos){
	std::ifstream archi(nom_archi,std::ios::binary|std::ios::ate);
	Empleado v; EmpleadoBin x;
	int tamanio=archi.tellg()/sizeof(EmpleadoBin);
		if(pos>-1 && pos<tamanio){
		archi.seekg(0);
		archi.seekg(pos*sizeof(EmpleadoBin));
	}else{v.modDNI(-1);return v;}
	archi.read(reinterpret_cast<char*>(&x),sizeof(EmpleadoBin));
	if (x.activo) {
		v.modNombreYApellido(x.nya); v.modNacionalidad(x.nacionalidad);
		v.modDNI(x.dni); v.modFecha_Nac(x.fecha_nac); v.modOcupacion(x.ocupacion); 
		v.modSalario(x.salario); v.modFechaIngreso(x.fecha_ingreso);
		v.modCorreo(x.correo); v.modTelefono(x.telefono); v.modEstado(x.activo);
		archi.close();
		return v;
	}else{v.modDNI(-2);return v;}
};

std::vector<std::string> ConversionYLecturaMem_NomArchivos(std::string nom_archivo){
	std::ifstream archi(nom_archivo); 
	std::string s; 
	std::vector<std::string> v;
	while(getline(archi,s)){
		v.push_back(s);
	}
	archi.close();
	return v;
}

void EliminarClienteBin(int cod_compra,std::string nom_archi){
	std::fstream archi(nom_archi,std::ios::binary|std::ios::out|std::ios::in|std::ios::ate);
	int cant=archi.tellg()/sizeof(ClientesBin); archi.seekg(0); archi.seekp(0);
	for(int i=0;i<cant;i++) { 
		ClientesBin aux;
		archi.read(reinterpret_cast<char*>(&aux),sizeof(ClientesBin));
		if(aux.cod_compra==cod_compra && aux.activo){
			aux.activo=false;
			archi.seekp(i*sizeof(ClientesBin));
			archi.write(reinterpret_cast<char*>(&aux),sizeof(ClientesBin));
			break;
		}
	}
	archi.close();	
}
void EliminarEmpleadoBin(int dni,std::string nom_archi){
	std::fstream archi(nom_archi,std::ios::binary|std::ios::out|std::ios::in|std::ios::ate);
	
	int cant=archi.tellg()/sizeof(EmpleadoBin); archi.seekg(0); archi.seekp(0);
	for(int i=0;i<cant;i++) { 
		EmpleadoBin aux;
		archi.read(reinterpret_cast<char*>(&aux),sizeof(EmpleadoBin));
		if(aux.dni==dni && aux.activo){
			aux.activo=false;
			archi.seekp(i*sizeof(EmpleadoBin));
			archi.write(reinterpret_cast<char*>(&aux),sizeof(EmpleadoBin));
			break;
		}
	}
	archi.close();
}
	
void EliminarNomArchivo(std::string title,std::string nom_archi){
	std::vector<std::string> v=ConversionYLecturaMem_NomArchivos(nom_archi);
	for(size_t i=0;i<v.size();i++) { 
		if(v[i]==title){
			v.erase(v.begin()+i);
		}
	}
	ConversionYGuardadoTxt_NomArchivos(v,nom_archi,false);
}
bool ComparaInventario(Inventario a,Inventario b){
	if(a.cod_prod<b.cod_prod){return true;}else{return false;}
}

void ConversionYGuardadoBin_Activos(Activos &a,std::string nom_archi){
	std::ofstream archi(nom_archi,std::ios::binary);
	double dinero_caja=a.verDineroCaja(), dinero_banco=a.verDineroBanco(), dinero_credito=a.verDineroCredito(); 
	archi.write(reinterpret_cast<char*>(&dinero_caja),sizeof(double));
	archi.write(reinterpret_cast<char*>(&dinero_banco),sizeof(double));
	archi.write(reinterpret_cast<char*>(&dinero_credito),sizeof(double));
	archi.close();
}
void ConversionYGuardadoBin_Pasivos(Pasivos &a,std::string nom_archi){
	std::ofstream archi(nom_archi,std::ios::binary);
	float salarios=a.verSalarios(), deuda_prov=a.verDeudaProveedor(), servicios=a.verServiciosAPagar(), impuestos=a.verImpuestosVarios();
	archi.write(reinterpret_cast<char*>(&salarios),sizeof(float));
	archi.write(reinterpret_cast<char*>(&deuda_prov),sizeof(float));
	archi.write(reinterpret_cast<char*>(&servicios),sizeof(float));
	archi.write(reinterpret_cast<char*>(&impuestos),sizeof(float));
	archi.close();
}
	
Activos ConversionYLecturaMem_Activos(std::string nom_archi){
	std::ifstream archi(nom_archi,std::ios::binary);
	Activos a;
	double d_caja,d_banco,d_credito;
	archi.read(reinterpret_cast<char*>(&d_caja),sizeof(double));
	archi.read(reinterpret_cast<char*>(&d_banco),sizeof(double));
	archi.read(reinterpret_cast<char*>(&d_credito),sizeof(double));
	a.modDineroCaja(d_caja); a.modDineroBanco(d_banco); a.modDineroCredito(d_credito);
	archi.close();
	return a;
}
Pasivos ConversionYLecturaMem_Pasivos(std::string nom_archi){
	std::ifstream archi(nom_archi,std::ios::binary);
	Pasivos a;
	float salarios,deuda_prov,servicios,impuestos;
	archi.read(reinterpret_cast<char*>(&salarios),sizeof(float));
	archi.read(reinterpret_cast<char*>(&deuda_prov),sizeof(float));
	archi.read(reinterpret_cast<char*>(&servicios),sizeof(float));
	archi.read(reinterpret_cast<char*>(&impuestos),sizeof(float));
	a.modSalarios(salarios); a.modDeudaProveedor(deuda_prov); a.modServiciosAPagar(servicios); a.modImpuestosVarios(impuestos);
	archi.close();
	return a;
}

void combinarInventarios(std::vector<Inventario>& inventarios) {
	sort(inventarios.begin(),inventarios.end(),ComparaInventario);
	for(size_t i=0;i<inventarios.size();++i) {
		for(size_t j=i+1;j<inventarios.size();++j) {
			if (inventarios[i]==inventarios[j]) {
				inventarios[i].stock_disponible += inventarios[j].stock_disponible;
				
				inventarios.erase(inventarios.begin() + j);
				--j;
			}
		}
	}
}

void GuardarProductos(Clientes &a,const std::vector<Productos> &prod,std::string nom_archi, bool YaExiste){
	std::fstream archi(nom_archi,std::ios::binary|std::ios::in|std::ios::out);
	
	if (!archi.is_open()) {
		archi.open(nom_archi,std::ios::binary|std::ios::out);
		archi.close();
		archi.open(nom_archi,std::ios::binary|std::ios::in|std::ios::out);
	}
	
	bool encontrado=false;
	Productos aux;
	
	if (YaExiste) {
		for (size_t i=0;i<prod.size();i++) {
			Productos x=prod[i];
			x.client_id=a.verCodCompra();
			archi.seekg(0);
			while(!encontrado && archi.read(reinterpret_cast<char*>(&aux),sizeof(Productos))){
				if(aux.activo && aux.cod_prod==x.cod_prod && aux.client_id==a.verCodCompra()){
					encontrado=true; int punt=archi.tellg();
					archi.seekp(punt-sizeof(Productos));
					archi.write(reinterpret_cast<char*>(&x),sizeof(Productos));
					break;
				}
			}
		}
	}
	if(!YaExiste){
		archi.close();
		archi.open(nom_archi,std::ios::binary|std::ios::out|std::ios::app);
		for(size_t i=0;i<prod.size();i++) {
			Productos x=prod[i];
			archi.write(reinterpret_cast<char*>(&x), sizeof(Productos));
		}
	}
	archi.close();
}
void GuardarInventario(Inventario &a,std::string nom_archi, int pos, int cod_prod){
	std::fstream archi(nom_archi,std::ios::binary|std::ios::in|std::ios::out);
	
	if (!archi.is_open()) {
		archi.open(nom_archi,std::ios::binary|std::ios::out);
		archi.close();
		archi.open(nom_archi,std::ios::binary|std::ios::in|std::ios::out);
	}
	
	bool encontrado=false;
	Inventario actual;
	if (pos==-1 && cod_prod!=-1) {
		while(!encontrado && archi.read(reinterpret_cast<char*>(&actual),sizeof(Inventario))){
			if(actual.activo && actual.cod_prod==a.cod_prod){
				encontrado=true; int punt=archi.tellg();
				archi.seekp(punt-sizeof(Inventario));
				archi.write(reinterpret_cast<char*>(&a),sizeof(Inventario));
			}
		}
	}
	if (cod_prod==-1 && pos!=-1) {
		archi.seekp(pos*sizeof(Inventario));
		archi.write(reinterpret_cast<char*>(&a), sizeof(Inventario));
	}
	
	archi.close();
}

std::vector<Productos> LeerProductos(Clientes &a,std::string nom_archi){
	std::ifstream archi(nom_archi,std::ios::binary);
	std::vector<Productos> prod; Productos x;
	while(archi.read(reinterpret_cast<char*>(&x),sizeof(Productos))){
		if(a.verCodCompra()==x.client_id && x.activo){prod.push_back(x);}
	}
	archi.close();
	return prod;
}
Inventario LeerInventario(std::string nom_archi, int pos, int cod_prod){
	std::ifstream archi(nom_archi,std::ios::binary|std::ios::ate);
	int tamanio=archi.tellg()/sizeof(Inventario);
	Inventario x,y; y.precio=-1;
	archi.seekg(0);
	if (cod_prod==-1 && pos!=-1) {
		if(pos<tamanio){
			archi.seekg(0); archi.seekg(pos*sizeof(Inventario));
			archi.read(reinterpret_cast<char*>(&x),sizeof(Inventario));
			archi.close();
			return x;
		}else{x.precio=-1; archi.close(); return x;}//bandera para detener la lectura
	}
	if (pos==-1 && cod_prod!=-1) {
		while(archi.read(reinterpret_cast<char*>(&x),sizeof(Inventario))){
			if(x.activo && cod_prod==x.cod_prod){
				archi.close();
				return x;
			}
		}
	}
	
	archi.close();
	return y;
}

void EliminarProductos(int id_compra,std::string nom_archi){
	std::fstream archi(nom_archi,std::ios::binary|std::ios::out|std::ios::in|std::ios::ate);
	int cant=archi.tellg()/sizeof(Productos); archi.seekg(0); archi.seekp(0);
	for(int i=0;i<cant;i++) { 
		Productos aux;
		archi.read(reinterpret_cast<char*>(&aux),sizeof(Productos));
		if(aux.client_id==id_compra && aux.activo){
			aux.activo=false;
			archi.seekp(i*sizeof(Productos));
			archi.write(reinterpret_cast<char*>(&aux),sizeof(Productos));
		}
	}
	archi.close();
}
void EliminarProducto(Clientes &a,int cod_prod,std::string nom_archi){
	std::fstream archi(nom_archi,std::ios::binary|std::ios::out|std::ios::in|std::ios::ate);
	int cant=archi.tellg()/sizeof(Productos); archi.seekg(0); archi.seekp(0);
	for(int i=0;i<cant;i++) { 
		Productos aux;
		archi.read(reinterpret_cast<char*>(&aux),sizeof(Productos));
		if(aux.cod_prod==cod_prod && aux.activo && a.verCodCompra()==aux.client_id){
			aux.activo=false;
			archi.seekp(i*sizeof(Productos));
			archi.write(reinterpret_cast<char*>(&aux),sizeof(Productos));
			break;
		}
	}
	archi.close();
}
void EliminarInventario(int cod_prod,std::string nom_archi){
	std::fstream archi(nom_archi,std::ios::binary|std::ios::out|std::ios::in|std::ios::ate);
	int cant=archi.tellg()/sizeof(Inventario); archi.seekg(0); archi.seekp(0);
	for(int i=0;i<cant;i++) { 
		Inventario aux;
		archi.read(reinterpret_cast<char*>(&aux),sizeof(Inventario));
		if(aux.cod_prod==cod_prod && aux.activo){
			aux.activo=false;
			archi.seekp(i*sizeof(Inventario));
			archi.write(reinterpret_cast<char*>(&aux),sizeof(Inventario));
			break;
		}
	}
	archi.close();
}

void RenombrarYCrearCopiaClientes(std::string nom_archi){
	size_t punto = nom_archi.find('.'); std::string nom_archi_new=nom_archi;
	if (punto<nom_archi.size()) {
		nom_archi_new.insert(punto, "_new");
	} else {
		nom_archi_new += "_new";
	}
	std::ifstream archi_old(nom_archi,std::ios::binary);
	std::ofstream archi_new(nom_archi_new,std::ios::binary);
	ClientesBin aux;
	while(archi_old.read(reinterpret_cast<char*>(&aux),sizeof(ClientesBin))){
		if(aux.activo){archi_new.write(reinterpret_cast<char*>(&aux),sizeof(ClientesBin));}
	}
	std::string nom_archi_old=nom_archi;
	if (punto<nom_archi.size()) {
		nom_archi_old.insert(punto, "_old");
	} else {
		nom_archi_old += "_old";
	}
	archi_old.close(); archi_new.close();
	rename(nom_archi.c_str(),nom_archi_old.c_str());
	rename(nom_archi_new.c_str(),nom_archi.c_str());
	remove(nom_archi_old.c_str());
}
void RenombrarYCrearCopiaEmpleado(std::string nom_archi){
	size_t punto = nom_archi.find('.'); std::string nom_archi_new=nom_archi;
	if (punto<nom_archi.size()) {
		nom_archi_new.insert(punto, "_new");
	} else {
		nom_archi_new += "_new";
	}
	std::ifstream archi_old(nom_archi,std::ios::binary);
	std::ofstream archi_new(nom_archi_new,std::ios::binary);
	EmpleadoBin aux;
	while(archi_old.read(reinterpret_cast<char*>(&aux),sizeof(EmpleadoBin))){
		if(aux.activo){archi_new.write(reinterpret_cast<char*>(&aux),sizeof(EmpleadoBin));}
	}
	std::string nom_archi_old=nom_archi;
	if (punto<nom_archi.size()) {
		nom_archi_old.insert(punto, "_old");
	} else {
		nom_archi_old += "_old";
	}
	archi_old.close(); archi_new.close();
	rename(nom_archi.c_str(),nom_archi_old.c_str());
	rename(nom_archi_new.c_str(),nom_archi.c_str());
	remove(nom_archi_old.c_str());
}
void RenombrarYCrearCopiaProductos(std::string nom_archi){
	size_t punto = nom_archi.find('.'); std::string nom_archi_new=nom_archi;
	if (punto<nom_archi.size()) {
		nom_archi_new.insert(punto, "_new");
	} else {
		nom_archi_new += "_new";
	}
	std::ifstream archi_old(nom_archi,std::ios::binary);
	std::ofstream archi_new(nom_archi_new,std::ios::binary);
	Productos aux;
	while(archi_old.read(reinterpret_cast<char*>(&aux),sizeof(Productos))){
		if(aux.activo){archi_new.write(reinterpret_cast<char*>(&aux),sizeof(Productos));}
	}
	std::string nom_archi_old=nom_archi;
	if (punto<nom_archi.size()) {
		nom_archi_old.insert(punto, "_old");
	} else {
		nom_archi_old += "_old";
	}
	archi_old.close(); archi_new.close();
	rename(nom_archi.c_str(),nom_archi_old.c_str());
	rename(nom_archi_new.c_str(),nom_archi.c_str());
	remove(nom_archi_old.c_str());
}
void RenombrarYCrearCopiaInventario(std::string nom_archi){
	size_t punto = nom_archi.find('.'); std::string nom_archi_new=nom_archi;
	if (punto<nom_archi.size()) {
		nom_archi_new.insert(punto, "_new");
	} else {
		nom_archi_new += "_new";
	}
	std::ifstream archi_old(nom_archi,std::ios::binary);
	std::ofstream archi_new(nom_archi_new,std::ios::binary);
	Inventario aux;
	while(archi_old.read(reinterpret_cast<char*>(&aux),sizeof(Inventario))){
		if(aux.activo){archi_new.write(reinterpret_cast<char*>(&aux),sizeof(Inventario));}
	}
	std::string nom_archi_old=nom_archi;
	if (punto<nom_archi.size()) {
		nom_archi_old.insert(punto, "_old");
	} else {
		nom_archi_old += "_old";
	}
	archi_old.close(); archi_new.close();
	rename(nom_archi.c_str(),nom_archi_old.c_str());
	rename(nom_archi_new.c_str(),nom_archi.c_str());
	remove(nom_archi_old.c_str());
}

void GuardarLogs(std::string nom_archi,Logs log){
	std::fstream archi(nom_archi,std::ios::binary|std::ios::in|std::ios::out);
	
	if (!archi.is_open()) {
		archi.open(nom_archi,std::ios::binary|std::ios::out);
		archi.close();
		archi.open(nom_archi,std::ios::binary|std::ios::in|std::ios::out);
	}
	
	bool encontrado=false;
	LogsBin a;
	while(!encontrado && archi.read(reinterpret_cast<char*>(&a.log_bin),sizeof(a.log_bin))){
		std::string s=a.log_bin;
		std::string s1=verSeccion(s,1),s2=verSeccion(s,2),s3=verSeccion(s,5);
		if(std::atoi(s1.c_str())==log.verFecha() && std::atoi(s2.c_str())==log.verCodProd() && std::atoi(s3.c_str())==log.verCodCompra()){
			encontrado=true; int punt=archi.tellg();
			archi.seekp(punt-sizeof(a.log_bin));
			s=log.verLog();
			strcpy(a.log_bin,s.c_str());
			archi.write(reinterpret_cast<char*>(&a.log_bin),sizeof(a.log_bin));
			break;
		}
	}
	if(!encontrado){
		archi.close();
		archi.open(nom_archi,std::ios::binary|std::ios::out|std::ios::app);
		strcpy(a.log_bin,log.verLog().c_str());
		archi.write(reinterpret_cast<char*>(&a.log_bin),sizeof(a.log_bin));
	}
	archi.close();
}///inserta al final si no existe, si existe revisar por
void GuardarLogsClientes(std::string nom_archi,Logs log){
	std::fstream archi(nom_archi,std::ios::binary|std::ios::in|std::ios::out);
	
	if (!archi.is_open()) {
		archi.open(nom_archi,std::ios::binary|std::ios::out);
		archi.close();
		archi.open(nom_archi,std::ios::binary|std::ios::in|std::ios::out);
	}
	
	bool encontrado=false;
	LogsBin a;
	while(!encontrado && archi.read(reinterpret_cast<char*>(&a.log_clientes_bin),sizeof(a.log_clientes_bin))){
		std::string s=a.log_clientes_bin;
		std::string s1=verSeccion(s,1);
		if(std::atoi(s1.c_str())==log.verDni()){
			encontrado=true; int punt=archi.tellg();
			archi.seekp(punt-sizeof(a.log_clientes_bin));
			s1=verSeccion(s,3);
			log.modCantProd(std::atoi(s1.c_str())+log.verCantProd());
			s=log.verLogClientes();
			strcpy(a.log_clientes_bin,s.c_str());
			archi.write(reinterpret_cast<char*>(&a.log_clientes_bin),sizeof(a.log_clientes_bin));
			break;
		}
	}
	if(!encontrado){
		archi.close();
		archi.open(nom_archi,std::ios::binary|std::ios::out|std::ios::app);
		strcpy(a.log_clientes_bin,log.verLogClientes().c_str());
		archi.write(reinterpret_cast<char*>(&a.log_clientes_bin),sizeof(a.log_clientes_bin));
	}
	archi.close();
}///lo suma al que coincide o lo agrega si no existe
void GuardarLogsProd(std::string nom_archi,Logs log){
	std::fstream archi(nom_archi,std::ios::binary|std::ios::in|std::ios::out);
	
	if (!archi.is_open()) {
		archi.open(nom_archi,std::ios::binary|std::ios::out);
		archi.close();
		archi.open(nom_archi,std::ios::binary|std::ios::in|std::ios::out);
	}
	
	bool encontrado=false;
	LogsBin a;
	while(!encontrado && archi.read(reinterpret_cast<char*>(&a.log_prod_bin),sizeof(a.log_prod_bin))){
		std::string s=a.log_prod_bin;
		std::string s1=verSeccion(s,1);
		if(std::atoi(s1.c_str())==log.verCodProd()){
			encontrado=true; int punt=archi.tellg();
			archi.seekp(punt-sizeof(a.log_prod_bin));
			s1=verSeccion(s,2);
			log.modCantProd(std::atoi(s1.c_str())+log.verCantProd());
			s=log.verLogProd();
			strcpy(a.log_prod_bin,s.c_str());
			archi.write(reinterpret_cast<char*>(&a.log_prod_bin),sizeof(a.log_prod_bin));
			break;
		}
	}
	if(!encontrado){
		archi.close();
		archi.open(nom_archi,std::ios::binary|std::ios::out|std::ios::app);
		strcpy(a.log_prod_bin,log.verLogProd().c_str());
		archi.write(reinterpret_cast<char*>(&a.log_prod_bin),sizeof(a.log_prod_bin));
	}
	
}///lo suma al que coincide o lo agrega si no existe
std::string LeerLogs(std::string nom_archi,int pos){
	std::ifstream archi(nom_archi,std::ios::binary|std::ios::ate);
	std::string log; LogsBin a;
	int tamanio=archi.tellg()/sizeof(a.log_bin);
	if(pos>-1 && pos<tamanio){
		archi.seekg(0);
		archi.seekg(pos*sizeof(a.log_bin));
		archi.read(reinterpret_cast<char*>(&a.log_bin),sizeof(a.log_bin));
		log=a.log_bin;
	}else{log="X";}
	archi.close();
	return log;
}
std::string LeerLogsClientes(std::string nom_archi,int dni,int pos){
	std::ifstream archi(nom_archi,std::ios::binary|std::ios::ate);
	LogsBin a; int tamanio=archi.tellg()/sizeof(a.log_clientes_bin); archi.seekg(0);
	std::string log_clientes="X"; bool encontrado=false;
	if(dni!=-1 && pos==-1){
		while(!encontrado && archi.read(reinterpret_cast<char*>(&a.log_clientes_bin),sizeof(a.log_clientes_bin))){
			std::string s=a.log_clientes_bin,s1=verSeccion(s,1);
			if(std::atoi(s1.c_str())==dni){
				encontrado=true;
				log_clientes=a.log_clientes_bin;
			}
		}
	}
	if(pos!=-1 && dni==-1){
		if(pos>-1 && pos<tamanio){
			archi.seekg(0);
			archi.seekg(pos*sizeof(a.log_clientes_bin));
			archi.read(reinterpret_cast<char*>(&a.log_clientes_bin),sizeof(a.log_clientes_bin));
			log_clientes=a.log_clientes_bin;
		}else{return log_clientes;}
	}
	return log_clientes;
}
std::string LeerLogsProd(std::string nom_archi,int cod_prod,int pos){
	std::ifstream archi(nom_archi,std::ios::binary|std::ios::ate);
	LogsBin a; int tamanio=archi.tellg()/sizeof(a.log_prod_bin); archi.seekg(0);
	std::string log_prod="X"; bool encontrado=false;
	if (cod_prod!=-1 && pos==-1) {
		while(!encontrado && archi.read(reinterpret_cast<char*>(&a.log_prod_bin),sizeof(a.log_prod_bin))){
			std::string s=a.log_prod_bin,s1=verSeccion(s,1);
			if(std::atoi(s1.c_str())==cod_prod){
				encontrado=true;
				log_prod=a.log_prod_bin;
			}
		}
	}
	if (pos!=-1 && cod_prod==-1) {
		if(pos>-1 && pos<tamanio){
			archi.seekg(0);
			archi.seekg(pos*sizeof(a.log_prod_bin));
			archi.read(reinterpret_cast<char*>(&a.log_prod_bin),sizeof(a.log_prod_bin));
			
			log_prod=a.log_prod_bin;
		}else{return log_prod;}
	}
	return log_prod;
}	

void EliminarLog(std::string nom_archi,Logs log){
	std::fstream archi(nom_archi,std::ios::binary|std::ios::out|std::ios::in);
	LogsBin a; bool encontrado=false;
	while(!encontrado && archi.read(reinterpret_cast<char*>(&a.log_bin),sizeof(a.log_bin))){
		std::string s=a.log_bin;
		if(s==log.verLog()){
			encontrado=true; int punt=archi.tellg();
			archi.seekp(punt-sizeof(a.log_bin));
			std::string x="X_X_X_X_X_X"; strcpy(a.log_bin,x.c_str());
			archi.write(reinterpret_cast<char*>(&a.log_bin),sizeof(a.log_bin));
		}
	}
	archi.close();
}///inserta una X en el lugar del log
void EliminarLogCliente(std::string nom_archi,int dni,int num){
	std::fstream archi(nom_archi,std::ios::binary|std::ios::out|std::ios::in);
	LogsBin a; bool encontrado=false;
	while(!encontrado && archi.read(reinterpret_cast<char*>(&a.log_clientes_bin),sizeof(a.log_clientes_bin))){
		std::string s=a.log_clientes_bin,s1=verSeccion(s,1);
		if(std::atoi(s1.c_str())==dni){
			encontrado=true; int punt=archi.tellg();
			archi.seekp(punt-sizeof(a.log_clientes_bin));
			int numFinal=(std::atoi(verSeccion(s,3).c_str())-num);
			modSeccion(s,3,std::to_string(numFinal));
			strcpy(a.log_clientes_bin,s.c_str());
			archi.write(reinterpret_cast<char*>(&a.log_clientes_bin),sizeof(a.log_clientes_bin));
		}
		
	}
	archi.close();
}///le resta el numero que indique al dni 
void EliminarLogProd(std::string nom_archi,int cod_prod,int num){
	std::fstream archi(nom_archi,std::ios::binary|std::ios::out|std::ios::in);
	LogsBin a; bool encontrado=false;
	while(!encontrado && archi.read(reinterpret_cast<char*>(&a.log_prod_bin),sizeof(a.log_prod_bin))){
		std::string s=a.log_prod_bin,s1=verSeccion(s,1);
		if(std::atoi(s1.c_str())==cod_prod){
			encontrado=true; int punt=archi.tellg();
			archi.seekp(punt-sizeof(a.log_prod_bin));
			int numFinal=(std::atoi(verSeccion(s,2).c_str())-num);
			modSeccion(s,2,std::to_string(numFinal));
			strcpy(a.log_prod_bin,s.c_str());
			archi.write(reinterpret_cast<char*>(&a.log_prod_bin),sizeof(a.log_prod_bin));
		}
		
	}
	archi.close();
}///le resta el numero que indique al cod

int CuantosVendio(int cod_prod,int dni,std::string nom_archi,int fechaIni,int fechaFin,int deci){///deci=1(busca por cod_prod)deci=2(busca por dni)deci=3(busca por ambos)
	std::ifstream archi;
	int mesIni=(fechaIni/10)-(fechaIni/10000);
	int mesFin=(fechaFin/10)-(fechaFin/10000);
	int acumulador=0;
	for(int i=mesIni;i<mesFin+1;i++) { 
		size_t posUltimoGuion=nom_archi.find_last_of("_");
		nom_archi.insert(posUltimoGuion+1,std::to_string(mesIni+i));
		archi.open(nom_archi,std::ios::binary); LogsBin a;
		while(archi.read(reinterpret_cast<char*>(&a.log_bin),sizeof(a.log_bin))){
			std::string s=a.log_bin, s1=verSeccion(s,2), s2=verSeccion(s,1), s3=verSeccion(s,3), s4=verSeccion(s,6);
			switch(deci){
			case 1:
				if(std::atoi(s2.c_str())>=fechaIni && std::atoi(s2.c_str())<=fechaFin && std::atoi(s1.c_str())==cod_prod){
					acumulador+=std::atoi(s3.c_str());
				}
				break;
			case 2:
				if(std::atoi(s2.c_str())>=fechaIni && std::atoi(s2.c_str())<=fechaFin && std::atoi(s4.c_str())==dni){
					acumulador+=std::atoi(s3.c_str());
				}
				break;
			case 3:
				if(std::atoi(s2.c_str())>=fechaIni && std::atoi(s2.c_str())<=fechaFin && std::atoi(s1.c_str())==cod_prod && std::atoi(s4.c_str())==dni){
					acumulador+=std::atoi(s3.c_str());
				}
				break;
			}
		}
		archi.close();
	}
	return acumulador;
}///trabaja con el general 

bool MayorLogClientes(std::string s1,std::string s2) {
	int i1 = std::atoi(verSeccion(s1, 3).c_str());
	int i2 = std::atoi(verSeccion(s2, 3).c_str());
	
	return i1 > i2;
}	

bool MayorLogProd(std::string s1,std::string s2) {
	int i1 = std::atoi(verSeccion(s1, 2).c_str());
	int i2 = std::atoi(verSeccion(s2, 2).c_str());
	
	return i1 > i2;
}

void OrdenarLogClientes(std::string nom_archi){
	std::ifstream archi_in(nom_archi,std::ios::binary);
	LogsBin a; std::vector<std::string> memoria;
	while(archi_in.read(reinterpret_cast<char*>(&a.log_clientes_bin),sizeof(a.log_clientes_bin))){
		memoria.push_back(a.log_clientes_bin);
	}
	archi_in.close();
	sort(memoria.begin(),memoria.end(),MayorLogClientes);
	std::ofstream archi_out(nom_archi,std::ios::binary|std::ios::trunc);
	for(size_t i=0;i<memoria.size();i++) { 
		std::string aux=memoria[i];
		strcpy(a.log_clientes_bin,aux.c_str());
		archi_out.write(reinterpret_cast<char*>(&a.log_clientes_bin),sizeof(a.log_clientes_bin));
	}
	archi_out.close();
}
void OrdenarLogProd(std::string nom_archi){
	std::ifstream archi_in(nom_archi,std::ios::binary);
	LogsBin a; std::vector<std::string> memoria;
	while(archi_in.read(reinterpret_cast<char*>(&a.log_prod_bin),sizeof(a.log_prod_bin))){
		memoria.push_back(a.log_prod_bin);
	}
	archi_in.close();
	sort(memoria.begin(),memoria.end(),MayorLogProd);
	std::ofstream archi_out(nom_archi,std::ios::binary|std::ios::trunc);
	for(size_t i=0;i<memoria.size();i++) { 
		std::string aux=memoria[i];
		strcpy(a.log_prod_bin,aux.c_str());
		archi_out.write(reinterpret_cast<char*>(&a.log_prod_bin),sizeof(a.log_prod_bin));
	}
	archi_out.close();
}

void RenombrarYCrearCopiaLogs(std::string nom_archi){
	size_t punto = nom_archi.find('.'); std::string nom_archi_new=nom_archi;
	if (punto<nom_archi.size()) {
		nom_archi_new.insert(punto, "_new");
	} else {
		nom_archi_new += "_new";
	}
	std::ifstream archi_old(nom_archi,std::ios::binary);
	std::ofstream archi_new(nom_archi_new,std::ios::binary);
	LogsBin aux;
	while(archi_old.read(reinterpret_cast<char*>(&aux.log_bin),sizeof(aux.log_bin))){
		std::string s=aux.log_bin;
		if(s!="X_X_X_X_X_X"){archi_new.write(reinterpret_cast<char*>(&aux.log_bin),sizeof(aux.log_bin));}
	}
	std::string nom_archi_old=nom_archi;
	if (punto<nom_archi.size()) {
		nom_archi_old.insert(punto, "_old");
	} else {
		nom_archi_old += "_old";
	}
	archi_old.close(); archi_new.close();
	rename(nom_archi.c_str(),nom_archi_old.c_str());
	rename(nom_archi_new.c_str(),nom_archi.c_str());
	remove(nom_archi_old.c_str());
}
