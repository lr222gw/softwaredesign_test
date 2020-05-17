#pragma once

#include <iostream>
#include <string>
#include "Scene.h"

class UserInterface_IO { //<<:Singleton:>>
   //UserInterface_IO* theUserInterface_IO;

   UserInterface_IO() {};

   static UserInterface_IO* getReference() {

      UserInterface_IO* theUserInterface_io = new UserInterface_IO();
      return theUserInterface_io;
   }

   void output(std::string content) { 
      std::cout << content; 
   }

   std::string input() {
      std::string input;
      std::cin >> input;
      return input;
   }

public: 
   
   static void out_object_options(GameObject* obj, std::string interactionType ,std::vector<InteractionOption*> interactionOptions) {
      UserInterface_IO* ref = getReference();
      for (int i = 0; i < 50; i++) { ref->output("\n"); }

      std::string print;
      print = obj->getName() + ":\n";
      print += "How would you like to '" + interactionType + "'\n";
      
      print += "\n\nOptions : [ ";
      int c = 0;
      for (auto it : interactionOptions) {
         if (c < 1) { print += it->getOption(); }
         else {
            print += ", " + it->getOption();
         }
         c++;
      }
      print += " ]\n";

      //print += "Commands : [ \\leave ]";

      print += "\n>>";
      ref->output(print);

   }

   static void out_object(GameObject* obj, std::vector<InteractionType*> interactionTypes) {
      UserInterface_IO* ref = getReference();
      for (int i = 0; i < 50; i++) { ref->output("\n"); }

      std::string print;
      print = obj->getName() + ":\n";
      print += obj->getDescription();

      print += "\n\nInteractions : [ ";
      int c = 0;
      for (auto it : interactionTypes) {
         if (c < 1) { print += it->getActionName(); }
         else {
            print +=  ", " + it->getActionName() ;
         }
         c++;
      }
      print += " ]\n\n";
      print += "Commands : [ \\leave ]"; //, \\secretary, \\inventory, \\back 

      print += "\n>>";
      ref->output(print);

   }

   static void out_inventory(Scene* scene) { //TODO Not used anymore?
      UserInterface_IO* ref = getReference();
      for (int i = 0; i < 50; i++) { ref->output("\n"); }

      std::string print;
      print = scene->getName() + ":\n";
      print += scene->getDescription();
      print += "\n\nThese are the items in your inventory: \n" + scene->listAvailableElements();
      print += "\n\nCommands : [\\secretary, \\back ]";  // \\leave, \\back
      print += "\n>>";
      ref->output(print);
   }

   static void out_scene(Scene *scene) {
      UserInterface_IO* ref = getReference();
      for (int i = 0; i < 50; i++) { ref->output("\n"); }

      std::string print;
      print = scene->getName()+ ":\n";
      print += scene->getDescription();
      print += "\n\nYou see the following things in the scene: \n" + scene->listAvailableElements();      
      print += "\n\nCommands : [ \\leave, \\secretary, \\inventory ]";  // , \\back
      print += "\n>>";
      ref->output(print);
   }

   static void out(std::string content) {
      UserInterface_IO* ref = getReference();
      for (int i = 0; i < 50; i++) { ref->output("\n"); }
      content += "\n\n>>";
      ref->output(content);
   }

   static std::string in() {
      UserInterface_IO* ref = getReference();
      std::string input_str = ref->input(); 

      return input_str;
   }


};