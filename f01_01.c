// NIM - Name
// NIM - Name

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libs/dorm.h"
#include "libs/student.h"

int main(int _argc, char **_argv) {
    struct student_t *students = malloc(200 * sizeof(struct student_t));
    struct dorm_t *dorms = malloc(200 * sizeof(struct dorm_t));
    char data[200];
    char nim[12];
    char nama[40];
    char tahun[5];
    char dname[60];
    char *mahasiswa;
    int student_count = 0, dorm_count = 0;
    
    while (1) {
        fflush(stdin);
        data[0] = '\0';
        int c = 0;
        while (1) {
            char x = getchar();
            if (x == '\r') {
                continue;
            } else if (x == '\n') {
                break;
            }
            data[c] = x;
            data[++c] = '\0';
        }

        if (strcmp(data, "---") == 0) {
            break;
        } else if (strstr(data, "student-print-all-detail") != NULL) {
            print_student_detail(students, student_count);
        } else if (strstr(data, "student-print-all") != NULL) {
            print_student(students, student_count);
        } else if (strstr(data, "student-add") != NULL) {
            mahasiswa = strtok(data, "#");
            mahasiswa = strtok(NULL, "#");
            strcpy(nim, mahasiswa);

            mahasiswa = strtok(NULL, "#");
            strcpy(nama, mahasiswa);

            mahasiswa = strtok(NULL, "#");
            strcpy(tahun, mahasiswa);
                                                                                                          
            mahasiswa = strtok(NULL, "#");
            if (strcmp(mahasiswa, "male") == 0) {
                students[student_count] = create_student(nim, nama, tahun, GENDER_MALE);
            } else if (strcmp(mahasiswa, "female") == 0) {
                students[student_count] = create_student(nim, nama, tahun, GENDER_FEMALE);
            }
            student_count++;                          
        } else if (strstr(data, "dorm-print-all-detail") != NULL) {
            print_dorm_detail(dorms, dorm_count);
        } else if (strstr(data, "dorm-print-all") != NULL) {
            print_dorm(dorms, dorm_count);
        } else if (strstr(data, "dorm-add") != NULL) {
            mahasiswa = strtok(data, "#");
            mahasiswa = strtok(NULL, "#");
            strcpy(dname, mahasiswa);
            mahasiswa = strtok(NULL, "#");
            int kapasitas = atoi(mahasiswa);
            mahasiswa = strtok(NULL, "#");
            if (strcmp(mahasiswa, "male") == 0) {
                dorms[dorm_count] = create_dorm(dname, kapasitas, GENDER_MALE);
            } else if (strcmp(mahasiswa, "female") == 0) {
                dorms[dorm_count] = create_dorm(dname, kapasitas, GENDER_FEMALE);
            }
            dorm_count++;
        } else if (strstr(data, "assign-student") != NULL) {
            mahasiswa = strtok(data, "#");
            mahasiswa = strtok(NULL, "#");
            strcpy(nim, mahasiswa);
            mahasiswa = strtok(NULL, "#");
            strcpy(dname, mahasiswa);
            int idx_s = -1, idx_d = -1;
            for (int i = 0; i < student_count; i++) {
                if (strcmp(students[i].nim, nim) == 0) {
                    idx_s = i;
                    break;
                }
            }
            for (int i = 0; i < dorm_count; i++) {
                if (strcmp(dorms[i].nama, dname) == 0) {
                    idx_d = i;
                    break;
                }
            }
            if (idx_s != -1 && idx_d != -1) {
                assign_student(&students[idx_s], &dorms[idx_d]);
            }
        } else if (strstr(data, "student-leave") != NULL) {
            mahasiswa = strtok(data, "#");
            mahasiswa = strtok(NULL, "#");
            strcpy(nim, mahasiswa);
            int idx_s = -1, idx_d = -1;
            for (int i = 0; i < student_count; i++) {
                if (strcmp(students[i].nim, nim) == 0) {
                    idx_s = i;
                    break;
                }
            }
            if (idx_s != -1 && students[idx_s].dorm != NULL) {
                for (int i = 0; i < dorm_count; i++) {
                    if (strcmp(dorms[i].nama, students[idx_s].dorm->nama) == 0) {
                        idx_d = i;
                        break;
                    }
                }
                if (idx_d != -1) {
                    student_leave(&students[idx_s], &dorms[idx_d]);
                }
            }
        }
    }

    free(students);
    free(dorms);
    return 0;
}
