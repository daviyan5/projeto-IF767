#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "alg_utils_sg.hpp"
#include "pre_processing.hpp"
#include "aho_corasick.hpp"



alg_print_ret_mul aho_corasick(char *text, int *patt_size, int num_patt, int text_size, bool ignore_case,
                               int **go_to,int *fail, int *qnt_occ, int **occ){
    alg_print_ret_mul ret;
    ret.num_occ = (int*) calloc(num_patt ,sizeof(int));
    ret.occ = (int**) malloc(num_patt * sizeof(int*));

    int n = text_size;
    int node = 0, i = 0;

    while(i < n){
        int ch = text[i];
        while(go_to[node][ch] < 0){
            node = fail[node];
        }
        node = go_to[node][ch];
        ret.occ = (int**)realloc(ret.occ, qnt_occ[node]*sizeof(int*));
        for(int j = 0; j < qnt_occ[node]; j++){
            int k = occ[node][j];
            ret.num_occ[k]++;
            ret.occ[k] = (int*)realloc(ret.occ[k], ret.num_occ[k] * sizeof(int));
            ret.occ[k][ret.num_occ[k] - 1] = i - patt_size[k] + 1;
        }
        i++;
    }
    
    return ret;
}

