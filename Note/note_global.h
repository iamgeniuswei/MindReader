#ifndef NOTE_GLOBAL_H
#define NOTE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(NOTE_LIBRARY)
#  define NOTESHARED_EXPORT Q_DECL_EXPORT
#else
#  define NOTESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // NOTE_GLOBAL_H
