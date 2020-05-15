#include "pch.h"
#include "Scene.h"


void Scene::listAvailableElements()
{
}

bool Scene::isAvailable(std::string gameElementName)
{
   
   for (auto obj : this->gameObjects) {
      if (obj.getid() == gameElementName) {
         return true;
      }
   }
   

   return false;
}

bool Scene::isGameObject(std::string gameElementName)
{
   return false;
}
