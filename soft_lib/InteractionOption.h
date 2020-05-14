#pragma once

class InteractionOption {
protected:
   std::string option;
public:
   InteractionOption() {
      option = "";
   }
   std::string getOption() { return option; }
};
// Move, Open
class carefully : public InteractionOption {
public:
   carefully() { option = "carefully"; }
      

};

class forcefully : public InteractionOption {
public:
   forcefully() { option = "forcefully"; }

};

// Look
class closely : public InteractionOption {
public:
   closely() { option = "closely"; }


};

