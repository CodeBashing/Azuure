#include <glm\glm.hpp>
#include <glm/gtx/transform.hpp>


#include "src\graphics\window.h"
#include "src\graphics\shader.h"

#include "src\graphics\beta\simplerenderer2D.h"
#include "src\graphics\renderable2D.h"


int main() {
	//TESTING GROUND
	azuure::graphics::Window window("Azuure", 1280, 720);

	azuure::graphics::Shader shader("src/shaders/vertex.sdr", "src/shaders/fragment.sdr");
	shader.Enable();

	azuure::graphics::Renderable2D sprite1(glm::vec2(4, 4), glm::vec3(0, 0, 0), glm::vec4(1, 0, 1, 1), shader);
	azuure::graphics::Renderable2D sprite2(glm::vec2(5, 1), glm::vec3(0, 5, 0), glm::vec4(0, 1, 1, 1), shader);
	azuure::graphics::SimpleRenderer2D renderer;

	glm::mat4 ortho = glm::ortho(0.f, 16.f, 0.f, 9.f, -1.f, 1.f);
	shader.SetUniformMat4("proj_matrix", ortho);
	shader.SetUniform2f("light_position", glm::vec2(2.f, 2.f));

	glClearColor(1.f, 1.f, 1.f, 1.f);

	while (!window.Closed()) {
		window.Clear();

		renderer.Submit(&sprite1);
		renderer.Submit(&sprite2);
		renderer.Flush();

		window.Update();
	}
}