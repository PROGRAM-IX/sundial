#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include <math.h>

#include "vectorsprite.h"

#define PI 3.14159265

using std::vector;


int main ( int argc, char** argv )
{
    // initialize SDL video
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }

    // make sure SDL cleans up before exit
    atexit(SDL_Quit);

    // create a new window
    SDL_Surface* screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL);
    if ( !screen )
    {
        printf("Unable to set 640x480 video: %s\n", SDL_GetError());
        return 1;
    }
    
    int* keys = new int[256];
    
    vector<Vector2> vector2s;
    vector2s.push_back(Vector2(200, 200));
    vector2s.push_back(Vector2(250, 250));
    vector2s.push_back(Vector2(300, 300));
    vector2s.push_back(Vector2(250, 150) + Vector2(150, 150));
    
    glClearColor(0, 0, 0, 0);
    glClearDepth(1.0f);
     
    glViewport(0, 0, 640, 480);
     
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
     
    glOrtho(0, 640, 480, 0, 1, -1);
     
    glMatrixMode(GL_MODELVIEW);
     
    glEnable(GL_TEXTURE_2D);
     
    glLoadIdentity();

    Vector2 vs_pos = Vector2(200, 200);
    vector< Vector2 > vs_points;
    vs_points.push_back(Vector2(-20, -20));
    vs_points.push_back(Vector2(-20, 20));
    vs_points.push_back(Vector2(20, 20));
    vs_points.push_back(Vector2(20, -20));
    
    Colour vs_colour = Colour(50, 50, 255);
    VectorSprite vs = VectorSprite(vs_pos, &vs_points, &vs_colour);
    float COLOUR_CONV = 1.0/255.0;

    
    // program main loop
    bool done = false;
    while (!done)
    {
        // message processing loop
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
            case SDL_QUIT:
                done = true;
                break;

                // check for keypresses
            case SDL_KEYDOWN:
                {
                    /*// exit if ESCAPE is pressed
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        done = true;
                    else if (event.key.keysym.sym == SDLK_w)
                        vs.pos.y-=10;
                    else if (event.key.keysym.sym == SDLK_s)
                        vs.pos.y+=10;
                    else if (event.key.keysym.sym == SDLK_a)
                        vs.pos.x-=10;
                    else if (event.key.keysym.sym == SDLK_d)
                        vs.pos.x+=10;
                    */
                    keys[event.key.keysym.sym] = 1;
                    break;
                    
                }
            case SDL_KEYUP:
                {
                    keys[event.key.keysym.sym] = 0;
                    break;
                }
            } // end switch
        } // end of message processing

        // Use keyboard state to change game state
        
        if (keys[SDLK_ESCAPE] == 1)
        {
            done = true;
        }
        if (keys[SDLK_w] == 1)
        {
            vs.pos.y -= 10;
        }
        if (keys[SDLK_s] == 1)
        {
            vs.pos.y += 10;
        }
        if (keys[SDLK_a] == 1)
        {
            vs.pos.x -= 10;
        }
        if (keys[SDLK_d] == 1)
        {
            vs.pos.x += 10;
        }
        
        // DRAWING STARTS HERE
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        
        /*glBegin(GL_QUADS);
            glColor3f(1, 0, 0); glVertex3f(0, 0, 0);
            glColor3f(1, 1, 0); glVertex3f(100, 0, 0);
            glColor3f(1, 0, 1); glVertex3f(100, 100, 0);
            glColor3f(1, 1, 1); glVertex3f(0, 100, 0);
        glEnd();*/
        vs.rotate_radians(PI / 60.0);
        Colour d_col = *vs.colour;
        vector< Vector2 > d_pts = *vs.points;
        unsigned int i;
        glBegin(GL_LINE_LOOP);
            glColor3f(d_col.r*COLOUR_CONV, d_col.g*COLOUR_CONV, d_col.b*COLOUR_CONV);
            for (i = 0; i < d_pts.size(); i++)
            {
                glVertex2f(d_pts.at(i).x + vs.pos.x, d_pts.at(i).y + vs.pos.y);
            }
        glEnd();
        
        
        /*glBegin(GL_LINE_LOOP);
            glColor3f(1, 1, 1);
            unsigned int i;
            for (i = 0; i < vector2s.size(); i++)
            {
                glVertex3f(vector2s.at(i).x, vector2s.at(i).y, 0);
            }
        glEnd();*/
 
        SDL_GL_SwapBuffers();
    } // end main loop

    // all is well ;)
    printf("Exited cleanly\n");
    return 0;
}
