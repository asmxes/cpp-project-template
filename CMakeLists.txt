cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 11)

message(STATUS ${CMAKE_CXX_COMPILER})

# Nome del progetto
project(ProjectName)

# Aggiunge tutte le directory necessarie
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(LIB_DIR "${CMAKE_SOURCE_DIR}/lib")
set(ASSETS_DIR "${CMAKE_SOURCE_DIR}/assets")
set(BIN_DIR "${CMAKE_SOURCE_DIR}/bin")
set(BUILD_DIR "${CMAKE_BINARY_DIR}")

# Impostazioni per le opzioni di build
option(DEBUG_MODE "Build in debug mode" OFF)

if (DEBUG_MODE)
    set(CMAKE_BUILD_TYPE Debug)
    set(CMAKE_CXX_FLAGS_DEBUG "-g")
    set(TARGET_NAME "${PROJECT_NAME}_d")
else()
    set(CMAKE_BUILD_TYPE Release)
    set(TARGET_NAME ${PROJECT_NAME})
endif()

# Imposta il percorso delle librerie esterne
link_directories(${LIB_DIR})

# Includi i file header
include_directories(${INCLUDE_DIR})

# Aggiungi i file sorgenti
file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp")

# Aggiunge il target eseguibile
add_executable(${TARGET_NAME} ${SOURCES})
# add_library(${TARGET_NAME} SHARED ${SOURCES})
# add_library(${TARGET_NAME} STATIC ${SOURCES})

# Linka le librerie esterne se necessario
# target_link_libraries(${TARGET_NAME} libname)

# Imposta le directory di output
set_target_properties(${TARGET_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${BIN_DIR}
    ARCHIVE_OUTPUT_DIRECTORY ${BIN_DIR}
)

# Aggiunge un target per la pulizia
add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${BUILD_DIR}/*
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${BIN_DIR}/*
    COMMENT "Pulizia del contenuto della directory build"
)

target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -pedantic)

# Messaggio finale
message(STATUS "Build directory: ${BUILD_DIR}")
message(STATUS "Binary directory: ${BIN_DIR}")
