#pragma once

//GLEW
#include <GL\glew.h>

//GLM
#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>

//CUSTOM
#include "renderable2D.h"

namespace azuure { namespace graphics {
	class Renderer2D
	{
	public:
		Renderer2D();
		~Renderer2D();

		virtual void Submit(const Renderable2D *renderable) = 0;
		virtual void Flush() = 0;
	};

}}