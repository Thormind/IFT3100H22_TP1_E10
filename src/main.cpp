#include "ofMain.h"
#include "MainEditor.h"
#include "MainEditorWindow.h"

//========================================================================
int main( ){
	//ofSetupOpenGL(1900,1000,OF_WINDOW);			// <-------- setup the GL context

	ofGLFWWindowSettings settings;
	settings.setSize(1900, 1000);
	settings.resizable = false;
	shared_ptr<ofAppBaseWindow> editorWindow = ofCreateWindow(settings);


	shared_ptr<MainEditor> mainEditorSharedPtr = make_shared<MainEditor>();
	MainEditorWindow mainEditorWindow(mainEditorSharedPtr);
	mainEditorSharedPtr->attachObserver(mainEditorWindow);
	mainEditorSharedPtr->setOfBaseWindowSharedPtr(editorWindow);

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(editorWindow, mainEditorSharedPtr);
	ofRunMainLoop();

	// A faire: voir pourquoi on ne peut pas "delete" mainEditorPtr ici
	// (genere une exception)
}
