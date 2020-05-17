#pragma once
#include <iostream>
#include <string>

#include "Game.h"

#include "UserInterface_IO.h"


//#define EXIT_STR  "exit"
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
      Character *balto = new Character("Balto", "Tjena! Name's Balto. what do you want?...");
      
      
      //!Add Objects to ObjectVector for scenes
      //std::vector<GameObject> testScene_objects{ dummy, lamp, frog, balto }; //NOTE; Characters + objects
      std::vector<GameElement*> testScene_objects{ dummy, lamp, frog, balto }; //NOTE; Characters + objects
      Scene *test_scene = new Scene(testScene_objects, "townsquare", "Karlskrona townsquare, 'this is a generic description of a scene'...");

      std::vector<GameElement*> inventoryScene_objects{wallet};
      Scene *inventory_scene = new Scene(inventoryScene_objects, "inventory", "Your backpack, it can fit about anything.");

      std::vector<GameElement*> startScene_objects{}; //TODO:: What should we put here?... Nothing? Or only Secretary?
      Scene *start_scene = new Scene(startScene_objects, "start", "generic startscene description");

      std::vector<Scene*> * scenes = new std::vector<Scene*>{ start_scene, inventory_scene, test_scene };
      
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

      game = new Game(inventory_scene, start_scene, objrep, scenes);
      
   }

   void startGame() {
      

      bool dointerview = true;
      bool gameLoop = true;

      doInterviewScenario(SECRETARY);

      while (gameLoop) {

         //This is dummdumm code for Presentation of the Mission....
         if (dointerview) {
            dointerview = false;
            //Query loop 
            
         }

         //Always present options
         UserInterface_IO::out("\\townsquare, \\secretary, \\inventory"); 
         //Iput... 
         std::string input_str = UserInterface_IO::in();

         if(input_str[0] == '\\'){ // If first symbol is a '\' then it's a command...
            if (input_str == "\\secretary") {
               dointerview = true;
               //CharacterInterface *character_interface = game->initiateConversation(SECRETARY);
               doInterviewScenario(SECRETARY);
            }else if (input_str ==  "\\townsquare") {
               std::string input = ""; 
               while (input != EXIT_STR) {
                  Scene* s = game->getScene("townsquare");
                  UserInterface_IO::out_scene(s);
                  input = UserInterface_IO::in();
               }
               
            }
            else if (input_str ==  "\\inventory") {
               std::string input = "";
               while (input != EXIT_STR) {
                  Scene* s = game->getScene("inventory");
                  UserInterface_IO::out_scene(s);
                  input = UserInterface_IO::in();
               }

            }
         }
      }      
   }

   std::string doInterviewScenario(std::string character_name) {
      
      CharacterInterface* character_interface = game->initiateConversation(character_name);
      if (character_interface == nullptr) {
         std::cout << "Character_interface was null; Character '" << character_name << "' Not found" << std::endl;
      }

      std::string response;
      while (response != EXIT_STR) {
         std::string input_str = UserInterface_IO::in();
         if (input_str == "\\townsquare") { break; }
         response = character_interface->sendQuery(input_str);
         if (response != EXIT_STR) { UserInterface_IO::out(response); }
      }
      return "done";
   }

};