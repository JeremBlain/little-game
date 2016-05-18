#pragma once

#ifndef RENDER_AREA_HPP
#define RENDER_AREA_HPP

#include "circle.hpp"

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QMouseEvent>


//forward declaration of QLabel
class QLabel;



class render_area : public QWidget
{
    Q_OBJECT
public:

    render_area(QWidget *parent = 0);
    ~render_area();
    void reset();

private slots:
    void update_timer();

private: //functions
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void event_Horizon(const vec2& center_bh,const vec2& center_o);


private: //attributes
    circle circ; //le cercle joueur
    circle black_hole; //le cercle qui va servir de centre de rotation
    circle black_hole2; //un deuxième
    vec2 center_rot;

    QTimer timer;
    QTime time;
    bool rot;
    vec2 dir_trans; //direction de la translation du joueur


};

#endif
