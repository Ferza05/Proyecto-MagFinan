#include "HijaEmpleado.h"
#include "Funciones.h"
#include "Utilidades.h"
#include "HijaNuevoEmpleado.h"

HijaEmpleado::HijaEmpleado(wxWindow *parent) : BaseEmpleado(parent) {
	int anio=obtenerFechaDeHoy()/10000;
	std::vector<std::string> titulos=ConversionYLecturaMem_NomArchivos("data\\titles_source\\"+std::to_string(anio)+"_Empleados.txt");
	if(titulos.empty()){
		int ref=((obtenerFechaDeHoy()/10000)*100)+1;
		for(int i=0;i<12;i++) { 
			titulos.push_back("Empleados_"+std::to_string(ref)+".dat"); ref++;
		}
		ref=ref/100;
		ConversionYGuardadoTxt_NomArchivos(titulos,"data\\titles_source\\"+std::to_string(ref)+"_Empleados.txt",false);
	}
	int mes=(obtenerFechaDeHoy()/100)-(anio*100);
	m_archi_act=titulos[mes-1];
	m_data_pasivos= new Pasivos (ConversionYLecturaMem_Pasivos("data\\Pasivos_data\\Pasivos"+m_archi_act.substr(m_archi_act.find("_"))));
	Empleado a=ConversionYLecturaMem_Empleados("data\\Empleados_data\\"+m_archi_act,0); int j=0;
	while(a.verDNI()!=-1) { 
		m_GrillaListaEmpleados->AppendRows(1);
		wxString s=std::to_string(a.verDNI())+"_"+std::to_string(j+1);
		m_GrillaListaEmpleados->SetCellValue(j,0,s);
		j++;
		a=ConversionYLecturaMem_Empleados("data\\Empleados_data\\"+m_archi_act,j);
	}
	m_data=nullptr;
}

HijaEmpleado::~HijaEmpleado() {
	if (m_data!=nullptr) {
		ConversionYGuardadoBin_Empleados(*m_data,"data\\Empleados_data\\"+m_archi_act,m_empleado_pos);
		ConversionYGuardadoBin_Pasivos(*m_data_pasivos,"data\\Pasivos_data\\Pasivos"+m_archi_act.substr(m_archi_act.find("_")));
	}
	if(m_modificado){RenombrarYCrearCopiaEmpleado("data\\Empleados_data\\"+m_archi_act);}
}

void HijaEmpleado::ClickAgregarEmpleado( wxCommandEvent& event )  {
	delete m_data; m_data=nullptr;
	m_data=new Empleado;
	HijaNuevoEmpleado win(this,m_data);
	if(win.ShowModal()==1){
		m_GrillaListaEmpleados->AppendRows(1);
		m_empleado_pos=m_GrillaListaEmpleados->GetNumberRows()-1;
		m_data_pasivos->modSalarios(m_data_pasivos->verSalarios()+m_data->verSalario());
		m_data->modFechaIngreso(obtenerFechaDeHoy());
		wxString s=std::to_string(m_data->verDNI())+"_"+std::to_string(m_GrillaListaEmpleados->GetNumberRows());
		m_GrillaListaEmpleados->SetCellValue(m_empleado_pos,0,s);
		ConversionYGuardadoBin_Empleados(*m_data,"data\\Empleados_data\\"+m_archi_act,m_empleado_pos);
		ActGrillas_Empleado();
	}else{delete m_data; m_data=nullptr;}
}

void HijaEmpleado::EliminarEmpleado( wxCommandEvent& event )  {
	if (m_GrillaListaEmpleados->GetNumberRows()!=0) {
		m_modificado=true;
		std::string contenido=wx_to_std(m_GrillaListaEmpleados->GetCellValue(m_GrillaListaEmpleados->GetGridCursorRow(),0));
		m_empleado_pos=std::atoi(contenido.substr(contenido.find('_')+1).c_str())-1;
		if(m_data==nullptr){
			m_data=new Empleado (ConversionYLecturaMem_Empleados("data\\Empleados_data\\"+m_archi_act,m_empleado_pos));
			ActGrillas_Empleado();
		}
		m_GrillaListaEmpleados->DeleteRows(m_GrillaListaEmpleados->GetGridCursorRow());
		m_GrillaEmpleados1->ClearGrid();
		m_GrillaEmpleados2->ClearGrid();
		m_data_pasivos->modSalarios(m_data_pasivos->verSalarios() - m_data->verSalario());
		EliminarEmpleadoBin(m_data->verDNI(),"data\\Empleados_data\\"+m_archi_act);
		delete m_data;
		m_data=nullptr;
	}
}

void HijaEmpleado::ClickGuardarEmpleados( wxCommandEvent& event )  {
	GuardarDatos_Empleado();
}

void HijaEmpleado::ClickCargarEmpleados( wxCommandEvent& event )  {
	if(m_data!=nullptr){
		GuardarDatos_Empleado();
	}
	m_empleado_pos=m_GrillaListaEmpleados->GetGridCursorRow();
	delete m_data; m_data=nullptr;
	m_data=new Empleado (ConversionYLecturaMem_Empleados("data\\Empleados_data\\"+m_archi_act,m_empleado_pos));
	ActGrillas_Empleado();
}

void HijaEmpleado::ClickAceptarEmpleado( wxCommandEvent& event )  {
	GuardarDatos_Empleado();
	Close();
}

void HijaEmpleado::ClickCancelarEmpleado( wxCommandEvent& event )  {
	Close();
}

void HijaEmpleado::DobleClickEmpleado( wxGridEvent& event )  {
	if(m_data!=nullptr){
		GuardarDatos_Empleado();
	}
	m_empleado_pos=m_GrillaListaEmpleados->GetGridCursorRow();
	delete m_data; m_data=nullptr;
	m_data=new Empleado (ConversionYLecturaMem_Empleados("data\\Empleados_data\\"+m_archi_act,m_empleado_pos));
	ActGrillas_Empleado();
}

void HijaEmpleado::ActGrillas_Empleado(){
	if (m_data!=nullptr) {
		m_GrillaEmpleados2->SetCellValue(0,0,m_data->verOcupacion());
		m_GrillaEmpleados2->SetCellValue(0,1,"$"+std::to_string(m_data->verSalario()));
		m_GrillaEmpleados2->SetCellValue(0,2,ConvertirFormato_aaaammdd(m_data->verFechaIngreso()));
		m_GrillaEmpleados2->SetCellValue(0,3,m_data->verTelefono());
		m_GrillaEmpleados2->SetCellValue(0,4,m_data->verCorreo());
		
		m_GrillaEmpleados1->SetCellValue(0,0,m_data->verNombreYApellido());
		m_GrillaEmpleados1->SetCellValue(0,1,std::to_string(m_data->verDNI()));
	}else{}
}
void HijaEmpleado::GuardarDatos_Empleado(){
	if (m_data!=nullptr) {
		m_data->modOcupacion(wx_to_std(m_GrillaEmpleados2->GetCellValue(0,0)));
		m_data->modSalario(FiltrarYConvertir(m_GrillaEmpleados2->GetCellValue(0,1)));
		m_data->modFechaIngreso(ConvertirFormato_ddmmaaaa(m_GrillaEmpleados2->GetCellValue(0,2)));
		m_data->modTelefono(wx_to_std(m_GrillaEmpleados2->GetCellValue(0,3)));
		m_data->modCorreo(wx_to_std(m_GrillaEmpleados2->GetCellValue(0,4)));
		
		m_data->modNombreYApellido(wx_to_std(m_GrillaEmpleados1->GetCellValue(0,0)));
		m_data->modDNI(FiltrarYConvertir(m_GrillaEmpleados1->GetCellValue(0,1)));
		
		ConversionYGuardadoBin_Empleados(*m_data, "data\\Empleados_data\\"+m_archi_act, m_empleado_pos);
	}else{}
}

