#include <cmath>
#include <iostream>
#include "User.h"
#include "Node.h"
#include <fstream>
#include <string>

//opening and parsing the user file information into a Node
User readFromUserFile(const std::string& userFile, const std::string& targetPhoneNumber) {
    std::ifstream inputFile(userFile);
    User person = User();

    //error checking if file can't open
    if (!inputFile.is_open()) {
        std::cerr << "Can't open file" << std::endl;
        exit(1);
    }

    while (true) {
        std::string name, age, gender, phoneNumber, profession, school, latitude, longitude, premium, minAgePref, maxAgePref, maxDistancePref, genderPref, likedNumber;
        if (!(inputFile >> name >> age >> gender >> phoneNumber >> profession >> school >> latitude >> longitude >> premium >> minAgePref >> maxAgePref >> maxDistancePref >> genderPref >> likedNumber)) {
            break;
        }

        if (targetPhoneNumber == phoneNumber) {
            person = User(name, age, gender, phoneNumber, profession, school, latitude, longitude, premium, minAgePref, maxAgePref, maxDistancePref, genderPref, likedNumber);
        }
    }
    return person;
}

// calculate the distance between two coordinates using Haversine formula
double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    const double radiusOfEarth = 6371.0; // Earth's radius in kilometers

    // convert latitude and longitude from degrees to radians
    lat1 *= M_PI / 180.0;
    lon1 *= M_PI / 180.0;
    lat2 *= M_PI / 180.0;
    lon2 *= M_PI / 180.0;

    // Haversine formula
    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;
    double a = sin(dLat / 2.0) * sin(dLat / 2.0) + cos(lat1) * cos(lat2) * sin(dLon / 2.0) * sin(dLon / 2.0);
    double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));
    // distance in kilometers
    double distanceKM = radiusOfEarth * c;
    // convert it to distance in miles
    double distanceMiles = distanceKM * 0.621371;

    return distanceMiles;
}

void findProfiles(const std::string& userFile, const std::string& outputFile, const User& person) {
    std::ifstream inputFile(userFile);
    std::ofstream output(outputFile);
    bool foundMatch = false;

    if (!inputFile.is_open()) {
        std::cerr << "Can't open file" << std::endl;
        exit(1);
    }

    while (true) {
        std::string name, age, gender, phoneNumber, profession, school, latitude, longitude, premium, minAgePref, maxAgePref, maxDistancePref, genderPref, likedNumber;
        if (!(inputFile >> name >> age >> gender >> phoneNumber >> profession >> school >> latitude >> longitude >> premium >> minAgePref >> maxAgePref >> maxDistancePref >> genderPref >> likedNumber)) {
            break;
        }

        if (phoneNumber != person.getUserPhoneNumber() && (person.getUserGenderPref() == gender || person.getUserGenderPref() == "Both") &&
            std::stod(person.getUserMaxAgePref()) >= std::stod(age) && std::stod(person.getUserMinAgePref()) <= std::stod(age)
            && std::stod(person.getUserMaxDistancePref()) >= calculateDistance(std::stod(latitude), std::stod(longitude),
            std::stod(person.getUserCurrentLatitude()), std::stod(person.getUserCurrentLongitude()))) {

            foundMatch = true;
            output << name << " " << age << std::endl;
            if (!(profession == "Undisclosed")) {
                for (int i = 0; i < profession.size(); i++) {
                    if (profession[i] == '_') {
                        output << " ";
                    }
                    else {
                        output << profession.substr(i, 1);
                    }
                }
                output << std::endl;
            }
            if (!(school == "Undisclosed")) {
                for (int i = 0; i < school.size(); i++) {
                    if (school[i] == '_') {
                        output << " ";
                    }
                    else {
                        output << school.substr(i, 1);
                    }
                }
                //space checking for the last thing printing
                output << std::endl << std::endl;
            }
        }
    }
    if (!foundMatch) {
        output << "There are no users matching with your preference at this moment." << std::endl;
    }
    inputFile.close();
    output.close();
}

Node<User>* getLikes(const std::string& userFile, const User& person) {
    Node<User>* head = nullptr;
    Node<User>* current = head;
    std::ifstream inputFile(userFile);

    if (!inputFile.is_open()) {
        std::cerr << "Can't open file" << std::endl;
        exit(1);
    }
    while (true) {
        std::string name, age, gender, phoneNumber, profession, school, latitude, longitude, premium, minAgePref, maxAgePref, maxDistancePref, genderPref, likedNumber;
        if (!(inputFile >> name >> age >> gender >> phoneNumber >> profession >> school >> latitude >> longitude
                        >> premium >> minAgePref >> maxAgePref >> maxDistancePref >> genderPref >> likedNumber)) {
            break;
        }
        if (person.getUserLikedNumber().find(phoneNumber) != std::string::npos) {
            User temp = User(name, age, gender, phoneNumber, profession, school, latitude, longitude, premium, minAgePref, maxAgePref, maxDistancePref, genderPref, likedNumber);
            if (head == nullptr) {
                head = new Node<User>;
                head->value = temp;
                head->prev = nullptr;
                head->next = nullptr;
                current = head;
            }
            else {
                bool previous = false;
                while (current->next != nullptr) {
                    if (current->value.getUserPhoneNumber().compare(phoneNumber) > 0) {
                        current = current->next;
                    }
                    else if (current->value.getUserPhoneNumber().compare(phoneNumber) < 0){
                        previous = true;
                        break;
                    }
                }

                if (previous) {
                    Node<User>* old = current;
                    if (current->prev == nullptr) {
                        current->prev = new Node<User>;
                        current->prev->value = temp;
                        current->prev->next = current;
                        current->prev->prev = nullptr;
                        head = current->prev;
                    }
                    else {
                        current = current->prev;
                        current->next = new Node<User>;
                        current->next->value = temp;
                        current->next->prev = current;
                        current = current->next;
                        current->next = old;
                        current->next->prev = current;
                    }
                }
                else {
                    if (current->value.getUserPhoneNumber().compare(phoneNumber) < 0) {
                        current->prev = new Node<User>;
                        current->prev->value = temp;
                        current->prev->next = current;
                        current->prev->prev = nullptr;
                        head = current->prev;
                    }
                    else {
                        current->next = new Node<User>;
                        current->next->value = temp;
                        current->next->prev = current->next;
                        current->next->next = nullptr;
                    }
                }
                current = head;
            }
        }
    }

    inputFile.close();
    return head;
}

void showMatches(const std::string& outputFile, Node<User>* head, const std::string& phoneNumber) {
    std::ofstream output(outputFile);
    //Node<User>* temp;
    bool foundMatch = false;

    while (head != nullptr) {
        if (head->value.getUserLikedNumber().find(phoneNumber) != std::string::npos) {
            foundMatch = true;
            output << head->value.getUserName() << " " << head->value.getUserAge() << std::endl;
            if (!(head->value.getUserProfession() == "Undisclosed")) {
                for (int i = 0; i < head->value.getUserProfession().size(); i++) {
                    if (head->value.getUserProfession()[i] == '_') {
                        output << " ";
                    }
                    else {
                        output << head->value.getUserProfession().substr(i, 1);
                    }
                }
                output << std::endl;
            }
            if (!(head->value.getUserSchool() == "Undisclosed")) {
                for (int i = 0; i < head->value.getUserSchool().size(); i++) {
                    if (head->value.getUserSchool()[i] == '_') {
                        output << " ";
                    }
                    else {
                        output << head->value.getUserSchool().substr(i, 1);
                    }
                }
                //space checking for the last thing printing
                output << std::endl << std::endl;
            }
        }

        head = head->next;
    }
    if (!foundMatch) {
        output << "You do not have any matches at this moment." << std::endl;
    }
    output.close();
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        std::cerr << "Usage: " << argv[0] << " users.txt output.txt phoneNumber command" << std::endl;
        return 1;
    }

    const std::string userFile = argv[1];
    const std::string outputFile = argv[2];
    const std::string phoneNumber = argv[3];
    const std::string command = argv[4];

    User person = readFromUserFile(userFile, phoneNumber);
    Node<User>* head = nullptr;
    Node<User>* current;

    if (person.getUserName() == "null") {
        std::cerr << "No user with that phone number exists" << std::endl;
        return 1;
    }

    if (command == "profile") {
        findProfiles(userFile, outputFile, person);
    }
    else if (command == "match"){
        head = getLikes(userFile, person);
        current = head;
        while (current != nullptr) {
            std::cout << current->value << std::endl << std::endl;
            current = current->next;
        }
        showMatches(outputFile, head, phoneNumber);
    }
    else {
        std::cerr << "Invalid command. Please use either profile, match, like, or unmatch" << std::endl;
        return 1;
    }

    return 0;
}