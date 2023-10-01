--- src/jdk.hotspot.agent/bsd/native/libsaproc/BsdDebuggerLocal.cpp.orig	2022-07-20 22:54:48 UTC
+++ src/jdk.hotspot.agent/bsd/native/libsaproc/BsdDebuggerLocal.cpp
@@ -35,7 +35,11 @@
 #define amd64 1
 #endif
 
-#ifdef i386
+#if defined(i386) && !defined(i586)
+#define i586 1
+#endif
+
+#ifdef i586
 #include "sun_jvm_hotspot_debugger_x86_X86ThreadContext.h"
 #endif
 
@@ -347,7 +351,7 @@ JNIEXPORT jlongArray JNICALL Java_sun_jv
   }
 
 #undef NPRGREG
-#ifdef i386
+#ifdef i586
 #define NPRGREG sun_jvm_hotspot_debugger_x86_X86ThreadContext_NPRGREG
 #endif
 #ifdef amd64
@@ -369,7 +373,7 @@ JNIEXPORT jlongArray JNICALL Java_sun_jv
 
 #undef REG_INDEX
 
-#ifdef i386
+#ifdef i586
 #define REG_INDEX(reg) sun_jvm_hotspot_debugger_x86_X86ThreadContext_##reg
 
   regs[REG_INDEX(GS)]  = (uintptr_t) gregs.r_gs;
@@ -388,7 +392,7 @@ JNIEXPORT jlongArray JNICALL Java_sun_jv
   regs[REG_INDEX(CS)]  = (uintptr_t) gregs.r_cs;
   regs[REG_INDEX(SS)]  = (uintptr_t) gregs.r_ss;
 
-#endif /* i386 */
+#endif /* i586 */
 
 #ifdef amd64
 #define REG_INDEX(reg) sun_jvm_hotspot_debugger_amd64_AMD64ThreadContext_##reg
