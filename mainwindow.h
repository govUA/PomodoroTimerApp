#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QTimer>

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

private:
    Ui::MainWindow *ui;

    QListWidget *taskListWidget;
    QLineEdit *taskInputField;
    QPushButton *addTaskButton;
    QLabel *timerLabel;
    QPushButton *startButton;
    QPushButton *pauseButton;
    QPushButton *resetButton;

    QTimer *pomodoroTimer;
    int remainingTime;

private slots:
    void addTask();
    void startTimer();
    void pauseTimer();
    void resetTimer();
    void updateTimer();
};
#endif // MAINWINDOW_H
