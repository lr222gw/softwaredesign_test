#pragma once

#include <string>
#include "Character.h"
#include "InputSanitiser.h"

class CharacterInterface {
   Character*           currentActive;
   InputSanitiser       mySanitiser;

public:

   CharacterInterface*  create(std::string theCharacter); //Constructor

   std::string          sendQuery();
   std::string          endConversation();

   std::string          activate();


};