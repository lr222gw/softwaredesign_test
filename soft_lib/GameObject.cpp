#include "pch.h"
#include "GameObject.h"

//std::string GameObject::getid()
//{
//   return obj_id;
//}

std::vector<InteractionType*> GameObject::listInteractionTypes()
{
   std::vector<InteractionType*> toret;               //Filter out invalid interactionTypes...
   for (auto it : this->interactionTypes ) {
      if (this->isOn_state) {
         if (it->getActionName() != "Turn On") {
            toret.push_back(it);
         }
      }
      else {
         if (it->getActionName() != "Turn Off") {
            toret.push_back(it);
         }
      }
   }
   //return interactionTypes;
   return toret;
}

bool GameObject::startInteraction(std::string theInteractionType)
{
   if (this->isOn_state) {
      if (theInteractionType == "Turn On") {
         return false;
      }
   }
   else {
      if (theInteractionType == "Turn Off") {
         return false;
      }
   }

   for (auto type  : this->listInteractionTypes()) {
      if (type->getActionName() == theInteractionType) {
         setCurrentInteraction(type);
         return true;
      }
   }
   return false;
}

std::vector<InteractionOption*> GameObject::listCurrentInteractionOptions()
{
   return currentInteraction->getActionOptions();
}

void GameObject::setCurrentInteractionOptions(std::string the_options)
{
   for (auto io : currentInteraction->getActionOptions()) {
      if (io->getOption() == the_options) {
         this->currentOption = io;
      }
   }
}

std::string GameObject::startCurrentInteraction()
{
   std::string actionString;
   if (currentInteraction != nullptr) {

      if (this->currentOption != nullptr) {

         //actionString = this->getCurrentInteraction()->action(this->obj_id, this->currentOption->getOption());
         actionString = this->getCurrentInteraction()->action(this->getName(), this->currentOption->getOption());
      }
      else {
         //actionString = this->getCurrentInteraction()->action(this->obj_id, "");
         actionString = this->getCurrentInteraction()->action(this->getName(), "");
      }
   }
   else {
      actionString = "You cant do that\n";
   }
   //TODO: Unset current object, currentType, currentOption

   return actionString;
}
