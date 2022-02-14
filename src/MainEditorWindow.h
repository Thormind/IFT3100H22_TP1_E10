// filtre: MainEditor/View
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
 File names:    	  			MainEditorWindow.h
								MainEditorWindow.cpp
 Date created: 				    2022-02-10
 *******************************************************
 Change history
 *******************************************************
 2022-02-10	Initial version (et1)
********************************************************/

#pragma once

#ifndef MAIN_EDITOR_WINDOW_H
#define MAIN_EDITOR_WINDOW_H

#include <string>
#include "ofMain.h"
#include "Observer.h"
#include "MainEditor.h"
#include "MainEditorUndoAction.h"
#include "MainEditorRedoAction.h"
#include "StartIconEditionAction.h"

/**
 * Base class that manages all the window for the main editor
 * @author Frederic Belanger
 * @author Stephane Boulanger
 * @version 1.0
 * @since 1.0
 */
class MainEditorWindow : public Observer{
public:
	MainEditorWindow(shared_ptr<MainEditor> m_mainEditorSharedPtr);
	virtual ~MainEditorWindow() {}
	virtual void update() override;
	void setup();
	void draw();

private:
	void setupAllGui();
	void setupMainMenuGui();
	void setupMapPropertiesGui();
	void setupTileEditGui();
	void setupIconEditGui();
	void addAllListeners();
	void drawAllGuiPanels();

	// Temporaire, a effacer avant remise finale
	void drawElementLocations();

	//Fields
	const std::string WINDOW_TITLE{ "RPG Map Creator" };

	const std::string MAIN_MENU_GUI_TXT{ "Main menu" };
	const std::string MAP_PROPERTIES_GUI_TXT{ "Map properties" };
	const std::string TILE_EDIT_GUI_TXT{ "Tile edit" };
	const std::string ICON_EDIT_GUI_TXT{ "Icon edit" };

	const std::string UNDO_BUTTON_TXT{ "Undo" };
	const std::string REDO_BUTTON_TXT{ "Redo" };
	const std::string GRID_LINE_WIDTH_BUTTON_TXT{ "Grid line width" };
	const std::string TILE_TYPE_LABEL_TXT{ "Tyle type: " };
	const std::string TILE_TYPE_WALL_TXT{ "wall" };
	const std::string TILE_TYPE_FLOOR_TXT{ "floor" };
	const std::string TILE_TYPE_TOGGLE_TXT{ "Toggle tyle type (floor/wall)" };
	const std::string START_ICON_EDIT_BUTTON_TXT{ "Start icon editor" };

	const float GUI_MENU_WIDTH{ 300 };
	const float BUTTON_WIDTH{ 20 };
	const float BUTTON_HEIGHT{ 20 };
	
	const glm::vec2 MAIN_MENU_POSITION{ 100,20 };
	
	const glm::vec2 MAP_PROPERTIES_MENU_POSITION{ 100, 620 };
	const float STARTING_GRID_LINE_WIDTH{ 2 };
	const float MIN_GRID_LINE_WIDTH{ 2 };
	const float MAX_GRID_LINE_WIDTH{ 8 };	
	
	const glm::vec2 TILE_EDIT_MENU_POSITION{ 550, 340 };	
	const bool TILE_TYPE_TOGGLE_DEFAULT{ false };	
	
	const glm::vec2 ICON_EDIT_MENU_POSITION{ 550, 700 };	
	
	shared_ptr<MainEditor> m_mainEditorSharedPtr;

	ofxPanel m_mainMenuGui;
	ofxLabel m_mainMenuTitle;
	ofxButton m_undoButton;
	ofxButton m_redoButton;

	ofxPanel m_mapPropertiesGui;
	ofxIntSlider m_gridLineWidth;

	ofxPanel m_tileEditGui;
	ofxLabel m_tileTypeLabel;
	ofxToggle m_tileTypeToggle;

	ofxPanel m_iconEditGui;
	ofxButton m_startIconEditButton;

	MainEditorUndoAction m_mainEditorUndoAction;
	MainEditorRedoAction m_mainEditorRedoAction;
	StartIconEditionAction m_startIconEditionAction;
};

#endif // #define MAIN_EDITOR_WINDOW_H	