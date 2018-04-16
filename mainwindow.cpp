#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MySqlInit();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MySqlInit()
{
    QSqlDatabase qDatabases = QSqlDatabase::addDatabase("QMYSQL");
    qDatabases.setDatabaseName("students");    // 需要与数据库中的一致
    qDatabases.setHostName("localhost");    // 主机名(地址)
    qDatabases.setPort(3306);        // 端口
    qDatabases.setUserName("root");  //设置用户名
    qDatabases.setPassword("sun220807");  //设置密码
    if(qDatabases.open())
        {
            qDebug() << "ok";
        }
        else
        {
            qDebug() << qDatabases.lastError().text();
            qDebug() << QSqlDatabase::drivers();
            qDebug() << QCoreApplication::libraryPaths();
            qDebug(("error"));
        }

}
/*开发环境：
Win7 64位，Qt5.9.4，MySql5.7.21
下载mysql，网址：https://dev.mysql.com/downloads/
下载MySQL Community Server版本，只有这个版本是免费的。
还需要下载Windows (x86, 32-bit), ZIP Archive版本，也就是压缩包版本，这个版本的libmysql.dll才可以连接mysql驱动
把里面lib路径下的libmysql.dll放到D:\Qt\Qt5.9.4\5.9.4\msvc2015\bin下面
注意：
1、发布exe的时候使用Qt自带的Qt5.5 for Desktop程序进行发布，不会这个工具的自行百度，
2、发布的时候也需要将Windows (x86, 32-bit), ZIP Archive版本中lib路径下的libmysql.dll放到exe所在文件夹中，否则会加载驱动失败
*/
