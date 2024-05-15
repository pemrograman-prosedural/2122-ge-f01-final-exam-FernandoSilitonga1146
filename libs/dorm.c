#include "dorm.h"
#include <stdio.h>
#include <string.h>
#include "gender.h"

struct dorm_t create_dorm(char *_nama, unsigned short _kapasitas, enum gender_t _gender)
{                                                                                                                                                                                       
  struct dorm_t dorm_;                                                                                                                                                                                
    strcpy(dorm_.nama, _nama);                                                                                                                                        
    dorm_.kapasitas = _kapasitas;                                                                                                                                                                                                                                                                                                         
    dorm_.gender = _gender;   
    dorm_.residents_num = 0;                                                                                                                                            
                                                                                                                                                                                                                                                           
  return dorm_;                                                                                                                    
}                                                                                                               
void print_dorm(struct dorm_t *_dorm, int count){
          
    char jenis[10];                                                                                               
    strcpy(jenis, "|male\n");                                                                              
    char type[10];                                                                                      
    strcpy(type, "|female\n");                                                                  
                                                                                                 
    for (int i = 0; i < count; i++)                                         
    {
        if(_dorm[i].gender==0){
        printf("%s", _dorm[i].nama);
        printf("%d", _dorm[i].kapasitas);
        printf("%s", jenis);

        } else if(_dorm[i].gender==1){
            printf("%s|", _dorm[i].nama);
            printf("%d",  _dorm[i].kapasitas);
            printf("%s", type);
        }
    }
}
void print_dorm_detail(struct dorm_t *_dorm, int count){
         
    char jenis[10];                                                                                               
    strcpy(jenis, "|male\n");                                                                             
    char type[10];                                                                                      
    strcpy(type, "|female\n");                                                                  
                                                                                                
    for (int i = 0; i < count; i++)                                         
    {
        if(_dorm[i].gender==0){
        printf("%s", _dorm[i].nama);
        printf("%d", _dorm[i].kapasitas);
        printf("%s", jenis);
        printf("%d\n", _dorm[i].residents_num);

        } else if(_dorm[i].gender==1){
            printf("%s|", _dorm[i].nama);
            printf("%d",  _dorm[i].kapasitas);
            printf("%s", type);
            printf("%d\n", _dorm[i].residents_num);
        }
    }
}