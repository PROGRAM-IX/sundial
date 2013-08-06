#ifndef VECTOR2_H
    #define VECTOR2_H
#endif
    
class Vector2
{
    public:
        double x, y;
        
        Vector2()
        {
            x = 0;
            y = 0;
        }
        
        Vector2(double xPos, double yPos)
        {
            x = xPos;
            y = yPos;
        }
        
        Vector2 operator + (Vector2 other)
        {
            return Vector2(x+other.x, y+other.y);
        }
        
        Vector2 operator - (Vector2 other)
        {
            return Vector2(x-other.x, y-other.y);
        }
        
        Vector2 operator * (int scalar)
        {
            return Vector2(x*scalar, y*scalar);
        }
};
