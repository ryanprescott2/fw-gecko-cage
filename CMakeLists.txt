cmake_minimum_required(VERSION 3.14)

project(GeckoCage)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

enable_language(ASM)

add_compile_options(-Werror -Wall -Wno-fatal-errors -Wmissing-field-initializers -Wuninitialized  -Wno-missing-braces -Wunused -Wno-unused-function -Wsign-compare )
add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-Wreorder>)

# clang only
if (CMAKE_CXX_COMPILER_ID MATCHES "(Apple)?[Cc]lang")
  add_compile_options(-Wno-delete-non-abstract-non-virtual-dtor -Wignored-pragmas -Wsometimes-uninitialized -Wcomplex-component-init -Wconditional-uninitialized -Walign-mismatch)
endif()

add_compile_options(-Wno-maybe-uninitialized)

add_subdirectory(external)
add_subdirectory(platform)

add_subdirectory(application)