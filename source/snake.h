enum direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class SNAKE {
    public:
        int snakeLength;
        int snakeDirection;
        vector<pair<int,int> > snakeBody;

        void appendSnake();
        void changeDirection(int newDirection);
        bool isDied();
        void initSnake();
        void moveSnake();
        pair<int,int> nextCell();
        void printSnake();
};

void SNAKE::appendSnake() {
    ++snakeLength;
    snakeBody.emplace_back(0, 0);

    for (int i = snakeLength - 1; i > 0; --i) snakeBody[i] = snakeBody[i - 1];
    snakeBody[0] = nextCell();
}

void SNAKE::changeDirection(int newDirection) {
    if (snakeDirection == UP || snakeDirection == DOWN) {
        if (newDirection == LEFT || newDirection == RIGHT) snakeDirection = newDirection;
    }
    else {
        if (newDirection == UP || newDirection == DOWN) snakeDirection = newDirection;
    }
}

bool SNAKE::isDied() {
    for (int i = 1; i < snakeLength; ++i)
        if (snakeBody[i] == snakeBody[0]) return 1;
    return 0;
}

void SNAKE::initSnake() {
    snakeLength = 1;
    snakeDirection = RIGHT;
    snakeBody.emplace_back(rand()% boardWidth, rand()% boardHeight);
}

void SNAKE::moveSnake() {
    for (int i = snakeLength - 1; i > 0; --i) snakeBody[i] = snakeBody[i - 1];
    snakeBody[0] = nextCell();
}

pair<int,int> SNAKE::nextCell() {
    auto [x, y] = snakeBody[0];

    if (snakeDirection == UP) --y;
    else if (snakeDirection == DOWN) ++y;
    else if (snakeDirection == LEFT) --x;
    else if (snakeDirection == RIGHT) ++x;

    if (x < 0) x += boardWidth;
    else if (x == boardWidth) x -= boardWidth;
    
    if (y < 0) y += boardHeight;
    else if (y == boardHeight) y -= boardHeight;

    return {x, y};
}

void SNAKE::printSnake() {
    for (auto [x, y] : snakeBody)
        drawRectangle(x * 30, y * 30, 29, 29, 0, 0, 255, 0);
}