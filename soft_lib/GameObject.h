#pragma once

#include <string>

#include "GameElement.h"
#define NULL_ID "#empty#"

class GameObject : public GameElement {
   std::string obj_id;

public:
   GameObject() {
      obj_id = NULL_ID;
   }

   GameObject(std::string obj_id) {
      this->obj_id = obj_id;
   }

   std::string getid();

   void listInteractionTypes();
   void startInteraction(std::string theInteractionType);
   void listCurrentInteractionOptions(std::string);
   void setCurrentInteractionOptions(std::string the_options);
   void startCurrentInteraction();
   void abortCurrentInteraction();


};
