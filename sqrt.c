static inline float fast_sqrt(float n) {
    float est = n;
    long nf;

    nf = *(long*)&est;         // Make it a long, so we can actually do shit with the bits
    nf = (((nf >> 1)<<23)-0x3F7A7EFA)^0x80000000U;   // Why does this even work?
    est = *(float*)&nf;
    est = 0.5F*(est+(n/est)); // Two iterations of Newtons Method
    est = 0.5F*(est+(n/est)); // Here's the seccond one
    return est;
}
