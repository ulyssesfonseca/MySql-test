#include <QCoreApplication>
#include <QDebug>
#include <QtSql>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //qDebug() << "drivers:" << QSqlDatabase::drivers();


    if(QSqlDatabase::drivers().contains("QMYSQL"))
    {

        //especifica o driver do tipo da base de dados
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("192.168.222.62");
        db.setPort(3306);
        db.setDatabaseName("teste");
        db.setUserName("root");
        db.setPassword("12345");

        bool s_db = db.open();

        qDebug() << "Conexao : " << s_db;


            QSqlQuery query("SELECT * FROM tabela_01");
            //qDebug() << query.exec("SELECT * FROM teste.tabela_01;");

            while(query.next())
            {
                QString name = query.value(1).toString();
                qDebug() << name;
            }

    }
    else
    {
        qDebug() << "Instalar driver QMYSQL";
    }
    qDebug() << "fim";


    return a.exec();
}
