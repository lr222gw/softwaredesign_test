#include "pch.h"
#include "CharacterRepository.h"

bool CharacterRepository::getCharacter(std::string theCharacter, Character** character)
{
   auto ptr = getInstance();
   bool success = false;
   for(auto ch : ptr->char_list){
      if (ch->getName() == theCharacter) {
         *character = ch;   //!TODO: make sure this should not be ' *character = *ch;' 
         //! Sending in a double pointer was what I wanted to do....
         return true;
      }
   }
   return false;
}
