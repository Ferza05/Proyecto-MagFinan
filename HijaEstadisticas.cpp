#include "HijaEstadisticas.h"
#include "Funciones.h"
#include "Utilidades.h"
#include <cstdlib>

HijaEstadisticas::HijaEstadisticas(wxWindow *parent) : BaseEstadisticas(parent) {
	int refe=obtenerFechaDeHoy()/100;
	int mes=refe-(obtenerFechaDeHoy()/10000)*100;
	m_choiceMesClient->SetSelection(mes-1);
	m_choiceMesProd->SetSelection(mes-1);
	ActualizarGrillasClientes("data\\Logs_data\\Logs_Clientes_"+std::to_string(refe)+".dat");
	ActualizarGrillasProd("data\\Logs_data\\Logs_Prod_"+std::to_string(refe)+".dat");
}

HijaEstadisticas::~HijaEstadisticas() {
	
}

void HijaEstadisticas::SeleccionBusquedaPorCodigo( wxCommandEvent& event )  {
	if (m_checkBox2->GetValue()) {
		m_choiceDetalleProd->Enable();
		m_textCodProd->Enable();
		Inventario inv=LeerInventario("data\\Activos_data\\inv_Activos.dat",0,-1); int i=0;
		while(inv.precio!=-1) { 
			m_choiceDetalleProd->Append(inv.detalle);
			i++;
			inv=LeerInventario("data\\Activos_data\\inv_Activos.dat",i,-1);
		}
	}else{
		m_choiceDetalleProd->Clear();
		m_textCodProd->Clear();
		m_choiceDetalleProd->Disable();
		m_textCodProd->Disable();
	}
}

void HijaEstadisticas::SeleccionBusquedaPorDNI( wxCommandEvent& event )  {
	if (m_checkBox3->GetValue()) {
		m_textCtrlDNI->Enable();
	}else{
		m_textCtrlDNI->Clear();
		m_textCtrlDNI->Disable();
	}
}

void HijaEstadisticas::SeleccionBusquedaAmbos( wxCommandEvent& event )  {
	if (m_checkBox4->GetValue()) {
		m_checkBox2->SetValue(true);
		m_checkBox3->SetValue(true);
		m_textCtrlDNI->Enable();
		m_choiceDetalleProd->Enable();
		m_textCodProd->Enable();
		Inventario inv=LeerInventario("data\\Activos_data\\inv_Activos.dat",0,-1); int i=0;
		while(inv.precio!=-1) { 
			m_choiceDetalleProd->Append(inv.detalle);
			i++;
			inv=LeerInventario("data\\Activos_data\\inv_Activos.dat",i,-1);
		}
	}else{
		m_checkBox2->SetValue(false);
		m_checkBox3->SetValue(false);
		m_textCodProd->Clear();
		m_textCtrlDNI->Clear();
		m_choiceDetalleProd->Clear();
		m_textCtrlDNI->Disable();
		m_choiceDetalleProd->Disable();
		m_textCodProd->Disable();
		
	}
}

void HijaEstadisticas::ClickBuscarResultados( wxCommandEvent& event )  {
	if(m_checkBox2->GetValue() && m_checkBox3->GetValue() && m_checkBox4->GetValue()){
		int fechaIni=std::atoi(m_textCtrlFechaIni->GetValue().c_str());
		int fechaFin=std::atoi(m_textCtrlFechaFin->GetValue().c_str());
		int cod_prod=std::atoi(m_textCodProd->GetValue().c_str());
		int dni=std::atoi(m_textCtrlDNI->GetValue().c_str());
		int val=CuantosVendio(cod_prod,dni,"data\\Logs_data\\Logs.dat",fechaIni,fechaFin,3);
		m_textCodProd->Clear();
		m_choiceDetalleProd->Clear();
		m_textCtrlDNI->Clear();
		m_textCtrlFechaFin->Clear();
		m_textCtrlFechaIni->Clear();
		m_gridResultado->SetColLabelValue(0,"DNI y Cod_Prod");
		m_gridResultado->SetCellValue(0,0,std::to_string(dni)+"_"+std::to_string(cod_prod));
		m_gridResultado->SetCellValue(0,1,std::to_string(val));
		
	}else{
		if(m_checkBox2->GetValue()){
			int fechaIni=std::atoi(m_textCtrlFechaIni->GetValue().c_str());
			int fechaFin=std::atoi(m_textCtrlFechaFin->GetValue().c_str());
			int cod_prod=std::atoi(m_textCodProd->GetValue().c_str());
			int val=CuantosVendio(cod_prod,-1,"data\\Logs_data\\Logs.dat",fechaIni,fechaFin,1);
			m_textCodProd->Clear();
			m_choiceDetalleProd->Clear();
			m_textCtrlFechaFin->Clear();
			m_textCtrlFechaIni->Clear();
			m_gridResultado->SetColLabelValue(0,"Cod_Prod");
			m_gridResultado->SetCellValue(0,0,std::to_string(cod_prod));
			m_gridResultado->SetCellValue(0,1,std::to_string(val));
		}
		if(m_checkBox3->GetValue()){
			int fechaIni=std::atoi(m_textCtrlFechaIni->GetValue().c_str());
			int fechaFin=std::atoi(m_textCtrlFechaFin->GetValue().c_str());
			int dni=std::atoi(m_textCtrlDNI->GetValue().c_str());
			int val=CuantosVendio(-1,dni,"data\\Logs_data\\Logs.dat",fechaIni,fechaFin,2);
			m_textCtrlDNI->Clear();
			m_textCtrlFechaFin->Clear();
			m_textCtrlFechaIni->Clear();
			m_gridResultado->SetColLabelValue(0,"DNI");
			m_gridResultado->SetCellValue(0,0,std::to_string(dni));
			m_gridResultado->SetCellValue(0,1,std::to_string(val));
		}
	}
}

void HijaEstadisticas::ClickCerrar( wxCommandEvent& event )  {
	Close();
}

void HijaEstadisticas::ActualizarGrillasClientes(std::string nom_archi){
	OrdenarLogClientes(nom_archi);
	std::string s=LeerLogsClientes(nom_archi,-1,0); int i=0,cant=0;
	while(s!="X" && cant<5){
		if(verSeccion(s,3)!="0"){
			m_gridClientesMes->SetCellValue(i,0,verSeccion(s,1));
			m_gridClientesMes->SetCellValue(i,1,verSeccion(s,2));
			m_gridClientesMes->SetCellValue(i,2,verSeccion(s,3));
			cant++;
		}
		i++;
		s=LeerLogsClientes(nom_archi,-1,i);
	}
}

void HijaEstadisticas::ActualizarGrillasProd(std::string nom_archi){
	OrdenarLogProd(nom_archi);
	std::string s=LeerLogsProd(nom_archi,-1,0); int i=0,cant=0;
	while(s!="X" && cant<5){
		if(verSeccion(s,2)!="0"){
			Inventario aux=LeerInventario("data\\Activos_data\\inv_Activos.dat",-1,std::atoi(verSeccion(s,1).c_str()));
			m_gridProdMes->SetCellValue(i,0,verSeccion(s,1));
			m_gridProdMes->SetCellValue(i,1,verSeccion(s,2));
			m_gridProdMes->SetCellValue(i,2,aux.detalle);
			m_gridProdMes->SetCellValue(i,3,aux.rubro);
			cant++;
		}
		i++;
		s=LeerLogsProd(nom_archi,-1,i);
	}
}

void HijaEstadisticas::SeleccionProdMasVendidos( wxCommandEvent& event )  {
	int selec=m_choiceMesProd->GetSelection();
	m_gridProdMes->ClearGrid();
	int refe=((obtenerFechaDeHoy()/1000)*10)+selec+1;
	if(selec!=12){
		ActualizarGrillasProd("data\\Logs_data\\Logs_Prod_"+std::to_string(refe)+".dat");
	}else{
		ActualizarGrillasProd("data\\Logs_data\\Logs_Prod.dat");
	}
}

void HijaEstadisticas::SeleccionClientesMasCompras( wxCommandEvent& event )  {
	int selec=m_choiceMesClient->GetSelection();
	m_gridClientesMes->ClearGrid();
	int refe=((obtenerFechaDeHoy()/1000)*10)+selec+1;
	if(selec!=12){
		ActualizarGrillasClientes("data\\Logs_data\\Logs_Clientes_"+std::to_string(refe)+".dat");
	}else{
		ActualizarGrillasClientes("data\\Logs_data\\Logs_Clientes.dat");
	}
}

void HijaEstadisticas::SeleccionDetalleProducto( wxCommandEvent& event )  {
	int selec=m_choiceDetalleProd->GetSelection();
	Inventario inv=LeerInventario("data\\Activos_data\\inv_Activos.dat",selec,-1);
	m_textCodProd->SetValue(std::to_string(inv.cod_prod));
}

