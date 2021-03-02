#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);    //set display window color to white
    //glMatrixMode(GL_PROJECTION);        // set projection parametes
    //gluOrtho2D(0.0,600,0.0,600);
}

void reshape(int, int);
void drawRiver();
void drawSky();
void drawRoad();
void drawWheatField();
void drawBridge();

void drawWindow(int x1, int y1, int x2, int y2,float r, float g, float b);              // take the house outline and draw windows relative
void drawTree();
void drawHouseOutline (int x1, int y1, int x2, int y2, float r, float g, float b);
void drawRoof(int x1,int y1, int x2,int y2,int x3,int y3, float r, float g, float b);
void drawDoor(int x1,int y1, int x2,int y2, float r, float g, float b);

void drawGrass();

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);    // clear display window
    glLoadIdentity(); // reset coordinate system
    
    drawSky();
    drawRiver();
    drawGrass();
    //drawWheatField();
    drawBridge();
    drawRoad();
    drawTree();
    
    
    
    // Draw first house
    drawRoof(-550, -200, -450, -100, -350, -200, 0.878, 1.000, 1.000);
    drawHouseOutline(-550,-200,-350,-400, 0.282, 0.820, 0.800);
    drawDoor(-550,-200,-350,-400, 0.878, 1.000, 1.000);
    drawWindow(-550,-200,-350,-400, 0.878, 1.000, 1.000);
    
    // Draw second house
    drawRoof(-300, -200, -200, -100, -100, -200, 0.741, 0.718, 0.420);
    drawHouseOutline(-300,-200,-100,-400, 1.000, 0.894, 0.710);
    drawWindow(-300,-200,-100,-400, 0.741, 0.718, 0.420);
    drawDoor(-300,-200,-100,-400, 0.741, 0.718, 0.420);
    
    // Draw third house
    drawRoof(-550, 350, -450, 450, -350, 350, 1.000, 0.753, 0.796);
    drawHouseOutline(-550, 350, -350, 150, 0.545, 0.000, 0.000);
    drawWindow(-550, 350, -350, 150, 1.000, 0.753, 0.796);
    drawDoor(-550, 350, -350, 150, 1.000, 0.753, 0.796);
    
    // Draw fourth house
    drawRoof(-100, 350, 0, 450, 100, 350, 0.941, 1.000, 0.941);
    drawHouseOutline(-100, 350, 100, 150, 0.412, 0.412, 0.412);
    drawWindow(-100, 350, 100, 150, 0.941, 1.000, 0.941);
    drawDoor(-100, 350, 100, 150, 0.941, 1.000, 0.941);
    
    // Draw fifth house
    drawRoof(300, 350, 400, 450, 500, 350, 0.902, 0.902, 0.980);
    drawHouseOutline(300, 350, 500, 150, 0.545, 0.000, 0.545);
    drawWindow(300, 350, 500, 150, 0.902, 0.902, 0.980);
    drawDoor(300, 350, 500, 150, 0.902, 0.902, 0.980);
    
    glFlush();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);    // initlaize glut
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // set display mode
    glutInitWindowPosition(50, 100);    //set top left display window position
    glutInitWindowSize(600, 480);    //set display window width and height
    glutCreateWindow("An Example OpenGL Window");    // Create display window
    init();
    glutDisplayFunc(display); //send graphics to display window
    glutReshapeFunc(reshape);
    glutMainLoop();    // display everything and wait
    return 0;
}

void reshape(int width, int height){
    // view port
    glViewport(0, 0, width, height);    // sets the screen to whole width
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // set a new projection window
    gluOrtho2D(-600, 600, -600, 600);
    
    // switch back to default model view
    glMatrixMode(GL_MODELVIEW);
    
}

void drawSky(){
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.608, 0.622);
        glVertex2f(-600, 300);
        glVertex2f(-600, 600);
        glColor3f(1.0, 1.0, 0.0);
        glVertex2f(600, 600);
        glVertex2f(600, 000);
    glEnd();
}

void drawRoad(){
   // draw black road bottom
    glColor3f(0, 0, 0);
    int road_bot_1[] = {-600, -450};
    int road_bot_2[] = {600, -550};
    glRectiv(road_bot_1, road_bot_2);
    
    // draw top road
    int road_top_1[] = {-600, 100};
    int road_top_2[] = {600, 0};
    glRectiv(road_top_1, road_top_2);
    
    
    // yellow lines
    glColor3f(1.000, 1.000, 0.000);
    glLineStipple(50, 0xAAAA);
    glEnable(GL_LINE_STIPPLE);
    glLineWidth(3);
    glBegin(GL_LINES);
        glVertex2f(-599, -500);
        glVertex2f(599, -500);
        glVertex2f(-599, 50);
        glVertex2f(599, 50);
    glDisable(GL_LINE_STIPPLE);
    glFlush();
    glEnd();
}

void drawHouseOutline (int x1, int y1, int x2, int y2, float r, float g, float b){
    GLubyte brick[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xF3, 0xFF, 0xFF, 0xFF, 0xF3, 0xFF, 0xFF,
    0xFF, 0xF3, 0xFF, 0xFF, 0xFF, 0xF3, 0xFF, 0xFF,
    0xFF, 0xF3, 0xFF, 0xFF, 0xFF, 0xF3, 0xFF, 0xFF,
    0xFF, 0xF3, 0xFF, 0xFF, 0xFF, 0xF3, 0xFF, 0xFF,
    0xFF, 0xF3, 0xFF, 0xFF, 0xFF, 0xF3, 0xFF, 0xFF,
    0xFF, 0xF3, 0xFF, 0xFF, 0xFF, 0xF3, 0xFF, 0xFF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFC,
    0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFC,
    0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFC,
    0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFC,
    0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFC,
    0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFC
    };
    
    // outline of house
    glColor3f(0, 0, 0);
    int house_outline_1 [] = {x1, y1};
    int house_outline_2 [] = {x2, y2};
    glRectiv(house_outline_1, house_outline_2);
    glEnable(GL_POLYGON_STIPPLE);
    glColor3f(r, g, b);
    glPolygonStipple(brick);
    glRectiv(house_outline_1, house_outline_2);
    glDisable(GL_POLYGON_STIPPLE);
}

void drawRoof(int x1,int y1, int x2,int y2,int x3,int y3, float r, float g, float b){
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glVertex2i(x3, y3);
    glEnd( );
}

void drawDoor(int x1,int y1, int x2,int y2, float r, float g, float b){
    glColor3f(r, g, b);
    int door_top_left [] = {x2-100, y2+50};
    int door_bottom_right [] = {x2-50, y2};
    glRectiv(door_top_left, door_bottom_right);
}

void drawGrass(){
    // bottom grass
    glColor3f(0.180, 0.545, 0.341); // green
    int grass_outline_1 [] = {-600, -300};
    int grass_outline_2 [] = {600, -600};
    glRectiv(grass_outline_1, grass_outline_2);
    
    // top grass
    int grass_outline_3 [] = {-600, 300};
    int grass_outline_4 [] = {600, -100};
    glRectiv(grass_outline_3, grass_outline_4);
}

void drawWheatField(){
    glColor3f(0.933, 0.910, 0.667);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(-75, -330);
    glVertex2f(-75, -400);
    glVertex2f(-75, -330);
    glVertex2f(-70, -310);
    glEnd();
}

void drawBridge(){
    glColor3f(0.824, 0.706, 0.549);
    int bridge_top[] = {200, -80};
    int bridge_bottom[] = {300, -320};
    glRectiv(bridge_top, bridge_bottom);
    
}

void drawRiver(){
    glBegin(GL_POLYGON);
    glColor3f(0.000, 0.000, 0.804);
        glVertex2f(-600, -300);
        glVertex2f(-600, -100);
        
    glColor3f(0.255, 0.412, 0.882);
        glVertex2f(600, -300);
        glVertex2f(600, -100);
        glVertex2f(-600, 0);
    glEnd();
     
}

void drawTree(){
    // draw trunk
    glColor3f(0.545, 0.271, 0.075);
    int trunk_top_left[] = {400, -325};
    int trunk_bot_right[] = {450, -400};
    glRectiv(trunk_top_left, trunk_bot_right);
    
    // draw tree
    glColor3f(0.000, 0.392, 0.000);
    glPointSize(5);
    glBegin(GL_POLYGON);
    glVertex2f(425, -215);
    glVertex2f(385, -265);
    glVertex2f(415, -265);
    glVertex2f(355, -325);
    glVertex2f(500, -325);
    glVertex2f(445, -265);
    glVertex2f(465, -265);
    glEnd();
}

void drawWindow(int x1, int y1, int x2, int y2,float r, float g, float b){
    glColor3f(r, g, b);
    int left_window_1 [] = {x1+25, y1-25};
    int left_window_2 [] = {x1+75, y1-75};
    int right_window_1 [] = {left_window_1[0] + 100, left_window_1[1]};
    int right_window_2 [] = {right_window_1[0] + 50, left_window_2[1]};
    glRectiv(left_window_1, left_window_2);
    glRectiv(right_window_1, right_window_2);
}

