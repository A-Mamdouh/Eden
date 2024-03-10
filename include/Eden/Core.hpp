#pragma once

#define EDEN_NO_COPY(x) \
    x operator=(x &other) = delete;\
    x(x &other) = delete;

#define EDEN_NO_MOVE(x) \
    x operator=(x &&other) = delete;\
    x(x &&other) = delete;

#define EDEN_RAIIL(x) \
    EDEN_NO_COPY(x) \
    EDEN_NO_MOVE(x)