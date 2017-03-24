#pragma once


//STD
#include <deque>

//CUSTOM
#include "..\renderer2D.h"

namespace azuure { namespace graphics {
	class SimpleRenderer2D : public Renderer2D{
	public:
		void Submit(const Renderable2D *renderable) override;
		void Flush() override;
	private:
		std::deque<const Renderable2D*> m_renderQueue;
	};
}}