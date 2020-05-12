
#include "pch.h"
#include "../soft_lib/Scene.h"

TEST(Scene_isAvailable, returns_true_on_available) {

   //Arrange
   GameObject dummy("Dummy");
   std::vector<GameObject> gobj_vec;
   gobj_vec.push_back(dummy);

   Scene c_scene(gobj_vec);
   //GameObjectRepository objrep;
   //Scene i_scene;     

   //Game game(i_scene, c_scene, objrep);


   //Act
   bool result = c_scene.isAvailable("Dummy");

   //Assert
   ASSERT_EQ(result, true);

}

TEST(Scene_isAvailable, returns_false_on_notavilable) {

   //Arrange

   Scene c_scene;

   //Act
   bool result = c_scene.isAvailable("Dummy");

   //Assert
   ASSERT_NE(result, true);

}