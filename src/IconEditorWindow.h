// filtre: IconEditor/View
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
 File names:    	  			IconEditorWindow.h
								IconEditorWindow.cpp
 Date created: 				    2022-02-10
 *******************************************************
 Change history
 *******************************************************
 2022-02-10	Initial version (et1)
********************************************************/

#pragma once

#ifndef ICON_EDITOR_WINDOW_H
#define ICON_EDITOR_WINDOW_H

#include "Observer.h"
#include "IconEditor.h"
#include "IconEditorCloseAction.h"

/**
 * Class that manage the window for icon editor
 * @author Frederic Belanger
 * @author Stephane Boulanger
 * @version 1.0
 * @since 1.0
 */
class IconEditorWindow : public Observer {

public:
	//IconEditorWindow(IconEditor & IconEditor);
	//IconEditorWindow(shared_ptr<IconEditor> iconEditorSharedPtr);
	IconEditorWindow(shared_ptr<IconEditor> iconEditorSharedPtr);

	virtual ~IconEditorWindow() {}
	virtual void update() override;
	void setup();
	void draw();

private:
	void setupAllGui();
	void setupTestPanelGui();
	void addAllListeners();
	void drawAllGuiPanels();

	const std::string WINDOW_TITLE{ "Icon editor" };


	shared_ptr<IconEditor> m_iconEditorSharedPtr;

	ofxPanel m_testPanelGui;
	ofxButton m_closeAndSaveButton;

	IconEditorCloseAction m_iconEditorCloseAction;

};

#endif // #define ICON_EDITOR_WINDOW_H