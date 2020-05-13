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
      //GameObject* gameObj;// = nullptr;
      GameObject gameObj;
      std::cout << "Before:myGameObjects.getGameObject()" << std::endl;
      bool gotObj = this->myGameObjects->getGameObject(name, &gameObj);      //GAME OBJ is NULL even after!!! 
      std::cout << "After:myGameObjects.getGameObject()" << std::endl;
      
      //if (gameObj->getid() != NULL_ID) { //Since this is not allowed... SHOULD NOT BE HERE! 
      if(gotObj){
         //interactionList  = gameObj->listInteractionTypes();
         interactionList  = gameObj.listInteractionTypes();
         return interactionList;
      }
      else {
         //assert(false && "Game::selectGameObject: myGameObjects.getGameObject() returned NULL_ID!");
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