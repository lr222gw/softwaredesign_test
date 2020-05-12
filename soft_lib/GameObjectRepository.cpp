#include "pch.h"
#include "GameObjectRepository.h"


bool GameObjectRepository::getGameObject(std::string gameObjectName, GameObject* gameobj)
{
   
   for (auto obj : this->obj_list) {
      if (obj.getid() == gameObjectName) {
         *gameobj = obj;
         return true;
      }
   }
   return false;
}
