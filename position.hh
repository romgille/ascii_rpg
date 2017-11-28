#ifndef POSITION_H
#define POSITION_H

class Position {
public:
    int x;
    int y;

    Position(int x, int y);

    Position();

    void move(int alpha, int beta);

    void print();
};

#endif
