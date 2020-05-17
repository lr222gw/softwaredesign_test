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
      /*if (this->isOn_state) {
         if (it->getActionName() != "TurnOn") {
            toret.push_back(it);
         }
      }
      else {
         if (it->getActionName() != "TurnOff") {
            toret.push_back(it);
         }
      }*/
      toret.push_back(it);
   }
   //return interactionTypes;
   return toret;
}

bool GameObject::startInteraction(std::string theInteractionType)
{
   /*if (this->isOn_state) {
      if (theInteractionType == "TurnOn") {
         return false;
      }
   }
   else {
      if (theInteractionType == "TurnOff") {
         return false;
      }
   }*/

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

std::string GameObject::currentInteractionOptions_status() {
   std::string result;
   if (this->currentOption != nullptr) {
      //result = "You selected " + this->currentOption->getOption();
      result = this->currentOption->getOption();
   }
   else {
      result = "No option was set.";
   }
   return result;
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
