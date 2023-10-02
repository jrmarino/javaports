--- src/java.base/unix/native/libjava/java_props_md.c.orig	2022-07-20 22:54:48 UTC
+++ src/java.base/unix/native/libjava/java_props_md.c
@@ -401,6 +401,11 @@ GetJavaProperties(JNIEnv *env)
     {
 #ifdef MACOSX
         setOSNameAndVersion(&sprops);
+#elif defined __DragonFly__
+        struct utsname name;
+        uname(&name);
+        sprops.os_name = "DragonFlyBSD";
+        sprops.os_version = strdup(name.release);
 #else
         struct utsname name;
         uname(&name);
