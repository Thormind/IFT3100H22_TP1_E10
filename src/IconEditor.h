// filtre: IconEditor/Model

/******************************************************
 Class:   			  			IFT-2008
 Session: 						H2022
 Project:						TP-1: engin 3d


 Students:

 Donald-Simon Haché
 Frederic Belanger
 Jonathan Bedard
 Kristofer Nolan
 Stephane Boulanger
 William Dussault


 Teacher:	 					Philippe Voyer
 File names:    	  			IconEditon.h
								IconEditon.cpp
 Date created: 				    2022-01-28
 *******************************************************
 Change history
 *******************************************************
 2022-01-28	Initial version (et1)
 2022-02-05	Created most methods and attributes (et2)
 2022-02-10	Made some modifications so the pop up
			window could work (et3)
********************************************************/

#pragma once

#ifndef ICON_EDITOR_H
#define ICON_EDITOR_H

#include <array>
#include <string>
#include "ofxGui.h"
#include "Subject.h"
#include "GameMap.h"
#include "MainEditor.h"
#include "Square.h"
#include "IconSquareSelectAction.h"


/**
 * Class that manages all the data for the icon editor
 * @author Frederic Belanger
 * @author Stephane Boulanger
 * @version 1.0
 * @since 1.0
 */
class IconEditor : public ofBaseApp, public Subject {
public:
	IconEditor(MainEditor * mainEditorPtr);
	virtual ~IconEditor() {}
	void setup() final;
	void update() final;
	void draw() final;
	void exit() final;

	const std::map<std::string, RenderableObject*>& getRenderTable() const;

	/**
	* Allows the main editor to be available when the icon editor is closed.
	*/
	void releaseMainWindow();

	// Temporary, will be moved in GameTester
	/**
	* Allows the main editor to be shown when this editor is closed.
	*/
	void showMainEditor();

	// temporary, to erase once TileIcon2d is created******************
	void changeTestString();
	void sendNewTestStringToMainEditor();
	//*****************************************************************

private:
	/**
    * Passes a pointer of the current instance of this class to the controller.
    */
	void initIconEditorController();
	void initRenderTable();
	void addToRenderTable(const RenderableObject& renderableObjectPtr);
	void initIconSelectSquareArray();
	void addAllListeners();
	void addListenerToSquareIcon(Square* squarePtr);
	
	//Fields 
	const glm::vec2 ICON_SQUARE_POSITION{ 30, 165 };
	const float ICON_SQUARE_WIDTH{ 100 };
	const float SPACE_BETWEEN_ICON_SQUARES{ 10 };
	const ofColor ICON_SQUARE_COLOR{ ofColor::white };

	MainEditor * m_mainEditorPtr;

	// Temporary, this will be replaced by a "Tile2dIconCopy". It will be sent to
	// the main editor only if the user selects "save and close". 
	std::string m_testStringCopy;
	GameMap m_gameMap;
	std::map<std::string, RenderableObject*> m_renderTable;
	IconSquareSelectAction m_iconSquareSelectAction;

	// Premade icon 
	std::array<Square*, 8> m_iconSelectSquareArray;

	// Icon preview 
	Square m_SquareToRenderIconPreview{ glm::vec2(560, ofGetHeight() / 4), 300, ofColor::white, ofColor::white };

	// Loaded icon
	Square m_SquareToRenderLoadedIcon{ glm::vec2(1060, ofGetHeight() / 6), 300, ofColor::white, ofColor::white };
};

#endif // #define ICON_EDITOR_H
