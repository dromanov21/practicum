# include <stdio.h>
# include <math.h>
int main()
{
    float eps = 0.0000001;
    float pi1 = 0;
    float pi2 = sqrtf(0.5);
    float pi0 = sqrtf(0.5);
    while (fabs(pi2 - pi1) >= eps)
    {
        printf("pi2 - pi1 = %f\n", fabs(pi2 - pi1));
        pi1 = pi2;
        pi2 = pi2 * sqrtf(0.5 + 0.5 * pi0);
        pi0 = sqrtf(0.5 + 0.5 * pi0);
        printf("pi2 = %f\n", pi2);
    }
    printf("pi2 = %.10f, pi1 = %.a10f", pi2, pi1);
}
