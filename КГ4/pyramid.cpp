#include <iostream>

#define SIZE_OF_WINDOW 650 //Размер окна
//В этом файле опишем координаты и тп для пирамиды 

double K = 1; //коэффизиент маштабирования

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
		/*Формула для изотерической проекции может быть записана следующим образом:

x' = k * (x - z * cos(a))

y' = k * (y - z * sin(a))



где x' и y' - координаты точки на экране, x, y и z - координаты точки в 3D-пространстве, 
a - угол между направлением взгляда и осью X или Y (в зависимости от того, какая ось параллельна плоскости экрана)
и k - масштабный коэффициент.*/



		//Старая проекция
		//X = (K * x) / (z + K);
		//Y = (K * y) / (z + K);


		double a = 0.785; //Угол 45 в радианах
		X = K * (x - z * cos(a));
		Y = K * (y - z * sin(a));
	}



	void back_projection() {
		/*Для нахождения координат x и y по заданным формулам, необходимо воспользоваться обратными преобразованиями
		.Для этого необходимо выполнить следующие действия1.Выразить cos(a) и sin(a) через известные значения :

		cos(a) = (x - X) / z

			sin(a) = (y - Y) / z

			Подставить выражения для cos(a) и sin(a) в исходные уравнения :
		X = K * (x - z * (x - X) / z) = K * X

			Y = K * (y - z * (y - Y) / z) = K * Y

			Разделить обе стороны каждого уравнения на коэффициент K, чтобы найти значения координат :
		x = X / K + z * cos(a)

			y = Y / K + z * sin(a)

			Таким образом, чтобы найти значения координат x и y, 
			необходимо знать значения констант K, z, а также координаты центра(X, Y) и угол поворота плоскости(a)


*/

		//Старое преобразование
		//x = (X * (z + K)) / K;
		//y = (Y * (z + K)) / K;


		double a = 0.785;
		x = X / K + z * cos(a);

		y = Y / K + z * sin(a);
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