#include "IconEditorRenderer.h"
#include "SquareRenderer.h"
#include "GameMapRenderer.h"
#include "GameMap.h"
#include "Enumerations.h"

void IconEditorRenderer::draw(const std::map<std::string, RenderableObject*>& renderTable) {
	for (std::pair<std::string, RenderableObject*> pair : renderTable) {
		switch (pair.second->getRenderableType()) {

		case RenderableTypeEnum::SQUARE:
			draw(*(Square*)(pair.second));
			break;

		case RenderableTypeEnum::GAME_MAP:
			draw(*(GameMap*)(pair.second));
			break;
		default:
			break;
		}
	}
}

void IconEditorRenderer::draw(const Square& square) {
	SquareRenderer::draw(square);
}

void IconEditorRenderer::draw(const GameMap& gameMap) {
	GameMapRenderer::draw(gameMap);
}