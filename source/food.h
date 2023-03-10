class FOOD {
    public:
        int x, y;
    
    void generateFood();
    void printFood();
};

void FOOD::generateFood() {
    x = rand() %boardWidth; y = rand() %boardHeight;
}

void FOOD::printFood() {
    drawRectangle(x * 30, y * 30, 29, 29, 255, 0, 0, 255);
}