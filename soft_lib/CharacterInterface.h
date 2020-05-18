#pragma once

#include <string>
#include "Character.h"
#include "InputSanitiser.h"
#include "CharacterRepository.h"
#include "UserInterface_IO.h"

#include <iostream>

class CharacterInterface {
   Character*           currentActive;
   InputSanitiser       mySanitiser;

public:
   CharacterInterface(std::string theCharacter) {
      CharacterRepository* theInstance = CharacterRepository::getInstance();
      //Character** ch_to_get;
      bool success = theInstance->getCharacter(theCharacter, &currentActive);
      
   }
   //CharacterInterface*  create(std::string theCharacter); //Constructor

   std::string          sendQuery(std::string theQuery);
   GameObject*          promptItem();
   void                 close_Item();

   std::string          endConversation() {
      this->currentActive = nullptr;
      return "bye";
   }

   //std::string          activate();
   void                 activate();


};