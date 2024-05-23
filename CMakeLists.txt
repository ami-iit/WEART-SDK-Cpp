cmake_minimum_required(VERSION 3.5)
project(WeArtGloveLib
        LANGUAGES CXX C
        VERSION 1.0.0.0)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

# Defines the CMAKE_INSTALL_LIBDIR, CMAKE_INSTALL_BINDIR and many other useful macros.
# See https://cmake.org/cmake/help/latest/module/GNUInstallDirs.html
include(GNUInstallDirs)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
# Export symbols when on windows for making a SHARED lib
if(MSVC)
    set(CMAKE_DEBUG_POSTFIX "d")
endif()

# Build position independent code.(PIC)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# List of CPP (source) library files.
set(${PROJECT_NAME}_SRC
                    MiddlewareStatusListener.cpp
                    WeArtClient.cpp
                    WeArtEffect.cpp
                    WeArtHapticObject.cpp
                    WeArtMessages.cpp
                    WeArtMessageSerializer.cpp
                    WeArtAnalogSensorData.cpp
                    WeArtThimbleTrackingObject.cpp
                    WeArtTrackingCalibration.cpp
                    WeArtTrackingRawData.cpp
)

# Shared/Dynamic or Static library?
option(BUILD_SHARED_LIBS "Build libraries as shared as opposed to static" ON)

# List of HPP (header) library files.
set(${PROJECT_NAME}_HDR
                    MiddlewareStatusListener.h
                    WeArtClient.h
                    WeArtCommon.h
                    WeArtController.h
                    WeArtEffect.h
                    WeArtForce.h
                    WeArtHapticObject.h
                    WeArtMessageListener.h
                    WeArtMessages.h
                    WeArtMessageSerializer.h
                    WeArtAnalogSensorData.h
                    WeArtTemperature.h
                    WeArtTexture.h
                    WeArtThimbleTrackingObject.h
                    WeArtTrackingCalibration.h
                    WeArtTrackingRawData.h
                    WeArtGloveLib.h
                    nlohmann/json.hpp
)

# Add SHARED library with source *.cpp in src directory
add_library(${PROJECT_NAME} ${${PROJECT_NAME}_SRC} ${${PROJECT_NAME}_HDR})

# Enable RPATH support for installed binaries and libraries
include(AddInstallRPATHSupport)
add_install_rpath_support(BIN_DIRS "${CMAKE_INSTALL_FULL_BINDIR}"
                           LIB_DIRS "${CMAKE_INSTALL_FULL_LIBDIR}"
                           INSTALL_NAME_DIR "${CMAKE_INSTALL_FULL_LIBDIR}"
                           USE_LINK_PATH)


set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${${PROJECT_NAME}_VERSION}
                                                        PUBLIC_HEADER "${${PROJECT_NAME}_HDR}")
set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(${PROJECT_NAME} windowsapp.lib runtimeobject.lib)

target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
                                                         "$<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}>")

install(TARGETS ${PROJECT_NAME}
        EXPORT  ${PROJECT_NAME}
        LIBRARY       DESTINATION "${CMAKE_INSTALL_LIBDIR}"                            COMPONENT shlib
        ARCHIVE       DESTINATION "${CMAKE_INSTALL_LIBDIR}"                            COMPONENT lib
        RUNTIME       DESTINATION "${CMAKE_INSTALL_BINDIR}"                            COMPONENT bin
        PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}"        COMPONENT dev)

include(InstallBasicPackageFiles)
install_basic_package_files(${PROJECT_NAME}
                             VERSION ${${PROJECT_NAME}_VERSION}
                             COMPATIBILITY AnyNewerVersion
                             VARS_PREFIX ${PROJECT_NAME}
                             NO_CHECK_REQUIRED_COMPONENTS_MACRO)

# Add the uninstall target
include(AddUninstallTarget)
