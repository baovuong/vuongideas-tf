#include <QJsonObject>
#include <QJsonValue>

#include "imagecontroller.h"
#include "imgur.h"
#include "mediathings.h"

void ImageController::fetch()
{
    // write code
    Mediathings mediathings;
    renderJson(mediathings.linksFromImgur(httpRequest().queryItemValue("q")));
}

// Don't remove below this line
T_DEFINE_CONTROLLER(ImageController)
