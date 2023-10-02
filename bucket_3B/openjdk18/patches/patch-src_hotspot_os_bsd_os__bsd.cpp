--- src/hotspot/os/bsd/os_bsd.cpp.orig	2022-07-20 22:54:48 UTC
+++ src/hotspot/os/bsd/os_bsd.cpp
@@ -100,7 +100,7 @@
   #include <elf.h>
 #endif
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
   #include <pthread_np.h>
   #include <sys/link_elf.h>
   #include <vm/vm_param.h>
@@ -180,7 +180,7 @@ julong os::Bsd::available_memory() {
   if (kerr == KERN_SUCCESS) {
     available = vmstat.free_count * os::vm_page_size();
   }
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
   static const char *vm_stats[] = {
     "vm.stats.vm.v_free_count",
     "vm.stats.vm.v_cache_count",
@@ -188,7 +188,11 @@ julong os::Bsd::available_memory() {
   };
   size_t size;
   julong free_pages;
+#ifdef __DragonFly__
+  u_long i, npages;
+#else
   u_int i, npages;
+#endif
 
   for (i = 0, free_pages = 0; i < sizeof(vm_stats) / sizeof(vm_stats[0]); i++) {
     size = sizeof(npages);
@@ -366,7 +370,7 @@ void os::init_system_properties_values()
     #elif defined(__NetBSD__)
       #define DEFAULT_LIBPATH "/usr/lib:/usr/pkg/lib"
     #else
-      #define DEFAULT_LIBPATH "/usr/lib:/usr/local/lib"
+      #define DEFAULT_LIBPATH "/usr/lib:%%LOCALBASE%%/lib"
     #endif
   #else
     #define DEFAULT_LIBPATH OVERRIDE_LIBPATH
@@ -878,7 +882,7 @@ pid_t os::Bsd::gettid() {
   mach_port_deallocate(mach_task_self(), port);
   return (pid_t)port;
 
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
   return ::pthread_getthreadid_np();
 #elif defined(__OpenBSD__)
   retval = getthrid();
@@ -1290,7 +1294,7 @@ static int iter_callback(struct dl_phdr_
 }
 #endif
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 struct loaded_modules_info_param {
   os::LoadedModulesCallbackFunc callback;
   void *param;
@@ -1332,7 +1336,7 @@ static int dl_iterate_callback(struct dl
 #endif
 
 int os::get_loaded_modules_info(os::LoadedModulesCallbackFunc callback, void *param) {
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
   struct loaded_modules_info_param callback_param = {callback, param};
   return dl_iterate_phdr(&dl_iterate_callback, &callback_param);
 #elif defined(RTLD_DI_LINKMAP)
@@ -2207,7 +2211,11 @@ int os::active_processor_count() {
     return online_cpus;
 #endif
 
+#ifdef __DragonFly__
+  return sysconf(_SC_NPROCESSORS_ONLN);
+#else
   return _processor_count;
+#endif
 }
 
 uint os::processor_id() {
@@ -2258,7 +2266,7 @@ void os::set_native_thread_name(const ch
     char buf[MAXTHREADNAMESIZE];
     snprintf(buf, sizeof(buf), "Java: %s", name);
     pthread_setname_np(buf);
-#elif defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
     pthread_set_name_np(pthread_self(), name);
 #elif defined(__NetBSD__)
     pthread_setname_np(pthread_self(), "%s", const_cast<char *>(name));
