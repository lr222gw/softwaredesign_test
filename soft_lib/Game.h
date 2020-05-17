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

   std::vector<Scene*> *scenes;

public:
   Game() {
      
      playerInventory   = nullptr;
      currentScene      = nullptr;
      myGameObjects     = nullptr;

      currentGameObject    = new GameObject(); //TODO NULL_ID? 
      playerPhoneBook      = new PhoneBook();
      
   }
   Game(Scene* inventory, Scene* current, GameObjectRepository* go_db, std::vector<Scene*> *scens)
      : Game()
   {
      
      playerInventory = inventory;
      currentScene = current;
      myGameObjects = go_db;

      scenes = scens; 

      //Create Secretary, add to contacts + GameObjectRepository
      Secretary* secretary = new Secretary();
      playerPhoneBook->addContact(secretary);
      
      CharacterRepository::insertCharacter(secretary);
      
   }
   Scene* getScene(std::string name) {
      
      for (auto s : *scenes) { if (s->getName() == name) { currentScene = s; return s; } }
      return nullptr;
   }

   //std::string getStr();
   Scene* getCurrentScene() { return currentScene; }
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