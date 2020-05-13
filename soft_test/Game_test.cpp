
#include "pch.h"
#include "../soft_lib/Game.h"



TEST(Game_selectGameObject, retuns_valid_interactionType_when_data_exists) {

   //Arrange
   Look dummyType;
   std::vector<InteractionType*> typeList;
   typeList.push_back(&dummyType);

   GameObject dummy("Dummy", typeList);
   std::vector<GameObject> gobj_vec;
   gobj_vec.push_back(dummy);

   Scene *c_scene = new Scene(gobj_vec);
   GameObjectRepository *objrep = new GameObjectRepository();
   std::cout << "objrep:obj_Latest: " << objrep->obj_Latest->getid() << std::endl;
   Scene *i_scene = new Scene();

   Game game(i_scene, c_scene, objrep);

   //Act
   std::cout << "Before:selectGameObject" << std::endl;
   std::vector<InteractionType*> types = game.selectGameObject("Dummy");
   
   
   //Assert
   ASSERT_NE(types.size(), 0); // If object returned a List of 0 interactionTypes... 
}


