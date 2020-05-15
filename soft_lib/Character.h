#pragma once

#include "GameElement.h"

class Character : public GameElement {
   std::string greeting;
public:
   Character(std::string name, std::string greeting)
      :GameElement(name), greeting(greeting){}

   std::string getInitialGreeting() { return greeting; }

   std::string query(std::string theQuery);


};