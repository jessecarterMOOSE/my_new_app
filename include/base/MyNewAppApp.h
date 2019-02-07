//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef MY_NEW_APPAPP_H
#define MY_NEW_APPAPP_H

#include "MooseApp.h"

class MyNewAppApp;

template <>
InputParameters validParams<MyNewAppApp>();

class MyNewAppApp : public MooseApp
{
public:
  MyNewAppApp(InputParameters parameters);
  virtual ~MyNewAppApp();

  static void registerApps();
  static void registerAll(Factory & f, ActionFactory & af, Syntax & s);
};

#endif /* MY_NEW_APPAPP_H */
