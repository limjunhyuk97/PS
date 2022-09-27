// Fill function for Filling values in Anycases

// Fill Template
template<typename A, size_t N, typename T>
void Fill(A (&array) [N], const T &val) {
    std::fill((T*)array, (T*)(array+N), val);
}
