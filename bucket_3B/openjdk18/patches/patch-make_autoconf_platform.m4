--- make/autoconf/platform.m4.orig	2022-07-20 22:54:48 UTC
+++ make/autoconf/platform.m4
@@ -620,6 +620,16 @@ AC_DEFUN([PLATFORM_SET_RELEASE_FILE_OS_V
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
 
