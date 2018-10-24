#ifndef WIDGETINTERFACE_H
#define WIDGETINTERFACE_H


class WidgetInterface
{
public:
    WidgetInterface();
    virtual void initializeUI() = 0;
    virtual void initializeSignal() = 0;
};

#endif // WIDGETINTERFACE_H
