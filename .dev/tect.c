#include <immintrin.h>
int main(void) {
    __m512i v = _mm512_set1_epi32(42); // AVX-512
    return ((int*)&v)[0];
}
