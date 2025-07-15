#include "stylehelper.h"



QString StyleHelper::getMainWidgetStyle()
{
    return "background-color: rgb(240,240,240)";
}

QString StyleHelper::getStartXButtonsStyle()
{
    return "image: url(:/images/cross.png);";
}

QString StyleHelper::getStartOButtonsStyle()
{
    return "image: url(:/images/circle.png);";
}

QString StyleHelper::getStartXButtonsActiveStyle()
{
    return "image: url(:/images/cross.png);"
            "background-color: #bebebe;";
}

QString StyleHelper::getStartOButtonsActiveStyle()
{
    return "image: url(:/images/circle.png);"
            "background-color: #bebebe;";
}


