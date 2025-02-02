#include "sha256.h"
#include <string.h>

void sha256(unsigned char *out, const unsigned char *in) {
    u32 s[8], w[64], T0, T1;

    // Load words
    memcpy(w, in, 64);

    // Initial State
    s[0] = 0x6a09e667;
    s[1] = 0xbb67ae85;
    s[2] = 0x3c6ef372;
    s[3] = 0xa54ff53a;
    s[4] = 0x510e527f;
    s[5] = 0x9b05688c;
    s[6] = 0x1f83d9ab;
    s[7] = 0x5be0cd19;

    SHA256ROUND(s[0], s[1], s[2], s[3], s[4], s[5], s[6], s[7], 0, w[0]);
    SHA256ROUND(s[7], s[0], s[1], s[2], s[3], s[4], s[5], s[6], 1, w[1]);
    SHA256ROUND(s[6], s[7], s[0], s[1], s[2], s[3], s[4], s[5], 2, w[2]);
    SHA256ROUND(s[5], s[6], s[7], s[0], s[1], s[2], s[3], s[4], 3, w[3]);
    SHA256ROUND(s[4], s[5], s[6], s[7], s[0], s[1], s[2], s[3], 4, w[4]);
    SHA256ROUND(s[3], s[4], s[5], s[6], s[7], s[0], s[1], s[2], 5, w[5]);
    SHA256ROUND(s[2], s[3], s[4], s[5], s[6], s[7], s[0], s[1], 6, w[6]);
    SHA256ROUND(s[1], s[2], s[3], s[4], s[5], s[6], s[7], s[0], 7, w[7]);
    SHA256ROUND(s[0], s[1], s[2], s[3], s[4], s[5], s[6], s[7], 8, w[8]);
    SHA256ROUND(s[7], s[0], s[1], s[2], s[3], s[4], s[5], s[6], 9, w[9]);
    SHA256ROUND(s[6], s[7], s[0], s[1], s[2], s[3], s[4], s[5], 10, w[10]);
    SHA256ROUND(s[5], s[6], s[7], s[0], s[1], s[2], s[3], s[4], 11, w[11]);
    SHA256ROUND(s[4], s[5], s[6], s[7], s[0], s[1], s[2], s[3], 12, w[12]);
    SHA256ROUND(s[3], s[4], s[5], s[6], s[7], s[0], s[1], s[2], 13, w[13]);
    SHA256ROUND(s[2], s[3], s[4], s[5], s[6], s[7], s[0], s[1], 14, w[14]);
    SHA256ROUND(s[1], s[2], s[3], s[4], s[5], s[6], s[7], s[0], 15, w[15]);
    w[16] = WSIGMA1(w[14]) + w[0] + w[9] + WSIGMA0(w[1]);
    SHA256ROUND(s[0], s[1], s[2], s[3], s[4], s[5], s[6], s[7], 16, w[16]);
    w[17] = WSIGMA1(w[15]) + w[1] + w[10] + WSIGMA0(w[2]);
    SHA256ROUND(s[7], s[0], s[1], s[2], s[3], s[4], s[5], s[6], 17, w[17]);
    w[18] = WSIGMA1(w[16]) + w[2] + w[11] + WSIGMA0(w[3]);
    SHA256ROUND(s[6], s[7], s[0], s[1], s[2], s[3], s[4], s[5], 18, w[18]);
    w[19] = WSIGMA1(w[17]) + w[3] + w[12] + WSIGMA0(w[4]);
    SHA256ROUND(s[5], s[6], s[7], s[0], s[1], s[2], s[3], s[4], 19, w[19]);
    w[20] = WSIGMA1(w[18]) + w[4] + w[13] + WSIGMA0(w[5]);
    SHA256ROUND(s[4], s[5], s[6], s[7], s[0], s[1], s[2], s[3], 20, w[20]);
    w[21] = WSIGMA1(w[19]) + w[5] + w[14] + WSIGMA0(w[6]);
    SHA256ROUND(s[3], s[4], s[5], s[6], s[7], s[0], s[1], s[2], 21, w[21]);
    w[22] = WSIGMA1(w[20]) + w[6] + w[15] + WSIGMA0(w[7]);
    SHA256ROUND(s[2], s[3], s[4], s[5], s[6], s[7], s[0], s[1], 22, w[22]);
    w[23] = WSIGMA1(w[21]) + w[7] + w[16] + WSIGMA0(w[8]);
    SHA256ROUND(s[1], s[2], s[3], s[4], s[5], s[6], s[7], s[0], 23, w[23]);
    w[24] = WSIGMA1(w[22]) + w[8] + w[17] + WSIGMA0(w[9]);
    SHA256ROUND(s[0], s[1], s[2], s[3], s[4], s[5], s[6], s[7], 24, w[24]);
    w[25] = WSIGMA1(w[23]) + w[9] + w[18] + WSIGMA0(w[10]);
    SHA256ROUND(s[7], s[0], s[1], s[2], s[3], s[4], s[5], s[6], 25, w[25]);
    w[26] = WSIGMA1(w[24]) + w[10] + w[19] + WSIGMA0(w[11]);
    SHA256ROUND(s[6], s[7], s[0], s[1], s[2], s[3], s[4], s[5], 26, w[26]);
    w[27] = WSIGMA1(w[25]) + w[11] + w[20] + WSIGMA0(w[12]);
    SHA256ROUND(s[5], s[6], s[7], s[0], s[1], s[2], s[3], s[4], 27, w[27]);
    w[28] = WSIGMA1(w[26]) + w[12] + w[21] + WSIGMA0(w[13]);
    SHA256ROUND(s[4], s[5], s[6], s[7], s[0], s[1], s[2], s[3], 28, w[28]);
    w[29] = WSIGMA1(w[27]) + w[13] + w[22] + WSIGMA0(w[14]);
    SHA256ROUND(s[3], s[4], s[5], s[6], s[7], s[0], s[1], s[2], 29, w[29]);
    w[30] = WSIGMA1(w[28]) + w[14] + w[23] + WSIGMA0(w[15]);
    SHA256ROUND(s[2], s[3], s[4], s[5], s[6], s[7], s[0], s[1], 30, w[30]);
    w[31] = WSIGMA1(w[29]) + w[15] + w[24] + WSIGMA0(w[16]);
    SHA256ROUND(s[1], s[2], s[3], s[4], s[5], s[6], s[7], s[0], 31, w[31]);
    w[32] = WSIGMA1(w[30]) + w[16] + w[25] + WSIGMA0(w[17]);
    SHA256ROUND(s[0], s[1], s[2], s[3], s[4], s[5], s[6], s[7], 32, w[32]);
    w[33] = WSIGMA1(w[31]) + w[17] + w[26] + WSIGMA0(w[18]);
    SHA256ROUND(s[7], s[0], s[1], s[2], s[3], s[4], s[5], s[6], 33, w[33]);
    w[34] = WSIGMA1(w[32]) + w[18] + w[27] + WSIGMA0(w[19]);
    SHA256ROUND(s[6], s[7], s[0], s[1], s[2], s[3], s[4], s[5], 34, w[34]);
    w[35] = WSIGMA1(w[33]) + w[19] + w[28] + WSIGMA0(w[20]);
    SHA256ROUND(s[5], s[6], s[7], s[0], s[1], s[2], s[3], s[4], 35, w[35]);
    w[36] = WSIGMA1(w[34]) + w[20] + w[29] + WSIGMA0(w[21]);
    SHA256ROUND(s[4], s[5], s[6], s[7], s[0], s[1], s[2], s[3], 36, w[36]);
    w[37] = WSIGMA1(w[35]) + w[21] + w[30] + WSIGMA0(w[22]);
    SHA256ROUND(s[3], s[4], s[5], s[6], s[7], s[0], s[1], s[2], 37, w[37]);
    w[38] = WSIGMA1(w[36]) + w[22] + w[31] + WSIGMA0(w[23]);
    SHA256ROUND(s[2], s[3], s[4], s[5], s[6], s[7], s[0], s[1], 38, w[38]);
    w[39] = WSIGMA1(w[37]) + w[23] + w[32] + WSIGMA0(w[24]);
    SHA256ROUND(s[1], s[2], s[3], s[4], s[5], s[6], s[7], s[0], 39, w[39]);
    w[40] = WSIGMA1(w[38]) + w[24] + w[33] + WSIGMA0(w[25]);
    SHA256ROUND(s[0], s[1], s[2], s[3], s[4], s[5], s[6], s[7], 40, w[40]);
    w[41] = WSIGMA1(w[39]) + w[25] + w[34] + WSIGMA0(w[26]);
    SHA256ROUND(s[7], s[0], s[1], s[2], s[3], s[4], s[5], s[6], 41, w[41]);
    w[42] = WSIGMA1(w[40]) + w[26] + w[35] + WSIGMA0(w[27]);
    SHA256ROUND(s[6], s[7], s[0], s[1], s[2], s[3], s[4], s[5], 42, w[42]);
    w[43] = WSIGMA1(w[41]) + w[27] + w[36] + WSIGMA0(w[28]);
    SHA256ROUND(s[5], s[6], s[7], s[0], s[1], s[2], s[3], s[4], 43, w[43]);
    w[44] = WSIGMA1(w[42]) + w[28] + w[37] + WSIGMA0(w[29]);
    SHA256ROUND(s[4], s[5], s[6], s[7], s[0], s[1], s[2], s[3], 44, w[44]);
    w[45] = WSIGMA1(w[43]) + w[29] + w[38] + WSIGMA0(w[30]);
    SHA256ROUND(s[3], s[4], s[5], s[6], s[7], s[0], s[1], s[2], 45, w[45]);
    w[46] = WSIGMA1(w[44]) + w[30] + w[39] + WSIGMA0(w[31]);
    SHA256ROUND(s[2], s[3], s[4], s[5], s[6], s[7], s[0], s[1], 46, w[46]);
    w[47] = WSIGMA1(w[45]) + w[31] + w[40] + WSIGMA0(w[32]);
    SHA256ROUND(s[1], s[2], s[3], s[4], s[5], s[6], s[7], s[0], 47, w[47]);
    w[48] = WSIGMA1(w[46]) + w[32] + w[41] + WSIGMA0(w[33]);
    SHA256ROUND(s[0], s[1], s[2], s[3], s[4], s[5], s[6], s[7], 48, w[48]);
    w[49] = WSIGMA1(w[47]) + w[33] + w[42] + WSIGMA0(w[34]);
    SHA256ROUND(s[7], s[0], s[1], s[2], s[3], s[4], s[5], s[6], 49, w[49]);
    w[50] = WSIGMA1(w[48]) + w[34] + w[43] + WSIGMA0(w[35]);
    SHA256ROUND(s[6], s[7], s[0], s[1], s[2], s[3], s[4], s[5], 50, w[50]);
    w[51] = WSIGMA1(w[49]) + w[35] + w[44] + WSIGMA0(w[36]);
    SHA256ROUND(s[5], s[6], s[7], s[0], s[1], s[2], s[3], s[4], 51, w[51]);
    w[52] = WSIGMA1(w[50]) + w[36] + w[45] + WSIGMA0(w[37]);
    SHA256ROUND(s[4], s[5], s[6], s[7], s[0], s[1], s[2], s[3], 52, w[52]);
    w[53] = WSIGMA1(w[51]) + w[37] + w[46] + WSIGMA0(w[38]);
    SHA256ROUND(s[3], s[4], s[5], s[6], s[7], s[0], s[1], s[2], 53, w[53]);
    w[54] = WSIGMA1(w[52]) + w[38] + w[47] + WSIGMA0(w[39]);
    SHA256ROUND(s[2], s[3], s[4], s[5], s[6], s[7], s[0], s[1], 54, w[54]);
    w[55] = WSIGMA1(w[53]) + w[39] + w[48] + WSIGMA0(w[40]);
    SHA256ROUND(s[1], s[2], s[3], s[4], s[5], s[6], s[7], s[0], 55, w[55]);
    w[56] = WSIGMA1(w[54]) + w[40] + w[49] + WSIGMA0(w[41]);
    SHA256ROUND(s[0], s[1], s[2], s[3], s[4], s[5], s[6], s[7], 56, w[56]);
    w[57] = WSIGMA1(w[55]) + w[41] + w[50] + WSIGMA0(w[42]);
    SHA256ROUND(s[7], s[0], s[1], s[2], s[3], s[4], s[5], s[6], 57, w[57]);
    w[58] = WSIGMA1(w[56]) + w[42] + w[51] + WSIGMA0(w[43]);
    SHA256ROUND(s[6], s[7], s[0], s[1], s[2], s[3], s[4], s[5], 58, w[58]);
    w[59] = WSIGMA1(w[57]) + w[43] + w[52] + WSIGMA0(w[44]);
    SHA256ROUND(s[5], s[6], s[7], s[0], s[1], s[2], s[3], s[4], 59, w[59]);
    w[60] = WSIGMA1(w[58]) + w[44] + w[53] + WSIGMA0(w[45]);
    SHA256ROUND(s[4], s[5], s[6], s[7], s[0], s[1], s[2], s[3], 60, w[60]);
    w[61] = WSIGMA1(w[59]) + w[45] + w[54] + WSIGMA0(w[46]);
    SHA256ROUND(s[3], s[4], s[5], s[6], s[7], s[0], s[1], s[2], 61, w[61]);
    w[62] = WSIGMA1(w[60]) + w[46] + w[55] + WSIGMA0(w[47]);
    SHA256ROUND(s[2], s[3], s[4], s[5], s[6], s[7], s[0], s[1], 62, w[62]);
    w[63] = WSIGMA1(w[61]) + w[47] + w[56] + WSIGMA0(w[48]);
    SHA256ROUND(s[1], s[2], s[3], s[4], s[5], s[6], s[7], s[0], 63, w[63]);

    // Feed Forward
    s[0] = s[0] + 0x6a09e667;
    s[1] = s[1] + 0xbb67ae85;
    s[2] = s[2] + 0x3c6ef372;
    s[3] = s[3] + 0xa54ff53a;
    s[4] = s[4] + 0x510e527f;
    s[5] = s[5] + 0x9b05688c;
    s[6] = s[6] + 0x1f83d9ab;
    s[7] = s[7] + 0x5be0cd19;

    // Store Hash value
    memcpy(out, s, 32);
    return;
}
