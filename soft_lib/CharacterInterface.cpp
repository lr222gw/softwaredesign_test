#include "pch.h"
#include "CharacterInterface.h"

std::string CharacterInterface::activate()
{
   return currentActive->getInitialGreeting();
}
