//Student: Tsang Yuk Ki (56611715)
//Asm 2 Q4

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 100

class triangle {
	double area;
public:
	double l1, l2, l3;
	void calArea();
	double getArea();
	void outputResult();
};

void triangle::calArea() {
	double s = (l1 + l2 + l3) / 2;
	if (l1 > 0 && l2 > 0 && l3 > 0)
		area = sqrt(s * (s - l1) * (s - l2) * (s - l3));
	else
		area = 0;
}

double triangle::getArea() {
	return area;
}

void triangle::outputResult() {
	cout << "-- Triangle --" << endl;
	cout << "a = " << l1 << endl;
	cout << "b = " << l2 << endl;
	cout << "c = " << l3 << endl;
	cout << "area = " << area << endl;
}

class rectangle {
	double area;
public:
	double l1, l2;
	void calArea();
	double getArea();
	void outputResult();
};

void rectangle::calArea() {
	if (l1 > 0 && l2 > 0)
		area = l1 * l2;
	else
		area = 0;
}

double rectangle::getArea() {
	return area;
}

void rectangle::outputResult()
{
	cout << "-- Rectangle --" << endl;
	cout << "width = " << l1 << endl;
	cout << "height = " << l2 << endl;
	cout << "area = " << area << endl;
}

class circle {
	double area;
public:
	double r;
	void calArea();
	double getArea();
	void outputResult();
};

void circle::calArea() {
	if (r > 0)
		area = M_PI * r * r;
	else
		area = 0;
}

double circle::getArea() {
	return area;
}

void circle::outputResult()
{
	cout << "-- Circle --" << endl;
	cout << "r = " << r << endl;
	cout << "area = " << area << endl;
}

int main() {
	triangle tri[MAX];
	rectangle rec[MAX];
	circle cir[MAX];
	int nTri = 0, nRec = 0, nCir = 0, iTri, iRec, iCir;

	cout << "Enter number of Triangles: ";
	cin >> nTri;
	for (int i = 1; i <= nTri; i++) {
		cin >> tri[i].l1 >> tri[i].l2 >> tri[i].l3;
	}

	cout << "Enter number of Rectangles: ";
	cin >> nRec;
	for (int i = 1; i <= nRec; i++) {
		cin >> rec[i].l1 >> rec[i].l2;
	}

	cout << "Enter number of Circles: ";
	cin >> nCir;
	for (int i = 1; i <= nCir; i++) {
		cin >> cir[i].r;
	}

	cout << "Enter three indexes for picking: ";
	cin >> iTri >> iRec >> iCir;
	tri[iTri].calArea();
	rec[iRec].calArea();
	cir[iCir].calArea();
	cout << "The largest shape is:" << endl << setprecision(2) << fixed;
	if (tri[iTri].getArea() > rec[iRec].getArea() && tri[iTri].getArea() > cir[iCir].getArea())
		tri[iTri].outputResult();
	else if (rec[iRec].getArea() > tri[iTri].getArea() && rec[iRec].getArea() > cir[iCir].getArea())
		rec[iRec].outputResult();
	else
		cir[iCir].outputResult();

	return 0;
}