#include "warm.h"



int main() {
	RENDERER *renderer = NULL;
    WARMINIT("Error al inicializar SDL: ");

    Window myWindow = {"Mi ventana SDL", SCREEN_WIDTH, SCREEN_HEIGHT};
    WARMWIN* window = createWindow(myWindow);

    Add util;
	renderer = CreateRenderer(window);
    if (!renderer) {
		printf("Error al crear el renderizado");
	} else {
		std::cout << "Se creo bien el renderizado\n";
	}

	while (!loopShouldStop) {

		SDL_Event event;
		while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    loopShouldStop = true;
                    break;
            }
        }
	}
	util.delay(2000);
    util.destroy(window, false);
    util.FINISH();
    

    return 0;
}
