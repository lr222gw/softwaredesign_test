#pragma once

#pragma once

#include <string>

#include "Scene.h"
#include "GameObjectRepository.h"
#include "InteractionType.h"
#include "InteractionOptions.h"

class Game {

private:
   Scene                currentScene;
   Scene                playerInventory;
   GameObjectRepository myGameObjects;

   std::string          test;

public:
   Game() {}
   Game(Scene inventory, Scene current, GameObjectRepository db)
   {
      playerInventory = inventory;
      currentScene = current;
      myGameObjects = db;
   }

   std::string getStr();

   InteractionType* selectGameObject(std::string name);
   InteractionOptions* selectInteraction(GameObject theGameObject, std::string theInteraction);
   bool setInteractionOptions(std::string theOptions);
   void startInteraction();
   void abortInteraction();

   GameElement go();




};

//InteractionType* Game::selectGameObject(std::string name)
//{
//   return nullptr;
//}