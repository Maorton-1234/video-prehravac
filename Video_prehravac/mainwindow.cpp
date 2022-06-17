#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "help.h"

int volume_selector=1;
int volume_remember=50;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    QMainWindow::setWindowTitle("Video Prehrávač");
    player = new QMediaPlayer(this);
    audio = new QAudioOutput(this);
    vw = new QVideoWidget(this);
    player->setVideoOutput(vw);
    //this->setCentralWidget(vw);

    slider = new QSlider(this);
    bar = new QProgressBar;

    slider->setOrientation(Qt::Horizontal);
    bar->setOrientation(Qt::Horizontal);
    ui->statusbar->addPermanentWidget(slider);
   // ui->statusbar->addPermanentWidget(bar);
    connect(player,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);
    connect(slider,&QSlider::sliderMoved,player,&QMediaPlayer::setPosition);


}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_actionPlay_triggered()
{
    player->play();
    player->setAudioOutput(audio);
    audio->setVolume(volume_remember);
}


void MainWindow::on_actionPause_triggered()
{
    player->pause();

}


void MainWindow::on_actionVyber_videa_triggered()
{
    this->setCentralWidget(vw);
    QString filename = QFileDialog::getOpenFileName(this,"Otvoriť Súbor","","Video Súbor (*.*)");
    on_actionStop_triggered();

    player->setSource(QUrl::fromLocalFile(filename));

    on_actionPlay_triggered();

}



void MainWindow::on_actionStop_triggered()
{
    player->stop();
}


void MainWindow::on_actionSlowMotion_triggered()
{
    player->setPlaybackRate(0.5);
}


void MainWindow::on_actionNormalMotion_triggered()
{
    player->setPlaybackRate(1);
}


void MainWindow::on_actionFastMotion_triggered()
{
    player->setPlaybackRate(2);

}


void MainWindow::on_actionMute_toggled(bool)
{
    if(volume_selector== 1){
       audio->setVolume(0);
       volume_selector=0;
    }
    else if(volume_selector== 0) {
        audio->setVolume(volume_remember);
        volume_selector=1;
    }
}


void MainWindow::on_actionvolumeup_triggered()
{
    volume_remember=volume_remember+5;
    audio->setVolume(volume_remember);

}


void MainWindow::on_actionvolumedown_triggered()
{
    volume_remember=volume_remember-5;
    audio->setVolume(volume_remember);
}


void MainWindow::on_actionfullscreen_triggered()
{
    if(!isFullScreen()){
       vw->setFullScreen(true);
      }
    else {
        vw->setFullScreen(false);
     }
}


void MainWindow::on_actionVyber_videa_2_clicked()
{
    on_actionVyber_videa_triggered();
}


void MainWindow::on_actionPomocn_k_triggered()
{
    help pomoc;
    pomoc.setModal(true);
    pomoc.exec();
}


void MainWindow::on_pushButton_clicked()
{
    on_actionPomocn_k_triggered();
}

