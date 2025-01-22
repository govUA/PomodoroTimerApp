#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , remainingTime(1500)
{
    ui->setupUi(this);

    taskListWidget = findChild<QListWidget*>("taskListWidget");
    taskInputField = findChild<QLineEdit*>("taskInputField");
    addTaskButton = findChild<QPushButton*>("addTaskButton");
    timerLabel = findChild<QLabel*>("timerLabel");
    startButton = findChild<QPushButton*>("startButton");
    pauseButton = findChild<QPushButton*>("pauseButton");
    resetButton = findChild<QPushButton*>("resetButton");

    pomodoroTimer = new QTimer(this);
    connect(pomodoroTimer, &QTimer::timeout, this, &MainWindow::updateTimer);

    connect(addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
    connect(startButton, &QPushButton::clicked, this, &MainWindow::startTimer);
    connect(pauseButton, &QPushButton::clicked, this, &MainWindow::pauseTimer);
    connect(resetButton, &QPushButton::clicked, this, &MainWindow::resetTimer);

    timerLabel->setText("25:00");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTask()
{
    QString taskText = taskInputField->text();

    if (taskText.isEmpty()) {
        qDebug() << "Task input is empty!";
        return;
    }

    taskListWidget->addItem(taskText);

    taskInputField->clear();

    qDebug() << "Task added:" << taskText;
}

void MainWindow::startTimer()
{
    qDebug() << "Start button clicked!";
    pomodoroTimer->start(1000);
}

void MainWindow::pauseTimer()
{
    qDebug() << "Pause button clicked!";
    pomodoroTimer->stop();
}

void MainWindow::resetTimer()
{
    qDebug() << "Reset button clicked!";
    pomodoroTimer->stop();
    remainingTime = 1500;
    timerLabel->setText("25:00");
}

void MainWindow::updateTimer()
{
    if (remainingTime > 0) {
        remainingTime--;
        int minutes = remainingTime / 60;
        int seconds = remainingTime % 60;
        timerLabel->setText(QString("%1:%2")
                                .arg(minutes, 2, 10, QChar('0'))
                                .arg(seconds, 2, 10, QChar('0')));
    } else {
        pomodoroTimer->stop();
        qDebug() << "Time's up!";
    }
}
