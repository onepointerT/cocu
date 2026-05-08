
cmake_minimum_required( VERSION 3.15 )

project( cocu LANGUAGES CXX )

set( LIBCOCU_STABLE_VERSION 0 )
set( LIBCOCU_RELEASE 0 )
set( LIBCOCU_PATCH_VERSION 1 )
set( LIBCOCU_VERSION "${LIBCOCU_STABLE_VERSION}.${LIBCOCU_RELEASE}.${LIBCOCU_PATCH_VERSION}" )

set( LIBCOCU_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src )

set ( PROJECT_NAME "${CMAKE_PROJECT_NAME}" )
set ( PROJECT_VERSION "${LIBCOCU_VERSION}" )
set ( PROJECT_DESCRIPTION "Context Cursors -- Know what the user is doing and advance the next situations" )

set ( CMAKE_CXX_STANDARD 23 )


if( COCU_DESTDIR )
else()
	set( COCU_DESTDIR "${CMAKE_INSTALL_PREFIX}" )
endif()

add_subdirectory( ${CMAKE_CURRENT_SOURCE_DIR}/lib/ )

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/cocu )
file ( GLOB LIBCOCU_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/cocu/*.cpp )
add_library( cocu STATIC ${LIBCOCU_SOURCE} )
target_link_libraries( cocu passengercpp oneptr_priobool )


if( COCU_HEADER_INSTALL_DIR )
else()
	set( COCU_HEADER_INSTALL_DIR ${COCU_DESTDIR}/include/libcocu )
endif()

if ( COCU_LIB_INSTALL_DIR )
else()
	set ( COCU_LIB_INSTALL_DIR ${COCU_DESTDIR}/lib )
endif()

if( COCU_INSTALL_LIBS )
	install(TARGETS coculib DESTINATION ${COCU_LIB_INSTALL_DIR} )
	install(FILES ${LIBCOCU_HEADERS} DESTINATION ${COCU_HEADER_INSTALL_DIR} )
	install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/cmake/FindPrelude.cmake DESTINATION "${COCU_LIB_INSTALL_DIR}/cmake/FindPrelude.cmake" )
	configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/cocu.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/cmake/cocu.cmake @ONLY)
	install(FILES ${CMAKE_CURRENT_BINARY_DIR}/cmake/cocu.cmake DESTINATION "${COCU_LIB_INSTALL_DIR}/cmake" )
endif()


if( UNIX AND ENABLE_DOC_COCU )
	find_package(Doxygen)
	if(DOXYGEN_FOUND)
		message("-- Enabled doc_cocu target for make")
		configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
		add_custom_target(doc_cocu ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} COMMENT "Generating documentation with Doxygen")
	endif()
endif()
