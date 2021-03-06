#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Exam.h"
#include "Service.h"
#include <QMessageBox>
#include "TableModel.h"
#include "viewWidget.h"
class Exam : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    Exam(Service& service, Astronomer a,QWidget *parent = Q_NULLPTR);

private:
    Ui::ExamClass ui;
    Service& service;
    Astronomer a;
    //int index;

    void openWindow();
    void check(int c);

    int getSelectedIndex();
    void add();
    void search();
    void populateList();
    void update() override;

};
