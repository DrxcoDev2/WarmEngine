#ifndef WARM_H
#define WARM_H

#include <SDL2/SDL.h>
#include <iostream>

#include "config/config.h"

#define WIN_W_PRE 800
#define WIN_H_PRE 600

using WARMWIN = SDL_Window;
using RENDERER = SDL_Renderer;

// INIT
bool WARMINIT(const char* message) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << message << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}

// WINDOW STRUCT
struct Window {
    const char* name;
    int width;
    int height;
};

// CREAR VENTANA
WARMWIN* createWindow(const Window& w) {
    int width = (w.width > 0) ? w.width : WIN_W_PRE;
    int height = (w.height > 0) ? w.height : WIN_H_PRE;

    WARMWIN* window = SDL_CreateWindow(
        w.name,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        std::cerr << "Error al crear la ventana: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    return window;
}

// CLASE ADD
class Add {     //UTIL 
public:
    // Retardo (delay)
    void delay(int ms) { //USE MS, YOU CAN CONVERT TO S
        SDL_Delay(ms);
    }

    // Destruye una ventana SDL válida
    void destroy(WARMWIN* window, bool alert=true) {
        if (window) {
            SDL_DestroyWindow(window);
            if (alert == true) {
                std::cout << "Ventana destruida correctamente.\n";
            }
            
        } else {
            std::cerr << "Error: ventana nula, no se puede destruir.\n";
        }
    }

    void FINISH() {
        SDL_Quit();
    }
};

//RENDERER
RENDERER* CreateRenderer(WARMWIN* window, int index = -1) {
    RENDERER* renderer = SDL_CreateRenderer(
        window,
        index,
        SDL_RENDERER_ACCELERATED
    );

    if (!renderer) {
        std::cerr << "Error al crear el renderer: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    return renderer;
}




#endif // WARM_H
