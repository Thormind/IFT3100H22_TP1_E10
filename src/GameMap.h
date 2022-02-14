// filtre: SharedModels

#pragma once

#ifndef GAME_MAP_H
#define GAME_MAP_H

#include <string>
#include <map>
#include <array>
#include "Tile.h"
#include "ofMain.h"
#include "RenderableObject.h"


class GameMap : public RenderableObject {
public:
	GameMap();
	
private:
	void setup();
	
	static const RenderableTypeEnum RENDERABLE_TYPE;
	static int s_numberOfIteration;

	
	std::array<std::array<Tile, 10>, 10> m_tileList;

};

#endif // #define GAME_MAP_H	
