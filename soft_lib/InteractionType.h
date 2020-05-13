#pragma once

class InteractionType {
protected:
   std::string actionName;
public:
   InteractionType() {  //Should not need a constructor! 
   }
   std::string getActionName() { return actionName; }
   virtual std::string action() = 0;
};

class Move : public InteractionType {
public:
   Move() {
      this->actionName = "Move";
   }

   std::string action() override{      
      return "You moved";
   }
};

class Open : public InteractionType {
public:
   Open() {
      this->actionName = "Open";
   }
   std::string action() override {
      return "You opened";
   }
};

class TurnOff : public  InteractionType {
public:

   TurnOff() {
      this->actionName = "Turn Off";
   }
   std::string action() override {
      return "You turned off";

   }
};

class TurnOn : public InteractionType {
public:
   TurnOn()  {
      this->actionName = "Turn On";
   }
   std::string action() override {
      return "You turned on";

   }
};

class PickUp : public  InteractionType {
public:
   PickUp()  {
      this->actionName = "Pick Up";
   }

   std::string action() override {
      return "You picked up";

   }
};

class Drop : public InteractionType {
public:
   Drop() {
      this->actionName = "Drop";
   }
   std::string action() override {
      return "You dropped";

   }
};

class Taste : public InteractionType {
public:
   Taste() {
      this->actionName = "Taste";
   }
   std::string action() override {
      return "You tasted";

   }
};

class Look : public InteractionType {
public:
   Look() {
      this->actionName = "Look";
   }
   std::string action() override {
      return "You looked at";

   }
};
