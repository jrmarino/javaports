--- src/hotspot/share/utilities/macros.hpp.orig	2022-07-20 22:54:48 UTC
+++ src/hotspot/share/utilities/macros.hpp
@@ -415,7 +415,7 @@
 #define NOT_WINDOWS(code) code
 #endif
 
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__) || defined(__DragonFly__)
 #ifndef BSD
 #define BSD
 #endif // BSD defined in <sys/param.h>
