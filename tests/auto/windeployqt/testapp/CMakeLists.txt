# Generated from testapp.pro.

#####################################################################
## testapp Binary:
#####################################################################

qt_add_executable(testapp
    GUI
    OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/"
    SOURCES
        main.cpp
    PUBLIC_LIBRARIES
        Qt::Gui
)
