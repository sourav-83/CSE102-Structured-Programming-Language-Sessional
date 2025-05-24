#include <stdio.h>

int main ()
{

    int m,n;
    printf ("Enter the values of m and n: ");
    scanf ("%d%d", &m, &n);
    int nums1[m], nums2[n];
    if (m>0)
    {
    printf ("Enter the nums1 array: ");
    }
    for (int i=0; i<m; i++) {scanf("%d", &nums1[i]);}
    if (n>0)
    {
    printf ("Enter the nums2 array: ");
    }
    for (int i=0; i<n; i++) {scanf("%d", &nums2[i]);}

    int length = m+n;
    int combined_array [length];

    for (int i=0; i<m; i++) {combined_array[i]=nums1[i];}
    for (int i=m; i<m+n; i++) {combined_array[i]=nums2[i-m];}

    for (int i=0; i<length; i++)
    {
        for (int j=i+1; j<length; j++)
        {
            if (combined_array[i]>combined_array[j])
                {
                   int temp = combined_array[i];
                   combined_array[i]=combined_array[j];
                   combined_array[j]=temp;
                }
        }
    }

    if (length%2==1)
    {
        int midpoint = length/2; printf ("%d", combined_array[midpoint]);
    }
    else
    {
       int firstmid = (length/2)-1, secondmid = length/2;
       double ans = (combined_array[firstmid]+combined_array[secondmid])/2.0;
       printf ("%g", ans);

    }

    return 0;
}
