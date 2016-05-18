

#include "circle.hpp"

#include <cmath>

circle::circle()
    :center(),rayon(0.0f)
{}

circle::circle(vec2 const& center_param,float const radius_center)
    :center(center_param),rayon(radius_center)
{}


void circle::rotate_around(vec2 const center_rot)
{
    float delta_tho=0.16f; //incrément pour la rotation

    float cx = center.x;
    center.x = (cx-center_rot.x)*cos(delta_tho)-(center.y-center_rot.y)*sin(delta_tho) + center_rot.x;
    center.y = (cx-center_rot.x)*sin(delta_tho)+(center.y-center_rot.y)*cos(delta_tho) + center_rot.y;
}

void circle::translation(const vec2& dir)
{
    center += dir;
}


