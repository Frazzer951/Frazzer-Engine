set(LIB_NAME Frazzer_Engine)

include(FetchContent)
FetchContent_Declare(
        sfml
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG master
)
FetchContent_GetProperties(sfml)
if (NOT sfml_POPULATED)
    set(BUILD_SHARED_LIBS OFF)
    FetchContent_Populate(sfml)
    add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
endif ()

add_library (${LIB_NAME} frazzerEngine.cpp frazzerEngine.h)
target_link_libraries(${LIB_NAME} sfml-graphics)
target_include_directories (${LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})