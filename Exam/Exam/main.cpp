#include "Exam.h"
#include <QtWidgets/QApplication>
#include "Tests.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    addStarService_ValidInput_AllGood();
    addStarService_InvalidInputForName_ThrowEx();
    addStarService_InvalidInputForDiam_ThrowEx();

    Repository repo{ "Astronomers.txt","Stars.txt" };
    Service serv{ &repo };
    for (auto t : serv.getAllA())
    {
        Exam* w = new Exam{ serv,t };
        serv.addObserver(w);
        w->show();
    }
    return a.exec();
}
