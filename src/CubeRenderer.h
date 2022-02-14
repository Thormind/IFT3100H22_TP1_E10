// filtre: SharedModels

#pragma once

#ifndef CUBE_RENDERER_H
#define CUBE_RENDERER_H

#include "ofMain.h"
#include "Cube.h"
#include "Structures.h"
#include "Enumerations.h"

class CubeRenderer {
public:
	~CubeRenderer() {}
	void draw(const Cube & cube);
	
private:
	const int locatorBufferHead{ 0 };


	Locator* locators;

	MeshRenderModeEnum meshRenderMode;

	ofLight light;

	ofNode node;

};

#endif // #define CUBE_RENDERER_H