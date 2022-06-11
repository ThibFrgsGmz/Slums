set(TIVA_STARTUP_SOURCES ${CMAKE_CURRENT_LIST_DIR}/startup.c ${CMAKE_CURRENT_LIST_DIR}/syscalls.c)

####
# add_tiva_startup_dependency:
#
# @brief Adds a dependency on the built version of the Tiva startup library which
# includes the startup file and the system calls.
#
# @note I couldn't figure out why my syscalls were still being "not found" 
# during linking and this blog post helped me resolve that bug:
# https://jonathanhamberg.com/post/gcc-archive-linker-oddity/
#
# @param target: target project used to identify the output executable
#
# @example
#   get_module_name(${CMAKE_CURRENT_LIST_DIR})
#   add_tiva_startup_dependency(${MODULE_NAME})
####
function(add_tiva_startup_dependency target)
    # Create the startup library for the TI microcontroller
    if (NOT TARGET tiva::startup)
        add_library(tm4c123gxl_startup ${TIVA_STARTUP_SOURCES})
        target_link_options(tm4c123gxl_startup PUBLIC -Wl,--whole-archive ${CMAKE_CURRENT_BINARY_DIR}/lib/tm4c123gxl/libtm4c123gxl_startup.a -Wl,--no-whole-archive)
        add_library(tiva::startup ALIAS tm4c123gxl_startup)
    endif()

    # Add a dependency on the startup library to the target
    add_dependencies(${target} tiva::startup)
    target_link_libraries(${target} PRIVATE tiva::startup)
endfunction()