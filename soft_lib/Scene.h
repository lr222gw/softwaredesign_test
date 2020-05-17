#pragma once

#include <string>
#include <vector>

#include "GameObject.h"
#include "GameElement.h"

class Scene : public GameElement {
private: 
   //std::vector<GameObject> gameObjects;
   std::vector<GameElement*> gameObjects;
   std::string description; 
public:
   Scene() {}
   //Scene(std::vector<GameObject> gameObjects)  {
   Scene(std::vector<GameElement*> gameObjects, std::string name, std::string description)
   :GameElement(name){
      this->gameObjects = gameObjects;
      this->description = description;
   }
   std::string getDescription() { return description; }

   std::string listAvailableElements();
   bool isAvailable(std::string gameElementName);
   bool isGameObject(std::string gameElementName);
};