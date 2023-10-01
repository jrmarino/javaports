--- src/hotspot/os/bsd/os_bsd.cpp.orig	2022-07-20 22:54:48 UTC
+++ src/hotspot/os/bsd/os_bsd.cpp
@@ -366,7 +366,7 @@ void os::init_system_properties_values()
     #elif defined(__NetBSD__)
       #define DEFAULT_LIBPATH "/usr/lib:/usr/pkg/lib"
     #else
-      #define DEFAULT_LIBPATH "/usr/lib:/usr/local/lib"
+      #define DEFAULT_LIBPATH "/usr/lib:%%LOCALBASE%%/lib"
     #endif
   #else
     #define DEFAULT_LIBPATH OVERRIDE_LIBPATH
