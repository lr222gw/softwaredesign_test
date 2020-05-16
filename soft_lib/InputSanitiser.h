#pragma once
#include <string>
#include <iostream>

class InputSanitiser {

public: 
   std::string sanitiseInput(std::string theQuery) {
      std::cout << "InputSanitiser::sanitiseInput:>>I don't do much right now" << std::endl;
      //TODO:: cause Query to be LowerCase, set more than 1 spaces == 1 spaces...

      return theQuery;
   
   }; //Normalize text, all input to lowercase or something...

};
