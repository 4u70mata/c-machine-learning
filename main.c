#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float train[][2]  = {
    {0,0},
    {1,2},
    {2,4},
    {3,6},
    {4,8},
};
#define train_count sizeof(train)/sizeof(train[0])

float 
rand_float ()
{
    return (float) rand() / (float) RAND_MAX ;
}
float 
cost_function(float w)
{
    printf("Train Process beginning\n");
    float mse = 0.0f;
    for(size_t i = 0; i<train_count; i++ ){
        float x = train[i][0];
        float y = x*w;
        float d = y- train[i][1];
        mse +=d*d; // include math
        //printf("Actual : %f , Expected: %f\n", train[i][1], y);
    }
    mse /= train_count;
    //printf("Mean Squared Error: %f\n", mse);
    return mse;
}
int main(){
    // model : y = x*w  
    //time_t t;
    //srand(time(&t));
    srand(42);
    float w = rand_float()*10.0f ; // initialize weight vector w
    printf("Initialozation of weight vector w0: %f\n", w);
    float cost = cost_function(w);
    printf("cost with w0 :%f\n\n", cost);
    float eps = 1e-3;
    printf("grid search -esp :%f results with \n:", eps);
    printf("cost function of w + eps : %f", cost_function(w+eps));
    
    return 0;
}