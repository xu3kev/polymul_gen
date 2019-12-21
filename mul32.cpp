
#include<x86intrin.h>
#include<immintrin.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>

#define MUL256(e0,e1,a,b)     {__m256d d;    __m256d f;    __m256d g;    __m256d c;    e0 = (__m256d)_mm256_setzero_si256();    e1 = (__m256d)_mm256_setzero_si256();    __m256i mask;    c = _mm256_permutex_epi64(a, _MM_SHUFFLE(0,0,0,0));    d = _mm256_mul_pd(b,c);    e0 = _mm256_add_pd(e0,d);    c = _mm256_permutex_epi64(a, _MM_SHUFFLE(1,1,1,1));    g = _mm256_permutex_epi64(b, _MM_SHUFFLE(2,1,0,3));    d = _mm256_mul_pd(g,c);    mask =_mm256_setr_epi32(0,0,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF);    e0 = _mm256_add_pd(e0,(__m256d)(((__m256i)d)&mask));    e1 = _mm256_add_pd(e1,(__m256d)(((__m256i)d)&(~mask)));    c = _mm256_permutex_epi64(a, _MM_SHUFFLE(2,2,2,2));    g = _mm256_permutex_epi64(b, _MM_SHUFFLE(1,0,3,2));    d = _mm256_mul_pd(g,c);    mask =_mm256_setr_epi32(0,0,0,0,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF);    e0 = _mm256_add_pd(e0,(__m256d)(((__m256i)d)&mask));    e1 = _mm256_add_pd(e1,(__m256d)(((__m256i)d)&(~mask)));    c = _mm256_permutex_epi64(a, _MM_SHUFFLE(3,3,3,3));    g = _mm256_permutex_epi64(b, _MM_SHUFFLE(0,3,2,1));    d = _mm256_mul_pd(g,c);    mask =_mm256_setr_epi32(0,0,0,0,0,0,0xFFFFFFFF,0xFFFFFFFF);    e0 = _mm256_add_pd(e0,(__m256d)(((__m256i)d)&mask));    e1 = _mm256_add_pd(e1,(__m256d)(((__m256i)d)&(~mask)));    }


 inline uint64_t readTSCp() {
     unsigned dummy;
     return __rdtscp(&dummy);
  }


int main(){


    __attribute__ ((aligned (32))) double a[32];
    __attribute__ ((aligned (32))) double b[32];
    for(int i=0;i<32;++i){
        a[i] = rand()%10;
        printf(" %f", a[i]);
    }
    printf("\n");
    for(int i=0;i<32;++i){
        b[i] = rand()%10;
        printf(" %f", b[i]);
    }
    printf("\n");


__m256d v185,v189,v184,v187,v186,v188,v2,v190,v191,v192,v193,v194,v195,v200,v201,v196,v197,v198,v199,v202,v203,v204,v205,v206,v207,v208,v209,v210,v211,v212,v213,v214,v215,v216,v217,v218,v219,v220,v221,v7,v9,v12,v0,v10,v6,v8,v5,v11,v175,v13,v14,v39,v111,v40,v113,v41,v119,v42,v112,v43,v115,v47,v114,v53,v116,v44,v117,v45,v121,v1,v46,v118,v49,v120,v48,v122,v109,v50,v123,v51,v127,v55,v131,v52,v124,v54,v125,v56,v110,v126,v57,v129,v61,v128,v65,v130,v182,v58,v132,v59,v133,v60,v134,v63,v135,v62,v136,v64,v137,v183,v66,v142,v67,v145,v15,v68,v138,v69,v139,v70,v140,v71,v141,v76,v143,v77,v147,v72,v144,v73,v146,v74,v148,v75,v149,v78,v153,v79,v163,v80,v150,v81,v151,v82,v152,v83,v155,v84,v154,v87,v160,v85,v156,v89,v157,v16,v86,v158,v17,v88,v159,v18,v90,v161,v21,v91,v165,v19,v95,v162,v23,v105,v164,v3,v20,v92,v4,v22,v93,v166,v24,v94,v167,v25,v97,v171,v179,v29,v96,v168,v38,v102,v169,v26,v98,v170,v27,v99,v173,v28,v100,v172,v31,v101,v174,v30,v103,v176,v36,v107,v177,v32,v104,v178,v33,v106,v180,v34,v108,v181,v35,v37;
int64_t ts=readTSCp();
v0 = _mm256_load_pd(a+4*0);
v8 = _mm256_load_pd(b+4*0);
MUL256(v16,v17,v0,v8);
v0 = _mm256_load_pd(a+4*0);
v1 = _mm256_load_pd(a+4*1);
v18 = _mm256_add_pd(v0,v1);
v8 = _mm256_load_pd(b+4*0);
v9 = _mm256_load_pd(b+4*1);
v19 = _mm256_add_pd(v8,v9);
MUL256(v20,v21,v18,v19);
v1 = _mm256_load_pd(a+4*1);
v9 = _mm256_load_pd(b+4*1);
MUL256(v22,v23,v1,v9);
v24 = _mm256_sub_pd(v20,v16);
v25 = _mm256_sub_pd(v21,v17);
v26 = _mm256_sub_pd(v24,v22);
v27 = _mm256_sub_pd(v25,v23);
v28 = _mm256_add_pd(v17,v26);
v29 = _mm256_add_pd(v22,v27);
v0 = _mm256_load_pd(a+4*0);
v1 = _mm256_load_pd(a+4*1);
v2 = _mm256_load_pd(a+4*2);
v3 = _mm256_load_pd(a+4*3);
v30 = _mm256_add_pd(v0,v2);
v31 = _mm256_add_pd(v1,v3);
v8 = _mm256_load_pd(b+4*0);
v9 = _mm256_load_pd(b+4*1);
v10 = _mm256_load_pd(b+4*2);
v11 = _mm256_load_pd(b+4*3);
v32 = _mm256_add_pd(v8,v10);
v33 = _mm256_add_pd(v9,v11);
MUL256(v34,v35,v30,v32);
v36 = _mm256_add_pd(v30,v31);
v37 = _mm256_add_pd(v32,v33);
MUL256(v38,v39,v36,v37);
MUL256(v40,v41,v31,v33);
v42 = _mm256_sub_pd(v38,v34);
v43 = _mm256_sub_pd(v39,v35);
v44 = _mm256_sub_pd(v42,v40);
v45 = _mm256_sub_pd(v43,v41);
v46 = _mm256_add_pd(v35,v44);
v47 = _mm256_add_pd(v40,v45);
v2 = _mm256_load_pd(a+4*2);
v10 = _mm256_load_pd(b+4*2);
MUL256(v48,v49,v2,v10);
v2 = _mm256_load_pd(a+4*2);
v3 = _mm256_load_pd(a+4*3);
v50 = _mm256_add_pd(v2,v3);
v10 = _mm256_load_pd(b+4*2);
v11 = _mm256_load_pd(b+4*3);
v51 = _mm256_add_pd(v10,v11);
MUL256(v52,v53,v50,v51);
v3 = _mm256_load_pd(a+4*3);
v11 = _mm256_load_pd(b+4*3);
MUL256(v54,v55,v3,v11);
v56 = _mm256_sub_pd(v52,v48);
v57 = _mm256_sub_pd(v53,v49);
v58 = _mm256_sub_pd(v56,v54);
v59 = _mm256_sub_pd(v57,v55);
v60 = _mm256_add_pd(v49,v58);
v61 = _mm256_add_pd(v54,v59);
v62 = _mm256_sub_pd(v34,v16);
v63 = _mm256_sub_pd(v46,v28);
v64 = _mm256_sub_pd(v47,v29);
v65 = _mm256_sub_pd(v41,v23);
v66 = _mm256_sub_pd(v62,v48);
v67 = _mm256_sub_pd(v63,v60);
v68 = _mm256_sub_pd(v64,v61);
v69 = _mm256_sub_pd(v65,v55);
v70 = _mm256_add_pd(v29,v66);
v71 = _mm256_add_pd(v23,v67);
v72 = _mm256_add_pd(v48,v68);
v73 = _mm256_add_pd(v60,v69);
v0 = _mm256_load_pd(a+4*0);
v1 = _mm256_load_pd(a+4*1);
v2 = _mm256_load_pd(a+4*2);
v3 = _mm256_load_pd(a+4*3);
v4 = _mm256_load_pd(a+4*4);
v5 = _mm256_load_pd(a+4*5);
v6 = _mm256_load_pd(a+4*6);
v7 = _mm256_load_pd(a+4*7);
v74 = _mm256_add_pd(v0,v4);
v75 = _mm256_add_pd(v1,v5);
v76 = _mm256_add_pd(v2,v6);
v77 = _mm256_add_pd(v3,v7);
v8 = _mm256_load_pd(b+4*0);
v9 = _mm256_load_pd(b+4*1);
v10 = _mm256_load_pd(b+4*2);
v11 = _mm256_load_pd(b+4*3);
v12 = _mm256_load_pd(b+4*4);
v13 = _mm256_load_pd(b+4*5);
v14 = _mm256_load_pd(b+4*6);
v15 = _mm256_load_pd(b+4*7);
v78 = _mm256_add_pd(v8,v12);
v79 = _mm256_add_pd(v9,v13);
v80 = _mm256_add_pd(v10,v14);
v81 = _mm256_add_pd(v11,v15);
MUL256(v82,v83,v74,v78);
v84 = _mm256_add_pd(v74,v75);
v85 = _mm256_add_pd(v78,v79);
MUL256(v86,v87,v84,v85);
MUL256(v88,v89,v75,v79);
v90 = _mm256_sub_pd(v86,v82);
v91 = _mm256_sub_pd(v87,v83);
v92 = _mm256_sub_pd(v90,v88);
v93 = _mm256_sub_pd(v91,v89);
v94 = _mm256_add_pd(v83,v92);
v95 = _mm256_add_pd(v88,v93);
v96 = _mm256_add_pd(v74,v76);
v97 = _mm256_add_pd(v75,v77);
v98 = _mm256_add_pd(v78,v80);
v99 = _mm256_add_pd(v79,v81);
MUL256(v100,v101,v96,v98);
v102 = _mm256_add_pd(v96,v97);
v103 = _mm256_add_pd(v98,v99);
MUL256(v104,v105,v102,v103);
MUL256(v106,v107,v97,v99);
v108 = _mm256_sub_pd(v104,v100);
v109 = _mm256_sub_pd(v105,v101);
v110 = _mm256_sub_pd(v108,v106);
v111 = _mm256_sub_pd(v109,v107);
v112 = _mm256_add_pd(v101,v110);
v113 = _mm256_add_pd(v106,v111);
MUL256(v114,v115,v76,v80);
v116 = _mm256_add_pd(v76,v77);
v117 = _mm256_add_pd(v80,v81);
MUL256(v118,v119,v116,v117);
MUL256(v120,v121,v77,v81);
v122 = _mm256_sub_pd(v118,v114);
v123 = _mm256_sub_pd(v119,v115);
v124 = _mm256_sub_pd(v122,v120);
v125 = _mm256_sub_pd(v123,v121);
v126 = _mm256_add_pd(v115,v124);
v127 = _mm256_add_pd(v120,v125);
v128 = _mm256_sub_pd(v100,v82);
v129 = _mm256_sub_pd(v112,v94);
v130 = _mm256_sub_pd(v113,v95);
v131 = _mm256_sub_pd(v107,v89);
v132 = _mm256_sub_pd(v128,v114);
v133 = _mm256_sub_pd(v129,v126);
v134 = _mm256_sub_pd(v130,v127);
v135 = _mm256_sub_pd(v131,v121);
v136 = _mm256_add_pd(v95,v132);
v137 = _mm256_add_pd(v89,v133);
v138 = _mm256_add_pd(v114,v134);
v139 = _mm256_add_pd(v126,v135);
v4 = _mm256_load_pd(a+4*4);
v12 = _mm256_load_pd(b+4*4);
MUL256(v140,v141,v4,v12);
v4 = _mm256_load_pd(a+4*4);
v5 = _mm256_load_pd(a+4*5);
v142 = _mm256_add_pd(v4,v5);
v12 = _mm256_load_pd(b+4*4);
v13 = _mm256_load_pd(b+4*5);
v143 = _mm256_add_pd(v12,v13);
MUL256(v144,v145,v142,v143);
v5 = _mm256_load_pd(a+4*5);
v13 = _mm256_load_pd(b+4*5);
MUL256(v146,v147,v5,v13);
v148 = _mm256_sub_pd(v144,v140);
v149 = _mm256_sub_pd(v145,v141);
v150 = _mm256_sub_pd(v148,v146);
v151 = _mm256_sub_pd(v149,v147);
v152 = _mm256_add_pd(v141,v150);
v153 = _mm256_add_pd(v146,v151);
v4 = _mm256_load_pd(a+4*4);
v5 = _mm256_load_pd(a+4*5);
v6 = _mm256_load_pd(a+4*6);
v7 = _mm256_load_pd(a+4*7);
v154 = _mm256_add_pd(v4,v6);
v155 = _mm256_add_pd(v5,v7);
v12 = _mm256_load_pd(b+4*4);
v13 = _mm256_load_pd(b+4*5);
v14 = _mm256_load_pd(b+4*6);
v15 = _mm256_load_pd(b+4*7);
v156 = _mm256_add_pd(v12,v14);
v157 = _mm256_add_pd(v13,v15);
MUL256(v158,v159,v154,v156);
v160 = _mm256_add_pd(v154,v155);
v161 = _mm256_add_pd(v156,v157);
MUL256(v162,v163,v160,v161);
MUL256(v164,v165,v155,v157);
v166 = _mm256_sub_pd(v162,v158);
v167 = _mm256_sub_pd(v163,v159);
v168 = _mm256_sub_pd(v166,v164);
v169 = _mm256_sub_pd(v167,v165);
v170 = _mm256_add_pd(v159,v168);
v171 = _mm256_add_pd(v164,v169);
v6 = _mm256_load_pd(a+4*6);
v14 = _mm256_load_pd(b+4*6);
MUL256(v172,v173,v6,v14);
v6 = _mm256_load_pd(a+4*6);
v7 = _mm256_load_pd(a+4*7);
v174 = _mm256_add_pd(v6,v7);
v14 = _mm256_load_pd(b+4*6);
v15 = _mm256_load_pd(b+4*7);
v175 = _mm256_add_pd(v14,v15);
MUL256(v176,v177,v174,v175);
v7 = _mm256_load_pd(a+4*7);
v15 = _mm256_load_pd(b+4*7);
MUL256(v178,v179,v7,v15);
v180 = _mm256_sub_pd(v176,v172);
v181 = _mm256_sub_pd(v177,v173);
v182 = _mm256_sub_pd(v180,v178);
v183 = _mm256_sub_pd(v181,v179);
v184 = _mm256_add_pd(v173,v182);
v185 = _mm256_add_pd(v178,v183);
v186 = _mm256_sub_pd(v158,v140);
v187 = _mm256_sub_pd(v170,v152);
v188 = _mm256_sub_pd(v171,v153);
v189 = _mm256_sub_pd(v165,v147);
v190 = _mm256_sub_pd(v186,v172);
v191 = _mm256_sub_pd(v187,v184);
v192 = _mm256_sub_pd(v188,v185);
v193 = _mm256_sub_pd(v189,v179);
v194 = _mm256_add_pd(v153,v190);
v195 = _mm256_add_pd(v147,v191);
v196 = _mm256_add_pd(v172,v192);
v197 = _mm256_add_pd(v184,v193);
v198 = _mm256_sub_pd(v82,v16);
v199 = _mm256_sub_pd(v94,v28);
v200 = _mm256_sub_pd(v136,v70);
v201 = _mm256_sub_pd(v137,v71);
v202 = _mm256_sub_pd(v138,v72);
v203 = _mm256_sub_pd(v139,v73);
v204 = _mm256_sub_pd(v127,v61);
v205 = _mm256_sub_pd(v121,v55);
v206 = _mm256_sub_pd(v198,v140);
v207 = _mm256_sub_pd(v199,v152);
v208 = _mm256_sub_pd(v200,v194);
v209 = _mm256_sub_pd(v201,v195);
v210 = _mm256_sub_pd(v202,v196);
v211 = _mm256_sub_pd(v203,v197);
v212 = _mm256_sub_pd(v204,v185);
v213 = _mm256_sub_pd(v205,v179);
v214 = _mm256_add_pd(v72,v206);
v215 = _mm256_add_pd(v73,v207);
v216 = _mm256_add_pd(v61,v208);
v217 = _mm256_add_pd(v55,v209);
v218 = _mm256_add_pd(v140,v210);
v219 = _mm256_add_pd(v152,v211);
v220 = _mm256_add_pd(v194,v212);
v221 = _mm256_add_pd(v195,v213);

int64_t te=readTSCp();
printf("cycle = %d\n",int(te-ts));
__attribute__ ((aligned (32))) double output[64];
_mm256_store_pd(output+0, v16);
_mm256_store_pd(output+4, v28);
_mm256_store_pd(output+8, v70);
_mm256_store_pd(output+12, v71);
_mm256_store_pd(output+16, v214);
_mm256_store_pd(output+20, v215);
_mm256_store_pd(output+24, v216);
_mm256_store_pd(output+28, v217);
_mm256_store_pd(output+32, v218);
_mm256_store_pd(output+36, v219);
_mm256_store_pd(output+40, v220);
_mm256_store_pd(output+44, v221);
_mm256_store_pd(output+48, v196);
_mm256_store_pd(output+52, v197);
_mm256_store_pd(output+56, v185);
_mm256_store_pd(output+60, v179);
for(int i=0;i<64;++i) 
    printf(" %f",output[i]);
    printf("\n");
    
}