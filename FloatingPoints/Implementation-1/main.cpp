#include <iostream>
#include <immintrin.h>

int main () {

    __m128 a = _mm_set_ps(2.0,2.0,2.0,2.0);
    __m256 b = _mm256_set_ps(2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0);

    __m256 result = _mm256_add_ps(_mm256_set_m128(a,a),b);

    float* f = (float*)(&result); // this splits result into an array of 8 floats.
    printf ("%f %f %f %f %f %f %f %f\n", f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7]);
    return 0;
}