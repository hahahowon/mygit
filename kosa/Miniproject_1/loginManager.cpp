#include "LoginManager.h"

// 생성자
LoginManager::LoginManager(const std::string& filename)
    : userManager(filename) {}

// 로그인 함수
int LoginManager::login(const std::string& id, const std::string& password) {
    auto users = userManager.getAllUsers();
    for (const auto& pair : users) {
        const TestUser& user = pair.second;
        if (user.getId() == id && user.getPassword() == password) {
            if (user.getRole() == "admin") return 1;
            else return 0;
        }
    }   
    return -1; // 로그인 실패
}