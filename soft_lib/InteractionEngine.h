#pragma once


#include <string>


class InteractionEngine {


public: 
   InteractionEngine() {}

   //InteractionEngine* create();

   std::string parseQuery(std::string theQuery);
   
   std::string formatResponse(std::string theResponse, std::string nextConversationOptions);

};
