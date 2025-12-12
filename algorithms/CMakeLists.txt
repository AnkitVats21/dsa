file(GLOB children RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*")

foreach(child ${children})
    if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${child}")

        file(GLOB alg_src
            "${CMAKE_CURRENT_SOURCE_DIR}/${child}/*.cpp"
        )

        foreach(src ${alg_src})
            set_source_files_properties(
                ${src}
                PROPERTIES COMPILE_DEFINITIONS CATEGORY_NAME="${child}"
            )
        endforeach()

        list(APPEND ALL_ALGORITHM_SOURCES ${alg_src})
    endif()
endforeach()

add_library(Algorithms SHARED ${ALL_ALGORITHM_SOURCES})
target_include_directories(Algorithms PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Algorithms PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../base)
