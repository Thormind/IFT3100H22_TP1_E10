// filtre: MainEditor/Model

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
 File names:    	  			MainEditon.h
								MainEditon.cpp
 Date created: 				    2022-01-28
 *******************************************************
 Change history
 *******************************************************
 2022-01-28	Initial version (et1)
 2022-02-02	Created most methods and attributes (et2)
 2022-02-10	Made some modifications so pop up
			windows could work (et3)
********************************************************/

#pragma once

#ifndef MAIN_EDITOR_H
#define MAIN_EDITOR_H

#include <string>
#include "ofMain.h"
#include "ofxGui.h"
#include "Subject.h"
#include "GameMap.h"
#include "GLFW/glfw3.h"



/**
 * Base class that manages all the data for the main editor
 * @author Frederic Belanger
 * @author Donald-Simon Haché
 * @version 1.0
 * @since 1.0
 */
class MainEditor : public ofBaseApp, public Subject {
public:
	virtual ~MainEditor() {}
	void setup() final;
	void update() final;
	void draw() final;

	const std::map<std::string, RenderableObject *> & getRenderTable() const;

	//******************************************************************************
	// temporary, will be replaced by "getEditedTileIcon" and "setEditedTileIcon"
	const std::string & getTestString();
	void setTestString(const std::string testString);
	//*******************************************************************************

	// must be static to work with "windowCloseCallback"
	/**
	 * Basic setter.
	 * Must be static to work with "windowCloseCallback".
	 * Unlike "hideEditor", the consequece of this will not hide the window. 
	 * It will only keep what is inside from being drawn.
	 * @param shouldBeVisible if the editor should be drawn
	 */
	static void setShouldBeDrawn(const bool & shouldBeDrawn);
	
	/**
	 * Hide the main editor display.
	 * Used when a GameTester window is called.
	 */
	void hideEditor();

	/**
	 * Show the main editor display (when it's already hidden).
	 * Used when a GameTester window is closed.
	 */
	void showEditor();

	/**
	 * Basic setter.
	 */
	void setOfBaseWindowSharedPtr(shared_ptr<ofAppBaseWindow> ofBaseWindowSharedPtr);

	/**
	 * Keeps the user from closing the main window when a pop up window is active.
	 * Must be static in order to be used as a callback function.
	 * @param window a pointer to the main editor window frame
	 */
	static void MainEditor::windowCloseCallback(GLFWwindow* window);

	/**
	 * Basic getter.
	 * This brakes the MVC encapsulation a bit, but is needed because of the way
	 * Openframeworks handle multiple windows.
	 * @return a shared pointer to an instance of this class and the window frame
	 */
	const shared_ptr<ofAppBaseWindow> & getOfBaseWindowSharedPtr();

	/**
	 * Basic getter
	 * @return if the content of the main editor window whould be drawn
	 */
	const bool & getShouldBeDrawn();

	//***************************************************************************
	// temporary, for test only. Should be removed before release.
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	//****************************************************************************
	
private:

	/**
	* Passes a pointer of the current instance of this class to the controller.
	*/
	void initMainEditorController();

	/**
	 * Initialize the render table.
	 * This table contains all RenderableObject data to be displayed by MainEditorWindow.
     */
	void initRenderTable();

	/**
	 * Adds a RenderableObject to the render table.
	 * @param renderableObjectPtr a pointer to the object to be added
	 */
	void addToRenderTable(const RenderableObject & renderableObjectPtr);

	//Fields
	GameMap m_gameMap;
	std::map<std::string, RenderableObject*> m_renderTable;
	shared_ptr<ofAppBaseWindow> m_ofBaseWindowSharedPtr;
	static bool m_shouldBeDrawn;

	//*************************************************************************
	// Temporary, was used to test IconEditor. To be erased before release
	std::string m_testString = "an original icon.";
	//*************************************************************************


};

#endif // #define MAIN_EDITOR_H