// filtre: MainEditor/View

#pragma once

#ifndef MAIN_EDITOR_RENDER_VISITOR_H
#define MAIN_EDITOR_RENDER_VISITOR_H

#include<map>
#include "RenderableObject.h"
#include "GameMap.h"

class MainEditorRenderer{

public:
	static void draw(const std::map<std::string, RenderableObject *> & renderTable);

private:
	MainEditorRenderer() {} // classe avec seulement des méthodes statiques
	static void draw(const GameMap & gameMap);
};

#endif // #define MAIN_EDITOR_RENDER_VISITOR_H	