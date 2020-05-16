#pragma once

#include <string>
#include <vector>

#include "GameObject.h"
#include "GameElement.h"

class Scene : public GameElement {
private: 
   //std::vector<GameObject> gameObjects;
   std::vector<GameElement*> gameObjects;
   
public:
   Scene() {}
   //Scene(std::vector<GameObject> gameObjects)  {
   Scene(std::vector<GameElement*> gameObjects)  {
      this->gameObjects = gameObjects;
   }

   void listAvailableElements();
   bool isAvailable(std::string gameElementName);
   bool isGameObject(std::string gameElementName);
};