#include "test_bdmanager.h"
#include <execution>
#include <QVariant>
test_BDManager::test_BDManager() {}

test_BDManager::~test_BDManager()
{
    delete db;
}

TEST_F(test_BDManager, saveResults) {
    this->result << "exercise" << 1 << 2;
    QVector<QPair<QString, QVariant>> testResults = {
        QPair("Exercise", QVariant(result[0])),
        QPair("Typing speed", QVariant(result[1])),
        QPair("Number of mistakes", QVariant(result[2]))
    };

    this->db->saveResult(this->result);
    QVariantMap lastEntry = this->db->getAllResults().back();
    for (const auto &testValue : testResults) {
        ASSERT_TRUE(lastEntry[testValue.first] == testValue.second);
    }
}
