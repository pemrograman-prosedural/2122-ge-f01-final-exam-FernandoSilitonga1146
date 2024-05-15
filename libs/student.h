#ifndef STUDENT_H
#define STUDENT_H

#include "dorm.h"
#include "gender.h"

typedef struct {
    char id[15];
    char name[50];
    char year[5];
    enum gender_t gender;
    Dorm *dorm;
} Student;

Student create_student(char *_id, char *_name, char *_year, enum gender_t gender);
void printStudent(Student student);
void printStudentDetails(Student student);
short findStudentIdx(char *id, Student *students, unsigned short totalStudent);
void assign(Student *student, Dorm *dorm);
void unassign(Student *student, Dorm *dorm);
void moveStudent(Student *student, Dorm *newDorm, Dorm *oldDorm);

#endif
