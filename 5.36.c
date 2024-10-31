# include <stdio.h>
# include <string.h>
int main()
{
    char s[10];
    char s1[10];
    char s2[10];
    scanf("%10s", s);
    int i;
    int a;
    for (i = 0; i < 10; ++i)
    {
        a = i / 2;
        if (i % 2 == 1) s1[a] = s[i];
        else s2[a] = s[i];
    }
    printf("%5s%5s", s2, s1);
}
