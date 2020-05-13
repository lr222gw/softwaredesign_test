
#include "pch.h"
#include "../soft_lib/Game.h"

class Game_selectGameObject_arrange : public testing::Test {
protected: 
   Look dummyType;
   std::vector<InteractionType*> typeList;
   GameObject dummy;
   std::vector<GameObject> gobj_vec;
   Scene* c_scene;
   GameObjectRepository* objrep;
   Scene* i_scene;
   Game game;
public: 

   void SetUp() override {
      
      typeList.push_back(&dummyType);

      dummy = GameObject("Dummy", typeList);
      
      gobj_vec.push_back(dummy);

      c_scene = new Scene(gobj_vec);
      objrep = new GameObjectRepository();
      i_scene = new Scene();

      game = Game(i_scene, c_scene, objrep);
   }
   void TearDown() override {
      delete  c_scene;
      delete  objrep;
      delete  i_scene;
   }
};

//TEST(Game_selectGameObject, retuns_valid_interactionType_when_data_exists) {
TEST_F(Game_selectGameObject_arrange, retuns_valid_interactionType_when_data_exists) {

   //Arrange
   /*
   Look dummyType;
   std::vector<InteractionType*> typeList;
   typeList.push_back(&dummyType);

   GameObject dummy("Dummy", typeList);
   std::vector<GameObject> gobj_vec;
   gobj_vec.push_back(dummy);

   Scene *c_scene = new Scene(gobj_vec);
   GameObjectRepository *objrep = new GameObjectRepository();
   
   Scene *i_scene = new Scene();

   Game game(i_scene, c_scene, objrep);
   */

   //Act   
   std::vector<InteractionType*> types = game.selectGameObject("Dummy");   
   
   //Assert
   ASSERT_NE(types.size(), 0); // If object returned a List of 0 interactionTypes... 
}


