#include "simplerenderer2D.h"


namespace azuure { namespace graphics {
	void graphics::SimpleRenderer2D::Submit(const Renderable2D *renderable) {
		m_renderQueue.push_back(renderable);
	}
	void graphics::SimpleRenderer2D::Flush() {
		while (!m_renderQueue.empty()) {
			const Renderable2D* renderable = m_renderQueue.front();
			renderable->GetVAO()->Bind();
			renderable->GetIBO()->Bind();

			renderable->GetShader().SetUniformMat4("model_matrix", glm::translate(renderable->GetPosition()));
			renderable->GetShader().SetUniform4f("_color", renderable->GetColor());
			glDrawElements(GL_TRIANGLES, renderable->GetIBO()->GetCount(), GL_UNSIGNED_SHORT, nullptr);

			renderable->GetIBO()->Unbind();
			renderable->GetVAO()->Unbind();

			m_renderQueue.pop_front();
		}
	}

}}