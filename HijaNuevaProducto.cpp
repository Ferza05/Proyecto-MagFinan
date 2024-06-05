#include "HijaNuevaProducto.h"
#include <wx/msgdlg.h>
#include "Utilidades.h"
#include "Logs.h"
#include "Funciones.h"

HijaNuevaProducto::HijaNuevaProducto(wxWindow *parent, Clientes *c, Activos *a, std::string nom_archi) : BaseNuevoProducto(parent) , m_data(c), m_data_activos(a) , m_archi_act(nom_archi) {
	Inventario inv=LeerInventario("data\\Activos_data\\inv_Activos.dat",0,-1); int i=0;
	while(inv.precio!=-1) { 
		m_choiceProd->Append(inv.detalle);
		i++;
		inv=LeerInventario("data\\Activos_data\\inv_Activos.dat",i,-1);
	}
}

void HijaNuevaProducto::ClickAgregar( wxCommandEvent& event )  {
	if (!m_textCodigo->IsEmpty() && !m_textCantidad->IsEmpty()) {
		Inventario inv=LeerInventario("data\\Activos_data\\inv_Activos.dat",m_choiceProd->GetSelection(),-1);
		if (inv.precio!=-1) {
			if (inv.stock_disponible>=std::atoi(m_textCantidad->GetValue().c_str())) {
				Productos a; a.activo=true;
				a.client_id=m_data->verCodCompra();
				a.cod_prod=std::atoi(m_textCodigo->GetValue().c_str());
				a.cant_comp=std::atoi(m_textCantidad->GetValue().c_str());
				m_data->modCantArtComprados(m_data->verArctComprados()+a.cant_comp);
				inv.stock_disponible-=a.cant_comp;
				std::copy(std::begin(inv.detalle), std::end(inv.detalle), std::begin(a.marca));
				std::copy(std::begin(inv.rubro), std::end(inv.rubro), std::begin(a.tipo));
				a.precio=(inv.precio*a.cant_comp);
				m_data->modPago(m_data->verPago()+a.precio);
				if(m_data->verMetodoPago()=="Banco"){m_data_activos->modDineroBanco(m_data_activos->verDineroBanco() + (inv.precio*a.cant_comp));}
				if(m_data->verMetodoPago()=="Efectivo"){m_data_activos->modDineroCaja(m_data_activos->verDineroCaja() + (inv.precio*a.cant_comp));}
				if(m_data->verMetodoPago()=="Credito"){m_data_activos->modDineroCredito(m_data_activos->verDineroCredito() + (inv.precio*a.cant_comp));}
				std::vector<Productos> prod; prod.push_back(a);
				GuardarProductos(*m_data,prod,"data\\Clientes_data\\productos_"+m_archi_act,false);
				GuardarInventario(inv,"data\\Activos_data\\inv_Activos.dat",m_choiceProd->GetSelection(),-1);
				Logs L(*m_data,a);
				int refe=obtenerFechaDeHoy()/100;
				GuardarLogs("data\\Logs_data\\Logs_"+std::to_string(refe)+".dat",L);
				GuardarLogsClientes("data\\Logs_data\\Logs_Clientes.dat",L);
				GuardarLogsClientes("data\\Logs_data\\Logs_Clientes_"+std::to_string(refe)+".dat",L);
				GuardarLogsProd("data\\Logs_data\\Logs_Prod.dat",L);
				GuardarLogsProd("data\\Logs_data\\Logs_Prod_"+std::to_string(refe)+".dat",L);
			}else{wxMessageBox("No hay suficiente stock del producto seleccionado, intente con otro.","Advertencia",wxOK);}
		}else{wxMessageBox("No existe el producto ingresado, intente con otro.","Advertencia",wxOK);}
	}else{wxMessageBox("Campos necesarios incompletos.","Advertencia",wxOK);}
	EndModal(1);
}

void HijaNuevaProducto::ClickCancelar( wxCommandEvent& event )  {
	EndModal(0);
}

HijaNuevaProducto::~HijaNuevaProducto() {
	
}

void HijaNuevaProducto::ClickSeleccionProducto( wxCommandEvent& event )  {
	int selec=m_choiceProd->GetSelection();
	Inventario inv=LeerInventario("data\\Activos_data\\inv_Activos.dat",selec,-1);
	m_textCodigo->SetValue(std::to_string(inv.cod_prod));
}

