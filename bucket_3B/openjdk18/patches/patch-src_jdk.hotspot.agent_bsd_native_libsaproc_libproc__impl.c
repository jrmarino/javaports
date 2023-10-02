--- src/jdk.hotspot.agent/bsd/native/libsaproc/libproc_impl.c.orig	2022-07-20 22:54:48 UTC
+++ src/jdk.hotspot.agent/bsd/native/libsaproc/libproc_impl.c
@@ -663,7 +663,7 @@ ps_plog (const char *format, ...)
   va_end(alist);
 }
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 // ------------------------------------------------------------------------
 // Functions below this point are not yet implemented. They are here only
 // to make the linker happy.
