#include <iostream>
#include "pyramid.cpp"

using namespace std;
double xc, yc, zc;

void MENU() {
    system("CLS");
    cout << "Menu:\n\t-w/s to up/down\n\t-a/d to left/right\n\t-q/e to rotate\n\t-(-)/(+) to mashtabe\n\t- (/) to draw new lines\n\t- (C) to draw/del CIRCLE\n\n";


    cout << "A\t(" << A->x << "," << A->y << "," << A->z << ")\n";
    cout << "B\t(" << B->x << "," << B->y << "," << B->z << ")\n";
    cout << "C\t(" << C->x << "," << C->y << "," << C->z << ")\n";
    cout << "D\t(" << D->x << "," << D->y << "," << D->z << ")\n";



}

void random() {
    A->random();

    B->random();

    C->random();

    D->random();

    drawPyramid();
}

void projection() {
    A->projection();
    B->projection();
    C->projection();
    D->projection();
}

void back_projection() {
    A->back_projection();
    B->back_projection();
    C->back_projection();
    D->back_projection();
}

void center() {
    xc = (A->x + B->x + C->x + D->x) / 4;
    yc = (A->y + B->y + C->y + D->y) / 4;
    zc = (A->z + B->z + C->z + D->z) / 4;
}

void minus_center() {
    A->x -= xc;
    B->x -= xc;
    C->x -= xc;
    D->x -= xc;

    A->y -= yc;
    B->y -= yc;
    C->y -= yc;
    D->y -= yc;


    A->z -= zc;
    B->z -= zc;
    C->z -= zc;
    D->z -= zc;
}

void plus_center() {

    A->x += xc;
    B->x += xc;
    C->x += xc;
    D->x += xc;

    A->y += yc;
    B->y += yc;
    C->y += yc;
    D->y += yc;


    A->z += zc;
    B->z += zc;
    C->z += zc;
    D->z += zc;
}

void Rotate(float Q) {
    // Ищем центр линии
    double NEW_x1, NEW_x2, NEW_y1, NEW_y2, NEW_y3, NEW_x3, NEW_y4, NEW_x4;
      // "Перемещаем" линию в точку 0 0

    double Xc = (A->X + B->X + D->X + C->X) / 4;
    double Yc = (A->Y + B->Y + D->Y + C->Y) / 4;

    A->X -= Xc;
    B->X -= Xc;
    C->X -= Xc;
    D->X -= Xc; 
    
    A->Y -= Yc;
    B->Y -= Yc;
    C->Y -= Yc;
    D->Y -= Yc;

    //ПОворачиваем ее 
    NEW_x1 = A->X * cos(Q) + A->Y * sin(Q);
    NEW_y1 = -(A->X * sin(Q)) + A->Y * cos(Q);
    A->X = NEW_x1;
    A->Y = NEW_y1;

    NEW_x2 = B->X * cos(Q) + B->Y * sin(Q);
    NEW_y2 = -(B->X * sin(Q)) + B->Y * cos(Q);
    B->X = NEW_x2;
    B->Y = NEW_y2;

    NEW_x3 = C->X * cos(Q) + C->Y * sin(Q);
    NEW_y3 = -(C->X * sin(Q)) + C->Y * cos(Q);
    C->X = NEW_x3;
    C->Y = NEW_y3;


    NEW_x4 = D->X * cos(Q) + D->Y * sin(Q);
    NEW_y4 = -(D->X * sin(Q)) + D->Y * cos(Q);
    D->X = NEW_x4;
    D->Y = NEW_y4;



    A->X += Xc;
    B->X += Xc;
    C->X += Xc;
    D->X += Xc;

    A->Y += Yc;
    B->Y += Yc;
    C->Y += Yc;
    D->Y += Yc;


    back_projection();
}


void MASHTABE(float ALFA) {
    center();
    minus_center();
    A->mashtab(ALFA);
    B->mashtab(ALFA);
    C->mashtab(ALFA);
    D->mashtab(ALFA);
    plus_center();
    projection();
    drawPyramid();
}


void yRotere(double Q) {
    //По оси Y
 /*   x'=x*cos(L)+z*sin(L);
        y'=y;
        z'=-x*sin(L)+z*cos(L)*/

		center();
		
        minus_center();
		double NEW_x1, NEW_x2, NEW_z1, NEW_z2, NEW_z3, NEW_x3, NEW_z4, NEW_x4;
		NEW_x1 = A->x * cos(Q) + A->z * sin(Q);
		NEW_z1 = -(A->x * sin(Q)) + A->z * cos(Q);
		A->x = NEW_x1;
		A->z = NEW_z1;

		NEW_x2 = B->x * cos(Q) + B->z * sin(Q);
		NEW_z2 = -(B->x * sin(Q)) + B->z * cos(Q);
		B->x = NEW_x2;
		B->z = NEW_z2;

		NEW_x3 = C->x * cos(Q) + C->z * sin(Q);
		NEW_z3 = -(C->x * sin(Q)) + C->z * cos(Q);
		C->x = NEW_x3;
		C->z = NEW_z3;


		NEW_x4 = D->x * cos(Q) + D->z * sin(Q);
		NEW_z4 = -(D->x * sin(Q)) + D->z * cos(Q);
		D->x = NEW_x4;
		D->z = NEW_z4;

        plus_center();

		projection();
        
	}

void xRotere(double Q) {
    //По оси Y
 /*   x'=x*cos(L)+z*sin(L);
        y'=y;
        z'=-x*sin(L)+z*cos(L)*/

		center();
		
        minus_center();
		double NEW_y1, NEW_y2, NEW_z1, NEW_z2, NEW_z3, NEW_y3, NEW_z4, NEW_y4;
		NEW_y1 = A->y * cos(Q) + A->z * sin(Q);
		NEW_z1 = -(A->y * sin(Q)) + A->z * cos(Q);
		A->y = NEW_y1;
		A->z = NEW_z1;

		NEW_y2 = B->y * cos(Q) + B->z * sin(Q);
		NEW_z2 = -(B->y * sin(Q)) + B->z * cos(Q);
		B->y = NEW_y2;
		B->z = NEW_z2;

		NEW_y3 = C->y * cos(Q) + C->z * sin(Q);
		NEW_z3 = -(C->y * sin(Q)) + C->z * cos(Q);
		C->y = NEW_y3;
		C->z = NEW_z3;


		NEW_y4 = D->y * cos(Q) + D->z * sin(Q);
		NEW_z4 = -(D->y * sin(Q)) + D->z * cos(Q);
		D->y = NEW_y4;
		D->z = NEW_z4;

        plus_center();

		projection();
        
	}

    


void MoveLine(char trasport) {
    int zMove = 10000;

    switch (trasport)
    {


        // <- / ->
    case'w':
        A->Y -=5;
        B->Y -=5;
        C->Y -=5;
        D->Y -=5;
        break;

    case 's':
        A->Y +=5;
        B->Y +=5;
        C->Y +=5;
        D->Y +=5;

        break;
    case 'd':
        A->X +=5;
        B->X +=5;
        C->X +=5;
        D->X +=5;
        break;
    case 'a':
        A->X -=5;
        B->X -=5;
        C->X -=5;
        D->X -=5;
        break;
    case '9':
        A->z -= zMove;
        B->z -= zMove;
        C->z -= zMove;
        D->z -= zMove;
        projection();
        break; 
    case '0':
        A->z += zMove;
        B->z += zMove;
        C->z += zMove;
        D->z += zMove;
        projection();
        break;

        //ROTATE
    case 'q':
        Rotate(0.05);
        break;
    case 'e':
        Rotate(-0.05);
        break;
    case '1':
        yRotere(0.05);
        break;
    case '2':
        yRotere(-0.05);
        break;
     case 'r':
        xRotere(0.05);
        break;
    case 't':
        xRotere(-0.05);
        break;

        //MASHTABE
    case '+':
        MASHTABE(1.1);
        break;
    case '=':
        MASHTABE(1.1);
        break;
    case '-':
        MASHTABE(1 / 1.1);
        break;

    }

    back_projection();
    //Рисуем
    cleardevice();
    drawPyramid();
}

