aux_source_directory(. SRCS)
include_directories(.)
foreach(SRC  ${SRCS})
    if(${SRC} MATCHES  ".*\\.(cpp|cc)$" )
        #the target name will be the prefix of ${SRC}
        #e.g. demo3.cpp --> demo3
        get_filename_component(BIN ${SRC} NAME_WE )
        add_executable(${BIN} ${SRC})
        target_link_libraries(${BIN} pthread)
    endif()
endforeach(SRC)