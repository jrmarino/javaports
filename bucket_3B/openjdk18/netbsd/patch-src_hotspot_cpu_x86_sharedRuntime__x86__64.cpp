--- src/hotspot/cpu/x86/sharedRuntime_x86_64.cpp.orig	2022-07-20 22:54:48 UTC
+++ src/hotspot/cpu/x86/sharedRuntime_x86_64.cpp
@@ -3547,7 +3547,7 @@ void SharedRuntime::montgomery_multiply(
   // will use here a total of 8k bytes of stack space.
   int total_allocation = longwords * sizeof (julong) * 4;
   guarantee(total_allocation <= 8192, "must be");
-  julong *scratch = (julong *)alloca(total_allocation);
+  julong *scratch = (julong *)__builtin_alloca(total_allocation);
 
   // Local scratch arrays
   julong
@@ -3576,7 +3576,7 @@ void SharedRuntime::montgomery_square(ji
   // will use here a total of 6k bytes of stack space.
   int total_allocation = longwords * sizeof (julong) * 3;
   guarantee(total_allocation <= 8192, "must be");
-  julong *scratch = (julong *)alloca(total_allocation);
+  julong *scratch = (julong *)__builtin_alloca(total_allocation);
 
   // Local scratch arrays
   julong
