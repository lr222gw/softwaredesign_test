#pragma once
#include <vector>
#include <string>
#include "Character.h"

#include <iostream>  //basic testing



class PhoneBook {
   std::vector<Character*> contacts;
   bool contactDoesNotExist(std::string contact_toCheck);
public:
   PhoneBook() {
      
   }
   void addContact(Character* newContact) {
      
      if (contactDoesNotExist(newContact->getName())) {
         contacts.push_back(newContact);
      }
   };
   Character* getContactMethod(std::string theCharacter); //Check if we can Call character, i.e. player added character to phonebook..
};