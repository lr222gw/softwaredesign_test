
#include "pch.h"
#include "../soft_lib/Game.h"

class Game_selectGameObject_arrange : public testing::Test {
protected: 
   Look dummyType;
   TurnOn dummyTypeon;
   TurnOff dummyTypeoff;
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
      typeList.push_back(&dummyTypeon);
      typeList.push_back(&dummyTypeoff);

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
class Game_selectInteraction_arrange : public Game_selectGameObject_arrange {

};

TEST_F(Game_selectGameObject_arrange, retuns_valid_interactionType_when_data_exists) {
   //Arrange : see   "Game_selectGameObject_arrange"   
   //Act   
   std::vector<InteractionType*> types = game.selectGameObject("Dummy");    //NOTE; Dummy is setup inside Fixture!
   
   //Assert
   ASSERT_NE(types.size(), 0); // If object returned a List of 0 interactionTypes... 
}

TEST_F(Game_selectGameObject_arrange, retuns_ZeroVector_when_data_NOTexists) {
   //Arrange : see   "Game_selectGameObject_arrange"
   //Act   
   std::vector<InteractionType*> types = game.selectGameObject("NotDummy");    //NOTE; NotDummy is NOT setup inside Fixture!

   //Assert
   ASSERT_EQ(types.size(), 0); // If object returned a List of 0 interactionTypes... 
}

TEST_F(Game_selectInteraction_arrange, retuns_valid_interactionOptions_when_data_exists) {

   std::vector<InteractionType*> types = game.selectGameObject("Dummy"); //Select a "currentGameObject"
   std::vector<InteractionOption*> options = game.selectInteraction(game.getCurrentGameObject(), "Turn On");    //NOTE; Dummy is setup inside Fixture!

   ASSERT_NE(options.size(), 0); // If object returned a List of 0 interactionTypes... 
}

TEST_F(Game_selectInteraction_arrange, retuns_ZeroVector_interactionOptions_when_data_NOTexists) {

   std::vector<InteractionType*>    types    = game.selectGameObject("Dummy"); //Select a "currentGameObject"
   std::vector<InteractionOption*> options   = game.selectInteraction(game.getCurrentGameObject(), "Open");    //Cant Open the Dummy...

   ASSERT_EQ(options.size(), 0); // If object returned a List of 0 interactionTypes... then OK; Open deos not exist on Dummy 
}