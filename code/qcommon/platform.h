// Simple header file to dispatch to the relevant platform API headers
#ifndef _PLATFORM_H
#define _PLATFORM_H

#if (defined _WINDOWS || defined MINGW32)
#define PATH_SEP '\\'
#define DLL_EXT ".dll"
#include <windows.h>
#endif

#if (defined MINGW32)

//copied from wine windef.h (LGPL)
//also copy dinput.h and dsound.h from wine to mingw include directory
# ifdef UNICODE
#  define WINELIB_NAME_AW(func) func##W
# else
#  define WINELIB_NAME_AW(func) func##A
# endif#endif  /* WINE_NO_UNICODE_MACROS */

#ifdef WINE_NO_UNICODE_MACROS
# define DECL_WINELIB_TYPE_AW(type)  /* nothing */
#else
# define DECL_WINELIB_TYPE_AW(type)  typedef WINELIB_NAME_AW(type) type;
#endif

//copied from wine winnt.h (LGPL)
#define FIELD_OFFSET(type, field) ((LONG)offsetof(type, field))
//end of wine defines

//from gcc documentation
#define offsetof(type, member)  __builtin_offsetof (type, member)

#define Q_vsnprintf snprintf

#endif

#if defined (__linux__)
#define PATH_SEP '/'
typedef const char *LPCTSTR;
typedef const char *LPCSTR;
typedef unsigned long DWORD;
typedef unsigned int UINT;
typedef long INT32;
typedef void* HANDLE;
typedef HANDLE HINSTANCE;
typedef void *PVOID;
typedef DWORD COLORREF;
typedef unsigned char BYTE;
typedef unsigned char byte;
typedef long LONG;
typedef struct tagPOINT {
  LONG x;
  LONG y;
} POINT;
typedef unsigned short USHORT;
typedef unsigned short WORD;
typedef struct _GUID {
  DWORD Data1;
  WORD  Data2;
  WORD  Data3;
  BYTE  Data4[8];
} GUID;
#define strnicmp Q_stricmpn
#define strcmpi Q_stricmp
#define stricmp Q_stricmp
#define RGB(r,g,b)          ((COLORREF)((r) | ((g) << 8) | ((b) << 16)))

#define _isnan isnan
#define ARCH "i386"
#define DLL_EXT ".so"

#define _snprintf snprintf

#define __cdecl

#define vsprintf_s vsprintf
#define _strnicmp Q_stricmpn

#define OutputDebugString printf
#endif

#if defined (MACOS_X)
#define PATH_SEP '/'
typedef const char *LPCTSTR;
typedef const char *LPCSTR;
typedef unsigned long DWORD;
typedef unsigned int UINT;
typedef long INT32;
typedef void* HANDLE;
typedef HANDLE HINSTANCE;
typedef void *PVOID;
typedef DWORD COLORREF;
typedef unsigned char BYTE;
typedef unsigned char byte;
typedef long LONG;
typedef struct tagPOINT {
    LONG x;
    LONG y;
} POINT;
typedef unsigned short USHORT;
typedef unsigned short WORD;
typedef struct _GUID {
    DWORD Data1;
    WORD  Data2;
    WORD  Data3;
    BYTE  Data4[8];
} GUID;
#define strnicmp Q_stricmpn
#define strcmpi Q_stricmp
#define stricmp Q_stricmp
#define RGB(r,g,b)          ((COLORREF)((r) | ((g) << 8) | ((b) << 16)))

#define _isnan isnan
#define ARCH "i386"
#define DLL_EXT ".dylib"

#define _snprintf snprintf

#define __cdecl

#define vsprintf_s vsprintf
#define _strnicmp Q_stricmpn

#define OutputDebugString printf
#endif

#endif
