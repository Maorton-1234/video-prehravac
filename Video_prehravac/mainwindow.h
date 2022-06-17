#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QProgressBar>
#include <QSlider>
#include <QAudioOutput>





QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionPlay_triggered();

    void on_actionPause_triggered();

    void on_actionVyber_videa_triggered();

    void on_actionStop_triggered();

    void on_actionSlowMotion_triggered();

    void on_actionNormalMotion_triggered();

    void on_actionFastMotion_triggered();

    void on_actionMute_toggled(bool checked);

    void on_actionvolumeup_triggered();

    void on_actionvolumedown_triggered();

    void on_actionfullscreen_triggered();

    void on_actionVyber_videa_2_clicked();

    void on_actionPomocn_k_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;
    QVideoWidget* vw;
    QProgressBar* bar;
    QSlider* slider;
    QAudioOutput* audio;

};
#endif // MAINWINDOW_H
