#include <stdio.h>

#define N 10        // Nokta sayısı
#define X 10        // Yüzde farkı
#define EPSILON 0.001f   // Küçük değer (float tipi için 'f' ekledik)

// Küme merkezi ve nokta sayıları için global değişkenler (float tipi kullanılıyor)
float cluster1_x = 0.0f, cluster1_y = 0.0f;
int cluster1_points = 0;

float cluster2_x = 0.0f, cluster2_y = 0.0f;
int cluster2_points = 0;

float cluster3_x = 0.0f, cluster3_y = 0.0f;
int cluster3_points = 0;

// Mesafeyi karesini hesaplayan fonksiyon (float tipi kullanıyor)
float calculate_distance_squared(float x1, float y1, float x2, float y2) {
    float dx = x1 - x2;
    float dy = y1 - y2;
    return dx * dx + dy * dy;  // Mesafenin karesi
}

// Küme 1'i güncelleyen fonksiyon
void update_cluster1(float point_x, float point_y) {
    cluster1_x = (cluster1_x * cluster1_points + point_x) / (cluster1_points + 1);
    cluster1_y = (cluster1_y * cluster1_points + point_y) / (cluster1_points + 1);
    cluster1_points++;
}

// Küme 2'yi güncelleyen fonksiyon
void update_cluster2(float point_x, float point_y) {
    cluster2_x = (cluster2_x * cluster2_points + point_x) / (cluster2_points + 1);
    cluster2_y = (cluster2_y * cluster2_points + point_y) / (cluster2_points + 1);
    cluster2_points++;
}

// Küme 3'ü güncelleyen fonksiyon
void update_cluster3(float point_x, float point_y) {
    cluster3_x = (cluster3_x * cluster3_points + point_x) / (cluster3_points + 1);
    cluster3_y = (cluster3_y * cluster3_points + point_y) / (cluster3_points + 1);
    cluster3_points++;
}

// Noktayı bir kümeye atan fonksiyon
void classify_point(float point_x, float point_y) {
    // Her bir kümeye olan mesafe karelerini hesapla
    float dist1_squared = calculate_distance_squared(point_x, point_y, cluster1_x, cluster1_y);
    float dist2_squared = calculate_distance_squared(point_x, point_y, cluster2_x, cluster2_y);
    float dist3_squared = calculate_distance_squared(point_x, point_y, cluster3_x, cluster3_y);

    // En küçük ve ikinci en küçük mesafeyi bul
    float min_dist_squared = dist1_squared;
    float next_min_dist_squared = dist2_squared;

    if (dist3_squared < next_min_dist_squared) {
        next_min_dist_squared = dist3_squared;
    }
    if (dist1_squared > next_min_dist_squared) {
        next_min_dist_squared = dist1_squared;
        min_dist_squared = dist2_squared;
    }

    // Yüzde farkı hesapla
    float diff = ((next_min_dist_squared - min_dist_squared) / (next_min_dist_squared + EPSILON)) * 100;

    if (diff >= X) {
        // Noktayı en yakın kümeye dahil et
        if (min_dist_squared == dist1_squared) {
            printf("Point %.2f, %.2f was included in Cluster 1\n", point_x, point_y);
            update_cluster1(point_x, point_y);
        } else if (min_dist_squared == dist2_squared) {
            printf("Point %.2f, %.2f was included in Cluster 2\n", point_x, point_y);
            update_cluster2(point_x, point_y);
        } else {
            printf("Point %.2f, %.2f was included in Cluster 3\n", point_x, point_y);
            update_cluster3(point_x, point_y);
        }
    } else {
        printf("Point %.2f, %.2f was discarded\n", point_x, point_y);
    }
}

int main() {
    // Kullanıcıdan küme merkezlerini al
    printf("Enter the center for Cluster 1 (x y): ");
    scanf("%f %f", &cluster1_x, &cluster1_y);

    printf("Enter the center for Cluster 2 (x y): ");
    scanf("%f %f", &cluster2_x, &cluster2_y);

    printf("Enter the center for Cluster 3 (x y): ");
    scanf("%f %f", &cluster3_x, &cluster3_y);

    // N sayıda noktayı işle
    for (int i = 0; i < N; i++) {
        float point_x, point_y;
        printf("Enter point coordinates (x y): ");
        scanf("%f %f", &point_x, &point_y);

        classify_point(point_x, point_y);
    }

    // Sonuçları yazdır
    printf("Cluster 1: %.2f, %.2f, %d\n", cluster1_x, cluster1_y, cluster1_points);
    printf("Cluster 2: %.2f, %.2f, %d\n", cluster2_x, cluster2_y, cluster2_points);
    printf("Cluster 3: %.2f, %.2f, %d\n", cluster3_x, cluster3_y, cluster3_points);

    return 0;
}
