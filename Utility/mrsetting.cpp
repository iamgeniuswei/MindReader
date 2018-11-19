#include "mrsetting.h"
#include <QDebug>
MRSetting* MRSetting::_instance = nullptr;
MRSetting::MRSetting()
{
	//setting = new QSettings;
}

//TODO:待修改成线程安全版本
MRSetting * MRSetting::instance()
{
	if (_instance == nullptr)
		_instance = new MRSetting;
	return _instance;
}

MRSetting::~MRSetting()
{
    if(setting)
        delete setting;
}

QString MRSetting::getValue(const QString &group, const QString &key)
{
    QString value = QString();
    if(setting)
    {
        setting->beginGroup (group);
        if(setting->childKeys ().contains (key))
        {

            value = setting->value (key).toString ();
        }
        setting->endGroup ();
    }
    return value;
}

void MRSetting::setValue(const QString &group, const QString &key, const QString &value)
{
    if(setting)
    {
        QString com_key = group+"/"+key;
        setting->setValue (com_key, value);
    }
}

bool MRSetting::initializeSetting(const QString & app_dir, const QString & ini)
{
	appDir = app_dir;
	QString ini_path = appDir + "/" + ini;
    try
    {
        setting = new(std::nothrow) QSettings(ini_path, QSettings::IniFormat);
    }
    catch (std::exception &e)
    {
        qDebug() << e.what ();
    }
    return true;
}

QString MRSetting::getStyleSheet()
{
    QString value = getValue ("stylesheet", "current");
    return  value;
}

void MRSetting::setStyleSheet(const QString &stylesheet)
{

}

QString MRSetting::getWorkDirectory()
{
    return getValue ("directory", "working");
}

void MRSetting::setWorkDirectory(const QString &dir)
{
    setValue ("directory", "working", dir);
}

QString MRSetting::getFirstUseage()
{
    return getValue ("firstuse", "value");
}

void MRSetting::setFirstUseage()
{
    setValue ("firstuse", "value", "false");
}

QString MRSetting::getDatabaseName()
{
    return getValue ("database", "sqlite");
}
