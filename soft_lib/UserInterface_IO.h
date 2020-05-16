#pragma once

#include <iostream>
#include <string>

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