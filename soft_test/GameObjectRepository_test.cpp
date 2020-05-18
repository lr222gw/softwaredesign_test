#include "pch.h"
#include "../soft_lib/GameObjectRepository.h"

TEST(GameObjectRepository_getGameObject, returns_true_on_available) {
   // OBS; this test is dependent on the fact that GameObjectRepository does create and loads a Dummy object!

   //Arrange
   GameObject* dum = new GameObject("Dummy", std::vector<InteractionType*>{}, "dum dummy");
   std::vector<GameObject*> f{ dum };
   GameObjectRepository gor = GameObjectRepository(f);
   GameObject* obj  = new GameObject();

   //Act 
   bool result = gor.getGameObject("Dummy", obj);

   //delete obj;
   //Assert
   ASSERT_EQ(result, true);
}

TEST(GameObjectRepository_getGameObject, returns_false_on_notavailable) {
   //Arrange
   std::vector<GameObject*> f;
   GameObjectRepository gor = GameObjectRepository(f);
   GameObject *obj = new GameObject();
   //Act
   bool result = gor.getGameObject("ThisIsNotAObjectThatExists", obj);

   //Assert
   ASSERT_EQ(result, false);

}