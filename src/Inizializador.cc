#include "Inizializador.hh"


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

EventAction *Event = new EventAction(Run);
SetUserAction(Event);

SteppingAction *Stepping = new SteppingAction(Event);
SetUserAction(Stepping);


}
