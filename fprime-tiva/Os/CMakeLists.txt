# Basic module dependencies
set(MOD_DEPS
  Fw/Cfg
  Fw/Types
  # Fw/Logger
  # Utils/Hash
)

####
# Source Files:
#
# These source files activate the baremetal virtualization technology that allows for the PIco
# layer to take advantage of all functions of F prime (threaded components included) while still
# not using an OS. It is experimental technology, but it should work.
####

set(SOURCE_FILES
    # Common implementations
    ${FPRIME_FRAMEWORK_PATH}/Os/TaskCommon.cpp
    ${FPRIME_FRAMEWORK_PATH}/Os/TaskString.cpp
    ${FPRIME_FRAMEWORK_PATH}/Os/QueueCommon.cpp
    ${FPRIME_FRAMEWORK_PATH}/Os/QueueString.cpp
    # Baremetal virtualization implementations
    ${FPRIME_FRAMEWORK_PATH}/Os/Baremetal/Queue.cpp
    ${FPRIME_FRAMEWORK_PATH}/Os/Baremetal/Task.cpp
    ${FPRIME_FRAMEWORK_PATH}/Os/Baremetal/File.cpp
    ${FPRIME_FRAMEWORK_PATH}/Os/Baremetal/FileSystem.cpp
    ${FPRIME_FRAMEWORK_PATH}/Os/Baremetal/IntervalTimer.cpp
    ${FPRIME_FRAMEWORK_PATH}/Os/Baremetal/Mutex.cpp
    ${FPRIME_FRAMEWORK_PATH}/Os/Baremetal/SystemResources.cpp
    # Non-OS based queue implementations
    ${FPRIME_FRAMEWORK_PATH}/Os/Pthreads/BufferQueueCommon.cpp
    ${FPRIME_FRAMEWORK_PATH}/Os/Pthreads/FIFOBufferQueue.cpp
    # Provided by this package
    ${CMAKE_CURRENT_LIST_DIR}/tiva/IntervalTimer.cpp
)
register_fprime_module()

# In short, this Os layer depends on the framework's Os layer and vise-versa.
# Effectively it is one library build in two halves, the framework base, and
# this add-on. Here we make the link pointers depend on one another forming a
# weak circular dependency. This is allowed in CMake >=3.13.0
add_dependencies(Os fprime-tiva_Os)
target_link_libraries(Os PUBLIC fprime-tiva_Os)
target_link_libraries(fprime-tiva_Os PRIVATE Os)