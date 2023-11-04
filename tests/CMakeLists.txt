set(BINARY ${CMAKE_PROJECT_NAME}_tst)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Sql)


add_executable(${BINARY}
main.cpp
test_jsonfileparser.cpp
test_jsonfileparser.h
test_virtualkeyboard.h test_virtualkeyboard.cpp
)



add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql gtest)
target_link_libraries(${BINARY} PRIVATE RATATYPE-C_lib)
