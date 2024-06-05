#include "HijaActivos.h"
#include <vector>
#include <string>
#include "Utilidades.h"
#include <wx/string.h>
#include <wx/msgdlg.h>
#include "Funciones.h"
#include <wx/textdlg.h>

HijaActivos::HijaActivos(wxWindow *parent) : BaseActivos(parent) {
	int anio=obtenerFechaDeHoy()/10000;
	std::vector<std::string> titulos=ConversionYLecturaMem_NomArchivos("data\\titles_source\\"+std::to_string(anio)+"_Activos.txt");
	int mes=(obtenerFechaDeHoy()/100)-(anio*100);
	int dia=(obtenerFechaDeHoy()-anio*10000)-mes*100;
	if(titulos.empty()){
		int ref=((obtenerFechaDeHoy()/10000)*100)+1;
		for(int i=0;i<12;i++) { 
			titulos.push_back("Activos_"+std::to_string(ref)+".dat"); ref++;
			Activos a;
			ConversionYGuardadoBin_Activos(a,"data\\Activos_data\\"+titulos[i]);
		}
		ref=ref/100;
		ConversionYGuardadoTxt_NomArchivos(titulos,"data\\titles_source\\"+std::to_string(ref)+"_Activos.txt",false);
		m_data=new Activos;
		m_data->modDineroBanco(0);
		m_data->modDineroCaja(0);
		m_data->modDineroCredito(0);
		ActGrillas_Activos();
		GuardarDatos_Activos();
	}
	for(size_t i=0;i<titulos.size();i++) {
		wxString s=titulos[i];
		m_GrillaListaActivos->SetCellValue(i,0,s);
	}
	m_archi_act=titulos[mes-1];
	m_data=new Activos(ConversionYLecturaMem_Activos("data\\Activos_data\\"+m_archi_act));
	ConversionYGuardadoBin_Activos(*m_data,"data\\Activos_data\\"+m_archi_act);
	if(dia==20){
		m_data->modDineroBanco(m_data->verDineroBanco()+m_data->verDineroCredito());
		m_data->modDineroCredito(0);
	}
	for(size_t i=mes-1;i<titulos.size();i++) { 
		Activos act=ConversionYLecturaMem_Activos("data\\Activos_data\\"+titulos[i]);
		act=*m_data; 
		ConversionYGuardadoBin_Activos(act,"data\\Activos_data\\"+titulos[i]);
	}
	m_GrillaListaActivos->SetGridCursor(mes-1,0);
	ActGrillas_Activos();
	if(m_GrillaActivos->GetNumberRows()!=0){m_GrillaActivos->DeleteRows(0,m_GrillaActivos->GetNumberRows());}
	Inventario inv=LeerInventario("data\\Activos_data\\inv_Activos.dat",0,-1); int i=0;
	while(inv.precio!=-1) {
		m_GrillaActivos->AppendRows(1);
		m_GrillaActivos->SetCellValue(i, 0, "#"+std::to_string(inv.cod_prod));
		m_GrillaActivos->SetCellValue(i, 1, std::to_string(inv.stock_disponible));
		m_GrillaActivos->SetCellValue(i, 2, inv.detalle);
		m_GrillaActivos->SetCellValue(i, 3, inv.rubro);
		m_GrillaActivos->SetCellValue(i, 4, "$"+std::to_string(inv.precio));
		
		i++;
		inv=LeerInventario("data\\Activos_data\\inv_Activos.dat",i,-1);
	}
	
}

HijaActivos::~HijaActivos() {
	if(m_modificado){RenombrarYCrearCopiaInventario("data\\Activos_data\\inv_Activos.dat");}
}

void HijaActivos::ClickCancelarActivos( wxCommandEvent& event )  {
	Close();
}

void HijaActivos::ClickAceptarActivos( wxCommandEvent& event )  {
	GuardarDatos_Activos();
	Close();
}

void HijaActivos::ClickCargarArchivoActivos( wxCommandEvent& event )  {
	GuardarDatos_Activos();
	int f=m_GrillaListaActivos->GetGridCursorRow();
	m_archi_act=wx_to_std(m_GrillaListaActivos->GetCellValue(f,0));
	delete m_data; m_data=nullptr;
	m_data=new Activos(ConversionYLecturaMem_Activos("data\\Activos_data\\"+m_archi_act));
	ActGrillas_Activos();
}

void HijaActivos::ClickGuardarActivos( wxCommandEvent& event )  {
	GuardarDatos_Activos();
}

void HijaActivos::ClickAgregarProducto( wxCommandEvent& event )  {
	Inventario inv; int num=m_GrillaActivos->GetNumberRows();
	if (num>0) {
		inv.cod_prod=FiltrarYConvertir(m_GrillaActivos->GetCellValue(num-1,0))+1;
		m_GrillaActivos->AppendRows(1);
		m_GrillaActivos->SetCellValue(m_GrillaActivos->GetNumberRows()-1, 0, "#"+std::to_string(inv.cod_prod));
		m_GrillaActivos->SetCellValue(m_GrillaActivos->GetNumberRows()-1, 1, std::to_string(inv.stock_disponible));
		m_GrillaActivos->SetCellValue(m_GrillaActivos->GetNumberRows()-1, 2, inv.detalle);
		m_GrillaActivos->SetCellValue(m_GrillaActivos->GetNumberRows()-1, 3, inv.rubro);
		m_GrillaActivos->SetCellValue(m_GrillaActivos->GetNumberRows()-1, 4, "$"+std::to_string(inv.precio));
	}else{
		inv.cod_prod=1;
		m_GrillaActivos->AppendRows(1);
		m_GrillaActivos->SetCellValue(m_GrillaActivos->GetNumberRows()-1, 0, "#"+std::to_string(inv.cod_prod));
		m_GrillaActivos->SetCellValue(m_GrillaActivos->GetNumberRows()-1, 1, std::to_string(inv.stock_disponible));
		m_GrillaActivos->SetCellValue(m_GrillaActivos->GetNumberRows()-1, 2, inv.detalle);
		m_GrillaActivos->SetCellValue(m_GrillaActivos->GetNumberRows()-1, 3, inv.rubro);
		m_GrillaActivos->SetCellValue(m_GrillaActivos->GetNumberRows()-1, 4, "$"+std::to_string(inv.precio));
	}
	GuardarDatos_Activos();
}

void HijaActivos::ClickEliminarProducto( wxCommandEvent& event )  {
	if (m_GrillaActivos->GetNumberRows()!=0) {
		int f=m_GrillaActivos->GetGridCursorRow();
		int cod=FiltrarYConvertir(m_GrillaActivos->GetCellValue(f,0));
		EliminarInventario(cod,"data\\Activos_data\\inv_Activos.dat");
		m_modificado=true;
		m_GrillaActivos->DeleteRows(f,1);
	}
}

void HijaActivos::ClickDepositar( wxCommandEvent& event )  {
	double d = std::atof(m_textDeposito->GetValue().c_str());
	m_data->modDineroBanco(m_data->verDineroBanco()+d);
	m_data->modDineroCaja(m_data->verDineroCaja()-d);
	ActGrillas_Activos();
	GuardarDatos_Activos();
	m_textDeposito->Clear();
}

void HijaActivos::ClickRetiro( wxCommandEvent& event )  {
	double r = std::atof(m_textRetiro->GetValue().c_str());
	m_data->modDineroCaja(m_data->verDineroCaja()+r);
	m_data->modDineroBanco(m_data->verDineroBanco()-r);
	ActGrillas_Activos();
	GuardarDatos_Activos();
	m_textRetiro->Clear();
}

void HijaActivos::ActGrillas_Activos() {
	m_GrillaActivosDinero->SetCellValue(0, 0, "$"+wx_to_std(wxString::Format("%.2f", m_data->verDineroCaja())));
	m_GrillaActivosDinero->SetCellValue(0, 1, "$"+wx_to_std(wxString::Format("%.2f", m_data->verDineroBanco())));
	m_GrillaActivosDinero->SetCellValue(0, 2, "$"+wx_to_std(wxString::Format("%.2f", m_data->verDineroCredito())));
}


void HijaActivos::GuardarDatos_Activos() {
	int f = m_GrillaActivos->GetNumberRows();
	for(int i = 0; i < f; i++) {
		Inventario b;
		b.cod_prod=FiltrarYConvertir(m_GrillaActivos->GetCellValue(i,0)); 
		b.stock_disponible=FiltrarYConvertir(m_GrillaActivos->GetCellValue(i,1));
		strcpy(b.detalle,m_GrillaActivos->GetCellValue(i,2).c_str());
		strcpy(b.rubro,m_GrillaActivos->GetCellValue(i,3).c_str());
		b.precio=FiltrarYConvertir(m_GrillaActivos->GetCellValue(i,4));
		GuardarInventario(b,"data\\Activos_data\\inv_Activos.dat",i,-1);
	}
	
	int dineroCaja = FiltrarYConvertir(m_GrillaActivosDinero->GetCellValue(0, 0));
	int dineroBanco = FiltrarYConvertir(m_GrillaActivosDinero->GetCellValue(0, 1));
	int dineroCredito = FiltrarYConvertir(m_GrillaActivosDinero->GetCellValue(0, 2));
	
	m_data->modDineroCaja(dineroCaja);
	m_data->modDineroBanco(dineroBanco);
	m_data->modDineroCredito(dineroCredito);
	
	ConversionYGuardadoBin_Activos(*m_data,"data\\Activos_data\\"+m_archi_act);
}

void HijaActivos::DobleClickActivos( wxGridEvent& event )  {
	GuardarDatos_Activos();
	int f=m_GrillaListaActivos->GetGridCursorRow();
	m_archi_act=wx_to_std(m_GrillaListaActivos->GetCellValue(f,0));
	delete m_data; m_data=nullptr;
	m_data=new Activos(ConversionYLecturaMem_Activos("data\\Activos_data\\"+m_archi_act));
	ActGrillas_Activos();
}

void HijaActivos::ClickDescontarDinero( wxCommandEvent& event )  {
	double r = std::atof(m_textDescontarCasilla->GetValue().c_str());
	int casilla = m_GrillaActivosDinero->GetGridCursorCol();
	if(casilla==0){if(m_data->verDineroCaja()>0){m_data->modDineroCaja(m_data->verDineroCaja()-r);}else{wxMessageBox("La casilla seleccionada no es apta para un descuento de dinero. Motivo : Dinero insuficiente","Error",wxOK);}}
	if(casilla==1){if(m_data->verDineroBanco()>0){m_data->modDineroBanco(m_data->verDineroBanco()-r);}else{wxMessageBox("La casilla seleccionada no es apta para un descuento de dinero. Motivo : Dinero insuficiente","Error",wxOK);}}
	if(casilla==2){wxMessageBox("La casilla seleccionada no es apta para un descuento de dinero.","Error",wxOK);}
	ActGrillas_Activos();
	GuardarDatos_Activos();
	m_textDescontarCasilla->Clear();
}

