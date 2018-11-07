#ifndef PDFCORE_GLOBAL_H
#define PDFCORE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PDFCORE_LIBRARY)
#  define PDFCORESHARED_EXPORT Q_DECL_EXPORT
#else
#  define PDFCORESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // PDFCORE_GLOBAL_H
