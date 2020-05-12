#pragma once

#include "GameObject.h"
#include <string>

class GameObjectRepository {
public:
   GameObjectRepository() {
   }

   GameObject getGameObject(std::string gameElementName);



};