#pragma once

#include "GameObject.h"
#include <string>
#include <vector>

class GameObjectRepository {

   std::vector<GameObject> obj_list;

public:
   GameObjectRepository() {

      //TODO: Replace dummy code with a real database
      //This is dummy code... 
      GameObject dummy("Dummy");
      
      obj_list.push_back(dummy);

   }

   bool getGameObject(std::string gameObjectName, GameObject *gameobj);



};