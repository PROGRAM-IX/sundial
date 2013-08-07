#ifndef VECTORSPRITE_H
    #define VECTORSPRITE_H
#endif
#include <vector>
#include "vector2.h"
#include "colour.h"

using std::vector;

class VectorSprite
{
    public: 
        Vector2 pos;
        vector< Vector2 > * points;
        Colour * colour;
        
        VectorSprite(Vector2 _pos, vector< Vector2 > * _points, Colour * _colour)
        {
            pos = _pos;
            points = _points;
            colour = _colour;
        }
        
        void rotate_radians(double angle_radians)
        {
            double cos_a = cos(angle_radians);
            double sin_a = sin(angle_radians);
            //vector< Vector2 > d_pts = *points; This doesn't seem to reference the array referenced by points
            unsigned int i;
            double old_x, old_y;
            for(i = 0; i < points->size(); i++)
            {
                Vector2* v = &points->at(i);
                old_x = v->x;
                old_y = v->y;
                v->x = (old_x * cos_a - old_y * sin_a);
                v->y = (old_x * sin_a + old_y * cos_a);
            }
        }
};
