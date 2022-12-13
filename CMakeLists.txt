cmake_minimum_required(VERSION 3.2)

project (lab3s3)

add_subdirectory(
"${CMAKE_CURRENT_SOURCE_DIR}/googletest"
"googletest"

)


add_executable(
    main
    "${PROJECT_SOURCE_DIR}/main.cpp"
  
)

add_executable(
    test_Number
    "${PROJECT_SOURCE_DIR}/test_Number.cpp"
)

target_include_directories(
test_Number PRIVATE
"${CMAKE_CURRENT_SOURCE_DIR}/lab3s3"

)

target_link_libraries(
test_Number PRIVATE
gtest gtest_main
)



if(MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    target_compile_options(
        main PRIVATE
        /W4
    )
    target_compile_options(
        test_Number PRIVATE
        /W4
    )
else ()
    target_compile_options(
        main PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(
        test_Number PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()