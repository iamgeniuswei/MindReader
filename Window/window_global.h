#ifndef WINDOW_GLOBAL_H
#define WINDOW_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(WINDOW_LIBRARY)
#  define WINDOWSHARED_EXPORT Q_DECL_EXPORT
#else
#  define WINDOWSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // WINDOW_GLOBAL_H
