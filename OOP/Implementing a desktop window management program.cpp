#include <iostream>
#include <string>
#include <map>

class Window {
public:
    int x, y, w, h;

    Window(int x_ = 0, int y_ = 0, int w_ = 0, int h_ = 0) { x = x_, y = y_, w = w_, h = h_;}

    void move() {
        std::cout << "How much should the window size be changed? Enter two numbers\n";
        int dx, dy; std::cin >> dx >> dy;
        x += dx, y += dy;
        std::cout << "Window coordinates: \n";
        std::cout << x << " " << y << " " << x + h << " " << y + h << "\n";
    }

    void resize() {
        std::cout << "How much should the window size be changed? Enter two numbers\n";
        int dw, dh; std::cin >> dw >> dh;
        w += dw, h += dh;
        std::cout << "Window dimensions: \n";
        std::cout << w << " " << h << "\n";
    }
};

class Monitor{
private:
    int w = 80, h = 50;

public:

    friend void print(Monitor *a, Window *window) {
        for (int i = 0; i < a->h; ++i) {
            for (int j = 0; j < a->w; ++j) {
                if (window->x <= i && i <= window->x + window->h &&
                        window->y <= j && j <= window->y + window->w) std::cout << 1;
                else std::cout << 0;
            }
            std::cout << std::endl;
        }
    }
};

signed main() {
    std::string s;
    Monitor* monitor = new Monitor();
    Window* window = new Window();
    while (true) {
        std::cin >> s;
        if (s == "close") {
            exit(0);
        } else if (s == "display") {
            print(monitor, window);
        } else if (s == "move") {
            window->move();
        } else if (s == "resize") {
            window->resize();
        } else std::cout << "Invalid request !" << std::endl;
    }
}

