#include <stdio.h>
#include <string.h>
#include "student.h"

Student create_student(char *_id, char *_name, char *_year, enum gender_t gender) {
    Student student_;
    strcpy(student_.id, _id);
    strcpy(student_.name, _name);
    strcpy(student_.year, _year);
    student_.gender = gender;
    student_.dorm = NULL;
    return student_;
}

void printStudent(Student student) {
    printf("Student ID: %s\nName: %s\nYear: %s\nGender: %s\n",
           student.id, student.name, student.year,
           student.gender == GENDER_MALE ? "Male" : "Female");
}

void printStudentDetails(Student student) {
    printf("Student Details:\n");
    printStudent(student);
    if (student.dorm != NULL) {
        printf("Dorm: %s\n", student.dorm->name);
    } else {
        printf("Dorm: Unassigned\n");
    }
}

short findStudentIdx(char *id, Student *students, unsigned short totalStudent) {
    for (short i = 0; i < totalStudent; i++) {
        if (strcmp(students[i].id, id) == 0) {
            return i;
        }
    }
    return -1;  // Not found
}

void assign(Student *student, Dorm *dorm) {
    if (student->gender == dorm->gender && dorm->residents_num < dorm->capacity) {
        student->dorm = dorm;
        dorm->residents_num++;
    }
}

void unassign(Student *student, Dorm *dorm) {
    if (student->dorm == dorm) {
        student->dorm = NULL;
        dorm->residents_num--;
    }
}

void moveStudent(Student *student, Dorm *newDorm, Dorm *oldDorm) {
    unassign(student, oldDorm);
    assign(student, newDorm);
}
