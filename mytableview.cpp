#include "mytableview.h"
#include "ui_mytableview.h"

#include <QTableView>
#include <QStandardItemModel>

MyTableView::MyTableView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyTableView)
{
    ui->setupUi(this);

#if 0
    QStandardItemModel *model = new QStandardItemModel;
    model->setColumnCount(5);
    model->setRowCount(3);
#else
    QStandardItemModel *model = new QStandardItemModel(3, 5); //指定表格的行列
#endif

    QStringList Hlabels;
    Hlabels << "id" << "name" << "age" << "math" << "eng";
    model->setHorizontalHeaderLabels(Hlabels);   //设置行表头

    QStringList Vlabels;
    Vlabels << "col1" << "col2" << "col3";
    model->setVerticalHeaderLabels(Vlabels);    //设置列表头

    for ( int i = 0; i < model->rowCount(); i++ ) {
        for ( int j = 0; j < model->columnCount(); j++ ) {
            QStandardItem *item = new QStandardItem;
            item->setData(QVariant(i), Qt::EditRole);   //表明以数字形式存储
            model->setItem(i, j, item);
            model->item(i, j)->setTextAlignment(Qt::AlignCenter);   //设置居中
            model->item(i, j)->setForeground(Qt::red);  //设置单元格文本颜色

            QFont font;
            font.setFamily("Times");
            font.setPointSize(12);
            font.setBold(true); //加粗
            font.setItalic(true);   //斜体
            font.setUnderline(true);    //下划线
            model->item(i, j)->setFont(font);   //设置字体

            model->verticalHeaderItem(i)->setFont(font);    //设置表头字体
            model->horizontalHeaderItem(j)->setFont(font);
            model->verticalHeaderItem(i)->setForeground(Qt::red);   //设置表头字体颜色
            model->horizontalHeaderItem(j)->setForeground(Qt::red);
        }
    }

    Qt::ItemFlags flag = model->item(1, 2)->flags();
    model->item(1, 2)->setFlags(flag & ~Qt::ItemIsEditable);    //设置某一单元格不可编辑
    model->sort(3, Qt::DescendingOrder);    //按第四列降序


    QTableView *tableView = new QTableView(this);
//    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);  //设置不可编辑
//    tableView->setSelectionBehavior(QAbstractItemView::SelectRows); //选中一行
//    tableView->horizontalHeader()->setHidden(true); //隐藏列表头
//    tableView->verticalHeader()->setHidden(true);   //隐藏行表头
//    tableView->setSortingEnabled(true);     //设置可排序

    //如果在tableView中使用右键菜单，需启用该属性
    tableView->setContextMenuPolicy(Qt::CustomContextMenu);

    tableView->setModel(model);

    setCentralWidget(tableView);
    resize(550, 300);
}

MyTableView::~MyTableView()
{
    delete ui;
}
