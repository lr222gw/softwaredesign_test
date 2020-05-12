
#include "pch.h"
#include "../soft_lib/Game.h"




TEST(Game_selectGameObject, returnsInteractionType) {

   //Arrange
   GameObject dummy("Dummy");
   std::vector<GameObject> gobj_vec;
   gobj_vec.push_back(dummy);

   Scene c_scene(gobj_vec);
   GameObjectRepository objrep;
   Scene i_scene;     

   Game game(i_scene, c_scene, objrep);

   //Act
   InteractionType* type = game.selectGameObject("Dummy");

   //Assert
   ASSERT_NE(type, nullptr);

}


