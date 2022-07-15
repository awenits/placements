#include<stdio.h>
#include<stdlib.h>

int main()
{
    float *fptr = (float*) malloc(sizeof(float));
    *fptr = 7.5;

    printf("%f\n", *fptr);

    // 1-D Array Dynamic Memory Allocaion
    int* arr;
    int n=5, i;

    // Dynamically allocate memory using malloc() for array of 5 elements
    arr = (int*)malloc(n * sizeof(int));

    // Check if the memory has been successfully allocated by malloc or not
    if (arr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {

        // Inserting the elements into the array if memory allocated
        for (i = 0; i < n; ++i) {
            arr[i] = i + 1;
        }

        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", arr[i]);
        }
        printf("\n");
    }

    free(arr);  //dangling pointer
    printf("Contents of arr after deallocation %d\n", *(arr)); //prints garbage or 0
    arr = NULL;
    //printf("%d", *(arr));   // segmentation fault

    // 2D Array Dynamic Memory Allocation
    int row=3, col=4;
    arr = (int*) malloc((row*col)*sizeof(int));

    // Dynamically allocate memory using malloc() for 2d array of 12 elements
    if (arr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {

        // Inserting the elements into the array if memory allocated
        //memory is allocated like 1d arrays only
        for (i = 0; i < row*col; ++i) {
            arr[i] = i + 1;
        }

        printf("The elements of 2D array (row major): \n");
        for (i = 0; i < row; ++i) {
            for(int j=0; j<col; j++){
                printf("%d, ", arr[(i * col + j)]);
            }
             printf("\n");
        }

        printf("The elements of 2D array (column major): \n");
        for (i = 0; i < col; ++i) {
            for(int j=0; j<row; j++){
                printf("%d, ", arr[(j * col + i)]);
            }
             printf("\n");
        }
    }
    free(arr);  //dangling pointer
    printf("Contents of arr after deallocation: %d\n", *(arr)); //prints garbage or 0
    arr = NULL;
    //printf("%d", *(arr));   // segmentation fault


    // 2D array allocation using array of pointers
    int* arr2d[row];
    for (i = 0; i < row; i++)
        arr2d[i] = (int*)malloc(col * sizeof(int));

    // Note that arr[i][j] is same as *(*(arr+i)+j)
    int count = 0;
    for (i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            arr2d[i][j] = ++count; // Or *(*(arr+i)+j) = ++count

    for (i = 0; i < row; i++){
        for (int j = 0; j < col; j++)
            printf("%d ", arr2d[i][j]);
        printf("\n");
    }


    /* Code for further processing and free the
      dynamically allocated memory */

    for (int i = 0; i < row; i++)
        free(arr2d[i]);

    return 0;
}