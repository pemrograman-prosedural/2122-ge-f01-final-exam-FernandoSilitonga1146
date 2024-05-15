// 12S23002 - Fernando Silitonga
// 12S23017 - Andrey Jonathan

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libs/dorm.h" 
#include "libs/student.h"

int main(int _argc, char **_argv){
struct student_t *students = malloc(200 * sizeof(struct student_t));
char data[200];
char nim[12];
char nama[40];
char tahun[5];
char *mahasiswa; 
int i=0;

struct dorm_t *dorms = malloc(200 * sizeof(struct dorm_t));
    char dname[60];
    unsigned short kapasitas;
    int idx_s, idx_d;
    int stdnt=0, drm=0;
    
do
{   fflush(stdin);                       
    data[0] = '\0';
    int c = 0;                                            
    do{
    char x = getchar();
    if (x == '\r'){
        continue;
        }
    else if (x == '\n'){
        break;
        }
    data[c] = x;
    data[++c] = '\0';
    }while(1);
    if(strcmp(data, "---")==0){
        break;
        } 
    else if (strstr(data, "student-print-all-detail")!=NULL) {
        print_student_detail(students, i);
    }else if (strstr(data,"student-print-all")!=NULL){
        print_student(students, i);
    }else if (strstr(data, "student-add")!=NULL){
        
        mahasiswa = strtok(data, "#");
        mahasiswa = strtok(NULL, "#");
        strcpy(nim, mahasiswa);

        mahasiswa = strtok(NULL, "#");
        strcpy(nama, mahasiswa);

        mahasiswa = strtok(NULL, "#");
        strcpy(tahun, mahasiswa);
                                                                                                          
        mahasiswa = strtok(NULL, "#");
        if (strcmp(mahasiswa, "male")==0){
            students[i] = create_student(nim, nama, tahun, GENDER_MALE);
        } else if (strcmp(mahasiswa, "female")==0){
            students[i] = create_student(nim, nama, tahun, GENDER_FEMALE);
        }
        i++;                          
        }else if (strcmp(mahasiswa, "dorm-print-all-detail")==0) {
            print_dorm_detail(dorms, drm);
        }else if (strstr(mahasiswa,"dorm-print-all")!=NULL){
            print_dorm(dorms, drm);
        }else if (strcmp(mahasiswa, "dorm-add")==0){
            mahasiswa = strtok(NULL, "#");
            strcpy(dname, mahasiswa);
            mahasiswa = strtok(NULL, "#");
            kapasitas = atoi(mahasiswa);
            mahasiswa = strtok(NULL, "#");
            if (strcmp(mahasiswa, "male")==0){
                dorms[drm] = create_dorm(dname, kapasitas, GENDER_MALE);
            } else if (strcmp(mahasiswa, "female")==0){
                dorms[drm] = create_dorm(dname, kapasitas, GENDER_FEMALE);
            }
            drm++;
            
    } else if (strcmp(mahasiswa, "assign-student")==0)
    {
            mahasiswa = strtok(NULL, "#");
            strcpy(nim, mahasiswa);
            mahasiswa = strtok(NULL, "#");
            strcpy(dname, mahasiswa);
            idx_s = -99;
            idx_d = -99;
            for (int i = 0; i < stdnt; i++)
            {
                if(strcmp(students[i].nim, nim)==0)
                {
                    idx_s = i;
                    break;
                }
            }
            for (int i = 0; i < stdnt; i++)
            {
                if(strcmp(dorms[i].nama, dname)==0)
                {
                    idx_d = i;
                    break;
                }
            }
            if (idx_s!=-99 && idx_d!=-99)
            {
                assign_student(&students[idx_s], &dorms[idx_d], nim, dname);
            }
    }else if (strcmp(mahasiswa, "student-leave") == 0)
        {
            mahasiswa = strtok('\0', "#");
            strcpy(nim, mahasiswa);
       
            idx_s =0;
            idx_d = 0;
            int i = 0;
            
        while (i < stdnt){
                if (strcmp(students[i].nim, nim) == 0)
                {
                    idx_s = i;
                    break;
                    
                }
                i++;
        }
            
		
		while (i < drm){
			    if (strcmp(students[idx_s].dorm->nama, dorms[i].nama)==0)
		        {
			        idx_d = i;
			        break;
                    
		         }	
                 i++;
        }
                  
		
        
        student_leave(&students[idx_s], &dorms[idx_d]);
        }    
    } while(1);
    free(students);
    free(dorms);
    return 0;
}