#include <iostream>
#include "User.h"

//default constructor
User::User() {
    userLikedNumber = "null";
    userName = "null";
    userAge = "null";
    userGender = "null";
    userPhoneNumber = "null";
    userProfession = "null";
    userSchool = "null";
    userCurrentLatitude = "null";
    userCurrentLongitude = "null";
    isPremium = "null";
    userMinAgePref = "null";
    userMaxAgePref = "null";
    userMaxDistancePref = "null";
    userGenderPref = "null";
    userLikedNumber = "null";
}

User::User(std::string aUserName, std::string aUserAge, std::string aUserGender, std::string aUserPhoneNumber,
           std::string aUserProfession, std::string aUserSchool, std::string aUserCurrentLatitude, std::string aUserCurrentLongitude,
           std::string aIsPremium, std::string aUserMinAgePref, std::string aUserMaxAgePref, std::string aUserMaxDistancePref,
           std::string aUserGenderPref, std::string aUserLikedNumber) {
    userName = aUserName;
    userAge = aUserAge;
    userGender = aUserGender;
    userPhoneNumber = aUserPhoneNumber;
    userProfession = aUserProfession;
    userSchool = aUserSchool;
    userCurrentLatitude = aUserCurrentLatitude;
    userCurrentLongitude = aUserCurrentLongitude;
    isPremium = aIsPremium;
    userMinAgePref = aUserMinAgePref;
    userMaxAgePref = aUserMaxAgePref;
    userMaxDistancePref = aUserMaxDistancePref;
    userGenderPref = aUserGenderPref;
    userLikedNumber = aUserLikedNumber;
}

//getter functions
std::string User::getUserName() const {
    return userName;
}
std::string User::getUserAge() const {
    return userAge;
}
std::string User::getUserGender() const {
    return userGender;
}
std::string User::getUserPhoneNumber() const {
    return userPhoneNumber;
}
std::string User::getUserProfession() const {
    return userProfession;
}
std::string User::getUserSchool() const {
    return userSchool;
}
std::string User::getUserCurrentLatitude() const {
    return userCurrentLatitude;
}
std::string User::getUserCurrentLongitude() const {
    return userCurrentLongitude;
}
std::string User::getIsPremium() const {
    return isPremium;
}
std::string User::getUserMinAgePref() const {
    return userMinAgePref;
}
std::string User::getUserMaxAgePref() const {
    return userMaxAgePref;
}
std::string User::getUserMaxDistancePref() const {
    return userMaxDistancePref;
}
std::string User::getUserGenderPref() const {
    return userGenderPref;
}
std::string User::getUserLikedNumber() const {
    return userLikedNumber;
}

//setter functions
void User::setUserName(std::string aUserName) {
    userName = aUserName;
}
void User::setUserAge(std::string aUserAge) {
    userAge = aUserAge;
}
void User::setUserGender(std::string aUserGender) {
    userGender = aUserGender;
}
void User::setUserPhoneNumber(std::string aUserPhoneNumber) {
    userPhoneNumber = aUserPhoneNumber;
}
void User::setUserProfession(std::string aUserProfession) {
    userProfession = aUserProfession;
}
void User::setUserSchool(std::string aUserSchool) {
    userSchool = aUserSchool;
}
void User::setUserCurrentLatitude(std::string aUserCurrentLatitude) {
    userCurrentLatitude = aUserCurrentLatitude;
}
void User::setUserCurrentLongitude(std::string aUserCurrentLongitude) {
    userCurrentLongitude = aUserCurrentLongitude;
}
void User::setIsPremium(std::string aIsPremium) {
    isPremium = aIsPremium;
}
void User::setUserMinAgePref(std::string aUserMinAgePref) {
    userMinAgePref = aUserMinAgePref;
}
void User::setUserMaxAgePref(std::string aUserMaxAgePref) {
    userMaxAgePref = aUserMaxAgePref;
}
void User::setUserMaxDistancePref(std::string aUserMaxDistancePref) {
    userMaxAgePref = aUserMaxDistancePref;
}
void User::setUserGenderPref(std::string aUserGenderPref) {
    userGenderPref = aUserGenderPref;
}
void User::setUserLikedNumber(std::string aUserLikedNumber) {
    userLikedNumber = aUserLikedNumber;
}

std::ostream& operator<< (std::ostream& out, const User& m) {
    out << m.getUserName() << " " << m.getUserAge() << " " << m.getUserGender() << " " << m.getUserPhoneNumber() << " " << m.getUserProfession()
        << " " << m.getUserSchool() << " " << m.getUserCurrentLatitude() << " " << m.getUserCurrentLongitude() << " " << m.getIsPremium() << " " << m.getUserMinAgePref()
        << " " << m.getUserMaxAgePref() << " " << m.getUserMaxDistancePref() << " " << m.getUserGenderPref() << " " << m.getUserLikedNumber() << std::endl;
    return out;
}
