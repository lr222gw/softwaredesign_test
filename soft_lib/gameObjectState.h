#pragma once
#include <string>
#include<vector>
#include <tuple>
#include "InteractionOption.h"
#include "InteractionType.h"
//class StateHolder {
//   std::string state;
//   std::tuple<GameObjectState*, GameObjectState* > pair;
//   GameObjectState* currentState;
//public:
//   StateHolder(std::tuple<GameObjectState* , GameObjectState* > statePair) {
//      currentState = std::get<0>(statePair);      
//   }
//
//
//};

class GameObjectState {
protected:
   std::string state;
   std::vector<InteractionType*> interactionTypes;
   
public:
   GameObjectState() {
   }
   std::string getStateName() { return state; }
   //virtual GameObjectState* toggle() = 0;

};

class switchable : public GameObjectState {
public:
   InteractionType* current;
   bool on_bool; 
   TurnOn on;
   TurnOff off;
   switchable(bool on_b = false) {
      this->on_bool = on_b;
      current = &on;
   }
   std::string status() {
      if (on_bool) {
         return "is On";
      }
      else {
         return "is Off";
      }
   }
   std::string toggle() {
      if (on_bool) {
         current = &off;
         on_bool = false;
      }
      else {
         current = &on;
         on_bool = true;
      }
   }
};

class On_state : public GameObjectState {
public:
   GameObjectState* toggle() {}
};

class Off_state : public GameObjectState {
public:
   GameObjectState* toggle() {}
};