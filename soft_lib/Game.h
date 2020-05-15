#pragma once

#pragma once

#include <string>

#include "Scene.h"
#include "GameObjectRepository.h"
#include "InteractionType.h"
#include "InteractionOption.h"
#include "PhoneBook.h"
#include "Secretary.h"
#include "CharacterInterface.h"

class Game {

private:
   Scene                *currentScene;
   Scene                *playerInventory;
   GameObjectRepository *myGameObjects;

   GameObject           *currentGameObject;

   PhoneBook            *playerPhoneBook;
   
   //std::string          test;

public:
   Game() {
      playerInventory = nullptr;
      currentScene = nullptr;
      myGameObjects = nullptr;

      currentGameObject = new GameObject(); //TODO NULL_ID? 
      playerPhoneBook = new PhoneBook();
      Secretary* secretary = new Secretary();
      playerPhoneBook->addContect(secretary);
   }
   Game(Scene* inventory, Scene* current,  GameObjectRepository* db)
      : Game()
   {
      playerInventory = inventory;
      currentScene = current;
      myGameObjects = db;   
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

   CharacterInterface* initiateConversation(std::string theCharacter);





};

//InteractionType* Game::selectGameObject(std::string name)
//{
//   return nullptr;
//}