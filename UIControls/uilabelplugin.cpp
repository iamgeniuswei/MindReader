#include "uilabel.h"
#include "uilabelplugin.h"

#include <QtPlugin>

UILabelPlugin::UILabelPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void UILabelPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool UILabelPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *UILabelPlugin::createWidget(QWidget *parent)
{
    return new UILabel(parent);
}

QString UILabelPlugin::name() const
{
    return QLatin1String("UILabel");
}

QString UILabelPlugin::group() const
{
    return QLatin1String("");
}

QIcon UILabelPlugin::icon() const
{
    return QIcon(QLatin1String(":/label.png"));
}

QString UILabelPlugin::toolTip() const
{
    return QLatin1String("");
}

QString UILabelPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool UILabelPlugin::isContainer() const
{
    return false;
}

QString UILabelPlugin::domXml() const
{
    return QLatin1String("<widget class=\"UILabel\" name=\"uILabel\">\n</widget>\n");
}

QString UILabelPlugin::includeFile() const
{
    return QLatin1String("uilabel.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(uilabelplugin, UILabelPlugin)
#endif // QT_VERSION < 0x050000
