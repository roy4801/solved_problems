# ScanSubdir.cmake
# Reusable function to scan subdirectories and add them if they contain a CMakeLists.txt

function(scan_subdirectories)
	file(GLOB subdirs RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)
	foreach(subdir ${subdirs})
		if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${subdir})
			if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${subdir}/CMakeLists.txt)
				add_subdirectory(${subdir})
			endif()
		endif()
	endforeach()
endfunction()
file(GLOB subdirs RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)
