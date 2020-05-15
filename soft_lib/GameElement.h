#pragma once
#include <string>

class GameElement {

   std::string name;
public:

   GameElement() {
   }
   GameElement(std::string name ) 
   {
      this->name = name;
   }

   std::string getName() { return name; }



};
