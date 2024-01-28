#ifndef TEST_BDMANAGER_H
#define TEST_BDMANAGER_H
#include <gtest/gtest.h>
#include "../src/IDBManager.h"
#include "../src/DBTreningQuery.h"
#include "../src/DBTestingQuery.h"
#include <QVector>
class test_BDManager : public ::testing::Test
{
public:
    test_BDManager();
    ~test_BDManager();
    IDBManager* db = new DBTreningQuery("TEST_typing_data.db", "queryName");
    QVariantList result;

};

#endif // TEST_BDMANAGER_H
