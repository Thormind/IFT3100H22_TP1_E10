// filtre: IconEditor/Model
/******************************************************
 Class:   			  			IFT-2008
 Session: 						H2022
 Project:						TP-1: engin 3d


 Students:

 Donald-Simon Haché                       
 Frederic Belanger	                   
 Jonathan Bedard			   
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
            window could work
********************************************************/

#include "IconEditor.h"
#include "IconEditorController.h"
#include "MainEditorController.h"

IconEditor::IconEditor(MainEditor * mainEditorPtr)
	: m_mainEditorPtr(mainEditorPtr), m_testStringCopy(mainEditorPtr->getTestString()) {
	
	// À effacer
	cout << "before edition we have : " + mainEditorPtr->getTestString() << endl;
}

void IconEditor::setup() {
	initIconEditorController();
	initIconSelectSquareArray();
	initRenderTable();
	addAllListeners();
}

void IconEditor::update() {
	
}

void IconEditor::draw() {
	notifyObservers();
}

void IconEditor::exit() {
	releaseMainWindow();
}

const std::map<std::string, RenderableObject*>& IconEditor::getRenderTable() const {
	return m_renderTable;
}

void IconEditor::releaseMainWindow() {
	m_mainEditorPtr->setShouldBeDrawn(true);
}

void IconEditor::showMainEditor() {
	m_mainEditorPtr->showEditor();
}

void IconEditor::changeTestString() {
	m_testStringCopy = "a modified icon.";
}

void IconEditor::sendNewTestStringToMainEditor() {
	m_mainEditorPtr->setTestString(m_testStringCopy);
}

void IconEditor::initIconEditorController() {
	IconEditorController::getInstance()->setIconEditorPtr(this);
}

void IconEditor::initRenderTable() {
	addToRenderTable(m_gameMap);

	for (Square* squarePtr : m_iconSelectSquareArray) {
		addToRenderTable(*squarePtr);
	}

	addToRenderTable(m_SquareToRenderIconPreview);
	addToRenderTable(m_SquareToRenderLoadedIcon);
}

void IconEditor::addToRenderTable(const RenderableObject& renderableObject) {
	m_renderTable.insert(
		{ renderableObject.getObjectUniqueId(), (RenderableObject*)&renderableObject }
	);
}

void IconEditor::initIconSelectSquareArray() {
	int offsetY = 0;

	for (int j = 0; j < 8; ++j) {
		m_iconSelectSquareArray[j] = new Square(
			glm::vec2(ICON_SQUARE_POSITION.x + (j % 4) * (ICON_SQUARE_WIDTH + SPACE_BETWEEN_ICON_SQUARES),
				ICON_SQUARE_POSITION.y + offsetY),
			ICON_SQUARE_WIDTH, ofColor::white, ofColor::white);

		if (j == 3) {
			offsetY += (ICON_SQUARE_WIDTH + SPACE_BETWEEN_ICON_SQUARES);
		}
	}
}

void IconEditor::addAllListeners() {
	for (Square* squarePtr : m_iconSelectSquareArray) {
		addListenerToSquareIcon(squarePtr);
	}
	// tous les autres listeners (s'il y en a)
}

void IconEditor::addListenerToSquareIcon(Square* squarePtr) {
	ofAddListener(squarePtr->clickedInside, &m_iconSquareSelectAction, &IconSquareSelectAction::onClickInSquare);
}