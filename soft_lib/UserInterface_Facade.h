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
      GameObject dummy("Dummy", dummy_typeList);
      
      //Prepare Object; lamp 
      std::vector<InteractionType*> lamp_typeList{ &Look_Type, &Move_Type };
      GameObject lamp("Lamp", lamp_typeList, false);

      //Prepare Object Frog
      std::vector<InteractionType*> frog_typeList{ &Look_Type, &Taste_Type };
      GameObject frog("Frog", frog_typeList); 

      //Prepare Object wallet
      GameObject wallet;
      std::vector<InteractionType*> wallet_typeList{ &Look_Type };
      
      //!Add Objects to ObjectVector for scenes
      std::vector<GameObject> testScene_objects{dummy, lamp, frog};
      Scene *test_scene = new Scene(testScene_objects);

      std::vector<GameObject> inventoryScene_objects{wallet};
      Scene *inventory_scene = new Scene(inventoryScene_objects);

      std::vector<GameObject> startScene_objects{}; //TODO:: What should we put here?... Nothing? Or only Secretary?
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
};