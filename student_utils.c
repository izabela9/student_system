#include "student.h"

// Function to print all students
void printStudents(Student arr[], int n) {
    printf("Student Records:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", arr[i].name);
        printf("Age: %d\n", arr[i].age);
        printf("Grade: %.2f\n", arr[i].grade);
        printf("---------------\n");
    }
}

float getAverage(Student arr[], int n)
{
    float sum = 0.0;
    for (int i = 0; i < n; i++)
        sum += arr[i].grade;

    return (float)(sum / n);
}

// Function to find the minimum grade among students
float findMinimumGrade(Student students[], int n) {
    if (n <= 0) {
        return -1.0; // Return a negative value to indicate an error or no students
    }

    float minGrade = students[0].grade;

    for (int i = 1; i < n; i++) {
        if (students[i].grade < minGrade) {
            minGrade = students[i].grade;
        }
    }

    return minGrade;
}

// Function to find the maximum grade among students
float findMaximumGrade(Student students[], int n) {
    if (n <= 0) {
        return -1.0; // Return a negative value to indicate an error or no students
    }

    float maxGrade = students[0].grade;

    for (int i = 1; i < n; i++) {
        if (students[i].grade > maxGrade) {
            maxGrade = students[i].grade;
        }
    }

    return maxGrade;
}

// Function to calculate the average grade of all students
float calculateAverageGrade(Student students[], int n) {
    if (n <= 0) {
        return -1.0; // Return a negative value to indicate an error or no students
    }

    float sum = 0.0;

    for (int i = 0; i < n; i++) {
        sum += students[i].grade;
    }

    return sum / n;
}

// Function to count the number of students with grades above a given threshold
int countStudentsAboveThreshold(Student students[], int n, float threshold) {
    if (n <= 0) {
        return 0; // Return 0 if there are no students
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (students[i].grade > threshold) {
            count++;
        }
    }

    return count;
}

void printStatistics(Student students[], int n) {
    float minGrade = findMinimumGrade(students, n);
    float maxGrade = findMaximumGrade(students, n);
    float avgGrade = calculateAverageGrade(students, n);

    printf("Statistics:\n");
    printf("Number of students %d\n", n);
    printf("Minimum Grade: %.2f\n", minGrade);
    printf("Maximum Grade: %.2f\n", maxGrade);
    printf("Average Grade: %.2f\n", avgGrade);
}


// Function to read student data from a file and store it in an array
int readStudentDataFromFile(const char *filename, Student students[], int maxStudents) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 0; // Return 0 to indicate failure
    }

    int count = 0; // Initialize the count of read students

    while (count < maxStudents) {
        if (fscanf(file, "%s %d %f", students[count].name, &students[count].age, &students[count].grade) != 3) {
            break; // Break the loop if fscanf fails to read all three values
        }
        count++;
    }

    fclose(file);
    return count; // Return the number of students read from the file
}