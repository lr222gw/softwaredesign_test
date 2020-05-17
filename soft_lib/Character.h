#pragma once

#include "GameElement.h"
#include <vector>

#define NULL_QUERY "#nullquery#"
#define EXIT_STR "#exit#"

struct character_query {
   character_query(std::string q, std::string r) {
      query = q;
      response = r;
   }
   std::string query;
   std::string response;
};

struct character_state {
   character_state() {
      state = "disturb";
      presentation = "I don't have time right now...";
      nmbr_of_quries = 0;
   }
   character_state(std::string state, 
      std::string presentation, 
      std::vector<character_query> queries) {

      this->state = state;
      this->presentation = presentation;
      nmbr_of_quries = 0;

      for (auto q : queries) {
         Queries.push_back(q);
         nmbr_of_quries++;
      }

   }
   //identifier / Query 
   std::string state;
   
   //Scenario
   std::string presentation;

   //Possible Queries
   std::vector<character_query> Queries;
   int nmbr_of_quries;

   //Scenario_state

};

class Character : public GameElement {
protected:
   std::string greeting;

   character_state state;

   bool pending_state_presentation; 

public:
   /*Character(std::string name, std::string greeting, character_state* chr_state = new character_state())
      :GameElement(name), greeting(greeting), state(chr_state){} */

   Character(std::string name, std::string greeting)
      :GameElement(name), greeting(greeting) {
      pending_state_presentation = false;
    }

   
   std::string getInitialGreeting() { return greeting; }

   std::string query(std::string theQuery);


   std::string present_by_state() {

      std::string theResult = this->getName() + ":\n";
      if (this->pending_state_presentation) {
         this->pending_state_presentation = false;  //reset it         
         theResult += this->state.presentation;         
         theResult += "\n\n[ "+this->getQueryOptions()+" ]";
      }
      else {
         theResult += this->greeting;
         if (this->name == "Dr. Secretary") {
            theResult += "\n\n[mission, \\leave]";
         }
         
      }
      return theResult;
   }

   character_query searchQueries(std::string search_str ) {
      for (auto q : state.Queries) {
         if (q.query == search_str) {
            return q;
         }
      }     

      return character_query(NULL_QUERY, NULL_QUERY);
   }

   std::string getQueryOptions() {
      std::string nextConversationOptions;// = "\n[";
     //Get Options based on quiries
      int c = 0;

      for (auto q : this->state.Queries) {
         if (c < 1) {
            //nextConversationOptions += " " + q.query;
            nextConversationOptions += q.query;
         }
         else{
            nextConversationOptions += ", " + q.query;
         }
         c++;
      }
      //Add Standard Options
      nextConversationOptions += ", \\Back, \\leave";  //TODO:: lägg till saker som behövs här....
      

      return nextConversationOptions;
   }

   //character_state* searchQueries(std::string search_str, character_state *currstate) {

   //   
   //   character_state* toret = new character_state();
   //   
   //   

   //   for (auto q : currstate->Queries) {
   //      if (q->query == search_str) {
   //         toret = q;
   //         return toret;
   //         //break;
   //      }
   //      if (q->nmbr_of_quries > 0) {
   //         toret = searchQueries(search_str,q);
   //      }
   //   }


   //   return toret; 

   //}
};