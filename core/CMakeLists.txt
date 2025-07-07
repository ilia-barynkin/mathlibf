add_library(mathlib_core core.c)
target_include_directories(mathlib_core 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(test_core test_core.c)
target_link_libraries(test_core mathlib_core)
target_compile_definitions(test_core PRIVATE TESTING=1)
add_test(NAME test_core COMMAND test_core)