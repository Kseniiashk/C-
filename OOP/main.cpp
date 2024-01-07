#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <map>

class Phone{
public:
    std::string Number;
    std::string Name;
    Phone(std::string Number_ = "", std::string Name_ = "") { Number = Number_, Name = Name_; }
};

class PhoneBook{
private:
    std::map<std::string, Phone*> fromPhoneNumberGivePhone;
    std::map<std::string, Phone*> fromPhoneNameGivePhone;

public:
    void add() {
        std::cout << "Enter your phone number and name: ";
        std::string Number, Name;
        std::cin >> Number >> Name;
        if ((int) Number.size() == 12 && Number[0] == '+' && Number[1] == '7') {
            bool flag = 1;
            for (int i = 2; i < 12; ++i) {
                if ('0' <= Number[i] && Number[i] <= '9');
                else flag = 0;
            }
            if (!flag) {
                std::cout << "Wrong phone number !\n";
            } else {
                if (fromPhoneNumberGivePhone.find(Number) != fromPhoneNumberGivePhone.end()) {
                    std::cout << "This phone number is busy!\n";
                } else if (fromPhoneNameGivePhone.find(Name) != fromPhoneNameGivePhone.end()) {
                    std::cout << "This name is taken!\n";
                } else {
                    Phone *t = new Phone(Number, Name);
                    fromPhoneNumberGivePhone[Number] = t;
                    fromPhoneNameGivePhone[Name] = t;
                }
                std::cout << "OK\n";
            }
        } else std::cout << "Wrong phone number !\n";
    }

    void call() {
        std::cout << "Who should I call? \n";
        std::string s; std::cin >> s;
        if (fromPhoneNameGivePhone.find(s) != fromPhoneNameGivePhone.end()) {
            std::string Number = fromPhoneNameGivePhone[s]->Number;
            std::string Name = fromPhoneNameGivePhone[s]->Name;
            std::cout << "CALL " << Number << " " << Name << "\n";
        } else if (fromPhoneNumberGivePhone.find(s) != fromPhoneNumberGivePhone.end()) {
            std::string Number = fromPhoneNumberGivePhone[s]->Number;
            std::string Name = fromPhoneNumberGivePhone[s]->Name;
            std::cout << "CALL " << Number << " " << Name << "\n";
        } else {
            std::cout << "There is no such user!\n";
        }
    }

    void sms() {
        std::cout << "Who should I send a message to? \n";
        std::string s; std::cin >> s;
        if (fromPhoneNameGivePhone.find(s) != fromPhoneNameGivePhone.end()) {
            std::cout << "Enter your message: \n";
            std::string text; getline(std::cin, text); getline(std::cin, text);
            std::string Number = fromPhoneNameGivePhone[s]->Number;
            std::string Name = fromPhoneNameGivePhone[s]->Name;
            std::cout << "Sent " << Number << " " << Name << " a message: " << text << "\n";
        } else if (fromPhoneNumberGivePhone.find(s) != fromPhoneNumberGivePhone.end()) {
            std::cout << "Enter your message: \n";
            std::string text; getline(std::cin, text); getline(std::cin, text);
            std::string Number = fromPhoneNumberGivePhone[s]->Number;
            std::string Name = fromPhoneNumberGivePhone[s]->Name;
            std::cout << "Sent " << Number << " " << Name << " a message: " << text << "\n";
        } else {
            std::cout << "There is no such user!\n";
        }
    }
};

signed main() {
    PhoneBook* phoneBook = new PhoneBook();
    std::string s;
    while (true) {
        std::cin >> s;
        if (s == "add") {
            phoneBook->add();
        } else if (s == "call") {
            phoneBook->call();
        } else if (s == "sms") {
            phoneBook->sms();
        } else if (s == "exit") {
            exit(0);
        } else std::cout << "Invalid request !" << std::endl;
    }
}