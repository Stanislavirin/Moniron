#include "emitterclass.h"
void EmitterClass::ImageChangeFunction()
{
     emit ImageChangeSignal();
}

void EmitterClass::MechanicsErrorFunction()
{
    emit MechanicsErrorSignal();
}

void EmitterClass::WidSend()
{
    emit WidSignal();
}
