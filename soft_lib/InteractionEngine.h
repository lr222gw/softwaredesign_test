#pragma once


#include <string>
#include "Character.h"

class InteractionEngine {


public: 
   InteractionEngine() {}

   //InteractionEngine* create();

   std::string parseQuery(std::string theQuery);
   
   //std::string formatResponse(std::string theResponse, std::string nextConversationOptions, std::string name);
   //std::string formatResponse(std::string theResponse, std::string nextConversationOptions, Character * curr);
   std::string formatResponse(std::string theResponse, Character * curr);

};
