#=======================================================================================================================
# Define library targets
#=======================================================================================================================
add_library(Algorithms INTERFACE)
add_library(Algorithms::Algorithms ALIAS Algorithms)
target_include_directories(Algorithms INTERFACE ${CMAKE_CURRENT_LIST_DIR})

#=======================================================================================================================
# Install Zippy Library
#=======================================================================================================================
#include(GNUInstallDirs)
#install(TARGETS Zippy
#        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}${INSTALL_SUFFIX}
#        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}${INSTALL_SUFFIX}
#        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
#install(FILES ${Zippy_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/Zippy)