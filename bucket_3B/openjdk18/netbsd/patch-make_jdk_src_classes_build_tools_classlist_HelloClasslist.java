Workaround for:
Exception in thread "main" java.lang.NoSuchFieldError: preferIPv6Address
	at java.base@18.0.2/java.net.InetAddress.init(Native Method)
	at java.base@18.0.2/java.net.InetAddress.<clinit>(InetAddress.java:362)
	at build.tools.classlist.HelloClasslist.main(HelloClasslist.java:66)

--- make/jdk/src/classes/build/tools/classlist/HelloClasslist.java.orig	2022-07-20 22:54:48 UTC
+++ make/jdk/src/classes/build/tools/classlist/HelloClasslist.java
@@ -62,8 +62,7 @@ public class HelloClasslist {
 
         FileSystems.getDefault();
 
-        List<String> strings = Arrays.asList("Hello", "World!", "From: ",
-                InetAddress.getLoopbackAddress().toString());
+        List<String> strings = Arrays.asList("Hello", "World!");
 
         String helloWorld = strings.parallelStream()
                 .map(s -> s.toLowerCase(Locale.ROOT))
