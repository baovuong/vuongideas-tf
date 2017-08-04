#include "statistics.h"
#include "statisticsapicontroller.h"


void StatisticsApiController::mean()
{
    switch (httpRequest().method()) {
    case Tf::Post: {
        // get json array
        if (!httpRequest().hasJson()) {
            renderErrorResponse(Tf::BadRequest);
        }
        QJsonArray data = httpRequest().jsonData().array();
        QList<double> data1;
        foreach (const QJsonValue & d, data) {
            data1.append(d.toDouble());
        }

        Statistics statistics;
        QJsonObject output;
        output["mean"] = statistics.mean(data1);
        renderJson(output);
        break;
    }
    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void StatisticsApiController::standardDeviation()
{
    switch (httpRequest().method()) {
    case Tf::Post: {
        // get json array
        if (!httpRequest().hasJson()) {
            renderErrorResponse(Tf::BadRequest);
        }
        QJsonArray data = httpRequest().jsonData().array();
        QList<double> data1;
        foreach (const QJsonValue & d, data) {
            data1.append(d.toDouble());
        }

        Statistics statistics;
        QJsonObject output;
        output["mean"] = statistics.standardDeviation(data1);
        renderJson(output);
        break;
    }
    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void StatisticsApiController::histogram()
{
    // write code
}

void StatisticsApiController::typical_error()
{
    // write code
}

// Don't remove below this line
T_DEFINE_CONTROLLER(StatisticsApiController)
