#pragma once

#include <string>

#include "GameElement.h"
#include "InteractionType.h"
#include <vector>

#define NULL_ID "#empty#"

class GameObject : public GameElement {
   std::string obj_id;

   std::vector<InteractionType*> interactionTypes;

public:
   GameObject() {
      obj_id = NULL_ID;
   }

   GameObject(std::string obj_id, std::vector<InteractionType*> interactionTypes) {
      this->obj_id = obj_id;

      this->interactionTypes = interactionTypes;
      
   }

   std::string getid();

   std::vector<InteractionType*> listInteractionTypes();
   void startInteraction(std::string theInteractionType);
   void listCurrentInteractionOptions(std::string);
   void setCurrentInteractionOptions(std::string the_options);
   void startCurrentInteraction();
   void abortCurrentInteraction();


};
