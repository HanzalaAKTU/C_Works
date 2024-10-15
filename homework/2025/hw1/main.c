#include <stdio.h>

/* Define constants for the number of points and the difference threshold*/
#define N 10
#define X 10
#define EPSILON 0.0001

/*Initialize cluster centers and their point counts*/
float cluster1_x = 0.0f, cluster1_y = 0.0f;
int cluster1_point = 1; /*Count of points in Cluster 1*/

float cluster2_x = 0.0f, cluster2_y = 0.0f;
int cluster2_point = 1; /*Count of points in Cluster 2*/

float cluster3_x = 0.0f, cluster3_y = 0.0f;
int cluster3_point = 1; /*Count of points in Cluster 3*/

/*Function to calculate the squared distance between two points*/
float calculate_distance_squared (float x1, float y1, float x2, float y2) 
{
    float dx = x1 - x2;
    float dy = y1 - y2;

    return dx * dx + dy* dy; /*Return the squared distance*/
}

/*Function to update the cluster center based on a new point*/
void update_cluster(int cluster_no, float point_x, float point_y)
{
    switch (cluster_no)
    {
        case 1: /*Update Cluster 1*/
            cluster1_x = (cluster1_x * cluster1_point + point_x) / (cluster1_point + 1);
            cluster1_y = (cluster1_y * cluster1_point + point_y) / (cluster1_point + 1);
            cluster1_point++; /*Increment the point count*/
            break;
        case 2: /*Update Cluster 2*/
            cluster2_x = (cluster2_x * cluster2_point + point_x) / (cluster2_point + 1);
            cluster2_y = (cluster2_y * cluster2_point + point_y) / (cluster2_point + 1);
            cluster2_point++ ; /*Increment the point count*/
            break;
        case 3: /*Update Cluster 3*/
            cluster3_x = (cluster3_x * cluster3_point + point_x) / (cluster3_point + 1);
            cluster3_y = (cluster3_y * cluster3_point + point_y) / (cluster3_point + 1);
            cluster3_point++; /*Increment the point count*/
            break;
    }
}

/*Function to calculate the percentage difference between two distances*/
float calcualate_diff(float distance1, float distance2)
{
    return (distance1 - distance2) / (distance1 + EPSILON) * 100.0f; /*Avoid division by zero */
}

/*Function to check if the point should be added to the nearest cluster*/
int check_difference(float distance_to_cluster1, float distance_to_cluster2, float distance_to_cluster3, int nearest_cluster )
{
    float diff1, diff2;
    
    switch (nearest_cluster)
    {
    case 1:
        diff1 = calcualate_diff(distance_to_cluster2, distance_to_cluster1);
        diff2 = calcualate_diff(distance_to_cluster3, distance_to_cluster1);
        break;

    case 2:
        diff1 = calcualate_diff(distance_to_cluster1, distance_to_cluster2);
        diff2 = calcualate_diff(distance_to_cluster3, distance_to_cluster2);
        break;

    case 3:
        diff1 = calcualate_diff(distance_to_cluster1, distance_to_cluster3);
        diff2 = calcualate_diff(distance_to_cluster2, distance_to_cluster3);
        break;    
    }

    /*Check if the differences are below the threshold*/
    if (diff1 < X || diff2 < X)
        return 0; /*The point will not be added*/
    
    return 1; /*The point can be added to the nearest cluster*/
}

/*Function to find the nearest cluster for a given point*/
int find_nearest_cluster(float point_x,float point_y)
{
    /*Calculate distances to each cluster*/
    float distance_to_cluster1 = calculate_distance_squared(cluster1_x, cluster1_y, point_x, point_y);
    float distance_to_cluster2 = calculate_distance_squared(cluster2_x, cluster2_y, point_x, point_y);
    float distance_to_cluster3 = calculate_distance_squared(cluster3_x, cluster3_y, point_x, point_y);

    /*Check for equal distances to clusters*/
    if (distance_to_cluster1 == distance_to_cluster2 ||
        distance_to_cluster1 == distance_to_cluster3 ||
        distance_to_cluster2 == distance_to_cluster3 )
    {
        printf("\nPoint %.2f, %.2f is equally distant to multiple clusters, discarded. \n", point_x, point_y);
        return 0; /*The point is not added*/
    }
    
    /*Initialize the nearest cluster as Cluster 1*/
    float min_distance_cluster = distance_to_cluster1;
    int nearest_cluster = 1;
    
    /*Check for the nearest cluster*/
    if (distance_to_cluster2 < min_distance_cluster )
    {
        min_distance_cluster = distance_to_cluster2;
        nearest_cluster = 2;
    }

    if (distance_to_cluster3 < min_distance_cluster)
    {
        min_distance_cluster = distance_to_cluster3;
        nearest_cluster = 3;
    }

    /*Check if the point should be added to the nearest cluster*/
    if (check_difference(distance_to_cluster1, distance_to_cluster2, distance_to_cluster3, nearest_cluster))
    {
        printf("\nPoint %.2f, %.2f was include Cluster%d\n",point_x, point_y, nearest_cluster);
        update_cluster(nearest_cluster, point_x, point_y); /*Update the cluster with the new point*/
    }
    else
    {
        printf("\nPoint of %.2f, %.2f was discarded\n",point_x, point_y); /*The point is discarded*/
    }

    return nearest_cluster; /*Return the nearest cluster number*/
}

int main() 
{
    /*Get cluster centers from the user*/
    printf("Enter the center for Cluster 1 (x,y) :");
    scanf("%f %f",&cluster1_x, &cluster1_y);

    printf("\nEnter rhe center for Cluster 2 (x,y) : ");
    scanf("%f %f",&cluster2_x, &cluster2_y);

    printf("\nEnter rhe center for Cluster 3 (x,y) : ");
    scanf("%f %f",&cluster3_x, &cluster3_y);

    /*Loop to get points from the user*/
    for (int i = 0; i < N; i++)
    {
        float point_x, point_y;
        printf("\nEnter point coordinates (x,y)");
        scanf("%f %f",&point_x, &point_y);

        find_nearest_cluster(point_x, point_y); /*Find the nearest cluster for the point*/
    }
    
    /*Print the final cluster centers and their point counts*/
    printf("\nCluster 1: %.2f, %.2f, %d \n",cluster1_x, cluster1_y, cluster1_point);
    printf("\nCluster 2: %.2f, %.2f, %d \n",cluster2_x, cluster2_y, cluster2_point);
    printf("\nCluster 3: %.2f, %.2f, %d \n",cluster3_x, cluster3_y, cluster3_point);
}