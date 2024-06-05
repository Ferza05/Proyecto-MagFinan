#include "HijaNuevoEmpleado.h"
#include <wx/msgdlg.h>

HijaNuevoEmpleado::HijaNuevoEmpleado(wxWindow *parent,Empleado *a) : BaseNuevoEmpleado(parent),m_data(a) {
	
}

void HijaNuevoEmpleado::ClickAceptarNuevoEmpleado( wxCommandEvent& event )  {
	if(!m_textDNI->IsEmpty() && !m_textSalario->IsEmpty()){
		m_data->modDNI(std::atoi(m_textDNI->GetValue().c_str()));
		m_data->modSalario(std::atoi(m_textSalario->GetValue().c_str()));
		m_data->modEstado(true);
		EndModal(1);
	}else{wxMessageBox("Campos necesarios incompletos.","Advertencia",wxOK);}
}

void HijaNuevoEmpleado::ClickCancelarNuevoEmpleado( wxCommandEvent& event )  {
	EndModal(0);
}

HijaNuevoEmpleado::~HijaNuevoEmpleado() {
	
}

