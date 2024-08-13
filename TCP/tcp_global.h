#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(TCP_LIB)
#  define TCP_EXPORT Q_DECL_EXPORT
# else
#  define TCP_EXPORT Q_DECL_IMPORT
# endif
#else
# define TCP_EXPORT
#endif
