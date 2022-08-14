cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(vg_editor VERSION ${PROJECT_VERSION})

configure_file(version.h.in version.h)

add_executable(vg_editor_cli main.cpp)
add_library(vg_controller vg_controller.cpp)

set_target_properties(vg_editor_cli vg_controller PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(vg_controller
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(vg_editor_cli PRIVATE
    vg_controller
)


if (MSVC)
    target_compile_options(vg_editor_cli PRIVATE
        /W4
    )
    target_compile_options(vg_controller PRIVATE
        /W4
    )
else ()
    target_compile_options(vg_editor_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(vg_controller PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()



install(TARGETS vg_editor_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

