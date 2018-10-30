#ifndef MRSETTING_H
#define MRSETTING_H

#include <QString>
#include <QSettings>
#include "utility_global.h"
class UTILITYSHARED_EXPORT MRSetting
{
public:
    MRSetting();
    ~MRSetting();
    QString getValue(const QString& group, const QString& key);
    void setValue(const QString& group, const QString& key, const QString& value);
    bool initializeSetting(const QString& ini);
    QString getStyleSheet();
    void setStyleSheet(const QString& stylesheet);
    QString getWorkDirectory();
    void setWorkDirectory(const QString& dir);
    QString getFirstUseage();
    void setFirstUseage();
    QString getDatabaseName();

private:
    QSettings *setting = nullptr;
};

#endif // MRSETTING_H
