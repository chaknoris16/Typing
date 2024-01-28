set(BINARY ${CMAKE_PROJECT_NAME}_tst)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Sql)
find_package(GTest REQUIRED)

add_executable(${BINARY}
main.cpp
test_jsonfileparser.cpp
test_jsonfileparser.h
test_bdmanager.h test_bdmanager.cpp
../src/jsonconfigparser.h
../src/jsonconfigparser.cpp
../src/IDBManager.h
../src/DBTestingQuery.h
../src/DBTreningQuery.h

)



add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Sql GTest::GTest)

