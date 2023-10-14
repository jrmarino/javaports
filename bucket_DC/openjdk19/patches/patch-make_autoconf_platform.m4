--- make/autoconf/platform.m4.orig	2023-01-21 05:27:28 UTC
+++ make/autoconf/platform.m4
@@ -206,11 +206,11 @@ AC_DEFUN([PLATFORM_EXTRACT_VARS_FROM_OS]
       VAR_OS=macosx
       VAR_OS_TYPE=unix
       ;;
-    *bsd*)
+    *bsd*|*dragonfly*)
       VAR_OS=bsd
       VAR_OS_TYPE=unix
       case "$1" in
-        *freebsd*)
+        *freebsd*|*dragonfly*)
           VAR_OS_ENV=bsd.freebsd ;;
         *openbsd*)
           VAR_OS_ENV=bsd.openbsd ;;
@@ -628,6 +628,16 @@ AC_DEFUN([PLATFORM_SET_RELEASE_FILE_OS_V
   if test "x$OPENJDK_TARGET_OS" = "xaix"; then
     RELEASE_FILE_OS_NAME="AIX"
   fi
+  if test "x$OPENJDK_TARGET_OS" = "xbsd"; then
+    case "$target_os" in
+       freebsd*)   RELEASE_FILE_OS_NAME="FreeBSD" ;;
+       midnight*)  RELEASE_FILE_OS_NAME="MidnightBSD" ;;
+       dragonfly*) RELEASE_FILE_OS_NAME="DragonFly" ;;
+       netbsd*)    RELEASE_FILE_OS_NAME="NetBSD" ;;
+       openbsd*)   RELEASE_FILE_OS_NAME="OpenBSD" ;;
+       *)          RELEASE_FILE_OS_NAME="Unknown BSD" ;;
+    esac
+  fi
   RELEASE_FILE_OS_ARCH=${OPENJDK_TARGET_CPU}
   RELEASE_FILE_LIBC=${OPENJDK_TARGET_LIBC}
 
