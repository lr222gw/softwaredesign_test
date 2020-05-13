#include "pch.h"
#include "GameObjectRepository.h"
#include <assert.h>

#include <iostream>

bool GameObjectRepository::getGameObject(std::string gameObjectName, GameObject* gameobj)
{
   if (gameObjectName == NULL_ID) {
      assert(gameObjectName == NULL_ID && "GameObjectRepository::getGameObject: Not allowed to ask for object with ID NULL_ID!");
   }
         
   for (auto obj : this->obj_list) {
      
      if (obj != nullptr) {         
      
         if (obj->getid() == gameObjectName) {
            
            (*gameobj) = *obj;            
            return true;
         }
      }      
   }
   return false;
}
