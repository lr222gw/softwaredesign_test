#pragma once

#include "Character.h"
#include <string>
#include <vector>

#include <iostream>

class CharacterRepository { //Singleton

   //static CharacterRepository* theInstance;

   std::vector<Character*> char_list;

   CharacterRepository() {

      //TODO: Replace dummy code with a real database
      //This is dummy code... 

      /*Character *Secretary = new Character(
         "Secretary", 
         "Hello, i'm your Secretary. Type stuff to do stuff...");     */
      //char_list.push_back(Secretary);

   }
public:
   //Character* char_Latest;

   static CharacterRepository* getInstance() {

     //if (theInstance == nullptr) {
     //    theInstance = new CharacterRepository();
     //}
      static CharacterRepository* theInstance = new CharacterRepository();
      return theInstance;
   }

   static void insertCharacters(std::vector<Character*> characters) {
      auto ptr =  getInstance();
      for (auto character : characters) {
         ptr->char_list.push_back(character); //? Correct Pointer?...
         
      }
   }

   static void insertCharacter(Character* character) {
      auto ptr = getInstance();
      ptr->char_list.push_back(character); //? Correct Pointer?...
      
   }

   ~CharacterRepository() {
      for (auto o : char_list) {
         if (o != nullptr) {
            delete o;
         }
      }
   }

   //? Why would this work if it isnt static and above methods must be static
   bool getCharacter(std::string theCharacter, Character** character);

};