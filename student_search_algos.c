#include "student.h"

int linearSearch(Student arr[], int n, char searchName[]) {
    int i;
    for (i=0; i<n; i++){
        if (strcmp(arr[i].name, searchName) == 0)
            return i;
    }
    return -1;
}

// Function to perform binary search on student records by name
int binarySearch(Student arr[], int low, int high, char key[]) {
   
   int mid;

   while (low <= high) {
    mid = (low + high) / 2;

    if (strcmp(arr[mid].name, key) == 0)
        return mid;
    if (strcmp(arr[mid].name, key) > 0)
        high = mid - 1;
    else
        low = mid + 1;

   }

   return -1;
}