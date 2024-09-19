//
// Created by yerik on 9/18/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ventana.h" resolved

#include "ventana.h"

#include <cmath>

#include "./ui_ventana.h"
#include <iostream>
#include "mediciones.h"
#include <QChartView>
#include <QLineSeries>
#include <QValueAxis>
#include <QSplitter>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->bubbleSortButton, &QPushButton::clicked, this, &MainWindow::onBubbleSortButtonClicked);
    connect(ui->selectionSortButton, &QPushButton::clicked, this, &MainWindow::onSelectionSortButtonClicked);
    connect(ui->mergeSortButton, &QPushButton::clicked, this, &MainWindow::onMergeSortButtonClicked);
    connect(ui->binaryTreeSearchButton, &QPushButton::clicked, this, &MainWindow::onBinaryTreeSearchButtonClicked);
    connect(ui->allSortedLinkedListSearchButton, &QPushButton::clicked, this, &MainWindow::onAllSortedLinkedListSearchButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::clearLayout(QLayout *layout)
{
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr) {
        delete item->widget(); // Elimina el widget (en este caso, el QChartView)
        delete item;           // Elimina el QLayoutItem
    }
}
void MainWindow::createChart(const QString &algName) {
    // Limpiar el layout antes de agregar un nuevo gráfico
    clearLayout(ui->verticalLayout);

    string alg = algName.toStdString();

    // Crear series para los datos
    QtCharts::QLineSeries *seriesBest = new QtCharts::QLineSeries();
    QtCharts::QLineSeries *seriesAverage = new QtCharts::QLineSeries();
    QtCharts::QLineSeries *seriesWorst = new QtCharts::QLineSeries();
    QtCharts::QLineSeries *seriesTheoretical = new QtCharts::QLineSeries();

    seriesBest->setName("Best Case");
    seriesAverage->setName("Average Case");
    seriesWorst->setName("Worst Case");
    seriesTheoretical->setName("Theoretical Case");

    int N1 = 1000;
    int N2 = 2000;
    int N3 = 3000;
    int N4 = 4000;
    int N5 = 5000;

    // Inicialización de vectores para tamaños N1 a N5
    vector<int> best_case1(N1), worst_case1(N1), avg_case1(N1);
    vector<int> best_case2(N2), worst_case2(N2), avg_case2(N2);
    vector<int> best_case3(N3), worst_case3(N3), avg_case3(N3);
    vector<int> best_case4(N4), worst_case4(N4), avg_case4(N4);
    vector<int> best_case5(N5), worst_case5(N5), avg_case5(N5);

    MeasureTime medida;

    // Para N1
    iota(best_case1.begin(), best_case1.end(), 1);    // Caso mejor
    worst_case1=best_case1;
    reverse(worst_case1.begin(), worst_case1.end());  // Caso peor
    generate(avg_case1.begin(), avg_case1.end(), std::rand); // Caso promedio

    auto wc1 = medida.measureTime(alg, worst_case1,2);
    auto avg1 = medida.measureTime(alg, avg_case1,3);
    auto bc1 = medida.measureTime(alg, best_case1,1);

    seriesWorst->append(N1, wc1);
    seriesAverage->append(N1, avg1);
    seriesBest->append(N1, bc1);

    // Para N2
    iota(best_case2.begin(), best_case2.end(), 1);    // Caso mejor
    worst_case2=best_case2;
    reverse(worst_case2.begin(), worst_case2.end());  // Caso peor
    generate(avg_case2.begin(), avg_case2.end(), std::rand); // Caso promedio

    auto wc2 = medida.measureTime(alg, worst_case2,2);
    auto avg2 = medida.measureTime(alg, avg_case2,3);
    auto bc2 = medida.measureTime(alg, best_case2,1);

    seriesWorst->append(N2, wc2);
    seriesAverage->append(N2, avg2);
    seriesBest->append(N2, bc2);

    // Para N3
    iota(best_case3.begin(), best_case3.end(), 1);    // Caso mejor
    worst_case3=best_case3;
    reverse(worst_case3.begin(), worst_case3.end());  // Caso peor
    generate(avg_case3.begin(), avg_case3.end(), std::rand); // Caso promedio

    auto wc3 = medida.measureTime(alg, worst_case3,2);
    auto avg3 = medida.measureTime(alg, avg_case3,3);
    auto bc3 = medida.measureTime(alg, best_case3,1);

    seriesWorst->append(N3, wc3);
    seriesAverage->append(N3, avg3);
    seriesBest->append(N3, bc3);

    // Para N4
    iota(best_case4.begin(), best_case4.end(), 1);    // Caso mejor
    worst_case4=best_case4;
    reverse(worst_case4.begin(), worst_case4.end());  // Caso peor
    generate(avg_case4.begin(), avg_case4.end(), std::rand); // Caso promedio

    auto wc4 = medida.measureTime(alg, worst_case4,2);
    auto avg4 = medida.measureTime(alg, avg_case4,3);
    auto bc4 = medida.measureTime(alg, best_case4,1);

    seriesWorst->append(N4, wc4);
    seriesAverage->append(N4, avg4);
    seriesBest->append(N4, bc4);

    // Para N5
    iota(best_case5.begin(), best_case5.end(), 1);    // Caso mejor
    worst_case5=best_case5;
    reverse(worst_case5.begin(), worst_case5.end());  // Caso peor
    generate(avg_case5.begin(), avg_case5.end(), std::rand); // Caso promedio

    auto wc5 = medida.measureTime(alg, worst_case5,2);
    auto avg5 = medida.measureTime(alg, avg_case5,3);
    auto bc5 = medida.measureTime(alg, best_case5,1);

    seriesWorst->append(N5, wc5);
    seriesAverage->append(N5, avg5);
    seriesBest->append(N5, bc5);

    double C = 0.000000005;

    if (algName == "BubbleSort") {
        double C = 0.000000005;
        // Complejidad O(n²)
        seriesTheoretical->append(N1, C*N1 * N1);
        seriesTheoretical->append(N2, C*N2 * N2);
        seriesTheoretical->append(N3, C*N3 * N3);
        seriesTheoretical->append(N4, C*N4 * N4);
        seriesTheoretical->append(N5, C*N5 * N5);
    }else if (algName == "SelectionSort") {
        double C = 0.000000002;
        // Complejidad O(n²)
        seriesTheoretical->append(N1, C*N1 * N1);
        seriesTheoretical->append(N2, C*N2 * N2);
        seriesTheoretical->append(N3, C*N3 * N3);
        seriesTheoretical->append(N4, C*N4 * N4);
        seriesTheoretical->append(N5, C*N5 * N5);

    }
    else if (algName == "MergeSort") {
        double C = 0.00000003;
        // Complejidad O(n log n)
        seriesTheoretical->append(N1, C*N1 * log(N1));
        seriesTheoretical->append(N2, C*N2 * log(N2));
        seriesTheoretical->append(N3, C*N3 * log(N3));
        seriesTheoretical->append(N4, C*N4 * log(N4));
        seriesTheoretical->append(N5, C*N5 * log(N5));
    }
    else if (algName == "AllSortedLinkedListSearch") {
        double C = 0.00000001;
        // Complejidad O(n)
        seriesTheoretical->append(N1, C*N1);
        seriesTheoretical->append(N2, C*N2);
        seriesTheoretical->append(N3, C*N3);
        seriesTheoretical->append(N4, C*N4);
        seriesTheoretical->append(N5, C*N5);
    }else if (algName == "BinaryTreeSearch") {
        double C = 0.00000005;
        // Complejidad O( log n)
        seriesTheoretical->append(N1, C*log(N1));
        seriesTheoretical->append(N2, C*log(N2));
        seriesTheoretical->append(N3, C*log(N3));
        seriesTheoretical->append(N4, C*log(N4));
        seriesTheoretical->append(N5, C*log(N5));
    }

    // Crear el gráfico y usar el nombre del algoritmo en el título
    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(seriesBest);
    chart->addSeries(seriesAverage);
    chart->addSeries(seriesWorst);
    chart->addSeries(seriesTheoretical);

    // Configurar el título del gráfico utilizando algName
    chart->setTitle("Duracion de " + algName);
    chart->createDefaultAxes();
    chart->legend()->show();

    // Habilitar la leyenda para mostrar el nombre de las series
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Configurar los ejes
    QtCharts::QValueAxis *axisX = new QtCharts::QValueAxis;
    axisX->setTitleText("Tamaño N");
    axisX->setLabelFormat("%d");
    axisX->setTickCount(5);
    chart->addAxis(axisX, Qt::AlignBottom);
    seriesBest->attachAxis(axisX);
    seriesAverage->attachAxis(axisX);
    seriesWorst->attachAxis(axisX);
    seriesTheoretical->attachAxis(axisX);

    QtCharts::QValueAxis *axisY = new QtCharts::QValueAxis;
    axisY->setTitleText("Tiempo en ms");
    axisY->setLabelFormat("%d");
    axisY->setTickCount(5);
    chart->addAxis(axisY, Qt::AlignLeft);
    seriesBest->attachAxis(axisY);
    seriesAverage->attachAxis(axisY);
    seriesWorst->attachAxis(axisY);
    seriesTheoretical->attachAxis(axisY);

    // Crear el QChartView y añadirlo al layout de la ventana
    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Suponiendo que tienes un layout en tu UI llamado "verticalLayout"
    ui->verticalLayout->addWidget(chartView);
}

// Slot para Bubble Sort
void MainWindow::onBubbleSortButtonClicked() {
    createChart("BubbleSort");
}

void MainWindow::onSelectionSortButtonClicked() {
    createChart("SelectionSort");
}

// Slot para Merge Sort
void MainWindow::onMergeSortButtonClicked() {
    createChart("MergeSort");
}

// Slot para Binary Tree Search
void MainWindow::onBinaryTreeSearchButtonClicked() {
    createChart("BinaryTreeSearch");
}

// Slot para All Sorted Linked List Search
void MainWindow::onAllSortedLinkedListSearchButtonClicked() {
    createChart("AllSortedLinkedListSearch");
}
