#include "pch.h"
#include "CharacterInterface.h"

#include "UserInterface_IO.h"

void CharacterInterface::activate()
{
   std::string greeting = currentActive->getInitialGreeting();

   UserInterface_IO::out(greeting);
   

   //TODO:!! We should send the output to the UserInterface_IO...
}
