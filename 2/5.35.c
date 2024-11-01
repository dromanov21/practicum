# include <stdio.h> 
int G(int n, float *p) 
{ 
    float max0 = *p; 
    float min0 = *p; 
     
    for (int i = 0; i < n; ++i) 
    { 
        if (*p > max0) max0 = *p; 
        if (*p < min0) min0 = *p; 
        p = p + 1; 
    } 
    printf("%f\n%f\n", max0, min0); 
    return 0; 
} 
int main() 
{ 
    int n; 
    printf("%s", "Введите длину массива: "); 
    scanf("%d", &n); 
    float s[n]; 
    printf("%s", "Введите элементы массива: "); 
    for (int i = 0; i < n; ++i) 
        scanf("%f", &s[i]); 
    G(n, s); 
}
