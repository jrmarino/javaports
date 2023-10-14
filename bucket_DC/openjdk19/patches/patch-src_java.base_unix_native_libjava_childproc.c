--- src/java.base/unix/native/libjava/childproc.c.orig	2023-01-21 05:27:28 UTC
+++ src/java.base/unix/native/libjava/childproc.c
@@ -64,7 +64,7 @@ isAsciiDigit(char c)
   return c >= '0' && c <= '9';
 }
 
-#if defined(_BSDONLY_SOURCE)
+#if defined(_BSDONLY_SOURCE) || defined(__DragonFly__)
 /*
  * Quoting POSIX: "If a multi-threaded process calls fork(), the new
  * process shall contain a replica of the calling thread and its entire
@@ -80,7 +80,7 @@ isAsciiDigit(char c)
 int
 closeDescriptors(void)
 {
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
     closefrom(FAIL_FILENO + 1);
 #else
     int err;
