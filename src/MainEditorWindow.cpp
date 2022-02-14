// filtre: MainEditor/View

#include "MainEditorWindow.h"
#include "MainEditorRenderer.h"

MainEditorWindow::MainEditorWindow(shared_ptr<MainEditor> mainEditorSharedPtr)
	: m_mainEditorSharedPtr(mainEditorSharedPtr) {
	setup();
}

void MainEditorWindow::update() {
	draw();
}

void MainEditorWindow::setup() {
	ofSetWindowTitle(WINDOW_TITLE);

	setupAllGui();
	addAllListeners();
}

void MainEditorWindow::draw() {
	if (m_mainEditorSharedPtr->getShouldBeDrawn()) {
		drawElementLocations();
		drawAllGuiPanels();
		MainEditorRenderer::draw(m_mainEditorSharedPtr->getRenderTable());
	} 
}

void MainEditorWindow::setupAllGui() {
	setupMainMenuGui();
	setupMapPropertiesGui();
	setupTileEditGui();
	setupIconEditGui();
}

void MainEditorWindow::setupMainMenuGui() {
	m_mainMenuGui.setDefaultWidth(GUI_MENU_WIDTH); // Change la largeur par défault du paneau gui. Doit etre avant gui.setup()
	m_mainMenuGui.disableHeader();
	m_mainMenuGui.setup(MAIN_MENU_GUI_TXT);

	m_mainMenuGui.setPosition(MAIN_MENU_POSITION.x, MAIN_MENU_POSITION.y);
	m_mainMenuTitle.setBackgroundColor(ofColor::dimGrey);
	m_mainMenuGui.add(m_mainMenuTitle.setup("", MAIN_MENU_GUI_TXT));
	m_mainMenuGui.add(m_undoButton.setup(UNDO_BUTTON_TXT, BUTTON_WIDTH, BUTTON_HEIGHT));
	m_mainMenuGui.add(m_redoButton.setup(REDO_BUTTON_TXT, BUTTON_WIDTH, BUTTON_HEIGHT));

}

void MainEditorWindow::setupMapPropertiesGui() {
	m_mapPropertiesGui.setDefaultWidth(GUI_MENU_WIDTH); // Change la largeur par défault du paneau gui. Doit etre avant gui.setup()
	m_mapPropertiesGui.setup(MAP_PROPERTIES_GUI_TXT);

	m_mapPropertiesGui.setPosition(MAP_PROPERTIES_MENU_POSITION.x, MAP_PROPERTIES_MENU_POSITION.y);
	m_mapPropertiesGui.add(m_gridLineWidth.setup(GRID_LINE_WIDTH_BUTTON_TXT, STARTING_GRID_LINE_WIDTH,
		MIN_GRID_LINE_WIDTH, MAX_GRID_LINE_WIDTH));
}

void MainEditorWindow::setupTileEditGui() {
	m_tileEditGui.setDefaultWidth(GUI_MENU_WIDTH); // Change la largeur par défault du paneau gui. Doit etre avant gui.setup()
	m_tileEditGui.setup(TILE_EDIT_GUI_TXT);

	m_tileEditGui.setPosition(TILE_EDIT_MENU_POSITION.x, TILE_EDIT_MENU_POSITION.y);
	m_tileEditGui.add(m_tileTypeLabel.setup(TILE_TYPE_LABEL_TXT + TILE_TYPE_FLOOR_TXT));
	m_tileEditGui.add(m_tileTypeToggle.setup(TILE_TYPE_TOGGLE_TXT, TILE_TYPE_TOGGLE_DEFAULT));
}

void MainEditorWindow::setupIconEditGui() {
	m_iconEditGui.setDefaultWidth(GUI_MENU_WIDTH); // Change la largeur par défault du paneau gui. Doit etre avant gui.setup()
	m_iconEditGui.setup(ICON_EDIT_GUI_TXT);

	m_iconEditGui.setPosition(ICON_EDIT_MENU_POSITION.x, ICON_EDIT_MENU_POSITION.y);
	m_iconEditGui.add(m_startIconEditButton.setup(START_ICON_EDIT_BUTTON_TXT, BUTTON_WIDTH, BUTTON_HEIGHT));
}


void MainEditorWindow::addAllListeners() {
	m_undoButton.addListener(&m_mainEditorUndoAction, &MainEditorUndoAction::buttonPressed);
	m_redoButton.addListener(&m_mainEditorRedoAction, &MainEditorRedoAction::buttonPressed);
	m_startIconEditButton.addListener(&m_startIconEditionAction, &StartIconEditionAction::buttonPressed);
}

void MainEditorWindow::drawAllGuiPanels() {
	//m_mainMenuGui.setUseTTF(false); // pour corriger un bug avec le texte si on ouvre une 2ieme fenetre
	m_mainMenuGui.draw();
	m_mapPropertiesGui.draw();
	m_tileEditGui.draw();
	m_iconEditGui.draw();
}

// dessins temporaires, seulement pour donner une idee d'ou vont les elements de la fenetre. On peut effacer les dessins 
// correspondants lorsqu'on travail sur un element specifique.
void MainEditorWindow::drawElementLocations() {
	ofSetColor(ofColor::white);
	ofDrawLine(glm::vec2(500, 0), glm::vec2(500, 1000));

	// espace pour la carte avec la grille, on a donc des tuile de 40 x 40 (10 tuiles par rangee/colonne)
	// puisque la taille maximale d'une tuile est de 240x240, au redering, chaque tuile doit etre dessinee
	// avec un downscale de 6x
	ofNoFill();
	ofDrawRectangle(glm::vec2(50, 200), 400, 400);

	ofDrawLine(glm::vec2(900, 0), glm::vec2(900, 1000));

	// espace ou on voit la representation 2d de la tuile selectionnee. La tuile est affichee ici a sa taille reelle
	ofDrawRectangle(glm::vec2(580, 80), 240, 240);

	// espace ou on voit la representation 3d de la tuile selectionne.
	ofDrawRectangle(glm::vec2(1420, 80), 400, 400);
}


