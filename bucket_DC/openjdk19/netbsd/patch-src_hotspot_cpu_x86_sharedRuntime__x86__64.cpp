--- src/hotspot/cpu/x86/sharedRuntime_x86_64.cpp.orig	2023-01-21 05:27:28 UTC
+++ src/hotspot/cpu/x86/sharedRuntime_x86_64.cpp
@@ -3335,7 +3335,7 @@ void SharedRuntime::montgomery_multiply(
   int divisor = sizeof(julong) * 4;
   guarantee(longwords <= 8192 / divisor, "must be");
   int total_allocation = longwords * sizeof (julong) * 4;
-  julong *scratch = (julong *)alloca(total_allocation);
+  julong *scratch = (julong *)__builtin_alloca(total_allocation);
 
   // Local scratch arrays
   julong
@@ -3365,7 +3365,7 @@ void SharedRuntime::montgomery_square(ji
   int divisor = sizeof(julong) * 3;
   guarantee(longwords <= (8192 / divisor), "must be");
   int total_allocation = longwords * sizeof (julong) * 3;
-  julong *scratch = (julong *)alloca(total_allocation);
+  julong *scratch = (julong *)__builtin_alloca(total_allocation);
 
   // Local scratch arrays
   julong
