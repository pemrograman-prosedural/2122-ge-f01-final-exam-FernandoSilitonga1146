// NIM - Name
// NIM - Name

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libs/dorm.h"
#include "libs/student.h"

#define MAX_INPUT_LENGTH 100
#define MAX_DORMS 100
#define MAX_STUDENTS 100

void assign_student_to_dorm(struct student_t *student, struct dorm_t *dorm) {
    if (dorm->residents_num < dorm->capacity) {
        student->dorm = dorm;
        dorm->residents_num++;
    }
}

void remove_student_from_dorm(struct student_t *student) {
    if (student->dorm != NULL) {
        student->dorm->residents_num--;
        student->dorm = NULL;
    }
}

int main(int _argc, char **_argv) {
    struct dorm_t *dorms = malloc(MAX_DORMS * sizeof(struct dorm_t));
    struct student_t *students = malloc(MAX_STUDENTS * sizeof(struct student_t));
    char input[MAX_INPUT_LENGTH];
    char id[12];
    char student_name[40];
    char year[5];
    char dorm_name[40];
    unsigned short capacity;
    char *masukan;
    int data_student, data_dorm;
    int stdnt = 0, drm = 0;

    while (true) {
        fflush(stdin);
        input[0] = '\0';
        int c = 0;
        do {
            char x = getchar();
            if (x == '\r') {
                continue;
            }
            if (x == '\n') {
                break;
            }
            input[c] = x;
            input[++c] = '\0';
        } while (true);

        masukan = strtok(input, "#");
        if (strcmp(masukan, "---") == 0) {
            break;
        } else if (strcmp(masukan, "student-print-all") == 0) {
            for (int i = 0; i < stdnt; i++) {
                printf("%s|%s|%s|%s|%s\n", students[i].id, students[i].name, students[i].year, students[i].gender == GENDER_MALE ? "male" : "female", students[i].dorm != NULL ? students[i].dorm->name : "left");
            }

        } else if (strcmp(masukan, "student-print-all-detail") == 0) {
            for (int i = 0; i < stdnt; i++) {
                printf("%s|%s|%s|%s|%s\n", students[i].id, students[i].name, students[i].year, students[i].gender == GENDER_MALE ? "male" : "female", students[i].dorm != NULL ? students[i].dorm->name : "left");
            }

        } else if (strcmp(masukan, "student-add") == 0) {
            masukan = strtok(NULL, "#");
            strcpy(id, masukan);
            masukan = strtok(NULL, "#");
            strcpy(student_name, masukan);
            masukan = strtok(NULL, "#");
            strcpy(year, masukan);
            masukan = strtok(NULL, "#");
            if (strcmp(masukan, "male") == 0) {
                struct student_t (*pf)(char *_id, char *_name, char *_year, enum gender_t _gender) = create_student;
                students[stdnt] = pf(id, student_name, year, GENDER_MALE);
            } else if (strcmp(masukan, "female") == 0) {
                struct student_t (*pf)(char *_id, char *_name, char *_year, enum gender_t _gender) = create_student;
                students[stdnt] = pf(id, student_name, year, GENDER_FEMALE);
            }
            stdnt++;

        } else if (strcmp(masukan, "dorm-print-all") == 0) {
            for (int i = 0; i < drm; i++) {
                printf("%s|%d|%s\n", dorms[i].name, dorms[i].capacity, dorms[i].gender == GENDER_MALE ? "male" : "female");
            }

        } else if (strcmp(masukan, "dorm-print-all-detail") == 0) {
            for (int i = 0; i < drm; i++) {
                printf("%s|%d|%s\n", dorms[i].name, dorms[i].capacity, dorms[i].gender == GENDER_MALE ? "male" : "female");
                for (int j = 0; j < stdnt; j++) {
                    if (students[j].dorm != NULL && strcmp(students[j].dorm->name, dorms[i].name) == 0) {
                        printf("  - %s|%s|%s|%s\n", students[j].id, students[j].name, students[j].year, students[j].gender == GENDER_MALE ? "male" : "female");
                    }
                }
            }

        } else if (strcmp(masukan, "dorm-add") == 0) {
            masukan = strtok(NULL, "#");
            strcpy(dorm_name, masukan);
            masukan = strtok(NULL, "#");
            capacity = (unsigned short) atoi(masukan);
            masukan = strtok(NULL, "#");
            if (strcmp(masukan, "male") == 0) {
                struct dorm_t (*pf)(char *_name, unsigned short _capacity, enum gender_t _gender) = create_dorm;
                dorms[drm] = pf(dorm_name, capacity, GENDER_MALE);
            } else if (strcmp(masukan, "female") == 0) {
                struct dorm_t (*pf)(char *_name, unsigned short _capacity, enum gender_t _gender) = create_dorm;
                dorms[drm] = pf(dorm_name, capacity, GENDER_FEMALE);
            }
            drm++;

        } else if (strcmp(masukan, "assign-student") == 0) {
            masukan = strtok(NULL, "#");
            strcpy(id, masukan);
            masukan = strtok(NULL, "#");
            strcpy(dorm_name, masukan);
            data_student = -1;
            data_dorm = -1;
            for (int i = 0; i < stdnt; i++) {
                if (strcmp(students[i].id, id) == 0) {
                    data_student = i;
                    break;
                }
            }

            for (int i = 0; i < drm; i++) {
                if (strcmp(dorms[i].name, dorm_name) == 0) {
                    data_dorm = i;
                    break;
                }
            }

            if (data_student != -1 && data_dorm != -1) {
                assign_student_to_dorm(&students[data_student], &dorms[data_dorm]);
            }

        } else if (strcmp(masukan, "move-student") == 0) {
            masukan = strtok(NULL, "#");
            strcpy(id, masukan);
            masukan = strtok(NULL, "#");
            strcpy(dorm_name, masukan);
            data_student = -1;
            data_dorm = -1;
            for (int i = 0; i < stdnt; i++) {
                if (strcmp(students[i].id, id) == 0) {
                    data_student = i;
                    break;
                }
            }

            for (int i = 0; i < drm; i++) {
                if (strcmp(dorms[i].name, dorm_name) == 0) {
                    data_dorm = i;
                    break;
                }
            }

            if (data_student != -1) {
                if (data_dorm != -1) {
                    remove_student_from_dorm(&students[data_student]);
                    assign_student_to_dorm(&students[data_student], &dorms[data_dorm]);
                } else if (strcmp(dorm_name, "left") == 0) {
                    remove_student_from_dorm(&students[data_student]);
                }
            }

        } else if (strcmp(masukan, "dorm-empty") == 0) {
            masukan = strtok(NULL, "#");
            strcpy(dorm_name, masukan);
            data_dorm = -1;
            for (int i = 0; i < drm; i++) {
                if (strcmp(dorms[i].name, dorm_name) == 0) {
                    data_dorm = i;
                    break;
                }
            }

            if (data_dorm != -1) {
                for (int i = 0; i < stdnt; i++) {
                    if (students[i].dorm == &dorms[data_dorm]) {
                        remove_student_from_dorm(&students[i]);
                    }
                }
            }
        } else if (strcmp(masukan, "student-leave") == 0) {
            masukan = strtok(NULL, "#");
            strcpy(id, masukan);
            data_student = -1;
            for (int i = 0; i < stdnt; i++) {
                if (strcmp(students[i].id, id) == 0) {
                    data_student = i;
                    break;
                }
            }
            if (data_student != -1) {
                remove_student_from_dorm(&students[data_student]);
            }
        }
    }

    free(dorms);
    free(students);
    return 0;
}
