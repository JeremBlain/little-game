
#pragma once
#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QMainWindow>
#include <QKeyEvent>


namespace Ui{
class MainWindow;
}
class render_area;

class window: public QMainWindow
{
    Q_OBJECT

public:

    window(QWidget *parent=nullptr);
    ~window();

private slots:



private:

    void keyPressEvent(QKeyEvent *event);

    Ui::MainWindow *ui;
    render_area *render;

};

#endif
