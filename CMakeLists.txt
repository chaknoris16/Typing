cmake_minimum_required(VERSION 3.21)

project(TypingTrainer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#option(BUILD_TESTS "Build tests" ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

set(PROJECT_SOURCES
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.h
    src/mainwindow.ui
    src/resultwindow.cpp
    src/resultwindow.h
    src/resultwindow.ui
    src/resurce.qrc
    src/startwindow.cpp
    src/startwindow.h
    src/startwindow.ui
    src/typingtestingpage.h src/typingtestingpage.cpp
    src/vector_of_exercises.h  src/vector_of_exercises.cpp
    src/virtual_keyboard.h src/virtual_keyboard.cpp
    src/jsonconfigparser.h src/jsonconfigparser.cpp
    src/tableoutput.h src/tableoutput.cpp
    src/keyboardlayoutlanguagecontroller.h src/keyboardlayoutlanguagecontroller.cpp
    src/incorrectkeyboardlayout.h src/incorrectkeyboardlayout.cpp src/incorrectkeyboardlayout.ui
    src/IDBManager.h
    src/DBTreningQuery.h
    src/DBTestingQuery.h
    src/IJsonTextParser.h
    src/RandomElementPicker.h
    src/IRandomTextProvider.h
    src/IColorizeCharacter.h
    src/CharacterColorist.h
    src/ITypingSpeedCalculator.h
    src/TypingSpeedCalculator.h
    src/CostomComboBox.h
    src/ComboBoxManager.h
    src/ResourceCopier.h
)

add_executable(TypingTrainer
    ${PROJECT_SOURCES}
)

target_link_libraries(TypingTrainer PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
                                            Qt${QT_VERSION_MAJOR}::Sql)

include(GNUInstallDirs)
install(TARGETS TypingTrainer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(TypingTrainer)
endif()


if (ON)
 enable_testing()
 add_subdirectory(tests)
endif ()
