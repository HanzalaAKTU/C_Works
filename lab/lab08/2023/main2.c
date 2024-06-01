#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846


typedef struct 
{
  double x;
  double y;
  double z;
} vector;

double find_orthogonal(vector vec_1, vector vec_2, vector* output_vec) 
{
  // Calculate the cross product of the input vectors
  vector cross = 
  {
    .x = vec_1.y * vec_2.z - vec_1.z * vec_2.y,
    .y = vec_1.z * vec_2.x - vec_1.x * vec_2.z,
    .z = vec_1.x * vec_2.y - vec_1.y * vec_2.x
  };

  // Calculate the angle between the input vectors in degrees
  double dot = vec_1.x * vec_2.x + vec_1.y * vec_2.y + vec_1.z * vec_2.z;
  double mag_1 = sqrt(vec_1.x * vec_1.x + vec_1.y * vec_1.y + vec_1.z * vec_1.z);
  double mag_2 = sqrt(vec_2.x * vec_2.x + vec_2.y * vec_2.y + vec_2.z * vec_2.z);
  double angle = acos(dot / (mag_1 * mag_2)) * 180.0 / M_PI;

  // Set the output vector to the found orthogonal vector
  *output_vec = cross;

  // Return the calculated angle
  return angle;
}

int main() 
{
  vector vec_1 = { .x = 1.0, .y = 2.0, .z = 3.0 };
  vector vec_2 = { .x = 4.0, .y = 5.0, .z = 6.0 };
  vector output_vec;
  double angle = find_orthogonal(vec_1, vec_2, &output_vec);
  printf("Angle between vectors: %.2f degrees\n", angle);
  printf("Orthogonal vector: (%.2f, %.2f, %.2f)\n", output_vec.x, output_vec.y, output_vec.z);
  return 0;
}
