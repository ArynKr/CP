#include <stdio.h>

void Merge(int a[], int low, int high, int mid)
{
   int i = low, j = mid + 1, k = 0;
   int temp[high - low + 1];

   while (i <= mid && j <= high)
   {
      if (a[i] > a[j])          //comparison step
      {
         temp[k++] = a[i++];
      }

      else
      {
         temp[k++] = a[j++];
      }
   }

   while (i <= mid)
   {
      temp[k++] = a[i++];
   }

   while (j <= high)
   {
      temp[k++] = a[j++];
   }

   for (i = low; i <= high; i++)
   {
      a[i] = temp[i - low];
   }
}


void MergeSort(int a[], int low, int high)
{
   int mid;

   if (low < high)
   {
      mid = (low + high) / 2;

      MergeSort(a, low, mid);
      MergeSort(a, mid + 1, high);

      Merge(a, low, high, mid);
   }
}

int main()
{
   int n; 
   printf("Enter the number of elements: ");
   scanf("%d", &n);
   int a[n];
   printf("Enter the elements\n");
   for(int i=0; i<n; i++) {
    scanf("%d", &a[i]);
   }
   MergeSort(a, 0, n-1);
   for (int i = 0; i < n; i++)
   {
      printf("%d  ", a[i]);
   }
}
