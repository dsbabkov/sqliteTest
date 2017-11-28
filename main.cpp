#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

void createTables() {
    QSqlQuery (
               "CREATE TABLE Materials ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "Name TEXT"
               ");"
               );
}

void fillMaterials() {
    QSqlQuery ("INSERT INTO Materials (Name) "
              "VALUES ('20GL'), ('Cast iron');"
                );
}

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv)

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");
    qDebug() << "Database opened: " << db.open();

    createTables();
    fillMaterials();

    QSqlQuery query("SELECT * FROM Materials");
    while(query.next()) {
        qDebug() << query.value("id").toInt() << '\t' << query.value("name").toString();
    }

    return 0;
}
