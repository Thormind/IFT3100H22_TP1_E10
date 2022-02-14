// filtre: SharedModels

#include "GameMap.h"

const RenderableTypeEnum GameMap::RENDERABLE_TYPE{ RenderableTypeEnum::GAME_MAP };
int GameMap::s_numberOfIteration{ 0 };

GameMap::GameMap() 
	: RenderableObject(RENDERABLE_TYPE, s_numberOfIteration++) {
	setup();
}


void GameMap::setup() {
}

