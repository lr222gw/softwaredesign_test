#include "pch.h"
#include "GameObjectRepository.h"
#include <assert.h>

#include <iostream>

bool GameObjectRepository::getGameObject(std::string gameObjectName, GameObject* gameobj)
{
   if (gameObjectName == NULL_ID) {
      assert(gameObjectName == NULL_ID && "GameObjectRepository::getGameObject: Not allowed to ask for object with ID NULL_ID!");
   }
      
   std::cout << "Before:Loop: " << gameObjectName << std::endl;
   for (auto obj : this->obj_list) {
      std::cout << "During:Loop: " << gameObjectName << std::endl;
      if (obj != nullptr) {
         
      std::cout << "During:Loop_insideIF: " << gameObjectName << std::endl;
         if (obj->getid() == gameObjectName) {
            std::cout << "Before:Assign gameobj = obj: " << gameObjectName << std::endl;
            gameobj = obj;
            std::cout << "Aftrer:Assign gameobj = obj: " << gameObjectName << std::endl;
            return true;
         }
      }
      std::cout << "During:Loop_OutSideIF: " << gameObjectName << std::endl;
   }
   return false;
}
