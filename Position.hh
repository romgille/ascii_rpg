#ifndef POSITION_HH
#define POSITION_HH

class Position {
  private:
    int x;
    int y;

  public:
    Position();
    Position(int x_, int y_);
    ~Position() = default;

    int getX();
    void setX(int x_);

    int getY();
    void setY(int y_);

    bool operator==(Position p);

    Position operator+(Position p);
};

#endif /* end of include guard: POSITION_HH */
