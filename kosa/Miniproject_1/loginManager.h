#ifndef LOGIN_MANAGER_H
#define LOGIN_MANAGER_H

#include <string>
#include "testManagement.h"

class LoginManager {
private:
    TestUserManager userManager;

public:
    // 생성자: 사용자 데이터 파일명 전달
    LoginManager(const std::string& filename);

    // 로그인 함수: 성공(관리자=1, 일반=0), 실패(-1)
    int login(const std::string& id, const std::string& password);
};

#endif // LOGIN_MANAGER_H