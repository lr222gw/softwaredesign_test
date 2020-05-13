#include "pch.h"
#include "GameObject.h"

std::string GameObject::getid()
{
   return obj_id;
}

std::vector<InteractionType*> GameObject::listInteractionTypes()
{
   return interactionTypes;
}
