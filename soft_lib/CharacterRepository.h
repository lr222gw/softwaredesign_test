#pragma once

#include "Character.h"
#include <string>
#include <vector>

#include <iostream>

class CharacterRepository { //Singleton

   static CharacterRepository* theInstance;

   std::vector<Character*> char_list;

   CharacterRepository() {

      //TODO: Replace dummy code with a real database
      //This is dummy code... 

      Character *Secretary = new Character(
         "Secretary", 
         "Hello, i'm your Secretary. Type stuff to do stuff...");
      

      char_list.push_back(Secretary);

   }
public:
   //Character* char_Latest;

   static CharacterRepository* getInstance() {

      if (theInstance == nullptr) {
         theInstance = new CharacterRepository();
      }
      return theInstance;

   }

   ~CharacterRepository() {
      for (auto o : char_list) {
         if (o != nullptr) {
            delete o;
         }
      }
   }

   bool getCharacter(std::string theCharacter, Character* character);




};