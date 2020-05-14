// software.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "../soft_lib/Game.h"

int main()
{
    std::cout << "Hello World!\n";
    
    Look    dummyType;
    TurnOn  dummyTypeon;
    TurnOff dummyTypeoff;
    std::vector<InteractionType*> typeList;
    GameObject dummy;
    std::vector<GameObject> gobj_vec;
    Scene* c_scene;
    GameObjectRepository* objrep;
    Scene* i_scene;
    Game game;
    typeList.push_back(&dummyType);
    typeList.push_back(&dummyTypeon);
    typeList.push_back(&dummyTypeoff);

    dummy = GameObject("Dummy", typeList);
    gobj_vec.push_back(dummy);

    c_scene = new Scene(gobj_vec);
    objrep = new GameObjectRepository();
    i_scene = new Scene();

    game = Game(i_scene, c_scene, objrep);
   ////////////////////////////////////////////////
   game.selectGameObject("Dummy");
   game.selectInteraction(game.getCurrentGameObject(), "Turn On");
   std::string ret = game.startInteraction();
   
    std::cout << ret << std::endl;
  
   //std::cout << "After: " <<  g.getStr() <<  std::endl;

   
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
