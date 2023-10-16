--- src/hotspot/share/runtime/os.cpp.orig	2022-07-20 22:54:48 UTC
+++ src/hotspot/share/runtime/os.cpp
@@ -883,7 +883,7 @@ bool os::print_function_and_library_name
   //  is worse than (raw) C-heap allocation in that case).
   char* p = buf;
   if (p == NULL) {
-    p = (char*)::alloca(O_BUFLEN);
+    p = (char*) __builtin_alloca(O_BUFLEN);
     buflen = O_BUFLEN;
   }
   int offset = 0;
