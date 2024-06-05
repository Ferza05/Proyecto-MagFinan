#include "HijaNuevaCompra.h"
#include <wx/msgdlg.h>

HijaNuevaCompra::HijaNuevaCompra(wxWindow *parent,Clientes *a) : BaseNuevaCompra(parent),m_data(a) {
	
}

void HijaNuevaCompra::ClickAceptarNuevaCompra( wxCommandEvent& event )  {
	if (!m_textDNI->IsEmpty()) {
		m_data->modDNI(std::atoi(m_textDNI->GetValue().c_str()));
		m_data->modEstado(true);
		int deci=m_choiceMetodoPago->GetSelection();
		if(deci==0){m_data->modMetodoPago("Efectivo");} 
		if(deci==1){m_data->modMetodoPago("Banco");} 
		if(deci==2){m_data->modMetodoPago("Credito");}
		EndModal(1);
	}else{wxMessageBox("Campos necesarios incompletos.","Advertencia",wxOK);}
}

void HijaNuevaCompra::ClickCancelarNuevaCompra( wxCommandEvent& event )  {
	EndModal(0);
}

HijaNuevaCompra::~HijaNuevaCompra() {
	
}

