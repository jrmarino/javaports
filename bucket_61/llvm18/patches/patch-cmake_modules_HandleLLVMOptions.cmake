--- cmake/modules/HandleLLVMOptions.cmake.orig	2024-06-15 17:21:32 UTC
+++ cmake/modules/HandleLLVMOptions.cmake
@@ -271,7 +271,7 @@ endif()
 
 # Pass -Wl,-z,defs. This makes sure all symbols are defined. Otherwise a DSO
 # build might work on ELF but fail on MachO/COFF.
-if(NOT (CMAKE_SYSTEM_NAME MATCHES "Darwin|FreeBSD|OpenBSD|DragonFly|AIX|OS390" OR
+if(NOT (TRUE OR
         WIN32 OR CYGWIN) AND
    NOT LLVM_USE_SANITIZER)
   set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-z,defs")
