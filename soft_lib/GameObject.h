#pragma once

#include <string>

#include "GameElement.h"
#include "InteractionType.h"
#include <vector>

#define NULL_ID "#empty#"

enum status {
   True,
   False,
   None 
};

class GameObject : public GameElement {
   //std::string obj_id;

   std::vector<InteractionType*> interactionTypes;
   InteractionType*              currentInteraction;
   InteractionOption*            currentOption;

   std::string                   description;

   bool isOn_state;  

public:
   GameObject():GameElement(NULL_ID){
      //obj_id = NULL_ID;
      currentInteraction      = nullptr;
      currentOption           = nullptr;

      isOn_state              = false;
   }

   GameObject(std::string obj_id, std::vector<InteractionType*> interactionTypes, std::string desc, bool isOn = false) 
      : GameElement(obj_id)
   {
      //this->obj_id = obj_id;
      //this->name = obj_id;

      this->interactionTypes  = interactionTypes;
      currentInteraction      = nullptr;
      currentOption           = nullptr;
      description             = desc;
      isOn_state = isOn;
      
   }

   std::string getDescription() { return description; }

   //std::string getid();
   InteractionType* getCurrentInteraction() { return currentInteraction; }
   void setCurrentInteraction(InteractionType* curr) { currentInteraction = curr; }

   std::vector<InteractionType*> listInteractionTypes();
   bool startInteraction(std::string theInteractionType);
   std::vector<InteractionOption*> listCurrentInteractionOptions();
   void setCurrentInteractionOptions(std::string the_options);
   std::string startCurrentInteraction();
   void abortCurrentInteraction();


};
