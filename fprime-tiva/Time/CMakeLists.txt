set(SOURCE_FILES
    ${CMAKE_CURRENT_LIST_DIR}/TivaTimeImpl.cpp
)

set(MOD_DEPS
  Svc/Time
)

register_fprime_module()