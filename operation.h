#pragma once

#include <iostream>
#include <vector>
#include <fstream>

struct Point {
    long double x, y;

    friend std::istream& operator>>(std::istream &in, Point&p) {
        in >> p.x >> p.y;
        return in;
    }

    friend std::ostream& operator<<(std::ostream &out, Point &p) {
        out << p.x << " " << p.y << std::endl;
        return out;
    }

    friend bool operator==(Point&a, Point&b) {
        return a.x == b.x && a.y == b.y;
    }
};

void scalpel(std::vector<Point> &cut) {
    cut.push_back(*new Point());
    cut.push_back(*new Point());
    int index = (int)cut.size() - 2;
    while (index < (int)cut.size()) {
        std::string name_point = "";
        if (index % 2 == 0) std::cout << "Enter the beginning point's coordinates to make a cut xy : " << std::endl;
        else std::cout << "Enter the ending point's coordinates to make a cut xy : " << std::endl;
        std::cin >> cut[index];
        index++;
    }
    std::cout << "The cut was made between the coordinates (" << cut[index - 2].x << ", "
              << cut[index - 2].y << ") and (" << cut[index - 1].x << "," << cut[index - 1].y << ")" << std::endl;
}

void hemostat(std::vector<Point> &clamps) {
    std::cout << "Input the point at which it is required to set a clamp xy : " << std::endl;
    clamps.push_back(*new Point());
    std::cin >> clamps[(int)clamps.size() - 1];
    std::cout << "The clamp was installed at the point with the coordinates (" <<
        clamps[(int)clamps.size() - 1].x << "," << clamps[(int)clamps.size() - 1].y << ")" << std::endl;
}

void tweezer(std::vector<Point> &tweezers) {
    std::cout << "Input the point at which it is required to set a tweezers xy : " << std::endl;
    tweezers.push_back(*new Point());
    std::cin >> tweezers[(int)tweezers.size() - 1];
    std::cout << "The tweezers were installed at the point with the coordinates (" <<
        tweezers[(int)tweezers.size() - 1].x << "," << tweezers[(int)tweezers.size() - 1].y << ")" << std::endl;
}

void suture(std::vector<Point> &cut) {
    int index = (int)cut.size() - 2;
    while (index < (int)cut.size()) {
        std::string name_point = "";
        if (index % 2 == 0) std::cout << "Enter the beginning point's coordinates to make a seam xy : " << std::endl;
        else std::cout << "Enter the ending point's coordinates to make a seam xy : " << std::endl;
        while (true) {
            Point a;
            std::cin >> a;
            if (cut[index] == a) break;
            std::cout << "Invalid coordinate !" << std::endl;
        }
        index++;
    }
    std::cout << "The seam was made between the coordinates (" << cut[index - 2].x << ", "
               << cut[index - 2].y << ") and (" << cut[index - 1].x << "," << cut[index - 1].y << ")" << std::endl;
}