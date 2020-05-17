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
      Look    *Look_Type       = new Look(); 
      TurnOn  *TurnOn_Type     = new TurnOn(); 
      TurnOff *TurnOff_Type    = new TurnOff();
      Taste   *Taste_Type      = new Taste(); 
      Move    *Move_Type       = new Move();

      //Prepare Demo Objects
      std::vector<InteractionType*> dummy_typeList{Look_Type, Taste_Type};
      GameObject *dummy = new GameObject("Dummy", dummy_typeList, "Dummy object, just a dummy...");
      
      //Prepare Object; lamp 
      std::vector<InteractionType*> lamp_typeList{ Look_Type, Move_Type };
      GameObject *lamp = new GameObject("Lamp", lamp_typeList, "It's an old lamp, there's a on-off-switch..." ,false );

      //Prepare Object Frog
      std::vector<InteractionType*> frog_typeList{ Look_Type, Taste_Type };
      GameObject *frog = new GameObject("Frog", frog_typeList, "A Yellow frog, might be tasty...");

      //Prepare Object wallet
      std::vector<InteractionType*> wallet_typeList{ Look_Type };
      GameObject* wallet = new GameObject("Wallet", wallet_typeList, "My wallet, it's as empty as my heart...");

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
      std::vector<GameObject*> objlist{
         dummy, lamp, frog, wallet
      };
      GameObjectRepository* objrep = new GameObjectRepository(objlist);

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
         parseInput(input_str);


         //if(input_str[0] == '\\'){ // If first symbol is a '\' then it's a command...
         //   if (input_str == "\\secretary") {
         //      dointerview = true;
         //      //CharacterInterface *character_interface = game->initiateConversation(SECRETARY);
         //      doInterviewScenario(SECRETARY);
         //   }else if (input_str ==  "\\townsquare") {
         //      enterScene("townsquare");
         //      /*std::string input = ""; 
         //      while (input != EXIT_STR && input != "\\leave") {
         //         Scene* s = game->getScene("townsquare");
         //         UserInterface_IO::out_scene(s);
         //         input = UserInterface_IO::in();
         //      }*/
         //      
         //   }
         //   else if (input_str ==  "\\inventory" ) {
         //      std::string input = "";
         //      while (input != EXIT_STR && input != "\\leave") {
         //         Scene* s = game->getScene("inventory");
         //         
         //         UserInterface_IO::out_scene(s);
         //         input = UserInterface_IO::in();

         //         

         //      }

         //   }
         //}
      }      
   }

   std::string parseInput(std::string in) {

      //is it a default command
      if (in == "\\secretary") {
         doInterviewScenario(SECRETARY);
      }
      
      //We won't allow transition from the Inventory Scene to other scnees... Player must use \back
      //We won't allow transition during an interview or interaction with object...
      //We won't allow transistion from currentscene to a new instance of currentscene...
      bool illegal_scenetransition = true;
      if (this->game->getCurrentScene() != nullptr) { 
         if (game->getCurrentScene()->getName() == "inventory")   { illegal_scenetransition = false; }
         if (game->getCurrentScene()->getName() == &in[1])        { illegal_scenetransition = false; }
      }
      //else { illegal_scenetransition = false; }

      if (illegal_scenetransition && (*game->getCurrentGameObject())->getName() == NULL_ID) {

         //if (in == "\\inventory") { //inventory is counted as a scene, it will be treated amongst the other scenes...
            //enterScene("inventory");
         //}

         //Scenes
         if (in[0] == '\\') {
            std::string fixed = &in[1];
            Scene* temp = this->game->getScene(fixed);
            if (temp != nullptr) {
               enterScene(fixed);
            }
         }
      }
      

      if (this->game->getCurrentScene() != nullptr) {
         //Objects in currentScene
         if (this->game->getCurrentScene()->isAvailable(in)) {
            interactWithObject(in);
         }
      }
      
      

      return "done";
   }

   std::string interactWithObject(std::string objet) {

      std::string input = "";
      while (input != EXIT_STR && input != "\\leave"){

         std::vector<InteractionType*> interactionTypes = this->game->selectGameObject(objet);
         UserInterface_IO::out_object(*this->game->getCurrentGameObject(), interactionTypes);
         input = UserInterface_IO::in();
         parseInput(input);
         if (input == "\\back") {
            enterScene(this->game->getCurrentScene()->getName());
         }
      }

      return "Done";
   }

   std::string enterScene(std::string scenename) {

      std::string input = "";
      std::string prevScene = this->game->getCurrentScene()->getName();
      while (input != EXIT_STR && input != "\\leave") {
         Scene* s = game->getScene(scenename);
         if (s != nullptr) {

            UserInterface_IO::out_scene(s);
            input = UserInterface_IO::in();
            parseInput(input);
            /*if (input == "\\back" && game->getCurrentScene()->getName() == "inventory") {
               enterScene(prevScene);
            }*/
         }
         else { return "invalid scene"; }
      }
      game->unset_currentScene();
      return "Done";
   }

   std::string doInterviewScenario(std::string character_name) {
      
      CharacterInterface* character_interface = game->initiateConversation(character_name);
      if (character_interface == nullptr) {
         std::cout << "Character_interface was null; Character '" << character_name << "' Not found" << std::endl;
      }

      std::string response;
      while (response != EXIT_STR) {
         std::string input_str = UserInterface_IO::in();
         //if (input_str == "\\townsquare") { break; }
         response = character_interface->sendQuery(input_str);
         if (response != EXIT_STR) { UserInterface_IO::out(response); }
      }
      return "done";
   }

};