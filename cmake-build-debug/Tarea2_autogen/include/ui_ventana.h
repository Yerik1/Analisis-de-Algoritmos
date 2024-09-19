/********************************************************************************
** Form generated from reading UI file 'ventana.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANA_H
#define UI_VENTANA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *prueba;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *bubbleSortButton;
    QPushButton *selectionSortButton;
    QPushButton *mergeSortButton;
    QPushButton *binaryTreeSearchButton;
    QPushButton *allSortedLinkedListSearchButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(835, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: black;"));
        prueba = new QLabel(centralwidget);
        prueba->setObjectName(QString::fromUtf8("prueba"));
        prueba->setGeometry(QRect(330, 100, 63, 20));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 160, 771, 421));
        verticalLayoutWidget->setStyleSheet(QString::fromUtf8("background-color: black;"));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        bubbleSortButton = new QPushButton(centralwidget);
        bubbleSortButton->setObjectName(QString::fromUtf8("bubbleSortButton"));
        bubbleSortButton->setGeometry(QRect(30, 10, 120, 30));
        bubbleSortButton->setStyleSheet(QString::fromUtf8("background-color: black; color: white;"));
        selectionSortButton = new QPushButton(centralwidget);
        selectionSortButton->setObjectName(QString::fromUtf8("selectionSortButton"));
        selectionSortButton->setGeometry(QRect(160, 10, 120, 30));
        selectionSortButton->setStyleSheet(QString::fromUtf8("background-color: black; color: white;"));
        mergeSortButton = new QPushButton(centralwidget);
        mergeSortButton->setObjectName(QString::fromUtf8("mergeSortButton"));
        mergeSortButton->setGeometry(QRect(290, 10, 120, 30));
        mergeSortButton->setStyleSheet(QString::fromUtf8("background-color: black; color: white;"));
        binaryTreeSearchButton = new QPushButton(centralwidget);
        binaryTreeSearchButton->setObjectName(QString::fromUtf8("binaryTreeSearchButton"));
        binaryTreeSearchButton->setGeometry(QRect(420, 10, 160, 30));
        binaryTreeSearchButton->setStyleSheet(QString::fromUtf8("background-color: black; color: white;"));
        allSortedLinkedListSearchButton = new QPushButton(centralwidget);
        allSortedLinkedListSearchButton->setObjectName(QString::fromUtf8("allSortedLinkedListSearchButton"));
        allSortedLinkedListSearchButton->setGeometry(QRect(590, 10, 220, 30));
        allSortedLinkedListSearchButton->setStyleSheet(QString::fromUtf8("background-color: black; color: white;"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "An\303\241lisis de Algoritmos", nullptr));
        prueba->setText(QString());
        bubbleSortButton->setText(QCoreApplication::translate("MainWindow", "Bubble Sort", nullptr));
        selectionSortButton->setText(QCoreApplication::translate("MainWindow", "Selection Sort", nullptr));
        mergeSortButton->setText(QCoreApplication::translate("MainWindow", "Merge Sort", nullptr));
        binaryTreeSearchButton->setText(QCoreApplication::translate("MainWindow", "Binary Tree Search", nullptr));
        allSortedLinkedListSearchButton->setText(QCoreApplication::translate("MainWindow", "All Sorted Linked List Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANA_H
