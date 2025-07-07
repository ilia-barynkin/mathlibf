add_library(mathlib_geometry geometry.c)
target_include_directories(mathlib_geometry 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(mathlib_geometry
    PRIVATE mathlib_core)
add_executable(test_geometry test_geometry.c)
target_include_directories(test_geometry
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../core
        ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(test_geometry
    PRIVATE
    mathlib_geometry 
    mathlib_core
    m)
target_compile_definitions(test_geometry PRIVATE TESTING=1)
add_test(NAME test_geometry COMMAND test_geometry)