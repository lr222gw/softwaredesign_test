#pragma once

#include <string>
#include "Character.h"

#define SECRETARY "Dr. Secretary"

class Secretary : public Character{


   void loadScene(); //Any scene; inventory, ingame scene, testscene...

public: 
   Secretary() 
      :Character("Dr. Secretary", "Hello, I'm Dr. Secretary.") 
   {
      //hardcoded for demo
     /* this->state = new character_state(
         "Mission",
         "You've been hired by mr.*Ceasar* to investigate a potential murder, the victims name is *Brutus*.\nYou should head to the crimescene, it's at the north corner of the *Town square*. You can't miss it.",
            std::vector<character_state*>{
                  new character_state("Ceasar",
                     "Ceasar is the owner of MegaCorp."),
                  new character_state("Brutus",
                     "We don't know much more about Brutus other than he was working for *MegaCorp*. Maybe you could Check if there's anything of interest at his officestall...",
                        std::vector<character_state*>{
                           "MegaCorp",
                           "It's a corperation owned by Ceasar Zalad. \n Their         office is located at the West corner of *Town               Square*. "
                        }
                     ),
                     new  character_state("Town square",
                     "You can navigate to Townsquare by typing \\townsqaure")
            }
         
         );*/

      
   }

   
   

};