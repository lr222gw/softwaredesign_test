#pragma once

#include <string>
#include "Character.h"
#include "InputSanitiser.h"
#include "CharacterRepository.h"

#include <iostream>

class CharacterInterface {
   Character*           currentActive;
   InputSanitiser       mySanitiser;

public:
   CharacterInterface(std::string theCharacter) {
      CharacterRepository* theInstance = CharacterRepository::getInstance();
      //Character** ch_to_get;
      bool success = theInstance->getCharacter(theCharacter, &currentActive);
      std::cout << "yes";
   }
   //CharacterInterface*  create(std::string theCharacter); //Constructor

   std::string          sendQuery();
   std::string          endConversation();

   std::string          activate();


};