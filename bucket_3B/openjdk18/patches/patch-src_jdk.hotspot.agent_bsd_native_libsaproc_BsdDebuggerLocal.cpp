--- src/jdk.hotspot.agent/bsd/native/libsaproc/BsdDebuggerLocal.cpp.orig	2022-07-20 22:54:48 UTC
+++ src/jdk.hotspot.agent/bsd/native/libsaproc/BsdDebuggerLocal.cpp
@@ -24,7 +24,7 @@
  */
 
 #include <stdlib.h>
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <machine/sysarch.h>
 #endif
 #include <cxxabi.h>
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
 
@@ -321,7 +325,11 @@ JNIEXPORT jbyteArray JNICALL Java_sun_jv
   bufPtr = env->GetByteArrayElements(array, &isCopy);
   CHECK_EXCEPTION_(0);
 
+#ifdef __DragonFly__
+  err = PS_ERR; /* XXX unsupported */
+#else
   err = ps_pread(get_proc_handle(env, this_obj), (psaddr_t) (uintptr_t)addr, bufPtr, numBytes);
+#endif
   env->ReleaseByteArrayElements(array, bufPtr, 0);
   return (err == PS_OK)? array : 0;
 }
@@ -347,7 +355,7 @@ JNIEXPORT jlongArray JNICALL Java_sun_jv
   }
 
 #undef NPRGREG
-#ifdef i386
+#ifdef i586
 #define NPRGREG sun_jvm_hotspot_debugger_x86_X86ThreadContext_NPRGREG
 #endif
 #ifdef amd64
@@ -369,7 +377,7 @@ JNIEXPORT jlongArray JNICALL Java_sun_jv
 
 #undef REG_INDEX
 
-#ifdef i386
+#ifdef i586
 #define REG_INDEX(reg) sun_jvm_hotspot_debugger_x86_X86ThreadContext_##reg
 
   regs[REG_INDEX(GS)]  = (uintptr_t) gregs.r_gs;
@@ -388,7 +396,7 @@ JNIEXPORT jlongArray JNICALL Java_sun_jv
   regs[REG_INDEX(CS)]  = (uintptr_t) gregs.r_cs;
   regs[REG_INDEX(SS)]  = (uintptr_t) gregs.r_ss;
 
-#endif /* i386 */
+#endif /* i586 */
 
 #ifdef amd64
 #define REG_INDEX(reg) sun_jvm_hotspot_debugger_amd64_AMD64ThreadContext_##reg
@@ -412,17 +420,19 @@ JNIEXPORT jlongArray JNICALL Java_sun_jv
   regs[REG_INDEX(CS)] = gregs.r_cs;
   regs[REG_INDEX(RSP)] = gregs.r_rsp;
   regs[REG_INDEX(SS)] = gregs.r_ss;
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
   void **fs_base = NULL, **gs_base = NULL;
   amd64_get_fsbase(fs_base);
   amd64_get_gsbase(gs_base);
 
   regs[REG_INDEX(FSBASE)] = (long) *fs_base;
   regs[REG_INDEX(GSBASE)] = (long) *gs_base;
+#ifndef __DragonFly__
   regs[REG_INDEX(DS)] = gregs.r_ds;
   regs[REG_INDEX(ES)] = gregs.r_es;
   regs[REG_INDEX(FS)] = gregs.r_fs;
   regs[REG_INDEX(GS)] = gregs.r_gs;
+#endif
 #endif /* __FreeBSD__ */
 
 #endif /* amd64 */
