#ifndef MOOSE_MAXAPP_H
#define MOOSE_MAXAPP_H

#include "MooseApp.h"

class MooseMaxApp;

template<>
InputParameters validParams<MooseMaxApp>();

class MooseMaxApp : public MooseApp
{
public:
  MooseMaxApp(const std::string & name, InputParameters parameters);
  virtual ~MooseMaxApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* MOOSE_MAXAPP_H */
