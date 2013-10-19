Status
======

* can fully compile OpenJK in Windows and Linux
* codeJK2 dll will now compile but not tested (at all!!)

* to make a debug build (can use with GDB) add -DCMAKE_BUILD_TYPE=DEBUG to cmake command

Compiling using MINGW32 in Windows
==================================

* install MSYS/MingW32
* install libz using mingw-get "mingw-get install libz"
* copy xinput.h, dinput.h and dsound.h from wine to mingw/include
* CMakeLists.txt: UseInternalZlib -> OFF
* mkdir build && cd build
* run "cmake -G "MSYS Makefiles" .."
* make
* copy relevant dlls from mingw/bin (note dlls are currently linked dynamically)

Cross-compiling with MINGW32 in Linux
=====================================

Only tested in Ubuntu 12.04, generated binaries not tested!

* apt-get install mingw32
* can't use included zlib.lib -> put a Mingw32 libz.a in OpenJK/lib (might have to rename/remove zlib.lib)
* CMakeLists.txt: UseInternalZlib -> *ON*
* you *must* use cmake 2.8.8+ as the cmake files in the project make use of features introduced in that version - easy to compile from source
* copy xinput.h, dinput.h and dsound.h from wine to mingw include directory (system location)
* mkdir build && cd build
* cmake ../OpenJK -DCMAKE_TOOLCHAIN_FILE=../OpenJK/CMakeModules/mingw-toolchain.cmake
* make


