#include <stdio.h>
#include <string.h>

#define STR_SIZE 255
#define LEN 5

int main(void) {
    char* fname = "ababv";
    int len = LEN;
    int count = 10000;
    int tmp = 1;
    int farr[LEN] = {0};
    int name_size = STR_SIZE - 7 - len;
    int i_f = 0;
    char name[STR_SIZE] = {0};
    for(int i = 0; i < len; i++) {
        farr[i] = 1;
    }
    if (len < 4) {
        tmp = 4 - (len - 1);
        farr[len-1] = tmp;
    }
    for(int i = 0; i < count; i++) {
        for(int j = 0; j < len; j++) {
            for(int k = 0; k < farr[j]; k++){
                name[i_f++] = fname[j];
            }
        }
        int sum = 0;
        for(int j = 0; j < LEN; j++){
            sum+=farr[j];
        }
        farr[len-1]++;
        for(int j = len - 1; j > 0; j--) {
            farr[j-1] += (farr[j]) / name_size;
            farr[j] = farr[j] % name_size;
            if(farr[j] == 0) {
                farr[j] = tmp;
                name_size--;
            }

        }
        printf("%d %s\n", strlen(name),name);

        for(int z = 0; z < STR_SIZE; z++){
            name[z] = 0;
        }
        i_f = 0;
    }
    for(int i = 0; i < len; i++) {
        printf("%d", farr[i]);
    }
    return 0;
}