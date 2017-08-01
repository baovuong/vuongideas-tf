#include "testingcontroller.h"

#include "mediathings.h"

void TestingController::images()
{
    // write code
    Mediathings mediathings;
    QList<QString> links = mediathings.linksFromImgur(httpRequest().queryItemValue("q"));
    texport(links);
    setLayout("default_layout");
    render();
}

// Don't remove below this line
T_DEFINE_CONTROLLER(TestingController)
