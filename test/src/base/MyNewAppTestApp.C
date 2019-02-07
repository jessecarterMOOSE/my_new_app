//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "MyNewAppTestApp.h"
#include "MyNewAppApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<MyNewAppTestApp>()
{
  InputParameters params = validParams<MyNewAppApp>();
  return params;
}

MyNewAppTestApp::MyNewAppTestApp(InputParameters parameters) : MooseApp(parameters)
{
  MyNewAppTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

MyNewAppTestApp::~MyNewAppTestApp() {}

void
MyNewAppTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  MyNewAppApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"MyNewAppTestApp"});
    Registry::registerActionsTo(af, {"MyNewAppTestApp"});
  }
}

void
MyNewAppTestApp::registerApps()
{
  registerApp(MyNewAppApp);
  registerApp(MyNewAppTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
MyNewAppTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MyNewAppTestApp::registerAll(f, af, s);
}
extern "C" void
MyNewAppTestApp__registerApps()
{
  MyNewAppTestApp::registerApps();
}
