#pragma once
#include "InteractionOption.h"
#include <vector>

//#define NULL_OPTION "#no_option#"
#define NULL_OPTION ""



class InteractionType {
protected:
   std::string                      actionName;
   std::vector<InteractionOption*>  optionList;
   std::string                      typeState;
   
public:
   InteractionType() {  //Should not need a constructor! 
      
   }
   std::string                      getActionName()      { return actionName; }
   std::vector<InteractionOption*>  getActionOptions()   { return optionList; }

   virtual std::string action(std::string obj_name, std::string option) = 0;
   std::string getTypeState() { return typeState; };
};

class Move : public InteractionType {
public:
   Move() {
      this->actionName = "Move";
            
      optionList.push_back(new carefully());
      optionList.push_back(new forcefully());
      
   }

   std::string action(std::string obj_name, std::string option = NULL_OPTION) override {
      return "You moved " + obj_name + " " + option;
   }
};

class Open : public InteractionType {
public:
   Open() {
      this->actionName = "Open";

      optionList.push_back(new carefully());
      optionList.push_back(new forcefully());
      typeState = "Closed";
   }
   std::string action(std::string obj_name, std::string option = NULL_OPTION) override {
      typeState = "Opened";
      return "You opened " + obj_name + " " + option;
   }
};

class ToggleOnOff : public  InteractionType {
public:

   ToggleOnOff() {
      this->actionName = "TurnOff";
      //optionList.push_back(new carefully());
      //optionList.push_back(new forcefully());
      typeState = "is On";
   }
   std::string action(std::string obj_name, std::string option = NULL_OPTION) override {
      
      if (typeState == "is Off") {

         this->actionName = "TurnOff";
         typeState = "is On";
         return "You turned On " + obj_name +" "+ option;
      }
      else {

         typeState = "is Off";
         this->actionName = "TurnOn";
         return "You turned off " + obj_name +" "+ option;
      }
   }
};

//class TurnOn : public InteractionType {
//public:
//   TurnOn() {
//      this->actionName = "TurnOn";
//      optionList.push_back(new carefully());
//      optionList.push_back(new forcefully());
//      typeState = "is Off";
//   }
//   std::string action(std::string obj_name, std::string option = NULL_OPTION) override {
//      typeState = "is On";
//      return "You turned on " + obj_name + " " + option;
//
//   }
//};

class PickUp : public  InteractionType {
public:
   PickUp() {
      this->actionName = "PickUp";
   }

   std::string action(std::string obj_name, std::string option = NULL_OPTION) override {
      return "You picked up " + obj_name + " " + option;

   }
};

class Drop : public InteractionType {
public:
   Drop() {
      this->actionName = "Drop";
   }
   std::string action(std::string obj_name, std::string option = NULL_OPTION) override {
      return "You dropped " + obj_name + " " + option;

   }
};

class Taste : public InteractionType {
public:
   Taste() {
      this->actionName = "Taste";
      typeState = "not yet tasted...";
   }
   std::string action(std::string obj_name, std::string option = NULL_OPTION) override {
      typeState = "has tasted it";
      return "You tasted " + obj_name + " " + option;

   }
};

class Look : public InteractionType {
public:
   Look() {
      this->actionName = "Look";
      optionList.push_back(new closely());
      
      
   }
   std::string action(std::string obj_name, std::string option = NULL_OPTION) override {
      return "You looked at " + obj_name + " " + option;

   }
};
