#include "HijaPasivos.h"
#include "Funciones.h"
#include "Utilidades.h"
#include <wx/msgdlg.h>
#include <string>
#include <wx/textdlg.h>
using namespace std;

HijaPasivos::HijaPasivos(wxWindow *parent) : BasePasivos(parent) {
	int anio=obtenerFechaDeHoy()/10000;
	std::vector<std::string> titulos=ConversionYLecturaMem_NomArchivos("data\\titles_source\\"+std::to_string(anio)+"_Pasivos.txt");
	if(titulos.empty()){
		int ref=((obtenerFechaDeHoy()/10000)*100)+1;
		for(int i=0;i<12;i++) { 
			titulos.push_back("Pasivos_"+std::to_string(ref)+".dat"); ref++;
			Pasivos a;
			ConversionYGuardadoBin_Pasivos(a,"data\\Pasivos_data\\"+titulos[i]);
		}
		ref=ref/100;
		ConversionYGuardadoTxt_NomArchivos(titulos,"data\\titles_source\\"+std::to_string(ref)+"_Pasivos.txt",false);
		m_data=new Pasivos;
		m_data->modDeudaProveedor(0);
		m_data->modImpuestosVarios(0);
		m_data->modSalarios(0);
		m_data->modServiciosAPagar(0);
		ActGrilla_Pasivos();
		GuardarDatos_Pasivos();
	}
	for(size_t i=0;i<titulos.size();i++) {
		wxString s=titulos[i];
		m_GrillaListaPasivos->SetCellValue(i,0,s);
	}
	int mes=(obtenerFechaDeHoy()/100)-(anio*100);
	m_archi_act=titulos[mes-1];
	m_GrillaListaPasivos->SetGridCursor(mes-1,0);
	m_data=new Pasivos (ConversionYLecturaMem_Pasivos("data\\Pasivos_data\\"+m_archi_act));
	for(size_t i=mes-1;i<titulos.size();i++) { 
		Pasivos pas=ConversionYLecturaMem_Pasivos("data\\Pasivos_data\\"+titulos[i]);
		pas=*m_data;
		ConversionYGuardadoBin_Pasivos(pas,"data\\Pasivos_data\\"+titulos[i]);
	}
	m_data_activos=new Activos(ConversionYLecturaMem_Activos("data\\Activos_data\\Activos"+m_archi_act.substr(m_archi_act.find("_"))));
	ActGrilla_Pasivos();
}

HijaPasivos::~HijaPasivos() {
	
}

void HijaPasivos::ClickAceptarPasivos( wxCommandEvent& event )  {
	GuardarDatos_Pasivos();
	Close();
}

void HijaPasivos::ClickCancelarPasivos( wxCommandEvent& event )  {
	Close();
}

void HijaPasivos::DobleClickPasivos( wxGridEvent& event )  {
	if(m_modificaciones_temp_pasivos){int deci=wxMessageBox("Esta a punto de cargar otro archivo sin guardar el vigente, quiere guardar antes de continuar?","Advertencia",wxYES_NO);
	if(deci==wxYES){GuardarDatos_Pasivos();}else{m_modificaciones_temp_pasivos=false;}
	}
	int f=m_GrillaListaPasivos->GetGridCursorRow();
	m_archi_act=wx_to_std(m_GrillaListaPasivos->GetCellValue(f,0));
	delete m_data; m_data=nullptr;
	m_data=new Pasivos(ConversionYLecturaMem_Pasivos("data\\Pasivos_data\\"+m_archi_act));
	delete m_data_activos; m_data_activos=nullptr;
	m_data_activos = new Activos(ConversionYLecturaMem_Activos("data\\Activos_data\\Activos"+m_archi_act.substr(m_archi_act.find("_"))));
	ActGrilla_Pasivos();
}

void HijaPasivos::ClickMostrarBalance( wxCommandEvent& event )  {
	double acumuladorP=(m_data->verDeudaProveedor()+m_data->verImpuestosVarios()+m_data->verSalarios()+m_data->verServiciosAPagar());
	double acumuladorA=(m_data_activos->verDineroBanco()+m_data_activos->verDineroCaja());
	double acumuladorF=(acumuladorA-acumuladorP);
	std::string s="Su Balance es de: $"+wx_to_std(wxString::Format("%.2f",acumuladorF));
	wxMessageBox(s,"Balance",wxOK);
}

void HijaPasivos::ClickLiquidarTodo( wxCommandEvent& event )  {
	int deci=wxMessageBox("Quiere usar el dinero en cuanta bancaria para liquidar esta deuda?, de no ser así se usará el dinero en caja.","Advertencia",wxYES_NO|wxCANCEL);
	
	if (deci!=wxID_CANCEL) {
		double AcuPasivos=(m_data->verDeudaProveedor()+m_data->verImpuestosVarios()+m_data->verSalarios()+m_data->verServiciosAPagar());
		if(deci==wxYES && AcuPasivos<m_data_activos->verDineroBanco()){
			m_data_activos->modDineroBanco(m_data_activos->verDineroBanco()-AcuPasivos);
			m_data->modDeudaProveedor(0); m_data->modImpuestosVarios(0); m_data->modSalarios(0); m_data->modServiciosAPagar(0);
			wxMessageBox("Resultado luego de la liquidación: $"+wx_to_std(wxString::Format("%.2f",m_data_activos->verDineroBanco()))+" En cuenta bancaria.","Resultado",wxOK);
			ActGrilla_Pasivos();
		}else{if(deci==wxYES){wxMessageBox("La operación se cancelo ya que no cuenta con suficiente dinero en su cuenta bancaria.","Error",wxOK);}}
		if(deci==wxNO && AcuPasivos<m_data_activos->verDineroCaja()){
			m_data_activos->modDineroCaja(m_data_activos->verDineroCaja()-AcuPasivos);
			m_data->modDeudaProveedor(0); m_data->modImpuestosVarios(0); m_data->modSalarios(0); m_data->modServiciosAPagar(0);
			wxMessageBox("Resultado luego de la liquidación: $"+wx_to_std(wxString::Format("%.2f",m_data_activos->verDineroCaja()))+" En caja.","Resultado",wxOK);
			ActGrilla_Pasivos();
		}else{if(deci==wxNO){wxMessageBox("La operación se cancelo ya que no cuenta con suficiente dinero en efectivo.","Error",wxOK);}}
	}
	
}

void HijaPasivos::ClickLiquidarCasilla( wxCommandEvent& event )  {
	int num=m_GrillaPasivos->GetGridCursorCol();
	double casilla=FiltrarYConvertir(m_GrillaPasivos->GetCellValue(0,num));
	int deci=wxMessageBox("Quiere usar el dinero en cuanta bancaria para liquidar esta deuda?, de no ser así se usará el dinero en caja","Advertencia",wxYES_NO|wxCANCEL);
	if (deci!=wxID_CANCEL) {
		if(deci==wxYES && casilla<m_data_activos->verDineroBanco()){
			m_data_activos->modDineroBanco(m_data_activos->verDineroBanco()-casilla);
			switch(num){
			case 0:m_data->modDeudaProveedor(0.00);
				break;
			case 1:m_data->modImpuestosVarios(0.00);
				break;
			case 2:m_data->modSalarios(0.00);
				break;
			case 3:m_data->modServiciosAPagar(0.00);
				break;
			}
			ActGrilla_Pasivos();
			wxMessageBox("Resultado luego de la liquidación: $"+wx_to_std(wxString::Format("%.2f",m_data_activos->verDineroBanco()))+" En cuenta bancaria.","Resultado",wxOK);
		}else{if(deci==wxYES){wxMessageBox("La operación se cancelo ya que no cuenta con suficiente dinero en su cuenta bancaria.","Error",wxOK);}}
		if(deci==wxNO && casilla<m_data_activos->verDineroCaja()){
			m_data_activos->modDineroCaja(m_data_activos->verDineroCaja()-casilla);
			switch(num){
			case 0:m_data->modDeudaProveedor(0.00);
				break;
			case 1:m_data->modImpuestosVarios(0.00);
				break;
			case 2:m_data->modSalarios(0.00);
				break;
			case 3:m_data->modServiciosAPagar(0.00);
				break;
			}
			ActGrilla_Pasivos();
			wxMessageBox("Resultado luego de la liquidación: $"+wx_to_std(wxString::Format("%.2f",m_data_activos->verDineroCaja()))+" En caja.","Resultado",wxOK);
		}else{if(deci==wxNO){wxMessageBox("La operación se cancelo ya que no cuenta con suficiente dinero en efectivo.","Error",wxOK);}}
	}
}

void HijaPasivos::ClickGuardarPasivos( wxCommandEvent& event )  {
	GuardarDatos_Pasivos();
}

void HijaPasivos::ClickCargarPasivos( wxCommandEvent& event )  {
	if(m_modificaciones_temp_pasivos){int deci=wxMessageBox("Esta a punto de cargar otro archivo sin guardar el vigente, quiere guardar antes de continuar?","Advertencia",wxYES_NO);
	if(deci==wxYES){GuardarDatos_Pasivos();}else{m_modificaciones_temp_pasivos=false;}
	}
	int f=m_GrillaListaPasivos->GetGridCursorRow();
	m_archi_act=wx_to_std(m_GrillaListaPasivos->GetCellValue(f,0));
	delete m_data; m_data=nullptr;
	m_data=new Pasivos(ConversionYLecturaMem_Pasivos("data\\Pasivos_data\\"+m_archi_act));
	delete m_data_activos; m_data_activos=nullptr;
	m_data_activos = new Activos(ConversionYLecturaMem_Activos("data\\Activos_data\\Activos"+m_archi_act.substr(m_archi_act.find("_"))));
	ActGrilla_Pasivos();
}
void HijaPasivos::ActGrilla_Pasivos(){
	m_GrillaPasivos->SetCellValue(0,0,"$"+wx_to_std(wxString::Format("%.2f",m_data->verDeudaProveedor())));
	m_GrillaPasivos->SetCellValue(0,1,"$"+wx_to_std(wxString::Format("%.2f",m_data->verImpuestosVarios())));
	m_GrillaPasivos->SetCellValue(0,2,"$"+wx_to_std(wxString::Format("%.2f",m_data->verSalarios())));
	m_GrillaPasivos->SetCellValue(0,3,"$"+wx_to_std(wxString::Format("%.2f",m_data->verServiciosAPagar())));
}
void HijaPasivos::GuardarDatos_Pasivos(){
	m_modificaciones_temp_pasivos=false;
	float deuda=FiltrarYConvertir(m_GrillaPasivos->GetCellValue(0,0));
	float impuestos=FiltrarYConvertir(m_GrillaPasivos->GetCellValue(0,1));
	float salarios=FiltrarYConvertir(m_GrillaPasivos->GetCellValue(0,2));
	float servicios=FiltrarYConvertir(m_GrillaPasivos->GetCellValue(0,3));
	m_data->modDeudaProveedor(deuda);
	m_data->modImpuestosVarios(impuestos);
	m_data->modSalarios(salarios);
	m_data->modServiciosAPagar(servicios);
	
	ConversionYGuardadoBin_Pasivos(*m_data,"data\\Pasivos_data\\"+m_archi_act);
	if(m_data_activos!=nullptr){ConversionYGuardadoBin_Activos(*m_data_activos,"data\\Activos_data\\Activos"+m_archi_act.substr(m_archi_act.find("_")));}
}



void HijaPasivos::ClickAgregarACasilla( wxCommandEvent& event )  {
	int col=m_GrillaPasivos->GetGridCursorCol();
	double agregar=FiltrarYConvertir(m_textAgregar->GetValue());
	switch(col){
	case 0:m_data->modDeudaProveedor(m_data->verDeudaProveedor()+agregar);
		break;
	case 1:m_data->modImpuestosVarios(m_data->verImpuestosVarios()+agregar);
		break;
	case 2:m_data->modSalarios(m_data->verSalarios()+agregar);
		break;
	case 3:m_data->modServiciosAPagar(m_data->verServiciosAPagar()+agregar);
		break;
	}
	ActGrilla_Pasivos();
	m_textAgregar->Clear();
}

