cmake_minimum_required(VERSION 3.13.0)
project(template VERSION 0.1.0)

#For using ./cmake/aux_cpp.cmake in sub-directory,
#we need to append ./cmake to `CMAKE_MODULE_PATH`
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
#Saving target binary to ./bin
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(CMAKE_CXX_STANDARD 17)


include(CTest)
enable_testing()

#Using linux cmd `ls` to get all sub-directory  
execute_process(COMMAND  "ls" WORKING_DIRECTORY ${PROJECT_SOURCE_DIR} OUTPUT_VARIABLE DirStr )

#For using `foreach(item  ${Dir} )`,
#we need to convert `CMake string` ${DirStr} to `CMake list` ${Dir}.
string(REPLACE "\n" ";" Dir ${DirStr})

#Traversing ${Dir}
foreach(item  ${Dir} )

    #Getting ABSOLUTE path. item ---> /path/to/item
    get_filename_component(fullpath ${item} ABSOLUTE  )

    #Ignoring item which is not DIRECTORY,something like ReadMe.md
    if(IS_DIRECTORY ${fullpath}) 
        #Filter out some sub-directory that you don't want to contain
        if(${item} MATCHES "^(bin)|(build)|(.vscode)$" )
            message(STATUS "Ignore Directory: ${item}")
            continue()
        endif()
        #Retrieving sub-directory  which contains  CMakeLists.txt
        if(EXISTS ${fullpath}/CMakeLists.txt)
            message(STATUS "Add Sub-Directory: ${fullpath}")
            add_subdirectory(${fullpath})
        endif()
    endif()

endforeach()


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
