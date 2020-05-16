#pragma once

#include <string>
#include "Character.h"

#define SECRETARY "Dr. Secretary"

class Secretary : public Character{


   void loadScene(); //Any scene; inventory, ingame scene, testscene...

public: 
   Secretary() 
      :Character("Dr. Secretary", "Hello, I'm Dr. Secretary.") 
   {}

   
   

};