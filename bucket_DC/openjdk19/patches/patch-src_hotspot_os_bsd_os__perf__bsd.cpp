--- src/hotspot/os/bsd/os_perf_bsd.cpp.orig	2023-01-21 05:27:28 UTC
+++ src/hotspot/os/bsd/os_perf_bsd.cpp
@@ -327,7 +327,7 @@ int CPUPerformanceInterface::CPUPerforma
     if (sysctl(mib, miblen, &cpu_load_info, &length, NULL, 0) == -1) {
       return OS_ERR;
     }
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
     size_t alllength = length * _num_procs;
     long *allcpus = NEW_C_HEAP_ARRAY(long, CPUSTATES * _num_procs, mtInternal);
 
@@ -506,7 +506,7 @@ int CPUPerformanceInterface::CPUPerforma
   }
 
   long jvm_context_switches = ((task_events_info_t)task_info_data)->csw;
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
   unsigned int jvm_context_switches = 0;
   size_t length = sizeof(jvm_context_switches);
   if (sysctlbyname("vm.stats.sys.v_swtch", &jvm_context_switches, &length, NULL, 0) == -1) {
