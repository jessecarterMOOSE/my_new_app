#include "MyNewAppApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

#include "BisonApp.h"
#include "BisonSyntax.h"

template <>
InputParameters
validParams<MyNewAppApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

MyNewAppApp::MyNewAppApp(InputParameters parameters) : MooseApp(parameters)
{
  MyNewAppApp::registerAll(_factory, _action_factory, _syntax);
  BisonApp::registerAll(_factory, _action_factory, _syntax);
}

MyNewAppApp::~MyNewAppApp() {}

void
MyNewAppApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"MyNewAppApp"});
  Registry::registerActionsTo(af, {"MyNewAppApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
MyNewAppApp::registerApps()
{
  registerApp(MyNewAppApp);
  BisonApp::registerApps();
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
MyNewAppApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MyNewAppApp::registerAll(f, af, s);
}
extern "C" void
MyNewAppApp__registerApps()
{
  MyNewAppApp::registerApps();
}
