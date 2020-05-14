#pragma once

#include <string>

class Secretary {


   void loadScene(); //Any scene; inventory, ingame scene, testscene...

public: 

   std::string greetings();
   std::string query(std::string safeQuery);

};