#pragma once
#include <iostream>
#include <string>

#include "Game.h"

//This class is the Middleman between UserInterface (commandLine) and Business Logic  
class UserInterface_Facade { 
   Game *game;


public:
   UserInterface_Facade() {                        //Setting up a Demoscene...
      //create InteractionTypes for Objects
      Look    Look_Type; TurnOn  TurnOn_Type; TurnOff TurnOff_Type; Taste   Taste_Type; Move    Move_Type;

      //Prepare Demo Objects
      std::vector<InteractionType*> dummy_typeList{&Look_Type, &Taste_Type};
      GameObject *dummy = new GameObject("Dummy", dummy_typeList);
      
      //Prepare Object; lamp 
      std::vector<InteractionType*> lamp_typeList{ &Look_Type, &Move_Type };
      GameObject *lamp = new GameObject("Lamp", lamp_typeList, false);

      //Prepare Object Frog
      std::vector<InteractionType*> frog_typeList{ &Look_Type, &Taste_Type };
      GameObject *frog = new GameObject("Frog", frog_typeList);

      //Prepare Object wallet
      std::vector<InteractionType*> wallet_typeList{ &Look_Type };
      GameObject* wallet = new GameObject("Wallet", wallet_typeList);

      //Prepare a Some random Character.. : Balto 
      Character *balto = new Character("Balto", "ohoy! Name's Balto. Whut can er do fer ye?...");
      
      
      //!Add Objects to ObjectVector for scenes
      //std::vector<GameObject> testScene_objects{ dummy, lamp, frog, balto }; //NOTE; Characters + objects
      std::vector<GameElement*> testScene_objects{ dummy, lamp, frog, balto }; //NOTE; Characters + objects
      Scene *test_scene = new Scene(testScene_objects);

      std::vector<GameElement*> inventoryScene_objects{wallet};
      Scene *inventory_scene = new Scene(inventoryScene_objects);

      std::vector<GameElement*> startScene_objects{}; //TODO:: What should we put here?... Nothing? Or only Secretary?
      Scene *start_scene = new Scene(startScene_objects);
      
      //NOTE  NOTE NOTE //NOTE  NOTE NOTE //NOTE  NOTE NOTE 
      /*
         Game does should NOT store all the scenes... Only the first scene should be stored by game. 
         Player should be able to switch between scenes by communicating with the Secretary...
            THUS Secretary should be an object within every Scene... (Maybe not inventory...)
            THUS ...
      */
      //NOTE  NOTE NOTE //NOTE  NOTE NOTE //NOTE  NOTE NOTE 

      //Obj
      GameObjectRepository* objrep = new GameObjectRepository();

      game = new Game(inventory_scene, start_scene, objrep);
      
   }

   void startGame() {
      CharacterInterface* character_interface = game->initiateConversation(SECRETARY);
      if (character_interface == nullptr) {
         std::cout << "Character_interface was null; Character '"<< SECRETARY<<"' Not found" << std::endl;
      }
   }

};