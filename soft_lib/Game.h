#pragma once

#pragma once

#include <string>

#include "Scene.h"
#include "GameObjectRepository.h"
#include "InteractionType.h"
#include "InteractionOption.h"

class Game {

private:
   Scene                *currentScene;
   Scene                *playerInventory;
   GameObjectRepository *myGameObjects;

   GameObject           *currentGameObject;
   
   //std::string          test;

public:
   Game() {}
   Game(Scene* inventory, Scene* current,  GameObjectRepository* db)
   {
      playerInventory = inventory;
      currentScene = current;
      myGameObjects = db;
      currentGameObject = new GameObject(); //TODO NULL_ID? 
   }


   //std::string getStr();
   GameObject* getCurrentGameObject() { return currentGameObject; }
   void setCurrentGameObject(GameObject* curr) { currentGameObject = curr; }
   

   std::vector<InteractionType*> selectGameObject(std::string name);
   std::vector<InteractionOption*> selectInteraction(GameObject *theGameObject, std::string theInteraction); //TODO: Change to std::vector<InteractionType>
   void setInteractionOptions(std::string theOptions);
   std::string startInteraction();
   void abortInteraction();

   //GameElement go();

   void initiateConversation(std::string theCharacter);





};

//InteractionType* Game::selectGameObject(std::string name)
//{
//   return nullptr;
//}