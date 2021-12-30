#pragma once
#include "cstdlib"

class MovableBuffer {
public:
    int size;
    float* buffer;

    MovableBuffer(int size) {
        this->size = size;
        buffer = (float*)malloc(size * sizeof(float));
    }

    ~MovableBuffer() {
        delete buffer;
    }

    void push(float in) {
        int index = 0;
        float out = buffer[index];
        while (index < size) {
            out = buffer[index];
            buffer[index] = in;
            in = out;
            index++;
        }
    }
};