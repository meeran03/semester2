#include <iostream>
using namespace std;

void allocate(float *&a, float *&b)
{
	float *width = new float;
	float *height = new float;

	a = width;
	b = height;
}
void input(float *width, float *height)
{
	cout << "Enter width: ";
	cin >> *width;

	cout << "Enter height: ";
	cin >> *height;
}
void Print(float *width, float *height)
{
	cout << "Width: " << *width << endl;
	cout << "Height: " << *height << endl;
}
float Area(float *width, float *height)
{
	float area = (*width) * (*height);
	return area;
}

void deallocate(int *&width,int *&height) {
    delete []width;
    delete []height;
    width = nullptr;
    height = nullptr;
}

int main()
{
	float *ptr1 = nullptr;
	float *ptr2 = nullptr;

	allocate(ptr1, ptr2);
	input(ptr1, ptr2);
	Print(ptr1, ptr2);
	int area = Area(ptr1, ptr2);
	cout << "Area = " << area << endl;

	return 0;
}