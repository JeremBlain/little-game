
#include "window.hpp"

#include "render_area.hpp"
#include "ui_mainwindow.h"


window::window(QWidget *parent)
    :QMainWindow(parent),ui(new Ui::MainWindow),render(new render_area)
{
    ui->setupUi(this);
    ui->Layout_scene->addWidget(render);
}

window::~window()
{}

void window::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case 'R':
       render->reset();
        break;
    default:
        break;
    }
}
