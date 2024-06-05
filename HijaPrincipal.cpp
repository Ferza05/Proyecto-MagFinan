#include "HijaPrincipal.h"
#include "HijaActivos.h"
#include "HijaPasivos.h"
#include "HijaEmpleado.h"
#include "HijaClientes.h"
#include <wx/textdlg.h>
#include <wx/msgdlg.h>
#include <wx/icon.h>
#include "HijaEstadisticas.h"


HijaPrincipal::HijaPrincipal(wxWindow *parent) : BasePrincipal(parent){
	
}

HijaPrincipal::~HijaPrincipal() {
	
}

void HijaPrincipal::ClickActivos( wxCommandEvent& event )  {

	HijaActivos *win=new HijaActivos(this);

	wxIcon icon;
	icon.LoadFile("data\\source img\\user-manage_114453.ico", wxBITMAP_TYPE_ICO);
	win->SetIcon(icon);

	win->Show();
}

void HijaPrincipal::ClickPasivos( wxCommandEvent& event )  {
	
	HijaPasivos *win=new HijaPasivos(this);
	
	wxIcon icon;
	icon.LoadFile("data\\source img\\user-manage_114453.ico", wxBITMAP_TYPE_ICO);
	win->SetIcon(icon);
	
	win->Show();
}

void HijaPrincipal::ClickCerrarSesion( wxCommandEvent& event )  {
	Close();
}


void HijaPrincipal::ClickRecoPrincipal( wxCommandEvent& event )  {
	ShellExecute(NULL,L"open",L"data\\manual de usuario.pdf",L"manual del usuario.pdf",NULL,SW_NORMAL);
}

void HijaPrincipal::ClickClientes( wxCommandEvent& event )  {
	
	HijaClientes *win0=new HijaClientes(this);
	
	wxIcon icon;
	icon.LoadFile("data\\source img\\user-manage_114453.ico", wxBITMAP_TYPE_ICO);
	win0->SetIcon(icon);
	
	win0->Show();
}

void HijaPrincipal::ClickEmpleados( wxCommandEvent& event )  {
	
	HijaEmpleado *win1=new HijaEmpleado(this);
	
	wxIcon icon;
	icon.LoadFile("data\\source img\\user-manage_114453.ico", wxBITMAP_TYPE_ICO);
	win1->SetIcon(icon);
	
	win1->Show();
}

void HijaPrincipal::ClickEstadisticas( wxCommandEvent& event )  {
	HijaEstadisticas *win1=new HijaEstadisticas(this);
	
	wxIcon icon;
	icon.LoadFile("data\\source img\\user-manage_114453.ico", wxBITMAP_TYPE_ICO);
	win1->SetIcon(icon);
	
	win1->Show();
}

