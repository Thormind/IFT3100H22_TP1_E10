// filtre: SharedModels

#pragma once

/**************************************************************

       *
       ***
**************     IMPORTANT: ne pas changer l'order des enum, 
*****************  toujours ajouter les nouveaux à la fin de la
**************     liste existante. 
	   ***         
	   *

**************************************************************/

enum class RenderableTypeEnum {
	CIRCLE,
	GAME_MAP,
	SQUARE,
	CUBE
};

enum class MeshRenderModeEnum { 
	FILL,
	WIREFRAME,
	VERTEX
};

