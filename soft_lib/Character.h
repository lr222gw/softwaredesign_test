#pragma once

#include "GameElement.h"
#include <vector>

//struct character_state {
//   character_state() {
//      query = "disturb";
//      presentation = "I don't have time right now...";
//      nmbr_of_quries = 0;
//   }
//   character_state(std::string query, 
//      std::string presentation, 
//      std::vector<character_state*> queries = std::vector<character_state*>{ new character_state() }) {
//
//      this->query = query;
//      this->presentation = presentation;
//      nmbr_of_quries = 0;
//
//      for (auto q : queries) {
//         Queries.push_back(q);
//         nmbr_of_quries++;
//      }
//
//   }
//   //identifier / Query 
//   std::string query;
//   
//   //Scenario
//   std::string presentation;
//
//   //Possible Queries
//   std::vector<character_state*> Queries;
//   int nmbr_of_quries;
//
//   //Scenario_state
//
//};

class Character : public GameElement {
protected:
   std::string greeting;

   //character_state* state;

public:
   /*Character(std::string name, std::string greeting, character_state* chr_state = new character_state())
      :GameElement(name), greeting(greeting), state(chr_state){} */

   Character(std::string name, std::string greeting)
      :GameElement(name), greeting(greeting) {}

   
   std::string getInitialGreeting() { return greeting; }

   std::string query(std::string theQuery);

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