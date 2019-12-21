
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


    __attribute__ ((aligned (32))) double a[64];
    __attribute__ ((aligned (32))) double b[64];
    for(int i=0;i<64;++i){
        a[i] = rand()%10;
        printf(" %f", a[i]);
    }
    printf("\n");
    for(int i=0;i<64;++i){
        b[i] = rand()%10;
        printf(" %f", b[i]);
    }
    printf("\n");


__m256d v255,v546,v256,v549,v259,v544,v257,v545,v261,v547,v258,v551,v260,v548,v262,v550,v263,v552,v267,v553,v277,v557,v264,v563,v265,v554,v266,v555,v269,v556,v268,v559,v274,v558,v270,v560,v271,v561,v272,v565,v273,v562,v275,v564,v279,v566,v276,v567,v278,v571,v280,v575,v281,v568,v285,v569,v291,v570,v282,v573,v283,v572,v284,v574,v287,v576,v286,v577,v288,v578,v289,v579,v293,v580,v290,v581,v292,v586,v294,v589,v295,v582,v299,v583,v303,v584,v296,v585,v297,v587,v298,v591,v301,v588,v300,v590,v302,v592,v304,v593,v305,v597,v306,v607,v307,v594,v308,v595,v309,v596,v3,v314,v599,v4,v315,v598,v310,v604,v311,v600,v312,v601,v313,v602,v316,v603,v317,v605,v318,v609,v319,v606,v320,v608,v321,v610,v322,v611,v325,v614,v323,v615,v326,v612,v324,v613,v39,v40,v41,v45,v55,v42,v2,v43,v44,v47,v46,v52,v48,v49,v50,v51,v53,v57,v54,v56,v58,v59,v63,v69,v60,v61,v62,v65,v64,v66,v67,v71,v68,v70,v72,v73,v77,v81,v74,v75,v76,v79,v78,v80,v82,v83,v84,v85,v86,v87,v92,v93,v88,v89,v90,v91,v94,v95,v96,v97,v98,v99,v100,v103,v101,v105,v102,v104,v106,v107,v109,v110,v108,v401,v399,v403,v400,v402,v404,v405,v409,v415,v1,v406,v407,v408,v411,v410,v412,v413,v417,v414,v416,v418,v419,v423,v425,v420,v421,v422,v427,v426,v428,v15,v429,v430,v431,v432,v433,v438,v439,v434,v435,v436,v437,v440,v441,v442,v443,v444,v445,v446,v447,v16,v448,v17,v449,v18,v450,v19,v451,v20,v452,v21,v453,v22,v454,v23,v455,v24,v456,v25,v457,v26,v458,v27,v459,v28,v460,v29,v461,v30,v462,v31,v465,v463,v32,v467,v33,v464,v34,v466,v37,v468,v35,v469,v38,v470,v36,v471,v7,v9,v12,v0,v10,v6,v8,v5,v11,v424,v13,v14,v327,v473,v621,v328,v483,v616,v329,v472,v617,v333,v475,v618,v343,v474,v619,v330,v480,v623,v331,v476,v620,v332,v477,v622,v335,v478,v624,v334,v479,v625,v340,v481,v629,v336,v485,v633,v337,v482,v626,v338,v484,v627,v339,v486,v628,v341,v487,v631,v345,v491,v630,v342,v497,v632,v344,v488,v634,v346,v489,v635,v347,v490,v636,v351,v493,v637,v357,v492,v638,v348,v494,v639,v349,v495,v644,v350,v499,v645,v353,v496,v640,v352,v498,v641,v354,v500,v642,v355,v501,v643,v359,v505,v646,v356,v509,v647,v358,v502,v648,v360,v503,v649,v361,v504,v650,v365,v507,v651,v369,v506,v652,v362,v508,v653,v363,v510,v654,v364,v511,v655,v367,v512,v656,v366,v513,v657,v368,v514,v658,v370,v515,v659,v371,v520,v660,v372,v521,v661,v373,v516,v662,v374,v517,v663,v375,v518,v664,v380,v519,v665,v383,v522,v666,v376,v523,v667,v377,v524,v668,v378,v525,v669,v379,v526,v670,v381,v527,v671,v385,v528,v672,v382,v531,v673,v384,v529,v674,v386,v533,v675,v387,v530,v676,v391,v532,v677,v398,v534,v678,v388,v535,v679,v389,v539,v680,v390,v543,v681,v393,v536,v682,v392,v537,v683,v397,v538,v684,v394,v541,v685,v395,v540,v686,v396,v542,v687,v113,v111,v121,v112,v118,v114,v115,v116,v117,v119,v123,v120,v122,v124,v125,v129,v135,v126,v127,v128,v131,v130,v132,v133,v137,v134,v136,v138,v139,v143,v147,v140,v141,v142,v145,v144,v146,v148,v149,v150,v151,v152,v153,v158,v161,v154,v155,v156,v157,v159,v163,v160,v162,v164,v165,v169,v179,v166,v167,v168,v171,v170,v176,v172,v173,v174,v175,v177,v181,v178,v180,v182,v183,v688,v187,v689,v193,v690,v184,v691,v185,v692,v186,v693,v189,v694,v188,v695,v190,v696,v191,v697,v195,v698,v192,v699,v194,v700,v196,v701,v197,v702,v201,v703,v205,v704,v198,v705,v199,v706,v200,v707,v203,v708,v202,v709,v204,v710,v206,v711,v207,v712,v208,v713,v209,v210,v211,v216,v217,v212,v213,v214,v215,v218,v219,v220,v221,v222,v223,v224,v225,v226,v227,v228,v229,v230,v231,v232,v233,v234,v235,v236,v237,v238,v239,v240,v241,v242,v243,v244,v245,v246,v247,v248,v249,v250,v251,v252,v253,v254;
int64_t ts=readTSCp();
v0 = _mm256_load_pd(a+4*0);
v16 = _mm256_load_pd(b+4*0);
MUL256(v32,v33,v0,v16);
v0 = _mm256_load_pd(a+4*0);
v1 = _mm256_load_pd(a+4*1);
v34 = _mm256_add_pd(v0,v1);
v16 = _mm256_load_pd(b+4*0);
v17 = _mm256_load_pd(b+4*1);
v35 = _mm256_add_pd(v16,v17);
MUL256(v36,v37,v34,v35);
v1 = _mm256_load_pd(a+4*1);
v17 = _mm256_load_pd(b+4*1);
MUL256(v38,v39,v1,v17);
v40 = _mm256_sub_pd(v36,v32);
v41 = _mm256_sub_pd(v37,v33);
v42 = _mm256_sub_pd(v40,v38);
v43 = _mm256_sub_pd(v41,v39);
v44 = _mm256_add_pd(v33,v42);
v45 = _mm256_add_pd(v38,v43);
v0 = _mm256_load_pd(a+4*0);
v1 = _mm256_load_pd(a+4*1);
v2 = _mm256_load_pd(a+4*2);
v3 = _mm256_load_pd(a+4*3);
v46 = _mm256_add_pd(v0,v2);
v47 = _mm256_add_pd(v1,v3);
v16 = _mm256_load_pd(b+4*0);
v17 = _mm256_load_pd(b+4*1);
v18 = _mm256_load_pd(b+4*2);
v19 = _mm256_load_pd(b+4*3);
v48 = _mm256_add_pd(v16,v18);
v49 = _mm256_add_pd(v17,v19);
MUL256(v50,v51,v46,v48);
v52 = _mm256_add_pd(v46,v47);
v53 = _mm256_add_pd(v48,v49);
MUL256(v54,v55,v52,v53);
MUL256(v56,v57,v47,v49);
v58 = _mm256_sub_pd(v54,v50);
v59 = _mm256_sub_pd(v55,v51);
v60 = _mm256_sub_pd(v58,v56);
v61 = _mm256_sub_pd(v59,v57);
v62 = _mm256_add_pd(v51,v60);
v63 = _mm256_add_pd(v56,v61);
v2 = _mm256_load_pd(a+4*2);
v18 = _mm256_load_pd(b+4*2);
MUL256(v64,v65,v2,v18);
v2 = _mm256_load_pd(a+4*2);
v3 = _mm256_load_pd(a+4*3);
v66 = _mm256_add_pd(v2,v3);
v18 = _mm256_load_pd(b+4*2);
v19 = _mm256_load_pd(b+4*3);
v67 = _mm256_add_pd(v18,v19);
MUL256(v68,v69,v66,v67);
v3 = _mm256_load_pd(a+4*3);
v19 = _mm256_load_pd(b+4*3);
MUL256(v70,v71,v3,v19);
v72 = _mm256_sub_pd(v68,v64);
v73 = _mm256_sub_pd(v69,v65);
v74 = _mm256_sub_pd(v72,v70);
v75 = _mm256_sub_pd(v73,v71);
v76 = _mm256_add_pd(v65,v74);
v77 = _mm256_add_pd(v70,v75);
v78 = _mm256_sub_pd(v50,v32);
v79 = _mm256_sub_pd(v62,v44);
v80 = _mm256_sub_pd(v63,v45);
v81 = _mm256_sub_pd(v57,v39);
v82 = _mm256_sub_pd(v78,v64);
v83 = _mm256_sub_pd(v79,v76);
v84 = _mm256_sub_pd(v80,v77);
v85 = _mm256_sub_pd(v81,v71);
v86 = _mm256_add_pd(v45,v82);
v87 = _mm256_add_pd(v39,v83);
v88 = _mm256_add_pd(v64,v84);
v89 = _mm256_add_pd(v76,v85);
v0 = _mm256_load_pd(a+4*0);
v1 = _mm256_load_pd(a+4*1);
v2 = _mm256_load_pd(a+4*2);
v3 = _mm256_load_pd(a+4*3);
v4 = _mm256_load_pd(a+4*4);
v5 = _mm256_load_pd(a+4*5);
v6 = _mm256_load_pd(a+4*6);
v7 = _mm256_load_pd(a+4*7);
v90 = _mm256_add_pd(v0,v4);
v91 = _mm256_add_pd(v1,v5);
v92 = _mm256_add_pd(v2,v6);
v93 = _mm256_add_pd(v3,v7);
v16 = _mm256_load_pd(b+4*0);
v17 = _mm256_load_pd(b+4*1);
v18 = _mm256_load_pd(b+4*2);
v19 = _mm256_load_pd(b+4*3);
v20 = _mm256_load_pd(b+4*4);
v21 = _mm256_load_pd(b+4*5);
v22 = _mm256_load_pd(b+4*6);
v23 = _mm256_load_pd(b+4*7);
v94 = _mm256_add_pd(v16,v20);
v95 = _mm256_add_pd(v17,v21);
v96 = _mm256_add_pd(v18,v22);
v97 = _mm256_add_pd(v19,v23);
MUL256(v98,v99,v90,v94);
v100 = _mm256_add_pd(v90,v91);
v101 = _mm256_add_pd(v94,v95);
MUL256(v102,v103,v100,v101);
MUL256(v104,v105,v91,v95);
v106 = _mm256_sub_pd(v102,v98);
v107 = _mm256_sub_pd(v103,v99);
v108 = _mm256_sub_pd(v106,v104);
v109 = _mm256_sub_pd(v107,v105);
v110 = _mm256_add_pd(v99,v108);
v111 = _mm256_add_pd(v104,v109);
v112 = _mm256_add_pd(v90,v92);
v113 = _mm256_add_pd(v91,v93);
v114 = _mm256_add_pd(v94,v96);
v115 = _mm256_add_pd(v95,v97);
MUL256(v116,v117,v112,v114);
v118 = _mm256_add_pd(v112,v113);
v119 = _mm256_add_pd(v114,v115);
MUL256(v120,v121,v118,v119);
MUL256(v122,v123,v113,v115);
v124 = _mm256_sub_pd(v120,v116);
v125 = _mm256_sub_pd(v121,v117);
v126 = _mm256_sub_pd(v124,v122);
v127 = _mm256_sub_pd(v125,v123);
v128 = _mm256_add_pd(v117,v126);
v129 = _mm256_add_pd(v122,v127);
MUL256(v130,v131,v92,v96);
v132 = _mm256_add_pd(v92,v93);
v133 = _mm256_add_pd(v96,v97);
MUL256(v134,v135,v132,v133);
MUL256(v136,v137,v93,v97);
v138 = _mm256_sub_pd(v134,v130);
v139 = _mm256_sub_pd(v135,v131);
v140 = _mm256_sub_pd(v138,v136);
v141 = _mm256_sub_pd(v139,v137);
v142 = _mm256_add_pd(v131,v140);
v143 = _mm256_add_pd(v136,v141);
v144 = _mm256_sub_pd(v116,v98);
v145 = _mm256_sub_pd(v128,v110);
v146 = _mm256_sub_pd(v129,v111);
v147 = _mm256_sub_pd(v123,v105);
v148 = _mm256_sub_pd(v144,v130);
v149 = _mm256_sub_pd(v145,v142);
v150 = _mm256_sub_pd(v146,v143);
v151 = _mm256_sub_pd(v147,v137);
v152 = _mm256_add_pd(v111,v148);
v153 = _mm256_add_pd(v105,v149);
v154 = _mm256_add_pd(v130,v150);
v155 = _mm256_add_pd(v142,v151);
v4 = _mm256_load_pd(a+4*4);
v20 = _mm256_load_pd(b+4*4);
MUL256(v156,v157,v4,v20);
v4 = _mm256_load_pd(a+4*4);
v5 = _mm256_load_pd(a+4*5);
v158 = _mm256_add_pd(v4,v5);
v20 = _mm256_load_pd(b+4*4);
v21 = _mm256_load_pd(b+4*5);
v159 = _mm256_add_pd(v20,v21);
MUL256(v160,v161,v158,v159);
v5 = _mm256_load_pd(a+4*5);
v21 = _mm256_load_pd(b+4*5);
MUL256(v162,v163,v5,v21);
v164 = _mm256_sub_pd(v160,v156);
v165 = _mm256_sub_pd(v161,v157);
v166 = _mm256_sub_pd(v164,v162);
v167 = _mm256_sub_pd(v165,v163);
v168 = _mm256_add_pd(v157,v166);
v169 = _mm256_add_pd(v162,v167);
v4 = _mm256_load_pd(a+4*4);
v5 = _mm256_load_pd(a+4*5);
v6 = _mm256_load_pd(a+4*6);
v7 = _mm256_load_pd(a+4*7);
v170 = _mm256_add_pd(v4,v6);
v171 = _mm256_add_pd(v5,v7);
v20 = _mm256_load_pd(b+4*4);
v21 = _mm256_load_pd(b+4*5);
v22 = _mm256_load_pd(b+4*6);
v23 = _mm256_load_pd(b+4*7);
v172 = _mm256_add_pd(v20,v22);
v173 = _mm256_add_pd(v21,v23);
MUL256(v174,v175,v170,v172);
v176 = _mm256_add_pd(v170,v171);
v177 = _mm256_add_pd(v172,v173);
MUL256(v178,v179,v176,v177);
MUL256(v180,v181,v171,v173);
v182 = _mm256_sub_pd(v178,v174);
v183 = _mm256_sub_pd(v179,v175);
v184 = _mm256_sub_pd(v182,v180);
v185 = _mm256_sub_pd(v183,v181);
v186 = _mm256_add_pd(v175,v184);
v187 = _mm256_add_pd(v180,v185);
v6 = _mm256_load_pd(a+4*6);
v22 = _mm256_load_pd(b+4*6);
MUL256(v188,v189,v6,v22);
v6 = _mm256_load_pd(a+4*6);
v7 = _mm256_load_pd(a+4*7);
v190 = _mm256_add_pd(v6,v7);
v22 = _mm256_load_pd(b+4*6);
v23 = _mm256_load_pd(b+4*7);
v191 = _mm256_add_pd(v22,v23);
MUL256(v192,v193,v190,v191);
v7 = _mm256_load_pd(a+4*7);
v23 = _mm256_load_pd(b+4*7);
MUL256(v194,v195,v7,v23);
v196 = _mm256_sub_pd(v192,v188);
v197 = _mm256_sub_pd(v193,v189);
v198 = _mm256_sub_pd(v196,v194);
v199 = _mm256_sub_pd(v197,v195);
v200 = _mm256_add_pd(v189,v198);
v201 = _mm256_add_pd(v194,v199);
v202 = _mm256_sub_pd(v174,v156);
v203 = _mm256_sub_pd(v186,v168);
v204 = _mm256_sub_pd(v187,v169);
v205 = _mm256_sub_pd(v181,v163);
v206 = _mm256_sub_pd(v202,v188);
v207 = _mm256_sub_pd(v203,v200);
v208 = _mm256_sub_pd(v204,v201);
v209 = _mm256_sub_pd(v205,v195);
v210 = _mm256_add_pd(v169,v206);
v211 = _mm256_add_pd(v163,v207);
v212 = _mm256_add_pd(v188,v208);
v213 = _mm256_add_pd(v200,v209);
v214 = _mm256_sub_pd(v98,v32);
v215 = _mm256_sub_pd(v110,v44);
v216 = _mm256_sub_pd(v152,v86);
v217 = _mm256_sub_pd(v153,v87);
v218 = _mm256_sub_pd(v154,v88);
v219 = _mm256_sub_pd(v155,v89);
v220 = _mm256_sub_pd(v143,v77);
v221 = _mm256_sub_pd(v137,v71);
v222 = _mm256_sub_pd(v214,v156);
v223 = _mm256_sub_pd(v215,v168);
v224 = _mm256_sub_pd(v216,v210);
v225 = _mm256_sub_pd(v217,v211);
v226 = _mm256_sub_pd(v218,v212);
v227 = _mm256_sub_pd(v219,v213);
v228 = _mm256_sub_pd(v220,v201);
v229 = _mm256_sub_pd(v221,v195);
v230 = _mm256_add_pd(v88,v222);
v231 = _mm256_add_pd(v89,v223);
v232 = _mm256_add_pd(v77,v224);
v233 = _mm256_add_pd(v71,v225);
v234 = _mm256_add_pd(v156,v226);
v235 = _mm256_add_pd(v168,v227);
v236 = _mm256_add_pd(v210,v228);
v237 = _mm256_add_pd(v211,v229);
v0 = _mm256_load_pd(a+4*0);
v1 = _mm256_load_pd(a+4*1);
v2 = _mm256_load_pd(a+4*2);
v3 = _mm256_load_pd(a+4*3);
v4 = _mm256_load_pd(a+4*4);
v5 = _mm256_load_pd(a+4*5);
v6 = _mm256_load_pd(a+4*6);
v7 = _mm256_load_pd(a+4*7);
v8 = _mm256_load_pd(a+4*8);
v9 = _mm256_load_pd(a+4*9);
v10 = _mm256_load_pd(a+4*10);
v11 = _mm256_load_pd(a+4*11);
v12 = _mm256_load_pd(a+4*12);
v13 = _mm256_load_pd(a+4*13);
v14 = _mm256_load_pd(a+4*14);
v15 = _mm256_load_pd(a+4*15);
v238 = _mm256_add_pd(v0,v8);
v239 = _mm256_add_pd(v1,v9);
v240 = _mm256_add_pd(v2,v10);
v241 = _mm256_add_pd(v3,v11);
v242 = _mm256_add_pd(v4,v12);
v243 = _mm256_add_pd(v5,v13);
v244 = _mm256_add_pd(v6,v14);
v245 = _mm256_add_pd(v7,v15);
v16 = _mm256_load_pd(b+4*0);
v17 = _mm256_load_pd(b+4*1);
v18 = _mm256_load_pd(b+4*2);
v19 = _mm256_load_pd(b+4*3);
v20 = _mm256_load_pd(b+4*4);
v21 = _mm256_load_pd(b+4*5);
v22 = _mm256_load_pd(b+4*6);
v23 = _mm256_load_pd(b+4*7);
v24 = _mm256_load_pd(b+4*8);
v25 = _mm256_load_pd(b+4*9);
v26 = _mm256_load_pd(b+4*10);
v27 = _mm256_load_pd(b+4*11);
v28 = _mm256_load_pd(b+4*12);
v29 = _mm256_load_pd(b+4*13);
v30 = _mm256_load_pd(b+4*14);
v31 = _mm256_load_pd(b+4*15);
v246 = _mm256_add_pd(v16,v24);
v247 = _mm256_add_pd(v17,v25);
v248 = _mm256_add_pd(v18,v26);
v249 = _mm256_add_pd(v19,v27);
v250 = _mm256_add_pd(v20,v28);
v251 = _mm256_add_pd(v21,v29);
v252 = _mm256_add_pd(v22,v30);
v253 = _mm256_add_pd(v23,v31);
MUL256(v254,v255,v238,v246);
v256 = _mm256_add_pd(v238,v239);
v257 = _mm256_add_pd(v246,v247);
MUL256(v258,v259,v256,v257);
MUL256(v260,v261,v239,v247);
v262 = _mm256_sub_pd(v258,v254);
v263 = _mm256_sub_pd(v259,v255);
v264 = _mm256_sub_pd(v262,v260);
v265 = _mm256_sub_pd(v263,v261);
v266 = _mm256_add_pd(v255,v264);
v267 = _mm256_add_pd(v260,v265);
v268 = _mm256_add_pd(v238,v240);
v269 = _mm256_add_pd(v239,v241);
v270 = _mm256_add_pd(v246,v248);
v271 = _mm256_add_pd(v247,v249);
MUL256(v272,v273,v268,v270);
v274 = _mm256_add_pd(v268,v269);
v275 = _mm256_add_pd(v270,v271);
MUL256(v276,v277,v274,v275);
MUL256(v278,v279,v269,v271);
v280 = _mm256_sub_pd(v276,v272);
v281 = _mm256_sub_pd(v277,v273);
v282 = _mm256_sub_pd(v280,v278);
v283 = _mm256_sub_pd(v281,v279);
v284 = _mm256_add_pd(v273,v282);
v285 = _mm256_add_pd(v278,v283);
MUL256(v286,v287,v240,v248);
v288 = _mm256_add_pd(v240,v241);
v289 = _mm256_add_pd(v248,v249);
MUL256(v290,v291,v288,v289);
MUL256(v292,v293,v241,v249);
v294 = _mm256_sub_pd(v290,v286);
v295 = _mm256_sub_pd(v291,v287);
v296 = _mm256_sub_pd(v294,v292);
v297 = _mm256_sub_pd(v295,v293);
v298 = _mm256_add_pd(v287,v296);
v299 = _mm256_add_pd(v292,v297);
v300 = _mm256_sub_pd(v272,v254);
v301 = _mm256_sub_pd(v284,v266);
v302 = _mm256_sub_pd(v285,v267);
v303 = _mm256_sub_pd(v279,v261);
v304 = _mm256_sub_pd(v300,v286);
v305 = _mm256_sub_pd(v301,v298);
v306 = _mm256_sub_pd(v302,v299);
v307 = _mm256_sub_pd(v303,v293);
v308 = _mm256_add_pd(v267,v304);
v309 = _mm256_add_pd(v261,v305);
v310 = _mm256_add_pd(v286,v306);
v311 = _mm256_add_pd(v298,v307);
v312 = _mm256_add_pd(v238,v242);
v313 = _mm256_add_pd(v239,v243);
v314 = _mm256_add_pd(v240,v244);
v315 = _mm256_add_pd(v241,v245);
v316 = _mm256_add_pd(v246,v250);
v317 = _mm256_add_pd(v247,v251);
v318 = _mm256_add_pd(v248,v252);
v319 = _mm256_add_pd(v249,v253);
MUL256(v320,v321,v312,v316);
v322 = _mm256_add_pd(v312,v313);
v323 = _mm256_add_pd(v316,v317);
MUL256(v324,v325,v322,v323);
MUL256(v326,v327,v313,v317);
v328 = _mm256_sub_pd(v324,v320);
v329 = _mm256_sub_pd(v325,v321);
v330 = _mm256_sub_pd(v328,v326);
v331 = _mm256_sub_pd(v329,v327);
v332 = _mm256_add_pd(v321,v330);
v333 = _mm256_add_pd(v326,v331);
v334 = _mm256_add_pd(v312,v314);
v335 = _mm256_add_pd(v313,v315);
v336 = _mm256_add_pd(v316,v318);
v337 = _mm256_add_pd(v317,v319);
MUL256(v338,v339,v334,v336);
v340 = _mm256_add_pd(v334,v335);
v341 = _mm256_add_pd(v336,v337);
MUL256(v342,v343,v340,v341);
MUL256(v344,v345,v335,v337);
v346 = _mm256_sub_pd(v342,v338);
v347 = _mm256_sub_pd(v343,v339);
v348 = _mm256_sub_pd(v346,v344);
v349 = _mm256_sub_pd(v347,v345);
v350 = _mm256_add_pd(v339,v348);
v351 = _mm256_add_pd(v344,v349);
MUL256(v352,v353,v314,v318);
v354 = _mm256_add_pd(v314,v315);
v355 = _mm256_add_pd(v318,v319);
MUL256(v356,v357,v354,v355);
MUL256(v358,v359,v315,v319);
v360 = _mm256_sub_pd(v356,v352);
v361 = _mm256_sub_pd(v357,v353);
v362 = _mm256_sub_pd(v360,v358);
v363 = _mm256_sub_pd(v361,v359);
v364 = _mm256_add_pd(v353,v362);
v365 = _mm256_add_pd(v358,v363);
v366 = _mm256_sub_pd(v338,v320);
v367 = _mm256_sub_pd(v350,v332);
v368 = _mm256_sub_pd(v351,v333);
v369 = _mm256_sub_pd(v345,v327);
v370 = _mm256_sub_pd(v366,v352);
v371 = _mm256_sub_pd(v367,v364);
v372 = _mm256_sub_pd(v368,v365);
v373 = _mm256_sub_pd(v369,v359);
v374 = _mm256_add_pd(v333,v370);
v375 = _mm256_add_pd(v327,v371);
v376 = _mm256_add_pd(v352,v372);
v377 = _mm256_add_pd(v364,v373);
MUL256(v378,v379,v242,v250);
v380 = _mm256_add_pd(v242,v243);
v381 = _mm256_add_pd(v250,v251);
MUL256(v382,v383,v380,v381);
MUL256(v384,v385,v243,v251);
v386 = _mm256_sub_pd(v382,v378);
v387 = _mm256_sub_pd(v383,v379);
v388 = _mm256_sub_pd(v386,v384);
v389 = _mm256_sub_pd(v387,v385);
v390 = _mm256_add_pd(v379,v388);
v391 = _mm256_add_pd(v384,v389);
v392 = _mm256_add_pd(v242,v244);
v393 = _mm256_add_pd(v243,v245);
v394 = _mm256_add_pd(v250,v252);
v395 = _mm256_add_pd(v251,v253);
MUL256(v396,v397,v392,v394);
v398 = _mm256_add_pd(v392,v393);
v399 = _mm256_add_pd(v394,v395);
MUL256(v400,v401,v398,v399);
MUL256(v402,v403,v393,v395);
v404 = _mm256_sub_pd(v400,v396);
v405 = _mm256_sub_pd(v401,v397);
v406 = _mm256_sub_pd(v404,v402);
v407 = _mm256_sub_pd(v405,v403);
v408 = _mm256_add_pd(v397,v406);
v409 = _mm256_add_pd(v402,v407);
MUL256(v410,v411,v244,v252);
v412 = _mm256_add_pd(v244,v245);
v413 = _mm256_add_pd(v252,v253);
MUL256(v414,v415,v412,v413);
MUL256(v416,v417,v245,v253);
v418 = _mm256_sub_pd(v414,v410);
v419 = _mm256_sub_pd(v415,v411);
v420 = _mm256_sub_pd(v418,v416);
v421 = _mm256_sub_pd(v419,v417);
v422 = _mm256_add_pd(v411,v420);
v423 = _mm256_add_pd(v416,v421);
v424 = _mm256_sub_pd(v396,v378);
v425 = _mm256_sub_pd(v408,v390);
v426 = _mm256_sub_pd(v409,v391);
v427 = _mm256_sub_pd(v403,v385);
v428 = _mm256_sub_pd(v424,v410);
v429 = _mm256_sub_pd(v425,v422);
v430 = _mm256_sub_pd(v426,v423);
v431 = _mm256_sub_pd(v427,v417);
v432 = _mm256_add_pd(v391,v428);
v433 = _mm256_add_pd(v385,v429);
v434 = _mm256_add_pd(v410,v430);
v435 = _mm256_add_pd(v422,v431);
v436 = _mm256_sub_pd(v320,v254);
v437 = _mm256_sub_pd(v332,v266);
v438 = _mm256_sub_pd(v374,v308);
v439 = _mm256_sub_pd(v375,v309);
v440 = _mm256_sub_pd(v376,v310);
v441 = _mm256_sub_pd(v377,v311);
v442 = _mm256_sub_pd(v365,v299);
v443 = _mm256_sub_pd(v359,v293);
v444 = _mm256_sub_pd(v436,v378);
v445 = _mm256_sub_pd(v437,v390);
v446 = _mm256_sub_pd(v438,v432);
v447 = _mm256_sub_pd(v439,v433);
v448 = _mm256_sub_pd(v440,v434);
v449 = _mm256_sub_pd(v441,v435);
v450 = _mm256_sub_pd(v442,v423);
v451 = _mm256_sub_pd(v443,v417);
v452 = _mm256_add_pd(v310,v444);
v453 = _mm256_add_pd(v311,v445);
v454 = _mm256_add_pd(v299,v446);
v455 = _mm256_add_pd(v293,v447);
v456 = _mm256_add_pd(v378,v448);
v457 = _mm256_add_pd(v390,v449);
v458 = _mm256_add_pd(v432,v450);
v459 = _mm256_add_pd(v433,v451);
v8 = _mm256_load_pd(a+4*8);
v24 = _mm256_load_pd(b+4*8);
MUL256(v460,v461,v8,v24);
v8 = _mm256_load_pd(a+4*8);
v9 = _mm256_load_pd(a+4*9);
v462 = _mm256_add_pd(v8,v9);
v24 = _mm256_load_pd(b+4*8);
v25 = _mm256_load_pd(b+4*9);
v463 = _mm256_add_pd(v24,v25);
MUL256(v464,v465,v462,v463);
v9 = _mm256_load_pd(a+4*9);
v25 = _mm256_load_pd(b+4*9);
MUL256(v466,v467,v9,v25);
v468 = _mm256_sub_pd(v464,v460);
v469 = _mm256_sub_pd(v465,v461);
v470 = _mm256_sub_pd(v468,v466);
v471 = _mm256_sub_pd(v469,v467);
v472 = _mm256_add_pd(v461,v470);
v473 = _mm256_add_pd(v466,v471);
v8 = _mm256_load_pd(a+4*8);
v9 = _mm256_load_pd(a+4*9);
v10 = _mm256_load_pd(a+4*10);
v11 = _mm256_load_pd(a+4*11);
v474 = _mm256_add_pd(v8,v10);
v475 = _mm256_add_pd(v9,v11);
v24 = _mm256_load_pd(b+4*8);
v25 = _mm256_load_pd(b+4*9);
v26 = _mm256_load_pd(b+4*10);
v27 = _mm256_load_pd(b+4*11);
v476 = _mm256_add_pd(v24,v26);
v477 = _mm256_add_pd(v25,v27);
MUL256(v478,v479,v474,v476);
v480 = _mm256_add_pd(v474,v475);
v481 = _mm256_add_pd(v476,v477);
MUL256(v482,v483,v480,v481);
MUL256(v484,v485,v475,v477);
v486 = _mm256_sub_pd(v482,v478);
v487 = _mm256_sub_pd(v483,v479);
v488 = _mm256_sub_pd(v486,v484);
v489 = _mm256_sub_pd(v487,v485);
v490 = _mm256_add_pd(v479,v488);
v491 = _mm256_add_pd(v484,v489);
v10 = _mm256_load_pd(a+4*10);
v26 = _mm256_load_pd(b+4*10);
MUL256(v492,v493,v10,v26);
v10 = _mm256_load_pd(a+4*10);
v11 = _mm256_load_pd(a+4*11);
v494 = _mm256_add_pd(v10,v11);
v26 = _mm256_load_pd(b+4*10);
v27 = _mm256_load_pd(b+4*11);
v495 = _mm256_add_pd(v26,v27);
MUL256(v496,v497,v494,v495);
v11 = _mm256_load_pd(a+4*11);
v27 = _mm256_load_pd(b+4*11);
MUL256(v498,v499,v11,v27);
v500 = _mm256_sub_pd(v496,v492);
v501 = _mm256_sub_pd(v497,v493);
v502 = _mm256_sub_pd(v500,v498);
v503 = _mm256_sub_pd(v501,v499);
v504 = _mm256_add_pd(v493,v502);
v505 = _mm256_add_pd(v498,v503);
v506 = _mm256_sub_pd(v478,v460);
v507 = _mm256_sub_pd(v490,v472);
v508 = _mm256_sub_pd(v491,v473);
v509 = _mm256_sub_pd(v485,v467);
v510 = _mm256_sub_pd(v506,v492);
v511 = _mm256_sub_pd(v507,v504);
v512 = _mm256_sub_pd(v508,v505);
v513 = _mm256_sub_pd(v509,v499);
v514 = _mm256_add_pd(v473,v510);
v515 = _mm256_add_pd(v467,v511);
v516 = _mm256_add_pd(v492,v512);
v517 = _mm256_add_pd(v504,v513);
v8 = _mm256_load_pd(a+4*8);
v9 = _mm256_load_pd(a+4*9);
v10 = _mm256_load_pd(a+4*10);
v11 = _mm256_load_pd(a+4*11);
v12 = _mm256_load_pd(a+4*12);
v13 = _mm256_load_pd(a+4*13);
v14 = _mm256_load_pd(a+4*14);
v15 = _mm256_load_pd(a+4*15);
v518 = _mm256_add_pd(v8,v12);
v519 = _mm256_add_pd(v9,v13);
v520 = _mm256_add_pd(v10,v14);
v521 = _mm256_add_pd(v11,v15);
v24 = _mm256_load_pd(b+4*8);
v25 = _mm256_load_pd(b+4*9);
v26 = _mm256_load_pd(b+4*10);
v27 = _mm256_load_pd(b+4*11);
v28 = _mm256_load_pd(b+4*12);
v29 = _mm256_load_pd(b+4*13);
v30 = _mm256_load_pd(b+4*14);
v31 = _mm256_load_pd(b+4*15);
v522 = _mm256_add_pd(v24,v28);
v523 = _mm256_add_pd(v25,v29);
v524 = _mm256_add_pd(v26,v30);
v525 = _mm256_add_pd(v27,v31);
MUL256(v526,v527,v518,v522);
v528 = _mm256_add_pd(v518,v519);
v529 = _mm256_add_pd(v522,v523);
MUL256(v530,v531,v528,v529);
MUL256(v532,v533,v519,v523);
v534 = _mm256_sub_pd(v530,v526);
v535 = _mm256_sub_pd(v531,v527);
v536 = _mm256_sub_pd(v534,v532);
v537 = _mm256_sub_pd(v535,v533);
v538 = _mm256_add_pd(v527,v536);
v539 = _mm256_add_pd(v532,v537);
v540 = _mm256_add_pd(v518,v520);
v541 = _mm256_add_pd(v519,v521);
v542 = _mm256_add_pd(v522,v524);
v543 = _mm256_add_pd(v523,v525);
MUL256(v544,v545,v540,v542);
v546 = _mm256_add_pd(v540,v541);
v547 = _mm256_add_pd(v542,v543);
MUL256(v548,v549,v546,v547);
MUL256(v550,v551,v541,v543);
v552 = _mm256_sub_pd(v548,v544);
v553 = _mm256_sub_pd(v549,v545);
v554 = _mm256_sub_pd(v552,v550);
v555 = _mm256_sub_pd(v553,v551);
v556 = _mm256_add_pd(v545,v554);
v557 = _mm256_add_pd(v550,v555);
MUL256(v558,v559,v520,v524);
v560 = _mm256_add_pd(v520,v521);
v561 = _mm256_add_pd(v524,v525);
MUL256(v562,v563,v560,v561);
MUL256(v564,v565,v521,v525);
v566 = _mm256_sub_pd(v562,v558);
v567 = _mm256_sub_pd(v563,v559);
v568 = _mm256_sub_pd(v566,v564);
v569 = _mm256_sub_pd(v567,v565);
v570 = _mm256_add_pd(v559,v568);
v571 = _mm256_add_pd(v564,v569);
v572 = _mm256_sub_pd(v544,v526);
v573 = _mm256_sub_pd(v556,v538);
v574 = _mm256_sub_pd(v557,v539);
v575 = _mm256_sub_pd(v551,v533);
v576 = _mm256_sub_pd(v572,v558);
v577 = _mm256_sub_pd(v573,v570);
v578 = _mm256_sub_pd(v574,v571);
v579 = _mm256_sub_pd(v575,v565);
v580 = _mm256_add_pd(v539,v576);
v581 = _mm256_add_pd(v533,v577);
v582 = _mm256_add_pd(v558,v578);
v583 = _mm256_add_pd(v570,v579);
v12 = _mm256_load_pd(a+4*12);
v28 = _mm256_load_pd(b+4*12);
MUL256(v584,v585,v12,v28);
v12 = _mm256_load_pd(a+4*12);
v13 = _mm256_load_pd(a+4*13);
v586 = _mm256_add_pd(v12,v13);
v28 = _mm256_load_pd(b+4*12);
v29 = _mm256_load_pd(b+4*13);
v587 = _mm256_add_pd(v28,v29);
MUL256(v588,v589,v586,v587);
v13 = _mm256_load_pd(a+4*13);
v29 = _mm256_load_pd(b+4*13);
MUL256(v590,v591,v13,v29);
v592 = _mm256_sub_pd(v588,v584);
v593 = _mm256_sub_pd(v589,v585);
v594 = _mm256_sub_pd(v592,v590);
v595 = _mm256_sub_pd(v593,v591);
v596 = _mm256_add_pd(v585,v594);
v597 = _mm256_add_pd(v590,v595);
v12 = _mm256_load_pd(a+4*12);
v13 = _mm256_load_pd(a+4*13);
v14 = _mm256_load_pd(a+4*14);
v15 = _mm256_load_pd(a+4*15);
v598 = _mm256_add_pd(v12,v14);
v599 = _mm256_add_pd(v13,v15);
v28 = _mm256_load_pd(b+4*12);
v29 = _mm256_load_pd(b+4*13);
v30 = _mm256_load_pd(b+4*14);
v31 = _mm256_load_pd(b+4*15);
v600 = _mm256_add_pd(v28,v30);
v601 = _mm256_add_pd(v29,v31);
MUL256(v602,v603,v598,v600);
v604 = _mm256_add_pd(v598,v599);
v605 = _mm256_add_pd(v600,v601);
MUL256(v606,v607,v604,v605);
MUL256(v608,v609,v599,v601);
v610 = _mm256_sub_pd(v606,v602);
v611 = _mm256_sub_pd(v607,v603);
v612 = _mm256_sub_pd(v610,v608);
v613 = _mm256_sub_pd(v611,v609);
v614 = _mm256_add_pd(v603,v612);
v615 = _mm256_add_pd(v608,v613);
v14 = _mm256_load_pd(a+4*14);
v30 = _mm256_load_pd(b+4*14);
MUL256(v616,v617,v14,v30);
v14 = _mm256_load_pd(a+4*14);
v15 = _mm256_load_pd(a+4*15);
v618 = _mm256_add_pd(v14,v15);
v30 = _mm256_load_pd(b+4*14);
v31 = _mm256_load_pd(b+4*15);
v619 = _mm256_add_pd(v30,v31);
MUL256(v620,v621,v618,v619);
v15 = _mm256_load_pd(a+4*15);
v31 = _mm256_load_pd(b+4*15);
MUL256(v622,v623,v15,v31);
v624 = _mm256_sub_pd(v620,v616);
v625 = _mm256_sub_pd(v621,v617);
v626 = _mm256_sub_pd(v624,v622);
v627 = _mm256_sub_pd(v625,v623);
v628 = _mm256_add_pd(v617,v626);
v629 = _mm256_add_pd(v622,v627);
v630 = _mm256_sub_pd(v602,v584);
v631 = _mm256_sub_pd(v614,v596);
v632 = _mm256_sub_pd(v615,v597);
v633 = _mm256_sub_pd(v609,v591);
v634 = _mm256_sub_pd(v630,v616);
v635 = _mm256_sub_pd(v631,v628);
v636 = _mm256_sub_pd(v632,v629);
v637 = _mm256_sub_pd(v633,v623);
v638 = _mm256_add_pd(v597,v634);
v639 = _mm256_add_pd(v591,v635);
v640 = _mm256_add_pd(v616,v636);
v641 = _mm256_add_pd(v628,v637);
v642 = _mm256_sub_pd(v526,v460);
v643 = _mm256_sub_pd(v538,v472);
v644 = _mm256_sub_pd(v580,v514);
v645 = _mm256_sub_pd(v581,v515);
v646 = _mm256_sub_pd(v582,v516);
v647 = _mm256_sub_pd(v583,v517);
v648 = _mm256_sub_pd(v571,v505);
v649 = _mm256_sub_pd(v565,v499);
v650 = _mm256_sub_pd(v642,v584);
v651 = _mm256_sub_pd(v643,v596);
v652 = _mm256_sub_pd(v644,v638);
v653 = _mm256_sub_pd(v645,v639);
v654 = _mm256_sub_pd(v646,v640);
v655 = _mm256_sub_pd(v647,v641);
v656 = _mm256_sub_pd(v648,v629);
v657 = _mm256_sub_pd(v649,v623);
v658 = _mm256_add_pd(v516,v650);
v659 = _mm256_add_pd(v517,v651);
v660 = _mm256_add_pd(v505,v652);
v661 = _mm256_add_pd(v499,v653);
v662 = _mm256_add_pd(v584,v654);
v663 = _mm256_add_pd(v596,v655);
v664 = _mm256_add_pd(v638,v656);
v665 = _mm256_add_pd(v639,v657);
v666 = _mm256_sub_pd(v254,v32);
v667 = _mm256_sub_pd(v266,v44);
v668 = _mm256_sub_pd(v308,v86);
v669 = _mm256_sub_pd(v309,v87);
v670 = _mm256_sub_pd(v452,v230);
v671 = _mm256_sub_pd(v453,v231);
v672 = _mm256_sub_pd(v454,v232);
v673 = _mm256_sub_pd(v455,v233);
v674 = _mm256_sub_pd(v456,v234);
v675 = _mm256_sub_pd(v457,v235);
v676 = _mm256_sub_pd(v458,v236);
v677 = _mm256_sub_pd(v459,v237);
v678 = _mm256_sub_pd(v434,v212);
v679 = _mm256_sub_pd(v435,v213);
v680 = _mm256_sub_pd(v423,v201);
v681 = _mm256_sub_pd(v417,v195);
v682 = _mm256_sub_pd(v666,v460);
v683 = _mm256_sub_pd(v667,v472);
v684 = _mm256_sub_pd(v668,v514);
v685 = _mm256_sub_pd(v669,v515);
v686 = _mm256_sub_pd(v670,v658);
v687 = _mm256_sub_pd(v671,v659);
v688 = _mm256_sub_pd(v672,v660);
v689 = _mm256_sub_pd(v673,v661);
v690 = _mm256_sub_pd(v674,v662);
v691 = _mm256_sub_pd(v675,v663);
v692 = _mm256_sub_pd(v676,v664);
v693 = _mm256_sub_pd(v677,v665);
v694 = _mm256_sub_pd(v678,v640);
v695 = _mm256_sub_pd(v679,v641);
v696 = _mm256_sub_pd(v680,v629);
v697 = _mm256_sub_pd(v681,v623);
v698 = _mm256_add_pd(v234,v682);
v699 = _mm256_add_pd(v235,v683);
v700 = _mm256_add_pd(v236,v684);
v701 = _mm256_add_pd(v237,v685);
v702 = _mm256_add_pd(v212,v686);
v703 = _mm256_add_pd(v213,v687);
v704 = _mm256_add_pd(v201,v688);
v705 = _mm256_add_pd(v195,v689);
v706 = _mm256_add_pd(v460,v690);
v707 = _mm256_add_pd(v472,v691);
v708 = _mm256_add_pd(v514,v692);
v709 = _mm256_add_pd(v515,v693);
v710 = _mm256_add_pd(v658,v694);
v711 = _mm256_add_pd(v659,v695);
v712 = _mm256_add_pd(v660,v696);
v713 = _mm256_add_pd(v661,v697);

int64_t te=readTSCp();
printf("cycle = %d\n",int(te-ts));
__attribute__ ((aligned (32))) double output[128];
_mm256_store_pd(output+0, v32);
_mm256_store_pd(output+4, v44);
_mm256_store_pd(output+8, v86);
_mm256_store_pd(output+12, v87);
_mm256_store_pd(output+16, v230);
_mm256_store_pd(output+20, v231);
_mm256_store_pd(output+24, v232);
_mm256_store_pd(output+28, v233);
_mm256_store_pd(output+32, v698);
_mm256_store_pd(output+36, v699);
_mm256_store_pd(output+40, v700);
_mm256_store_pd(output+44, v701);
_mm256_store_pd(output+48, v702);
_mm256_store_pd(output+52, v703);
_mm256_store_pd(output+56, v704);
_mm256_store_pd(output+60, v705);
_mm256_store_pd(output+64, v706);
_mm256_store_pd(output+68, v707);
_mm256_store_pd(output+72, v708);
_mm256_store_pd(output+76, v709);
_mm256_store_pd(output+80, v710);
_mm256_store_pd(output+84, v711);
_mm256_store_pd(output+88, v712);
_mm256_store_pd(output+92, v713);
_mm256_store_pd(output+96, v662);
_mm256_store_pd(output+100, v663);
_mm256_store_pd(output+104, v664);
_mm256_store_pd(output+108, v665);
_mm256_store_pd(output+112, v640);
_mm256_store_pd(output+116, v641);
_mm256_store_pd(output+120, v629);
_mm256_store_pd(output+124, v623);
for(int i=0;i<128;++i) 
    printf(" %f",output[i]);
    printf("\n");
    
}
