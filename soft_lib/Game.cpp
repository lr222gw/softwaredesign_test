#include "pch.h"
#include "Game.h"

std::string Game::getStr()
{
   return this->test;
}

InteractionType* Game::selectGameObject(std::string name)
{
   bool result = currentScene.isAvailable(name);

   if (result) {

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