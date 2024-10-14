#include <stdio.h>

#define N 10
#define X 10
#define EPSİLON 0.0001

float cluster1_x=0.0f, cluster1_y=0.0f;
int cluster1_point=1;

float cluster2_x=0.0f, cluster2_y=0.0f;
int cluster2_point=1;

float cluster3_x=0.0f, cluster3_y=0.0f;
int cluster3_point=1;

float calculate_distance_squared (float x1, float y1, float x2, float y2) {
    float dx = x1 - x2;
    float dy = y1 - y2;

    return dx * dx + dy* dy;
}

void update_cluster(int cluster_no, float point_x, float point_y){

    switch (cluster_no)
    {
        case 1:
            cluster1_x=(cluster1_x*cluster1_point+point_x)/(cluster1_point+1);
            cluster1_y=(cluster1_y*cluster1_point+point_y)/(cluster1_point+1);
            cluster1_point++; 
            break;
        case 2:
            cluster2_x=(cluster2_x*cluster2_point+point_x)/(cluster2_point+1);
            cluster2_y=(cluster2_y*cluster2_point+point_y)/(cluster2_point+1);
            cluster2_point++; 
            break;
        case 3:
            cluster3_x=(cluster3_x*cluster3_point+point_x)/(cluster3_point+1);
            cluster3_y=(cluster3_y*cluster3_point+point_y)/(cluster3_point+1);
            cluster3_point++; 
            break;
        default:
            printf("Invalid cluster number!");
            break;
    }
}

int find_nearest_cluster(float point_x,float point_y){

    float distance_to_cluster1 = calculate_distance_squared(cluster1_x,cluster1_y,point_x,point_y);
    float distance_to_cluster2 = calculate_distance_squared(cluster2_x,cluster2_y,point_x,point_y);
    float distance_to_cluster3 = calculate_distance_squared(cluster3_x,cluster3_y,point_x,point_y);

    

    if (distance_to_cluster1 < distance_to_cluster2 && distance_to_cluster1 < distance_to_cluster3)
    
        return 1;
    
    if (distance_to_cluster2 < distance_to_cluster1 && distance_to_cluster2 < distance_to_cluster3)

        return 2;

    if (distance_to_cluster3 < distance_to_cluster1 && distance_to_cluster3 < distance_to_cluster2)
    
        return 3;

}


int main() {

    printf("Enter the center for Cluster 1 (x,y) :");
    scanf("%f %f",&cluster1_x,&cluster1_y);

    printf("Enter rhe center for Cluster 2 (x,y) : ");
    scanf("%f %f",&cluster2_x,&cluster2_y);

    printf("Enter rhe center for Cluster 3 (x,y) : ");
    scanf("%f %f",&cluster3_x,&cluster3_y);

    for (int i = 0; i < N; i++)
    {
        float point_x, point_y;
        printf("Enter point coordinates (x,y)");
        scanf("%f %f",&point_x, &point_y);

        int nearest_cluster = find_nearest_cluster(point_x,point_y);
        update_cluster(nearest_cluster, point_x, point_y);

    }
    
    printf("Cluster 1: %.2f, %.2f, %d \n",cluster1_x,cluster1_y,cluster1_point);
    printf("Cluster 2: %.2f, %.2f, %d \n",cluster2_x,cluster2_y,cluster2_point);
    printf("Cluster 3: %.2f, %.2f, %d \n",cluster3_x,cluster3_y,cluster3_point);

}