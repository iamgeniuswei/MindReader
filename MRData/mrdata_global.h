#ifndef MRDATA_GLOBAL_H
#define MRDATA_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MRDATA_LIBRARY)
#  define MRDATASHARED_EXPORT Q_DECL_EXPORT
#else
#  define MRDATASHARED_EXPORT Q_DECL_IMPORT
#endif

#define DATAPERSISTENCE

#endif // MRDATA_GLOBAL_H
