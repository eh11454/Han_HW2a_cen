//This program takes in as input an angle in degrees between -360 to 360
//It will then calculate the derivative of sine using the central difference formula

#include <iostream>  
#include <stdio.h>       
#include <math.h> 
using namespace std;


//Modules
//------------------------------------
double f(double x);
double fp(double x);


int main() {

	//Variables 
	//---------------------------------------------
	double x, angle;
#define PI 3.14159265358979323
#define h .000050000
	cout.precision(10);
	cout << "Pi: " << fixed << PI << endl;
	cout << "h: " << fixed << h << endl;

	//Inputs 
	//---------------------------------------------------------------
	cout << "This program will calculate the derivative of sine x " << endl;

	cout << "Please enter an angle in degrees " << endl;
	cin >> x;
	while (x >= 360 || x <= -360) { //This while loop keeps the angle within the bounds I selected
		cout << "please enter an angle between -360 and 360 " << endl;
		cin >> x;
	}

	//Outputs
	//-------------------------------------------------------
	cout << "The derivative of sin x for the angle " << x << " is " << fp(x);
	

	return 0;
}

//A module to calculate the original function
//----------------------------------------------
double f(double x) {
	//double angle = (x * PI) / 180; //Conversion to radians

	return sin(x);
}

//A module to calculate the derivative of the function
double fp(double x) {
	double angle = (x * PI) / 180; //Conversion to radians

	return (f(angle + h) - f(angle - h)) / (2 * h);
}

//****************************************************************
//It should be noted that I am using Degrees not Radians
//However, while using 90deg in the Central Difference program, the derivate was 0.0000000000
//The Forward Difference program gave me a derivative of 0.0000250000
//Clearly the Central Difference formula was more precise
