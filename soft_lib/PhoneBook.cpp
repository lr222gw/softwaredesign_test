#include "pch.h"
#include "PhoneBook.h"


bool PhoneBook::contactDoesNotExist(std::string contact_toCheck)
{
   bool doesNotExist = true;
   for (auto contact : contacts) {
      if (contact->getName() == contact_toCheck) { doesNotExist = false; }
   }
   return doesNotExist;
}

Character* PhoneBook::getContactMethod(std::string theCharacter)
{
   Character* contactCharacter = nullptr;
   if (contactDoesNotExist(theCharacter) == false) { // Checks if Contact exists...
      for (auto contact : contacts) {
         if (contact->getName() == theCharacter) {
            std::cout << "returns Contact (in case of error...)" << std::endl;
            return contact; // <- might be wrong pointer! alternatively *contact... I think
         }
      }
   }
   return contactCharacter;
}
