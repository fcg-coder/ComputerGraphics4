#include <iostream>

#define SIZE_OF_WINDOW 650 //Размер окна
//В этом файле опишем координаты и тп для пирамиды 

double K = 1000000; //расстояние от ЗРИТЕЛЯ до экрана в пикселях)))

class pyramid
{
public:
	void random() {
		x = rand() % (SIZE_OF_WINDOW / 2) + (SIZE_OF_WINDOW / 4);
		y = rand() % (SIZE_OF_WINDOW / 2) + (SIZE_OF_WINDOW / 4);
		z = rand() % (SIZE_OF_WINDOW / 2) + (SIZE_OF_WINDOW / 4);
		projection();
	}

	

	void projection() {
		
		//xэ = kx / (z+k).
		X = (K * x) / (z + K);
		Y = (K * y) / (z + K);
	}

	void projectionXZ() {

	}

	void back_projection() {
		x = (X * (z + K)) / K;
		y = (Y * (z + K)) / K;
	}

	void mashtab(float ALFA) {
		//Центр тяжести пирамиды лежит на прямой, соединяющей центр тяжести 
		//площади основания с противолежащей вершиной на расстоянии 1/4 высоты от основания



		x *= ALFA;
		y *= ALFA;
		z *= ALFA;


		projection();
	}
	
	double x, y, z;
	double X, Y;
	
};

pyramid* A = new pyramid;
pyramid* B = new pyramid;
pyramid* C = new pyramid;
pyramid* D = new pyramid;

void drawPyramid() {
	line(A->X, A->Y, B->X, B->Y);
	line(A->X, A->Y, C->X, C->Y);
	line(A->X, A->Y, D->X, D->Y);
	line(C->X, C->Y, B->X, B->Y);
	line(D->X, D->Y, B->X, B->Y);
	line(C->X, C->Y, D->X, D->Y);
}