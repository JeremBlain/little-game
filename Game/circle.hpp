
#pragma once

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <iostream>

#include "vec2.hpp"


/** A structure containing parameter of a geometric circle */
struct circle
{
    vec2 center; //centre du cercle

    float rayon; //rayon du cercle

    /** Constructor circle (0,0) */
    circle();
    /** Constructor circle ({x,y},R) */
    circle(vec2 const& center_param,float radius_center);

    /** Méthodes */

    void rotate_around(const vec2 center_rot);

    void translation(const vec2& dir);

private:


};

#endif
