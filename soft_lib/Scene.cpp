#include "pch.h"
#include "Scene.h"


std::string Scene::listAvailableElements()
{
   std::string elements = "[ ";
   int c = 0;
   for (auto o : this->gameObjects) {
      if (c  < 1) { elements += o->getName(); }
      else{ elements += ", " + o->getName(); }
      c++;
   }
   elements += " ]";
   return elements;
}

bool Scene::isAvailable(std::string gameElementName)
{
   
   for (auto obj : this->gameObjects) {
      if (obj->getName() == gameElementName) {
         return true;
      }
   }
   

   return false;
}

bool Scene::isGameObject(std::string gameElementName)
{
   return false;
}
