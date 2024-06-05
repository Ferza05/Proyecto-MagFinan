
#include "Application.h"

#include <wx/image.h>
#include "HijaActivos.h"
#include "HijaPrincipal.h"
#include "HijaPasivos.h"
#include <wx/icon.h>
#include "HijaEstadisticas.h"

IMPLEMENT_APP(Application)

bool Application::OnInit() {
	wxDisableAsserts();
	wxInitAllImageHandlers();
	HijaPrincipal *win = new HijaPrincipal(NULL);
	
	wxIcon icon;
	icon.LoadFile("data\\source img\\user-manage_114453.ico", wxBITMAP_TYPE_ICO);
	win->SetIcon(icon);
	
	win->Show();
	
	
	return true;
}


