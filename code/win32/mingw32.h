//#ifndef _MINGW32_HEADER
//#define _MINGW32_HEADER

#if (defined MINGW32)

//copied from wine windef.h (LGPL)
//also copy dinput.h and dsound.h from wine to mingw include directory
# ifdef UNICODE
# define WINELIB_NAME_AW(func) func##W
# else
# define WINELIB_NAME_AW(func) func##A
# endif#endif /* WINE_NO_UNICODE_MACROS */

#ifdef WINE_NO_UNICODE_MACROS
# define DECL_WINELIB_TYPE_AW(type) /* nothing */
#else
# define DECL_WINELIB_TYPE_AW(type) typedef WINELIB_NAME_AW(type) type;
#endif

#undef offsetof
//from gcc documentation
#define offsetof(type, member) __builtin_offsetof (type, member)

#undef FIELD_OFFSET
//copied from wine winnt.h (LGPL)
#define FIELD_OFFSET(type, field) ((LONG)offsetof(type, field))
//end of wine defines

#endif

//copied from wine's winuser (LGPL)
#define SPI_SCREENSAVERRUNNING    SPI_SETSCREENSAVERRUNNING

//#endif // _MINGW32_HEADER
