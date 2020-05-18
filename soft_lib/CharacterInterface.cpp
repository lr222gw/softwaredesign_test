#include "pch.h"
#include "CharacterInterface.h"



std::string CharacterInterface::sendQuery(std::string theQuery)
{
   std::string response = "DUMMDUMM"; 

   std::string safeQuery = this->mySanitiser.sanitiseInput(theQuery);

   response = this->currentActive->query(safeQuery);

   return response;
}

GameObject* CharacterInterface::promptItem() {
   GameObject * gift = this->currentActive->checkTradeSlot();

   return gift;   
}

void CharacterInterface::close_Item() {
   this->currentActive->closeTradeSlot();
   
}


void CharacterInterface::activate()
{
   //std::string greeting = currentActive->getInitialGreeting();

   
   
   UserInterface_IO::out(currentActive->present_by_state());
  
   
   

   //TODO:!! We should send the output to the UserInterface_IO...
}
