#include "pch.h"
#include "Game.h"
#include <assert.h>

#include <iostream>
std::string Game::getStr()
{
   return this->test;
}

std::vector<InteractionType*> Game::selectGameObject(std::string name)
{
   bool result = currentScene->isAvailable(name);
   std::vector<InteractionType*> interactionList;

   if (result) {
      
      GameObject gameObj;
      
      bool gotObj = this->myGameObjects->getGameObject(name, &gameObj);      
                 
      if(gotObj){
         
         interactionList  = gameObj.listInteractionTypes();
         return interactionList;
      }
      else {
         assert(false && "Game::selectGameObject: myGameObjects.getGameObject() returned NULL_ID!");
      }

   }

   return interactionList;
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