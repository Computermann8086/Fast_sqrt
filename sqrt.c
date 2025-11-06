float fast_sqrt(float n){
    float est = n;
    long i;

    i = *(long*)&est;         // Make it a long, so we can actually do shit with the bits
    i = (((i >> 1)<<23)-1064992506)^2147483648U;   // Why does this even work?
    est = *(float*)&i;
    est = 0.5F*(est+(n/est)); // Two iterations of Newtons Method
    est = 0.5F*(est+(n/est)); // Here's the seccond one
    return est;
}
