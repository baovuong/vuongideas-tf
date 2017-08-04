#include "homecontroller.h"


void HomeController::index()
{
    // write code
    setLayout("default_layout");
    render();
}

// Don't remove below this line
T_DEFINE_CONTROLLER(HomeController)
