#pragma once
#include <string>

class GameElement {
protected:
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
