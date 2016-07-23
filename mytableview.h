#ifndef MYTABLEVIEW_H
#define MYTABLEVIEW_H

#include <QMainWindow>

namespace Ui {
class MyTableView;
}

class MyTableView : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyTableView(QWidget *parent = 0);
    ~MyTableView();

private:
    Ui::MyTableView *ui;
};

#endif // MYTABLEVIEW_H
