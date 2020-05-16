#pragma once

#include <iostream>
#include <string>

class UserInterface_IO {
   static UserInterface_IO* theUserInterface_IO;

   UserInterface_IO() {};
public: 

   static void output(std::string content) {
      if (theUserInterface_IO == nullptr) { theUserInterface_IO = new UserInterface_IO(); }
      std::cout << content << std::endl;
   }

   static std::string input() {
      if (theUserInterface_IO == nullptr) { theUserInterface_IO = new UserInterface_IO(); }

      std::string input;
      std::cin >> input;
      return input;
   }


};