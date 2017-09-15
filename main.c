/*Programmer: David Henshaw
 *Class: CptS 121, Fall 2017; Lab Section 03
 *Programming Assignment: PA1
 *Date: Spetember 7, 2017
 *Description: Program evaluates a series of equations based on input from the user. 
 */

/*I used a similar approach to each of the 8 equations. Printf prompts the user, scanf assigns the inputs to their address in memory. Next the calculations are performed and printf 
  displays the equation with the values plugged in, and the result */

#include <stdio.h>
#include <math.h>

#define G 6.67E-11
#define PI 3.141592

int main(void)
{
	char plaintext_character = '/0', encoded_character = '/0';
	int R1 = 0, R2 = 0, R3 = 0, a = 0;
	double force = 0, mass = 0, acceleration = 0, radius = 0, height = 0, volume_cylinder = 0, mass1 = 0, mass2 = 0, distance = 0, tan_theta = 0, theta = 0, parallel_resistance = 0, x = 0, x1 = 0, x2 = 0, y = 0, y1 = 0, y2 = 0, z = 0;

	// 1) Newton's Second Law
	printf("Please enter the mass and acceleration (floating-point values) for use in Newton's Second Law: ");
	scanf("%lf %lf", &mass, &acceleration);
	//printf("%lf, %lf: ", mass, acceleration); Check for saved values 
		force = mass * acceleration;
	printf("Newton's Second Law: Force = Mass * Acceleration = %lf * %lf = %lf\n", mass, acceleration, force);
	printf("\n");

	// 2) Cylindrical Volume Equation
	printf("Please enter radius and height (floating-point values) for use in cylindrical volume equation: ");
	scanf("%lf %lf", &radius, &height);
		volume_cylinder = PI * pow(radius,2) * height;
	printf("Volume of the cylinder: Volume_Cylinder = PI * Radius^2 * Height = %lf * %lf^2 * %lf = %lf\n", PI, radius, height, volume_cylinder);
	printf("\n");

	// 3 ) Character Encoding																											   
	printf("Please enter a plaintext character for ASCII encoding: ");
	scanf(" %c", &plaintext_character);
	//printf("%c", plaintext_character);
		encoded_character = 10 + (plaintext_character - 'a') + 'A';
	printf("Encoded character = 10 + (plaintext character - 'a' ) + 'A' = 10 + ( '%c' - 'a' ) + 'A' = %c\n", plaintext_character, encoded_character);
	printf("\n");

	// 4 ) Gravity
	printf("Please enter two mass values (floating-point) and a distance value (floating-point) to calculate gravitation force: ");
	scanf("%lf %lf %lf", &mass1, &mass2, &distance);
	//printf("%lf %lf %lf", mass1, mass2, distance);
		force = G * mass1 * mass2 / pow(distance, 2);
	printf("Gravitational Force = G * Mass 1 * Mass 2 / Distance^2 = %.13lf * %lf * %lf / %lf^2 = %.13lf\n", G, mass1, mass2, distance, force);	// %.13 carries constant G and result out 13 places to avoid getting a response of zero
	printf("\n");

	// 5 ) Tangent
	printf("Please enter an angle theta (floating-point) to solve for the tangent: ");
	scanf("%lf", &theta);
		tan_theta = sin(theta) / cos(theta);
	printf("Tangent (Theta) = Sin (Theta) / Cos (Theta) = Sin (%lf) / Cos (%lf) = %lf\n", theta, theta, tan_theta);
	printf("\n");

	// 6 ) Total Parallel Resistance
	printf("Please enter three resistance values (integers) to calculate the total parallel resistance: ");
	scanf("%d %d %d", &R1, &R2, &R3);
	//printf("%d %d %d", R1, R2, R3); checking for values
		parallel_resistance = 1 / (((double)1 / R1) + ((double)1 / R2) + ((double)1 / R3)); //double typecast for precision with integer division
	printf("Total Parallel Resistance: Parallel Resistance = 1 / (1 / R1 + 1 / R2 + 1 / R3) = 1 / (1 / %d + 1 / %d + 1 / %d) = %lf\n", R1, R2, R3, parallel_resistance);
	printf("\n");

	// 7 ) Distance Between Two Points
	printf("Please enter two (x,y) coordinate pairs (floating-point) to solve for the distance between two points: ");
	scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
		distance = sqrt((pow(x1 - x2, 2)) + pow(y1 - y2, 2));
	printf("Distance between two points: Distance = Square Root of (X1 - X2)^2 + (Y1 - Y2)^2 = Square Root of (%lf - %lf)^2 + (%lf - %lf)^2 = %lf\n", x1, x2, y1, y2, distance);	//pow function require math.h library
	printf("\n");

	// 8 ) General Equation
	printf("Please enter varaibles a (integer), x and z (floating-points) to solve for y in the general equation: ");
	scanf("%d %lf %lf", &a, &x, &z);
		y = (double)(7 / 5) * x / a + z - a / (a % 2) + PI;
	printf("General Equation: y = (7/5) * x / a + z - a / (a %% 2) + PI = (7/5) * %lf / %d + %lf - %d / (%d %% 2) + %lf = %lf\n", x, a, z, a, a, PI, y);	// double %% required for the % to print; even numbers cause modulus part of equation to divide by zero
	printf("\n");
	

	
	return 0;

}