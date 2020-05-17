#include "pch.h"
#include "InteractionEngine.h"

std::string InteractionEngine::parseQuery(std::string theQuery)
{
   
   return theQuery;
}

//std::string InteractionEngine::formatResponse(std::string theResponse, std::string nextConversationOptions, Character* curr)
std::string InteractionEngine::formatResponse(std::string theResponse, Character* curr)
{
   std::string concatinated = curr->getName() + ":\n";
   concatinated += theResponse + "\n";
   std::string conversationOptions = "\n[";
   conversationOptions += curr->getQueryOptions();
   conversationOptions += " ]\n";

   concatinated += conversationOptions;

   return concatinated;
}
