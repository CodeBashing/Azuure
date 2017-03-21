#include "src\graphics\window.h"


int main() {
	azuure::graphics::Window window("Azuure", 1280, 720);
	while (!window.Closed()) {
		window.Clear();
		window.Update();
	}
}