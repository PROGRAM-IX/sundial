#ifndef COLOUR_H
    #define COLOUR_H
#endif

class Colour
{
    public:
        int r;
        int g;
        int b;
        Colour(int _r, int _g, int _b)
        {
            r = _r;
            g = _g;
            b = _b;
        }
        Colour()
        {
            r = 255;
            g = 255;
            b = 255;
        }
    
};
