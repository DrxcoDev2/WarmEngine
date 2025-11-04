#include "warm.h"



int main() {
    WARMINIT("Error al inicializar SDL: ");

    Window myWindow = {"Mi ventana SDL", SCREEN_WIDTH, SCREEN_HEIGHT};
    WARMWIN* window = createWindow(myWindow);

    Add util;
    util.delay(2000);
    util.destroy(window, false);
    util.FINISH();
    

    return 0;
}
