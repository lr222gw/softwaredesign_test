#include "pch.h"
#include "CharacterInterface.h"



std::string CharacterInterface::sendQuery(std::string theQuery)
{
   std::string response = "DUMMDUMM"; 

   std::string safeQuery = this->mySanitiser.sanitiseInput(theQuery);

   response = this->currentActive->query(safeQuery);

   return response;
}

void CharacterInterface::activate()
{
   std::string greeting = currentActive->getInitialGreeting();

   UserInterface_IO::out(greeting);
   

   //TODO:!! We should send the output to the UserInterface_IO...
}
