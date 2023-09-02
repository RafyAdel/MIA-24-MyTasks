#include <stdio.h>
#include <stdlib.h>
#define initialVelocity 30
#define initialAngle 46
float kalman(float,float);
int main()
{
    float mpu6050[10] = {0.0, 11.68, 18.95, 23.56, 25.72, 25.38, 22.65, 18.01, 10.14, -0.26};
    float bno55[10] = {0.0,9.49, 16.36, 21.2, 23.16, 22.8, 19.5, 14.85, 6.79, -2.69};
    //fair
    float fair[10];
    printf("fair results are : \n");
    for (int i=0;i<10;i++)
    {
        fair[i]=(mpu6050[i]+bno55[i])/2;
        printf("%f ,",fair[i]);
    }
    printf("\n");
    //good
    float good[10];
    printf("good results are : \n");
    for (int i=0;i<10;i++)
    {
        good[i]=(mpu6050[i]*0.78+bno55[i]*0.92)/(0.92+0.78);
        /*formula to calculate the avg taking into consideration the accuracies is
        Average = (Reading1 * Accuracy1 + Reading2 * Accuracy2) / (Accuracy1 + Accuracy2)*/
        printf("%f ,",good[i]);
    }
    printf("\n");
    //hero
    float hero[10];
    printf("hero results are : \n");
    for (int i=0;i<10;i++)
    {
        hero[i]= kalman(mpu6050[i],bno55[i]);
        printf("%f ,",hero[i]);
    }
    printf("\n");
    //legend
    // i really didn't know how to go through it :(
    return 0;
}
float kalman(float z1,float z2)
{
    int A = 1, //(identity matrix)
    B = 0, //(no control input)
    uK1 = 0, //(no control input)
    Q = 0, //(process noise covariance matrix)
    H = 1, //(identity matrix, assuming direct measurement)
    R = 1, //(measurement noise covariance matrix)
    xNOTE = 0, //(initial estimated state)
    PNOTE = 1; //(initial error covariance)
    //prediction step using z1:
    float x1DASH = A * xNOTE + B * uK1  ; //(no control input)
    float P1DASH = A * PNOTE * 1/*transpose of matrix A*/ + Q ;//(assuming no process noise)
    //update step :
    float
    y1 = z1 - H * x1DASH ,// (innovation or measurement residual)
    S1 = H * P1DASH * 1/*TRANSPOSE H*/ + R ,//  (innovation covariance)
    K1 = P1DASH * 1/*transpose h*/ / S1 , //(optimal Kalman gain)
    x1 = x1DASH + K1 * y1 , //(updated state estimate)
    P1 = (1/*identity matrix*/ - K1 * H) * P1DASH ; //(updated error covariance)
    //prediction step using z2:
    float x2DASH = A * x1 + B * uK1  ; //(no control input)
    float P2DASH = A * P1 * 1/*transpose of matrix A*/ + Q ;//(assuming no process noise)
    //update step :
    float
    y2 = z2 - H * x2DASH ,// (innovation or measurement residual)
    S2 = H * P2DASH * 1/*TRANSPOSE H*/ + R ,//  (innovation covariance)
    K2 = P2DASH * 0.5/*transpose H??*/ / S2 , //(optimal Kalman gain)
    x2 = x2DASH + K2 * y2 , //(updated state estimate)
    P2 = (1/*identity matrix*/ - K2 * H) * P2DASH ; //(updated error covariance)

    return x2;
}
