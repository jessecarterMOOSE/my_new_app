//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef MY_NEW_APPTESTAPP_H
#define MY_NEW_APPTESTAPP_H

#include "MooseApp.h"

class MyNewAppTestApp;

template <>
InputParameters validParams<MyNewAppTestApp>();

class MyNewAppTestApp : public MooseApp
{
public:
  MyNewAppTestApp(InputParameters parameters);
  virtual ~MyNewAppTestApp();

  static void registerApps();
  static void registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs = false);
};

#endif /* MY_NEW_APPTESTAPP_H */
