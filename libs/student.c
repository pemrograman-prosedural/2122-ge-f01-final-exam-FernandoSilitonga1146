#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gender.h"

struct student_t create_student(char *_nim, char *_nama, char *_tahun,enum gender_t _gender){
    struct student_t student_;
    strcpy(student_.nim, _nim);
    strcpy(student_.nama, _nama);
    strcpy(student_.tahun, _tahun);
    student_.gender = _gender;
    student_.dorm = NULL;                                               
                                   
    return student_;
}
void print_student(struct student_t *_student, int a){
    char jenis[10];
    strcpy(jenis, "|male\n");
    char type[10];
    strcpy(type, "|female\n");

    for (int i = 0; i < a; i++){
        if (_student[i].gender==0)
        {
        printf("%s|", _student[i].nim);
        printf("%s|", _student[i].nama);                                       
        printf("%s", _student[i].tahun);
        printf("%s", jenis);
        }                                                 
        else if (_student[i].gender==1){
        printf("%s|", _student[i].nim);
        printf("%s|", _student[i].nama);
        printf("%s", _student[i].tahun);
        printf("%s", type);
        }
    }
}
void print_student_detail(struct student_t *_student, int a){
    char jenis[20];
    strcpy(jenis, "|male");
    char type[20]; 
    strcpy(type, "|female");  
    
    for (int i = 0; i < a; i++){
        if (_student[i].dorm == NULL){
        if (_student[i].gender==0)
        {
        printf("%s|", _student[i].nim);
        printf("%s|", _student[i].nama);
        printf("%s", _student[i].tahun);
        printf("%s|left\n", jenis);
        } 
        else if (_student[i].gender==1){
        printf("%s|", _student[i].nim);
        printf("%s|", _student[i].nama);
        printf("%s", _student[i].tahun);
        printf("%s|left\n", type);
        }
      }
    else {
        if (_student[i].gender==0)
        {
        printf("%s|", _student[i].nim);
        printf("%s|", _student[i].nama);
        printf("%s", _student[i].tahun);
        printf("%s", jenis);
        } 
        else if (_student[i].gender==1){
        printf("%s|", _student[i].nim);
        printf("%s|", _student[i].dorm->nama);
        printf("%s", _student[i].dorm->nama);
        printf("%s", type);
        }
    }
    }
}
void assign_student(struct student_t *_student,struct dorm_t *_dorm, char *nim, char *nama){
    if (_dorm->residents_num < _dorm->kapasitas){
        if (_student->gender == _dorm->gender){
             _dorm->residents_num++;
            _student->dorm = _dorm;
           
        }
    }
}
void student_leave(struct student_t *_students, struct dorm_t *_dorms){
    if (_students->dorm!=NULL)
    {
        _students->dorm = NULL;

        _dorms->residents_num--;
    }
}

