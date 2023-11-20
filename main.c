#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 100
#define LEARNING_RATE 0.0001
#define EPSILON 0.0000001
#define num_points  sizeof(dataset) / sizeof(dataset[0])

typedef struct {
    float x;
    float y;
} DataPoint;

// Squared difference for loss
float 
Loss(float x, float y, float w) {
    return pow(w * x - y, 2); 
}
// Gradient of the loss function
float 
Gradient(float x, float y, float w) {
    return 2 * x * (w * x - y); 
}
// Random number generation for w
float 
rand_float()
{
    return (float) rand() / (float) RAND_MAX ;
}

int 
main () 
{
    DataPoint dataset[] = {
        {0.0, 0.0},
        {1.0, 2.0},
        {2.0, 4.0},
        {3.0, 6.0},
        {4.0, 8.0},
        {5.0, 10.0},
        {6.0, 12.0},
        {13.0, 26.0},
        {14.0, 28.0},
        {15.0, 30.0},
        {16.0, 32.0},

    };

    srand(44); // Seed
    float w = rand_float()*10.0f ; 
    float loss, gradient;

    size_t i, j;
    for (i = 0; i < MAX_ITERATIONS; ++i) {
        loss = 0.0;
        for (j = 0; j < num_points; ++j) {
            // Calculate squared error for each point
            loss += Loss(dataset[j].x, dataset[j].y, w);
        }
        printf("loss: %f -- iteration : [%zu]\n" , loss, i);
        gradient = 0.0;
        for (j = 0; j < num_points; ++j) {
            // Total gradiant
            gradient += Gradient(dataset[j].x, dataset[j].y, w);
        }

        // Basic gradient descent
        w = w - LEARNING_RATE * gradient;

        // Convergence condition
        if (loss < EPSILON) {
            printf("Converged after %zu iterations\n", i + 1);
            break;
        }
    }

    printf("Final weight (w) value: %f\n", w);
    printf("loss : %f", loss);

    return 0;
}
