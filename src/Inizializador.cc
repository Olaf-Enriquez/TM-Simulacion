#include "Inizializador.hh"
#include "RunAction.hh"

action::action(){}
action::~action(){}

void action::BuildForMaster() const {

RunAction *Run = new RunAction();
SetUserAction(Run);

}

void action::Build() const {

generador_primario *generador1 = new generador_primario();
SetUserAction(generador1);

RunAction *Run = new RunAction();
SetUserAction(Run);

}
