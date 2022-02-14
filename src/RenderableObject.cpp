// filtre: SharedModels

#include "RenderableObject.h"

RenderableObject::RenderableObject(RenderableTypeEnum RenderableType, int objectInstanceNumber)
	: RENDERABLE_TYPE(RenderableType), OBJECT_UNIQUE_ID(std::to_string((int)RenderableType) + std::to_string(objectInstanceNumber)) {
}

const RenderableTypeEnum & RenderableObject::getRenderableType() const {
	return RENDERABLE_TYPE;
}

const std::string & RenderableObject::getObjectUniqueId() const {
	return OBJECT_UNIQUE_ID;
}


