class Position
{
    public:
        int x;
        int y;

        Position(int x, int y) {
            this->x = x;
            this->y = y;
        }

        void move(int alpha, int beta) {
            this->x += alpha;
            this->y += beta;
        }
};
