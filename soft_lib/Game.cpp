#include "pch.h"
#include "Game.h"
#include <assert.h>

#include <iostream>
//std::string Game::getStr()
//{
//   return this->test;
//}

std::vector<InteractionType*> Game::selectGameObject(std::string name)
{
   bool result = currentScene->isAvailable(name);
   std::vector<InteractionType*> interactionList;

   if (result) {
      
      //GameObject gameObj;
      GameObject *gameObj = getCurrentGameObject();
      
      //bool gotObj = this->myGameObjects->getGameObject(name, &gameObj);      
      bool gotObj = this->myGameObjects->getGameObject(name, gameObj);      
                 
      if(gotObj){
         
         //interactionList  = gameObj.listInteractionTypes();
         interactionList  = gameObj->listInteractionTypes();
         setCurrentGameObject(gameObj);
         return interactionList;
      }
      else {
         assert(false && "Game::selectGameObject: myGameObjects.getGameObject() returned NULL_ID!");
      }

   }

   return interactionList;
}


std::vector<InteractionOption*> Game::selectInteraction(GameObject *theGameObject, std::string theInteraction)
{
   //GameObject* curr = getCurrentGameObject();
   std::vector<InteractionOption*> options;

   bool validPick = theGameObject->startInteraction(theInteraction);

   if (validPick) {
      options = theGameObject->listCurrentInteractionOptions();
      //this->setCurrentGameObject(theGameObject);
      this->setCurrentGameObject(theGameObject);
   }

   return options;
}



void Game::setInteractionOptions(std::string theOptions)
{
   this->currentGameObject->setCurrentInteractionOptions(theOptions);
}

std::string Game::startInteraction()
{
   
   std::string ret = this->currentGameObject->startCurrentInteraction();
   //std::cout << ret << std::endl;
   return ret;
}

//void Game::startInteraction()
//{
//}

//void Game::abortInteraction()
//{
//}

//GameElement Game::go()
//{
//   this->test = "fofo";
//   return GameElement();
//}