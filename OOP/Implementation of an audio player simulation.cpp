#include <iostream>
#include <ctime>
#include <string>

class Track {
private:
    std::tm DateCreation;
    int Duration;
public:
    std::string Name;

    Track(std::string Name_,  std::tm DateCreation_, int Duration_) {
        Name = Name_, DateCreation = DateCreation_, Duration = Duration_;
    }

    void write() {
        std::cout << Name << " " << DateCreation.tm_mday << "." << DateCreation.tm_mon + 1 << "." << DateCreation.tm_year + 1900 << " " << Duration << std::endl;
    }
};

Track* a[10];

class Player {
private:
    bool recordingPlaying = false;

public:
    void play() {
        if (!recordingPlaying) {
            std::cout << "Enter the name of the song you want to listen to: " << std::endl;
            std::string s;
            getline(std::cin, s);
            getline(std::cin, s);
            bool flag = false;
            for (Track* i : a) {
                if (i->Name == s) {
                    flag = true;
                }
            }
            if (!flag) {
                std::cout << "There are no such songs!" << std::endl;
            }
            else {
                for (Track* i : a) {
                    if (i->Name == s) {
                        std::cout << "A new song has started : ";
                        i->write();
                        break;
                    }
                }
                recordingPlaying = true;
            }
        }
    }

    void stop() {
        if (recordingPlaying) {
            std::cout << "Stop playing the song." << std::endl;
            recordingPlaying = false;
        }
    }

    void pause() {
        if (recordingPlaying) {
            std::cout << "Pause playing the song." << std::endl;
            recordingPlaying = false;
        }
    }

    void next() {
        stop();
        int ind = rand() % 10;
        std::cout << "A new song has started : ";
        a[ind]->write();
        recordingPlaying = true;
    }
};

signed main() {
    std::string author[3] = {"Maybe Baby", "Billie Eilish", "Lady Gaga"};
    for (int i = 0; i < 10; ++i) {
        std::time_t t = std::time(nullptr);
        std::tm timeCreation = *std::localtime(&t);
        a[i] = new Track(author[rand() % 3] + " song_" + std::to_string(i), timeCreation, rand() % 80 + 80);
    }
    std::cout << "All songs : \n";
    for (int i = 0; i < 10; ++i)
        a[i]->write();
    std::string s;
    Player* player = new Player();
    while (true) {
        std::cin >> s;
        if (s == "play") {
            player->play();
        } else if (s == "pause") {
            player->pause();
        } else if (s == "next") {
            player->next();
        } else if (s == "stop") {
            player->stop();
        } else if (s == "exit") {
            exit(0);
        } else {
            std::cout << "Invalid request !" << std::endl;
        }
    }
}
