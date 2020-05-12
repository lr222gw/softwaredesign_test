#include "pch.h"
#include "Game.h"
#include <assert.h>

std::string Game::getStr()
{
   return this->test;
}

InteractionType* Game::selectGameObject(std::string name)
{
   bool result = currentScene.isAvailable(name);

   if (result) {
      GameObject gameObj;
      bool gotObj = this->myGameObjects.getGameObject(name, &gameObj);      
      if (gameObj.getid() != NULL_ID) {

      }
      else {
         assert(false && "Game::selectGameObject: myGameObjects.getGameObject() returned NULL_ID!");
      }

   }

   return nullptr;
}


InteractionOptions* Game::selectInteraction(GameObject theGameObject, std::string theInteraction)
{
   return nullptr;
}



bool Game::setInteractionOptions(std::string theOptions)
{
   return false;
}

//void Game::startInteraction()
//{
//}

void Game::abortInteraction()
{
}

GameElement Game::go()
{
   this->test = "fofo";
   return GameElement();
}