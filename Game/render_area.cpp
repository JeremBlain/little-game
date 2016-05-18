
#include "render_area.hpp"

#include <QPainter>
#include <QLabel>

#include <iostream>
#include <cassert>

render_area::render_area(QWidget *parent)
    :QWidget(parent),
      circ({200,100}, 21),
      black_hole({200,200}, 8),
      black_hole2({500,400}, 8),
      timer(), time(),
      rot(true), dir_trans()
{
    center_rot = black_hole.center;

    //timer calling the function update_timer periodicaly
    connect(&timer, SIGNAL(timeout()), this, SLOT(update_timer()));
    timer.start(32); //en millisecondes
}

render_area::~render_area()
{}

void render_area::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    /** Affichage du cercle joueur (rouge) */
    QBrush brush = painter.brush();
    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    vec2 c=circ.center;
    float r=circ.rayon;
    painter.drawEllipse(c.x-r, c.y-r, 2*r, 2*r);

    /** Affichage du cercle centre de rot */
    brush.setColor(Qt::black);
    painter.setBrush(brush);
    c=black_hole.center;
    r=black_hole.rayon;
    painter.drawEllipse(c.x-r, c.y-r, 2*r, 2*r);

     /** Affichage du 2e cercle centre de rot */
    c=black_hole2.center;
    r=black_hole2.rayon;
    painter.drawEllipse(c.x-r, c.y-r, 2*r, 2*r);

}

void render_area::update_timer()
{
    if(rot==true)
        circ.rotate_around(center_rot);
    else
    {
        circ.translation(dir_trans);
        event_Horizon(black_hole2.center, circ.center);
    }

    repaint();
}

void render_area::mousePressEvent(QMouseEvent *)
{
    rot = false;
    vec2 v = circ.center - black_hole.center;
    dir_trans = 4*vec_orth(v);
}

void render_area::event_Horizon(const vec2 &center_bh, const vec2& center_o)
{
    if(norm(center_bh-center_o)<100)
    {
        rot = true;
        center_rot = center_bh;
    }
}

void render_area::reset()
{
    circ.center = {200,100};
    circ.rayon = 21;
    black_hole.center = {200,200};
    black_hole.rayon = 8;
    black_hole2.center = {500,400};
    black_hole2.rayon = 8;
    rot=true;
    center_rot = black_hole.center;
    repaint();
}
