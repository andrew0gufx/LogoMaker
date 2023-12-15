cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME sfml_project)

link_libraries(stdc++fs)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp cmake_modules/bounce.cpp cmake_modules/bounce.h cmake_modules/moving.cpp cmake_modules/moving.h MultiText/TypingSFML.cpp MultiText/TypingSFML.h TextInputBox.cpp TextInputBox.h TextInput.cpp TextInput.h GUIComponent.cpp GUIComponent.h DropdownMenu.cpp DropdownMenu.h EventHandler.h History.cpp History.h Item.cpp Item.h ItemList.cpp ItemList.h MouseEvents.h SnapShot.cpp SnapShot.h States.cpp SnapshotInterface.h Menu.cpp Menu.h MenuBar.cpp MenuBar.h States.h BottomMenu.cpp BottomMenu.h Typing.cpp Typing.h Cursor.cpp Cursor.h FileItem.cpp FileItem.h FileNode.cpp FileNode.h FileTree.cpp FileTree.h WindowDialog.cpp WindowDialog.h Slider.cpp Slider.h ColorBar.cpp ColorBar.h FontSetting.cpp FontSetting.h NewFile.cpp NewFile.h ColorGradient.cpp ColorGradient.h ColorSquare.cpp ColorSquare.h ColorList.cpp ColorList.h ColorPicker.cpp ColorPicker.h InputBox.cpp InputBox.h LogoMaker.cpp LogoMaker.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()