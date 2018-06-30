
if (DRAWING_EXAMPLE)
    add_executable(system.drawing.example1
        example1.cpp
        )

    target_compile_features(system.drawing.example1
        PRIVATE cxx_auto_type
        PRIVATE cxx_nullptr
        PRIVATE cxx_range_for
        PRIVATE cxx_thread_local
        )

    target_include_directories(system.drawing.example1
        PUBLIC
            ../include
        )

    target_link_libraries(system.drawing.example1
        system.drawing
        )
endif()
