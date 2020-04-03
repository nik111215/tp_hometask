add_library(buffer SHARED buffer.cpp)
if (ARM_BUILD)
    install(TARGETS buffer DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
endif()
