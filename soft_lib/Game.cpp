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
      GameObject **gameObj = getCurrentGameObject();
      
      //bool gotObj = this->myGameObjects->getGameObject(name, &gameObj);      
      bool gotObj = this->myGameObjects->getGameObject(name, *gameObj);      
                 
      if(gotObj){
         
         //interactionList  = gameObj.listInteractionTypes();
         //(*gameObj)->listInteractionTypes();
         interactionList  = (*gameObj)->listInteractionTypes();
         setCurrentGameObject(*gameObj);
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
      //this->setCurrentGameObject(theGameObject); <-- This is done in SelectGameObject....
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

CharacterInterface* Game::initiateConversation(std::string theCharacter)
{

   CharacterInterface* characterInterface = nullptr;
   //is available in scene
   if (currentScene->isAvailable(theCharacter) ||theCharacter == SECRETARY)  {// todo: The Secretary should be available in any scene... alt. let xer be part of the construction of all scenes... (more coupled tough...)

      //getCharacter from PhoneBook
      Character* currentChar = this->playerPhoneBook->getContactMethod(theCharacter); //todo: Does not really have to return a Character pointer...
      
      if (currentChar != nullptr) { //todo: Note that, sometimes we dont need to contact somone through Pohne.. what if we could talk to them? Is it necessary to have them in our contact book then? 

         //Create a CharacterInterface for the given Character
         //CharacterInterface curr_characterInterface = 
         characterInterface = new CharacterInterface(theCharacter);
         
         
         //Activate interview
         
         characterInterface->activate();
      }
   }

   return characterInterface;
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