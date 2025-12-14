# AddSubdirTargets.cmake
# Reusable function to create targets from .cpp files
# Creates targets with naming pattern: <parent_folder>_<current_folder>_<filename>

function(add_subdir_targets)
    # Get parent folder name (e.g., ITSA)
    get_filename_component(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
    get_filename_component(PARENT_FOLDER_NAME ${PARENT_DIR} NAME)

    # Get current folder name (e.g., 202512)
    get_filename_component(CURRENT_FOLDER_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

    # Scan all .cpp files in this directory
    file(GLOB CPP_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

    foreach(CPP_FILE ${CPP_FILES})
        # Get filename without extension (e.g., p1)
        get_filename_component(FILE_NAME ${CPP_FILE} NAME_WE)
        
        # Create target name: <parent>_<current>_<filename>
        set(TARGET_NAME "${PARENT_FOLDER_NAME}_${CURRENT_FOLDER_NAME}_${FILE_NAME}")
        
        # Check if target matches the filter pattern
        if(NOT "${TARGET_NAME}" MATCHES "${TARGET_FILTER}")
            continue()
        endif()
        
        add_executable(${TARGET_NAME} ${CPP_FILE})
        
        # Set working directory to source directory for debugging/running
        set_target_properties(${TARGET_NAME} PROPERTIES
            VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        )
    endforeach()
endfunction()
