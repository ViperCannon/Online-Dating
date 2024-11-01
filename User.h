#ifndef HW5_USER_H
#define HW5_USER_H

class User {
public:
    User();
    User(std::string aUserName, std::string aUserAge, std::string aUserGender, std::string aUserPhoneNumber,
         std::string aUserProfession, std::string aUserSchool, std::string aUserCurrentLatitude, std::string aUserCurrentLongitude,
         std::string aIsPremium, std::string aUserMinAgePref, std::string aUserMaxAgePref, std::string aUserMaxDistancePref,
         std::string aUserGenderPref, std::string aUserLikedNumber);

    //Accessors
    std::string getUserName() const;
    std::string getUserAge() const;
    std::string getUserGender() const;
    std::string getUserPhoneNumber() const;
    std::string getUserProfession() const;
    std::string getUserSchool() const;
    std::string getUserCurrentLatitude() const;
    std::string getUserCurrentLongitude() const;
    std::string getIsPremium() const;
    std::string getUserMinAgePref() const;
    std::string getUserMaxAgePref() const;
    std::string getUserMaxDistancePref() const;
    std::string getUserGenderPref() const;
    std::string getUserLikedNumber() const;

    //Modifiers
    void setUserName(std::string aUserName);
    void setUserAge(std::string aUserAge);
    void setUserGender(std::string aUserGender);
    void setUserPhoneNumber(std::string aUserPhoneNumber);
    void setUserProfession(std::string aUserProfession);
    void setUserSchool(std::string aUserSchool);
    void setUserCurrentLatitude(std::string aUserCurrentLatitude);
    void setUserCurrentLongitude(std::string aUserCurrentLongitude);
    void setIsPremium(std::string aIsPremium);
    void setUserMinAgePref(std::string aUserMinAgePref);
    void setUserMaxAgePref(std::string aUserMaxAgePref);
    void setUserMaxDistancePref(std::string aUserMaxDistancePref);
    void setUserGenderPref(std::string aUserGenderPref);
    void setUserLikedNumber(std::string aUserLikedNumber);

private:
    //member variables
    std::string userName;
    std::string userAge;
    std::string userGender;
    std::string userPhoneNumber;
    std::string userProfession;
    std::string userSchool;
    std::string userCurrentLatitude;
    std::string userCurrentLongitude;
    std::string isPremium;
    std::string userMinAgePref;
    std::string userMaxAgePref;
    std::string userMaxDistancePref;
    std::string userGenderPref;
    std::string userLikedNumber;
};


//functions
std::ostream& operator<< (std::ostream& out, const User& m);

#endif //HW5_USER_H