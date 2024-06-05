#ifndef APPLICATION_H
#define APPLICATION_H
#include <wx/app.h>
#include "Activos.h"
#include "Pasivos.h"
#include "Clientes.h"
#include "Empleado.h"
#include "Personas.h"

class Application : public wxApp {
private:
public:
	virtual bool OnInit();
};

#endif
