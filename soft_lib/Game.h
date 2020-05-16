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
      std::cout << "A" << std::endl;
      playerInventory   = nullptr;
      currentScene      = nullptr;
      myGameObjects     = nullptr;

      currentGameObject    = new GameObject(); //TODO NULL_ID? 
      playerPhoneBook      = new PhoneBook();
      
   }
   Game(Scene* inventory, Scene* current,  GameObjectRepository* go_db)
      : Game()
   {
      std::cout << "B" << std::endl;
      playerInventory = inventory;
      currentScene = current;
      myGameObjects = go_db;

      //Create Secretary, add to contacts + GameObjectRepository
      Secretary* secretary = new Secretary();
      playerPhoneBook->addContact(secretary);
      
      CharacterRepository::insertCharacter(secretary);
      
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