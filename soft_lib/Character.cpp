#include "pch.h"
#include "Character.h"

#include "InteractionEngine.h"
#include "PlotEngine.h"

std::string Character::query(std::string theQuery)
{
   InteractionEngine interaction_engine;
   PlotEngine Plot_engine;

   //Query: How to get to *HoglandsPark*     <-- Note Hoglandspark is the keyword that will trigger something...


   std::string parsed_query = interaction_engine.parseQuery(theQuery);  //What do we want here...
   //parsed_query: hoglandspark 
   //character_state *currstate;
   
   character_query q = this->searchQueries(parsed_query);
   
   if (q.query != NULL_QUERY) {


      std::string plotState = Plot_engine.getPlotState();                  //What do we want here....

      std::string theResponse = q.response;

      

      std::string formatedResponse = interaction_engine.formatResponse(theResponse, this);   // hmm

      return formatedResponse;
   }

   return "Dunno";

}
