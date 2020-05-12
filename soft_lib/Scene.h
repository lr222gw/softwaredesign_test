#pragma once

#include <string>
#include <vector>

#include "GameObject.h"
#include "GameElement.h"

class Scene : public GameElement {
private: 
   std::vector<GameObject> gameObjects;
   
public:
   Scene() {}
   Scene(std::vector<GameObject> gameObjects)  {
      this->gameObjects = gameObjects;
   }

   void listAvailableElements();
   bool isAvailable(std::string gameElementName);
   bool isGameObject(std::string gameElementName);
};