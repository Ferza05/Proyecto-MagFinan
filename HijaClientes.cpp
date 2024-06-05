#include "HijaClientes.h"
#include "Funciones.h"
#include "Utilidades.h"
#include <wx/textdlg.h>
#include <wx/msgdlg.h>
#include "HijaNuevaCompra.h"
#include "HijaNuevaProducto.h"

HijaClientes::HijaClientes(wxWindow *parent) : BaseClientes(parent) {
	int anio=obtenerFechaDeHoy()/10000;
	std::vector<std::string> titulos=ConversionYLecturaMem_NomArchivos("data\\titles_source\\"+std::to_string(anio)+"_Clientes.txt");
	if(titulos.empty()){
		int ref=((obtenerFechaDeHoy()/10000)*100)+1;
		for(int i=0;i<12;i++) { 
			titulos.push_back("Clientes_"+std::to_string(ref)+".dat"); ref++;
		}
		ref=ref/100;
		ConversionYGuardadoTxt_NomArchivos(titulos,"data\\titles_source\\"+std::to_string(ref)+"_Clientes.txt",false);
	}
	int mes=(obtenerFechaDeHoy()/100)-(anio*100);
	m_archi_act=titulos[mes-1];
	m_data_activos= new Activos (ConversionYLecturaMem_Activos("data\\Activos_data\\Activos"+m_archi_act.substr(m_archi_act.find("_"))));
	Clientes a=ConversionYLecturaMem_Clientes("data\\Clientes_data\\"+m_archi_act,0); int j=0;
	while(a.verDNI()!=-1) { 
		//if (a.verDNI()!=-2) {
			m_GrillaListaClientes->AppendRows(1);
			wxString s=std::to_string(a.verDNI())+"_"+std::to_string(j+1);
			m_GrillaListaClientes->SetCellValue(j,0,s);
			j++;
			a=ConversionYLecturaMem_Clientes("data\\Clientes_data\\"+m_archi_act,j);
		//}
	}
	m_data=nullptr;
}

HijaClientes::~HijaClientes() {
	if (m_data!=nullptr) {
		GuardarDatos_Clientes();
	}
	if (m_modificado) {
		RenombrarYCrearCopiaClientes("data\\Clientes_data\\"+m_archi_act);
		RenombrarYCrearCopiaProductos("data\\Clientes_data\\productos_"+m_archi_act);
	}
}

void HijaClientes::ClickAceptarClientes( wxCommandEvent& event )  {
	GuardarDatos_Clientes();
	Close();
}

void HijaClientes::ClickCancelarClientes( wxCommandEvent& event )  {
	Close();
}

void HijaClientes::ClickGuardarClientes( wxCommandEvent& event )  {
	GuardarDatos_Clientes();
}

void HijaClientes::ClickCargarClientes( wxCommandEvent& event )  {
	if(m_data!=nullptr){
		GuardarDatos_Clientes();
		delete m_data; m_data=nullptr;
	}
	m_cliente_pos=m_GrillaListaClientes->GetGridCursorRow();
	m_data=new Clientes (ConversionYLecturaMem_Clientes("data\\Clientes_data\\"+m_archi_act,m_cliente_pos-1));
	
	ActGrillas_Clientes();
}

void HijaClientes::ClickAgregarCompra( wxCommandEvent& event )  {
	delete m_data; m_data=nullptr;
	m_data=new Clientes;
	HijaNuevaCompra win(this,m_data);
	if(win.ShowModal()==1){
		m_data->modFecha_Compra(obtenerFechaDeHoy());
		m_cliente_pos=m_GrillaListaClientes->GetNumberRows();
		if(m_GrillaListaClientes->GetNumberRows()!=0){
			Clientes c=ConversionYLecturaMem_Clientes("data\\Clientes_data\\"+m_archi_act,m_cliente_pos-1);
			m_data->modCodCompra(c.verCodCompra()+1);
		}else{
			int mesPasado=(obtenerFechaDeHoy()/100)-1;
			Clientes c=ConversionYLecturaMem_Clientes("data\\Clientes_data\\Clientes_"+std::to_string(mesPasado)+".dat",0); int i=0;
			while(c.verDNI()!=-1){
				i++;
				c=ConversionYLecturaMem_Clientes("data\\Clientes_data\\Clientes_"+std::to_string(mesPasado)+".dat",i);
			}
			if(i==0 && c.verDNI()==-1){m_data->modCodCompra(1);}
			else{c=ConversionYLecturaMem_Clientes("data\\Clientes_data\\Clientes_"+std::to_string(mesPasado)+".dat",i-1);
				m_data->modCodCompra(c.verCodCompra()+1);
			}
		}
		m_GrillaListaClientes->AppendRows(1);
		wxString s=std::to_string(m_data->verDNI())+"_"+std::to_string(m_GrillaListaClientes->GetNumberRows());
		m_GrillaListaClientes->SetCellValue(m_GrillaListaClientes->GetNumberRows()-1,0,s);
		ConversionYGuardadoBin_Clientes(*m_data,"data\\Clientes_data\\"+m_archi_act,m_cliente_pos);
		ActGrillas_Clientes();
	}
}

void HijaClientes::ClickEliminarCompra( wxCommandEvent& event )  {
	if (m_GrillaListaClientes->GetNumberRows()!=0) {
		m_modificado=true;
		std::string contenido=wx_to_std(m_GrillaListaClientes->GetCellValue(m_GrillaListaClientes->GetGridCursorRow(),0));	
		m_cliente_pos=std::atoi(contenido.substr(contenido.find('_')+1).c_str())-1;
		if (m_data==nullptr) {
			m_data=new Clientes (ConversionYLecturaMem_Clientes("data\\Clientes_data\\"+m_archi_act,m_cliente_pos));
			ActGrillas_Clientes();
		}
		std::vector<Productos> prod=LeerProductos(*m_data,"data\\Clientes_data\\productos_"+m_archi_act);
		int refe=obtenerFechaDeHoy()/100;
		for(size_t i=0;i<prod.size();i++){ 
			Productos x=prod[i];
			Logs L(*m_data,x);
			EliminarLog("data\\Logs_data\\Logs_"+std::to_string(refe)+".dat",L);
			RenombrarYCrearCopiaLogs("data\\Logs_data\\Logs_"+m_archi_act.substr(m_archi_act.find("_")));
			EliminarLogProd("data\\Logs_data\\Logs_Prod.dat",x.cod_prod,x.cant_comp);
			EliminarLogProd("data\\Logs_data\\Logs_Prod_"+std::to_string(refe)+".dat",x.cod_prod,x.cant_comp);
			Inventario inv=LeerInventario("data\\Activos_data\\inv_Activos.dat",-1,x.cod_prod);
			inv.stock_disponible+=x.cant_comp;
			GuardarInventario(inv,"data\\Activos_data\\inv_Activos.dat",-1,x.cod_prod);
		}
		EliminarProductos(m_data->verCodCompra(),"data\\Clientes_data\\productos_"+m_archi_act);
		
		m_GrillaListaClientes->DeleteRows(m_GrillaListaClientes->GetGridCursorRow());
		m_GrillaClientes1->ClearGrid();
		m_GrillaClientes2->ClearGrid();
		m_GrillaClientes3->ClearGrid();
		if(m_GrillaClientes3->GetNumberRows()!=0){m_GrillaClientes3->DeleteRows(0,m_GrillaClientes3->GetNumberRows());}
		std::string metodo_pago=m_data->verMetodoPago();
		if(metodo_pago=="Banco"){m_data_activos->modDineroBanco(m_data_activos->verDineroBanco() - m_data->verPago());}
		if(metodo_pago=="Efectivo"){m_data_activos->modDineroCaja(m_data_activos->verDineroCaja() - m_data->verPago());}
		if(metodo_pago=="Credito"){m_data_activos->modDineroCredito(m_data_activos->verDineroCredito() - m_data->verPago());}
		EliminarLogCliente("data\\Logs_data\\Logs_Clientes.dat",m_data->verDNI(),m_data->verArctComprados());
		EliminarLogCliente("data\\Logs_data\\Logs_Clientes_"+std::to_string(refe)+".dat",m_data->verDNI(),m_data->verArctComprados());
		EliminarClienteBin(m_data->verCodCompra(),"data\\Clientes_data\\"+m_archi_act);
		delete m_data;
		m_data=nullptr;
	}
}

void HijaClientes::ClickAgregarProducto( wxCommandEvent& event )  {
	if (m_data!=nullptr) {
		GuardarDatos_Clientes();
		HijaNuevaProducto win(this,m_data,m_data_activos, m_archi_act);
		if(win.ShowModal()==1){
			
			ActGrillas_Clientes();
		}
	}
}

void HijaClientes::ClickEliminarProducto( wxCommandEvent& event )  {
	if (m_data!=nullptr && m_GrillaClientes3->GetNumberRows()!=0) {
		m_modificado=true;
		int f=m_GrillaClientes3->GetGridCursorRow();
		Productos prod;
		prod.cod_prod=FiltrarYConvertir(m_GrillaClientes3->GetCellValue(f,0));
		prod.cant_comp=FiltrarYConvertir(m_GrillaClientes3->GetCellValue(f,1));
		std::string s1=wx_to_std(m_GrillaClientes3->GetCellValue(f,2)); strcpy(prod.marca,s1.c_str());
		std::string s2=wx_to_std(m_GrillaClientes3->GetCellValue(f,3)); strcpy(prod.tipo,s2.c_str());
		prod.precio=FiltrarYConvertir(m_GrillaClientes3->GetCellValue(f,4));
		Logs L(*m_data,prod);
		int val=FiltrarYConvertir(m_GrillaClientes3->GetCellValue(f,4));
		m_data->modPago(m_data->verPago()-val);
		if(m_data->verMetodoPago()=="Banco"){m_data_activos->modDineroBanco(m_data_activos->verDineroBanco() - val);}
		if(m_data->verMetodoPago()=="Efectivo"){m_data_activos->modDineroCaja(m_data_activos->verDineroCaja() - val);}
		if(m_data->verMetodoPago()=="Credito"){m_data_activos->modDineroCredito(m_data_activos->verDineroCredito() - val);}
		int cod_prod=FiltrarYConvertir(m_GrillaClientes3->GetCellValue(f,0));
		Inventario inv=LeerInventario("data\\Activos_data\\inv_Activos.dat",-1,cod_prod);
		inv.stock_disponible+=std::atoi(m_GrillaClientes3->GetCellValue(f,1).c_str());
		GuardarInventario(inv,"data\\Activos_data\\inv_Activos.dat",-1,cod_prod);
		m_data->modCantArtComprados(m_data->verArctComprados()-std::atoi(m_GrillaClientes3->GetCellValue(f,1).c_str()));
		int refe=obtenerFechaDeHoy()/100;
		EliminarLog("data\\Logs_data\\Logs_"+std::to_string(refe)+".dat",L);
		RenombrarYCrearCopiaLogs("data\\Logs_data\\Logs_"+m_archi_act.substr(m_archi_act.find("_")));
		EliminarLogCliente("data\\Logs_data\\Logs_Clientes.dat",m_data->verDNI(),prod.cant_comp);
		EliminarLogCliente("data\\Logs_data\\Logs_Clientes_"+std::to_string(refe)+".dat",m_data->verDNI(),prod.cant_comp);
		EliminarLogProd("data\\Logs_data\\Logs_Prod.dat",prod.cod_prod,prod.cant_comp);
		EliminarLogProd("data\\Logs_data\\Logs_Prod_"+std::to_string(refe)+".dat",prod.cod_prod,prod.cant_comp);
		EliminarProducto(*m_data,cod_prod,"data\\Clientes_data\\productos_"+m_archi_act);
		ActGrillas_Clientes();
	}
}

void HijaClientes::DobleClickClientes( wxGridEvent& event )  {
	if(m_data!=nullptr){
		GuardarDatos_Clientes();
		delete m_data; m_data=nullptr;
	}
	m_cliente_pos=m_GrillaListaClientes->GetGridCursorRow();
	m_data=new Clientes (ConversionYLecturaMem_Clientes("data\\Clientes_data\\"+m_archi_act,m_cliente_pos));
	
	ActGrillas_Clientes();
}

void HijaClientes::ActGrillas_Clientes(){
	if (m_data!=nullptr) {
		
		if(m_GrillaClientes3->GetNumberRows()!=0){m_GrillaClientes3->DeleteRows(0,m_GrillaClientes3->GetNumberRows());}
		m_GrillaClientes1->SetCellValue(0,0,"#"+std::to_string(m_data->verCodCompra()));
		m_GrillaClientes1->SetCellValue(0,1,"$"+std::to_string(m_data->verPago()));
		m_GrillaClientes1->SetCellValue(0,2,std::to_string(m_data->verArctComprados()));
		m_GrillaClientes1->SetCellValue(0,3,m_data->verMetodoPago());
		m_GrillaClientes1->SetCellValue(0,4,ConvertirFormato_aaaammdd(m_data->verFecha_Compra()));
		
		m_GrillaClientes2->SetCellValue(0,0,m_data->verNombreYApellido());
		m_GrillaClientes2->SetCellValue(0,1,std::to_string(m_data->verDNI()));
		
		const std::vector<Productos> &compra=LeerProductos(*m_data,"data\\Clientes_data\\productos_"+m_archi_act);
		for(size_t i=0;i<compra.size();i++) { 
			m_GrillaClientes3->AppendRows(1);
			Productos a = compra[i]; 
			m_GrillaClientes3->SetCellValue(i, 0, "#"+std::to_string(a.cod_prod));
			m_GrillaClientes3->SetCellValue(i, 1, std::to_string(a.cant_comp));
			std::string s1=a.marca,s2=a.tipo;
			m_GrillaClientes3->SetCellValue(i, 2, s1);
			m_GrillaClientes3->SetCellValue(i, 3, s2);
			m_GrillaClientes3->SetCellValue(i,4,"$"+std::to_string(a.precio));
		}
	}else{}
	
}
void HijaClientes::GuardarDatos_Clientes(){
	if (m_data!=nullptr) {
		m_data->modCodCompra(FiltrarYConvertir(m_GrillaClientes1->GetCellValue(0,0)));
		m_data->modPago(FiltrarYConvertir(m_GrillaClientes1->GetCellValue(0,1)));
		m_data->modCantArtComprados(FiltrarYConvertir(m_GrillaClientes1->GetCellValue(0,2)));
		m_data->modMetodoPago(wx_to_std(m_GrillaClientes1->GetCellValue(0,3)));
		m_data->modFecha_Compra(ConvertirFormato_ddmmaaaa(m_GrillaClientes1->GetCellValue(0,4)));
		
		m_data->modNombreYApellido(wx_to_std(m_GrillaClientes2->GetCellValue(0,0)));
		m_data->modDNI(FiltrarYConvertir(m_GrillaClientes2->GetCellValue(0,1)));
		
		int cant=m_GrillaClientes3->GetNumberRows();
		std::vector<Productos> compra;
		for(int i=0;i<cant;i++) { 
			Productos a;
			a.cod_prod=FiltrarYConvertir(m_GrillaClientes3->GetCellValue(i,0));
			a.cant_comp=FiltrarYConvertir(m_GrillaClientes3->GetCellValue(i,1));
			std::string s1=wx_to_std(m_GrillaClientes3->GetCellValue(i,2));
			strcpy(a.marca,s1.c_str());
			std::string s2=wx_to_std(m_GrillaClientes3->GetCellValue(i,3));
			strcpy(a.tipo,s2.c_str());
			a.precio=FiltrarYConvertir(m_GrillaClientes3->GetCellValue(i,4));
			
			compra.push_back(a);
		}
		ConversionYGuardadoBin_Clientes(*m_data,"data\\Clientes_data\\"+m_archi_act,m_cliente_pos);
		ConversionYGuardadoBin_Activos(*m_data_activos,"data\\Activos_data\\Activos"+m_archi_act.substr(m_archi_act.find("_")));
		if(m_data->verArctComprados()>0){GuardarProductos(*m_data,compra,"data\\Clientes_data\\productos_"+m_archi_act,true);}
	}else{}
}

void HijaClientes::ClickModCant( wxCommandEvent& event )  {
	if (m_data!=nullptr && m_GrillaClientes3->GetNumberRows()!=0) {
		wxTextEntryDialog dialog(this,"Ingrese la nueva cantidad comprada del producto seleccionado: ","Modificador de Compra","",wxOK|wxCANCEL);
		if(dialog.ShowModal()==wxID_OK){
			m_modificado=true;
			int f=m_GrillaClientes3->GetGridCursorRow(), refe=obtenerFechaDeHoy()/100;;
			Productos prod;
			prod.cod_prod=FiltrarYConvertir(m_GrillaClientes3->GetCellValue(f,0));
			prod.cant_comp=FiltrarYConvertir(m_GrillaClientes3->GetCellValue(f,1));
			std::string s1=wx_to_std(m_GrillaClientes3->GetCellValue(f,2)); strcpy(prod.marca,s1.c_str());
			std::string s2=wx_to_std(m_GrillaClientes3->GetCellValue(f,3)); strcpy(prod.tipo,s2.c_str());
			prod.precio=FiltrarYConvertir(m_GrillaClientes3->GetCellValue(f,4));
			Logs L(*m_data,prod);
			EliminarLog("data\\Logs_data\\Logs_"+std::to_string(refe)+".dat",L);
			RenombrarYCrearCopiaLogs("data\\Logs_data\\Logs_"+m_archi_act.substr(m_archi_act.find("_")));
			EliminarLogCliente("data\\Logs_data\\Logs_Clientes.dat",m_data->verDNI(),prod.cant_comp);
			EliminarLogCliente("data\\Logs_data\\Logs_Clientes_"+std::to_string(refe)+".dat",m_data->verDNI(),prod.cant_comp);
			EliminarLogProd("data\\Logs_data\\Logs_Prod.dat",prod.cod_prod,prod.cant_comp);
			EliminarLogProd("data\\Logs_data\\Logs_Prod_"+std::to_string(refe)+".dat",prod.cod_prod,prod.cant_comp);
			int val=FiltrarYConvertir(m_GrillaClientes3->GetCellValue(f,4));
			m_data->modPago(m_data->verPago()-val);
			m_data->modCantArtComprados(m_data->verArctComprados()-prod.cant_comp);
			if(m_data->verMetodoPago()=="Banco"){m_data_activos->modDineroBanco(m_data_activos->verDineroBanco() - val);}
			if(m_data->verMetodoPago()=="Efectivo"){m_data_activos->modDineroCaja(m_data_activos->verDineroCaja() - val);}
			if(m_data->verMetodoPago()=="Credito"){m_data_activos->modDineroCredito(m_data_activos->verDineroCredito() - val);}
			int cod_prod=FiltrarYConvertir(m_GrillaClientes3->GetCellValue(f,0));
			Inventario inv=LeerInventario("data\\Activos_data\\inv_Activos.dat",-1,cod_prod);
			inv.stock_disponible+=std::atoi(m_GrillaClientes3->GetCellValue(f,1).c_str());
			int deci=FiltrarYConvertir(dialog.GetValue());
			val=deci*inv.precio;
			inv.stock_disponible-=deci;
			GuardarInventario(inv,"data\\Activos_data\\inv_Activos.dat",-1,cod_prod);
			m_data->modPago(m_data->verPago()+val);
			m_data->modCantArtComprados(m_data->verArctComprados()+deci);
			ActGrillas_Clientes();
			if(m_data->verMetodoPago()=="Banco"){m_data_activos->modDineroBanco(m_data_activos->verDineroBanco() + val);}
			if(m_data->verMetodoPago()=="Efectivo"){m_data_activos->modDineroCaja(m_data_activos->verDineroCaja() + val);}
			if(m_data->verMetodoPago()=="Credito"){m_data_activos->modDineroCredito(m_data_activos->verDineroCredito() + val);}
			m_GrillaClientes3->SetCellValue(f,1,std::to_string(deci));
			m_GrillaClientes3->SetCellValue(f,4,"$"+std::to_string(val));
			GuardarDatos_Clientes();
			L.modCantProd(deci);
			GuardarLogs("data\\Logs_data\\Logs_"+std::to_string(refe)+".dat",L);
			GuardarLogsClientes("data\\Logs_data\\Logs_Clientes.dat",L);
			GuardarLogsClientes("data\\Logs_data\\Logs_Clientes_"+std::to_string(refe)+".dat",L);
			GuardarLogsProd("data\\Logs_data\\Logs_Prod.dat",L);
			GuardarLogsProd("data\\Logs_data\\Logs_Prod_"+std::to_string(refe)+".dat",L);
		}
	}
}

