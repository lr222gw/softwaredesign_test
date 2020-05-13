#pragma once

#include "GameObject.h"
#include <string>
#include <vector>

#include <iostream>

class GameObjectRepository {

   std::vector<GameObject*> obj_list;

public:
   GameObject* obj_Latest;
   GameObjectRepository() {

      //TODO: Replace dummy code with a real database
      //This is dummy code... 
      Look* dummy_type = new Look();
      std::vector<InteractionType*> gameobj_interactions;
      
      gameobj_interactions.push_back(dummy_type);
      GameObject * dummy_Obj = new GameObject("Dummy", gameobj_interactions);
      
      obj_list.push_back(dummy_Obj);
      obj_Latest = dummy_Obj;
      std::cout  << "Added dummy_obj to Obj_list: " << obj_Latest->getid() << std::endl;
   }

   //GameObjectRepository(const GameObjectRepository& cpy) {
   //   this->obj_Latest = cpy.obj_Latest;
   //   
   //   for (auto obj : cpy.obj_list) {
   //      this->obj_list.push_back(obj);
   //   }       
   //}

   ~GameObjectRepository() {
      for (auto o : obj_list ) {
         if (o != nullptr) {
            delete o;
         }
      }
   }

   bool getGameObject(std::string gameObjectName, GameObject *gameobj);



};