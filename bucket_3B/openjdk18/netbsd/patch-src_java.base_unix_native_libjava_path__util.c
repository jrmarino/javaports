--- src/java.base/unix/native/libjava/path_util.c.orig	2022-07-20 22:54:48 UTC
+++ src/java.base/unix/native/libjava/path_util.c
@@ -123,7 +123,7 @@ collapse(char *path)
 
     nc = collapsible(names);
     if (nc < 2) return;         /* Nothing to do */
-    ix = (char **)alloca(nc * sizeof(char *));
+    ix = (char **)__builtin_alloca(nc * sizeof(char *));
     splitNames(names, ix);
 
     for (i = 0; i < nc; i++) {
