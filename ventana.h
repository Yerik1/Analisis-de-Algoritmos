//
// Created by yerik on 9/18/24.
//

#ifndef VENTANA_H
#define VENTANA_H


#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void clearLayout(QLayout *layout);

    private slots:
        //void on_pushButton_clicked();

        void onBubbleSortButtonClicked();

    void onSelectionSortButtonClicked();

    void onMergeSortButtonClicked();

    void onBinaryTreeSearchButtonClicked();

    void onAllSortedLinkedListSearchButtonClicked();

private:
    Ui::MainWindow *ui;
    void createChart(const QString &algName);
};
#endif //VENTANA_H
