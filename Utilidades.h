#ifndef UTILIDADES_H
#define UTILIDADES_H
#include "Personas.h"
#include "Empleado.h"
#include "Clientes.h"
#include "Activos.h"
#include "Pasivos.h"
#include "Logs.h"
#include <iostream>
#include <vector>
#include <string>

void ConversionYGuardadoBin_Clientes(Clientes &a,std::string nom_archi, int pos);///Guardar en binario un cliente
void ConversionYGuardadoBin_Empleados(Empleado &a,std::string nom_archi, int pos);///Guardar en binario un empleado

void ConversionYGuardadoTxt_NomArchivos(const std::vector<std::string> &a,std::string nom_archi,bool escribir_al_final);///Guarda en txt los titulos de archivos binarios

Clientes ConversionYLecturaMem_Clientes(std::string nom_archi,int pos);///Lee desde el binario y retorna un cliente 
Empleado ConversionYLecturaMem_Empleados(std::string nom_archi,int pos);///Lee desde el binario y retorna un empleado

std::vector<std::string> ConversionYLecturaMem_NomArchivos(std::string nom_archivo);///Lee en memoria los titulos del txt

void EliminarClienteBin(int cod_compra,std::string nom_archi);///Elimina un cliente del binario con un switch off 
void EliminarEmpleadoBin(int dni, std::string nom_archi);///Elimina un empleado del binario con un switch off

void EliminarNomArchivo(std::string nom_archi);///Elimina un titulo cargandolo en memoria y escribiendolo de nuevo en el archivo (Base de datos muy pequeña)

bool ComparaInventario(Inventario a,Inventario b);///Funcion que compara el inventario para un sort (Innesesaria?,no se carga mas el inventario en memoria como antes)

void ConversionYGuardadoBin_Activos(Activos &a,std::string nomb_archi);///Guardar en binario una ficha activos
void ConversionYGuardadoBin_Pasivos(Pasivos &a,std::string nomb_archi);///Guardar en binario una ficha pasivos

Activos ConversionYLecturaMem_Activos(std::string nom_archi);///Lee desde el binario y retorna una ficha activos
Pasivos ConversionYLecturaMem_Pasivos(std::string nom_archi);///Lee desde el binario y retorna una ficha pasivos

bool operator==(const Inventario& inv1, const Inventario& inv2);

void combinarInventarios(std::vector<Inventario>& inventarios);///funcion que que usa un sort y la funcion ComparaInventario (No utilizada, pero con miedo de sacarla)

void GuardarProductos(Clientes &a, const std::vector<Productos> &prod ,std::string nom_archi, bool YaExiste);///Guardar en binario una cantidad de Productos de un cliente
void GuardarInventario(Inventario &a, std::string nom_archi, int pos, int cod_prod);///Guardar en binario una cantidad determinadad de inventario del activo

std::vector<Productos> LeerProductos(Clientes &a, std::string nom_archi);///Lee los productos del binario en un vector
Inventario LeerInventario(std::string nom_archi, int pos=-1, int cod_prod=-1);///Lee inventario individualmente debido al tamaño que puede tomar el binario

void EliminarProductos(int id_compra,std::string nom_archi);///Elimina todos los productos que haya comprado un cliente
void EliminarProducto(Clientes &a,int cod_prod,std::string nom_archi);///Elimina un producto determinado usando su codigo
void EliminarInventario(int cod_prod,std::string nom_archi);///Elimina un elemento del inventario por su codigo

void RenombrarYCrearCopiaClientes(std::string nom_archi);///Crea copia solo con los switch on y elimina el archivo viejo
void RenombrarYCrearCopiaEmpleado(std::string nom_archi);///Crea copia solo con los switch on y elimina el archivo viejo
void RenombrarYCrearCopiaProductos(std::string nom_archi);///Crea copia solo con los switch on y elimina el archivo viejo
void RenombrarYCrearCopiaInventario(std::string nom_archi);///Crea copia solo con los switch on y elimina el archivo viejo

void GuardarLogs(std::string nom_archi,Logs logs);///inserta al final si no existe, si existe revisar por///Probada
void GuardarLogsClientes(std::string nom_archi,Logs logs);///lo suma al que coincide o lo agrega si no existe///Probada
void GuardarLogsProd(std::string nom_archi,Logs logs);///lo suma al que coincide o lo agrega si no existe///Probada

std::string LeerLogs(std::string nom_archi,int pos);///Probada
std::string LeerLogsClientes(std::string nom_archi,int dni,int pos);///Probada
std::string LeerLogsProd(std::string nom_archi,int cod_prod,int pos);///Probada

void EliminarLog(std::string nom_archi,Logs log);///inserta una X en el lugar del log///Probada
void EliminarLogCliente(std::string nom_archi,int dni,int num);///le resta el numero que indique al dni///Probada
void EliminarLogProd(std::string nom_archi,int cod_prod,int num);///le resta el numero que indique al cod///Probada

int CuantosVendio(int cod_prod,int dni,std::string nom_archi,int fechaIni,int fechaFin,int deci);///trabaja con el general///deci=1(busca por cod_prod)deci=2(busca por dni)deci=3(busca por ambos) 

bool MayorLogClientes(std::string s1,std::string s2);///Probada
bool MayorLogProd(std::string s1,std::string s2);///Probada

void OrdenarLogClientes(std::string nom_archi);///Ordena bases de datos pequeñas(clientes anuales y mensuales)///Probada
void OrdenarLogProd(std::string nom_archi);///Ordena bases de datos pequeñas(productos vendidos anuales y mensuales)///Probada

void RenombrarYCrearCopiaLogs(std::string nom_archi);///Crea copia solo con los que son diferentes a X_X_X_X_X_X y elimina el archivo viejo
#endif
