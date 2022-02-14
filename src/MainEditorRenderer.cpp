// filtre: MainEditor/View

#include "MainEditorRenderer.h"
#include "GameMapRenderer.h"
#include "GameMap.h"
#include "Enumerations.h"

void MainEditorRenderer::draw(const std::map<std::string, RenderableObject *> & renderTable) {
	for (std::pair<std::string, RenderableObject *> pair : renderTable) {
		switch (pair.second->getRenderableType()) {


		case RenderableTypeEnum::GAME_MAP:
			draw(*(GameMap*)(pair.second));
			break;
		default:
			break;
		}
	}
}


void MainEditorRenderer::draw(const GameMap & gameMap) {
	GameMapRenderer::draw(gameMap);
}

