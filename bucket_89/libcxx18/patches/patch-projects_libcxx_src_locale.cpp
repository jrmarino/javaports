--- projects/libcxx/src/locale.cpp.orig	2024-04-17 00:21:15 UTC
+++ projects/libcxx/src/locale.cpp
@@ -979,7 +979,7 @@ const ctype<char>::mask* ctype<char>::cl
 }
 #else
 const ctype<char>::mask* ctype<char>::classic_table() noexcept {
-#  if defined(__APPLE__) || defined(__FreeBSD__)
+#  if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
   return _DefaultRuneLocale.__runetype;
 #  elif defined(__NetBSD__)
   return _C_ctype_tab_ + 1;
