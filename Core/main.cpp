#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include "src\graphics\window.h"
#include "src\graphics\shader.h"
#include "src\utils\fileutils.h"


int main() {
	azuure::graphics::Window window("Azuure", 1280, 720);

	//Testing
	GLfloat vertices[] = {
		4, 3, 0,
		12, 3, 0,
		4, 6, 0,
		4, 6, 0,
		12, 6, 0, 
		12, 3, 0
	};
	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glm::mat4 ortho = glm::ortho(0.f, 16.f, 0.f, 9.f, -1.f, 1.f);

	azuure::graphics::Shader shader("src/shaders/vertex.sdr", "src/shaders/fragment.sdr");
	shader.Enable();
	shader.SetUniformMat4("proj_matrix", ortho);

	glClearColor(1.f, 1.f, 1.f, 1.f);

	while (!window.Closed()) {
		window.Clear();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		window.Update();
	}
}