###
# Module for the Blinker component. The role of the Blinker component is to
# blink the microcontroller's onboard LED.
###

# register the component's source files
set(SOURCE_FILES
    ${CMAKE_CURRENT_LIST_DIR}/Blinker.fpp
    ${CMAKE_CURRENT_LIST_DIR}/Blinker.cpp
    $<IF:$<STREQUAL:${TARGET_MICROCONTROLLER},tm4c123gxl>,${CMAKE_CURRENT_LIST_DIR}/BlinkerTiva.cpp,${CMAKE_CURRENT_LIST_DIR}/BlinkerLinux.cpp>
)

# registers a module using the fprime build system
register_fprime_module()

target_link_libraries(App_Blinker PRIVATE 
    $<IF:$<STREQUAL:${TARGET_MICROCONTROLLER},tm4c123gxl>,texas_instruments::tm4c,>
    $<IF:$<BOOL:${USE_TIVAWARE}>,tivaware::tivaware,>
)