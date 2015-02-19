#include "MooseMaxApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<MooseMaxApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

MooseMaxApp::MooseMaxApp(const std::string & name, InputParameters parameters) :
    MooseApp(name, parameters)
{
  srand(libMesh::processor_id());
  
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  MooseMaxApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  MooseMaxApp::associateSyntax(_syntax, _action_factory);
}

MooseMaxApp::~MooseMaxApp()
{
}

extern "C" void MooseMaxApp__registerApps() { MooseMaxApp::registerApps(); }
void
MooseMaxApp::registerApps()
{
  registerApp(MooseMaxApp);
}

void
MooseMaxApp::registerObjects(Factory & factory)
{
}

void
MooseMaxApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
