cmake_minimum_required(VERSION 3.4.3)
set(LLVM_MAIN_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(PACKAGE_VERSION "%%VERSION%%")
set(LIBCXX_CXX_ABI "libcxxabi")
set(PRJDIR "${LLVM_MAIN_SRC_DIR}/projects")
set(LLVM_EXTERNAL_LIBCXX_SOURCE_DIR "${PRJDIR}/libcxx")
set(LIBCXXABI_LIBCXX_PATH "${PRJDIR}/libcxx")
set(LIBCXX_CXX_ABI_INCLUDE_PATHS "${PRJDIR}/libcxxabi/include")
set(LIBCXXABI_USE_LLVM_UNWINDER TRUE)

add_subdirectory(projects/libcxxabi)
add_subdirectory(projects/libcxx)
