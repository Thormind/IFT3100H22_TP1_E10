/******************************************************
 Class:   			  			IFT-2008
 Session: 						H2022
 Project:						TP-1: engin 3d


 Students:

 Donald-Simon Hache
 Frederic Belanger
 Jonathan Bedard
 Kristofer Nolan
 Stephane Boulanger
 William Dussault


 Teacher:	 					Philippe Voyer
 File names:    	  			IconEditorRenderer.h
								IconEditorRenderer.cpp
 Date created: 				    2022-02-10
 *******************************************************
 Change history
 *******************************************************
 2022-02-10	Initial version (et1)
********************************************************/
#pragma once

#ifndef ICON_EDITOR_RENDERER_H
#define ICON_EDITOR_RENDERER_H

#include <map>
#include "RenderableObject.h"
#include "Square.h"
#include "GameMap.h"

/**
 * Class that renderer icon editor 
 * @author Stephane Boulanger
 * @version 1.0
 * @since 1.0
 */
class IconEditorRenderer {
public:
	static void draw(const std::map<std::string, RenderableObject*>& renderTable);

private:
	IconEditorRenderer() {} // classe avec seulement des méthodes statiques
	static void draw(const Square& square);
	static void draw(const GameMap& gameMap);

};


#endif // #define ICON_EDITOR_RENDERER_H
