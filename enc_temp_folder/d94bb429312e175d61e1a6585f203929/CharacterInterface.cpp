#include "pch.h"
#include "CharacterInterface.h"

std::string CharacterInterface::activate()
{
   return currentActive->getInitialGreeting();

   //TODO:!! We should send the output to the UserInterface_IO...
}
