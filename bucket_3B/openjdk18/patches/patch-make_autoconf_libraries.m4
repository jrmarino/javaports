--- make/autoconf/libraries.m4.orig	2022-07-20 22:54:48 UTC
+++ make/autoconf/libraries.m4
@@ -200,9 +200,9 @@ AC_DEFUN_ONCE([LIB_SETUP_MISC_LIBS],
       ICONV_LDFLAGS="-L/usr/local/lib"
       ICONV_LIBS=-liconv
     elif test "x$OPENJDK_TARGET_OS_ENV" = "xbsd.freebsd"; then
-      ICONV_CFLAGS=-DLIBICONV_PLUG
-      ICONV_LDFLAGS=
-      ICONV_LIBS=
+      ICONV_CFLAGS=%%ICONV_CFLAGS%%
+      ICONV_LDFLAGS=%%ICONV_LDFLAGS%%
+      ICONV_LIBS=%%ICONV_LIBS%%
     else
       ICONV_CFLAGS=
       ICONV_LDFLAGS=
