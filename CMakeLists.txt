cmake_minimum_required(VERSION 3.20)
project(Benchme C)

set(CMAKE_C_STANDARD 99)

add_executable(Benchme main.c libs/generateArray.c libs/header.h libs/InsertionSort.c libs/HeapSort.c libs/bubbleSort.c libs/selectionSort.c)

find_package(Doxygen)

if (DOXYGEN_FOUND)
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started.")

    add_custom_target( doc ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}
            COMMENT "Generating documentation with Doxygen"
            VERBATIM )
else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate doxygen documentation")
endif (DOXYGEN_FOUND)