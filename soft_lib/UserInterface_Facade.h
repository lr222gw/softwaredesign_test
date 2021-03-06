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
      Look        *Look_Type           = new Look(); 
      //TurnOn     *TurnOn_Type           = new TurnOn(); 
      //TurnOff    *TurnOff_Type          = new TurnOff();
      ToggleOnOff *ToggleOnOff_type    = new ToggleOnOff();
      Taste       *Taste_Type          = new Taste(); 
      Move        *Move_Type           = new Move();

      //Prepare Demo Objects
      std::vector<InteractionType*> dummy_typeList{Look_Type, Taste_Type};
      GameObject *dummy = new GameObject("Dummy", dummy_typeList, "Dummy object, just a dummy...");
      
      //Prepare Object; lamp 
      //std::vector<InteractionType*> lamp_typeList{ Look_Type, Move_Type, TurnOn_Type, TurnOff_Type };
      std::vector<InteractionType*> lamp_typeList{ Look_Type, Move_Type, ToggleOnOff_type };
      GameObject *lamp = new GameObject("Lamp", lamp_typeList, "It's an old lamp, there's a on-off-switch..." );

      //Prepare Object Frog
      std::vector<InteractionType*> frog_typeList{ Look_Type, Taste_Type };
      GameObject *frog = new GameObject("Frog", frog_typeList, "A Yellow frog, might be tasty...");

      //Prepare Object wallet
      std::vector<InteractionType*> wallet_typeList{ Look_Type };
      GameObject* wallet = new GameObject("Wallet", wallet_typeList, "My wallet, it's as empty as my heart...");

      //Prepare object Phone, for balto...
      std::vector<InteractionType*> phone_typeList{ Look_Type };
      GameObject* phone = new GameObject("Phone", phone_typeList, "The phone seems to be broken...");

      //Prepare a Some random Character.. : Balto  
      character_state balto_state(
         "Free Phones",
         "Hi friend, I'll give you a phone. It's free!",
         std::vector<character_query>{
            character_query("Why", "I don't know! Here Take it!", phone)
         }
      );
      Character *balto = new Character("Balto", "Tjena! Name's Balto. what do you want?...", balto_state);
      
      CharacterRepository::insertCharacter(balto);
      
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
         dummy, lamp, frog, wallet, phone
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
         //Objects and Characters in currentScene
         if (this->game->getCurrentScene()->isAvailable(in)) {
            Character *h = new Character();
            
            if (CharacterRepository::getCharacter(in, &h)) {
               doInterviewScenario(in);
            }
            else {

               interactWithObject(in);
            }
         }
      }
      
      

      return "done";
   }

   std::string interactWithObject(std::string objet) {

      std::string input = "";
      while (input != EXIT_STR && input != "\\leave"){ //TODO:: using leave must cause the interaction to stop! bl.a. unset currentGameObject...

         std::vector<InteractionType*> interactionTypes = this->game->selectGameObject(objet);
         UserInterface_IO::out_object(*this->game->getCurrentGameObject(), interactionTypes);
         input = UserInterface_IO::in();
         if (input == "\\leave") {  break; }
         

         std::vector<InteractionOption*> interactionOptions = 
            game->selectInteraction(*this->game->getCurrentGameObject(),input);
         if (interactionOptions.size() > 0) { 
            UserInterface_IO::out_object_options(*this->game->getCurrentGameObject(), input, interactionOptions);
            input = UserInterface_IO::in();

            game->setInteractionOptions(input);
            std::string option_res = (*this->game->getCurrentGameObject())->currentInteractionOptions_status();
            option_res = "You selected to " +(*this->game->getCurrentGameObject())->getCurrentInteraction()->getActionName() + " "+ option_res;
            option_res += "\n\n type Ok to begin...";
            UserInterface_IO::out(option_res);
            //input = UserInterface_IO::in();
            UserInterface_IO::in(); //Only confirmation message... no nead to read it
         }
         std::string interactionResult = this->game->startInteraction();

         UserInterface_IO::out(interactionResult);
         UserInterface_IO::in();

         //parseInput(input);
         //if (input == "\\back") {
         //   enterScene(this->game->getCurrentScene()->getName());
         //}
      }

      game->abortInteraction();
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
         
         if (response != EXIT_STR) { 
            GameObject* gift = character_interface->promptItem();
            if (gift != nullptr) {
               UserInterface_IO::out(response + "\n Receiving "+ gift->getName() +" Do you accept?\n[ yes, no ]");
               std::string gift_str = UserInterface_IO::in();
               if (gift_str == "yes") {
                  this->game->addToInventory(gift);
               }else{}
               character_interface->close_Item();
               UserInterface_IO::out("YOU GOT AN ITEM!\n\n[ \\leave ]");

            }
            else {

               UserInterface_IO::out(response); 
            }
         }
         
         
      }
      character_interface->endConversation();
      return "done";
   }

};