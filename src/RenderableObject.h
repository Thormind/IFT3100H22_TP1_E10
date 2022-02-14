// filtre: SharedModels

#pragma once

#ifndef RENDERABLE_OBJECT_H
#define RENDERABLE_OBJECT_H

#include <string>
#include "Enumerations.h"

class RenderableObject {
public:
	virtual ~RenderableObject() {}
	const RenderableTypeEnum & getRenderableType() const;
	const std::string & getObjectUniqueId() const;
	

protected:
	RenderableObject(RenderableTypeEnum RenderableType, int objectInstanceNumber);
	const RenderableTypeEnum RENDERABLE_TYPE;
	const std::string OBJECT_UNIQUE_ID;

private:

};

#endif // #define RENDERABLE_OBJECT_H	
