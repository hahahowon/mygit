#include "testManagement.h"

// 생성자 구현
// C++에서 클래스 멤버 변수는 생성자에서 초기화
// unique_ptr 은 동적 할당이므로 make_unique 사용
// 파일명을 받아서 repository 객체 생성
TestUserManager::TestUserManager(const std::string& filename) {
    // make_unique: C++14 부터 지원
    // UserFileRepository 객체를 동적 생성하여 unique_ptr 에 저장
    repository = std::make_unique<UserFileRepository>(filename);
}

// 사용자 추가 메소드
// 새로운 ID 를 자동으로 생성하여 userList 에 저장
int TestUserManager::addUser(const std::string& id, const std::string& name, const std::string& phoneNumber, const std::string& password, const std::string& email, const std::string& address, const std::string& role) {
    // ID는 1부터 시작
    int user_num = 1;

    // map 은 정렬된 컨테이너이므로 rbegin() → 가장 큰 ID 를 참조
    if (!repository->getUserList().empty()) {
        user_num = repository->getUserList().rbegin()->first + 1;
    }

    // TestUser 생성 후 userList 에 저장 (role은 무조건 "customer")
    repository->getUserList().insert(std::make_pair(user_num, TestUser(name, phoneNumber, id, password, email, address, "customer")));

    // 새로 추가한 ID 반환
    return user_num;
}

// 사용자 수정 메소드
// ID를 찾아서 이름과 전화번호를 수정
bool TestUserManager::updateUser(int user_num, const std::string& id, const std::string& name, const std::string& phoneNumber, const std::string& password, const std::string& email, const std::string& address) {
    // map 은 key 기반 탐색 (O(log N))
    auto& userList = repository->getUserList();
    auto it = userList.find(user_num);

    if (it != userList.end()) {
        // 해당 ID 존재 → 값 수정
        it->second.setName(name);
        it->second.setPhoneNumber(phoneNumber);
        it->second.setId(id);
        it->second.setPassword(password);
        it->second.setEmail(email);
        it->second.setAddress(address);
        return true;
    }
    // 해당 ID 없음
    return false;
}

// 사용자 삭제 메소드
bool TestUserManager::deleteUser(int user_num) {
    auto& userList = repository->getUserList();

    // erase() : 삭제 성공 시 1 반환, 실패 시 0 반환
    return userList.erase(user_num) > 0;
}

// 전체 사용자 조회
std::vector<std::pair<int, TestUser>> TestUserManager::getAllUsers() const {
    // 반환용 벡터 준비
    std::vector<std::pair<int, TestUser>> users;

    // C++11 range-based for loop 사용
    for (const auto& pair : repository->getUserList()) {
        // pair = std::pair<int, TestUser>
        users.push_back(pair);
    }

    return users;
}

// 이름으로 사용자 검색
// 포인터 반환 방식 사용 (nullptr이면 찾지 못함)
std::pair<int, TestUser>* TestUserManager::findUserByName(const std::string& name) const {
    for (const auto& pair : repository->getUserList()) {
        // pair.second → TestUser 객체 참조
        if (pair.second.getName() == name) {
            // 값이 존재 → 동적 할당하여 포인터 반환
            return new std::pair<int, TestUser>(pair);
        }
    }
    
    // 못 찾음 → nullptr 반환
    return nullptr;
}

// CSV 파일 저장 (repository 에 저장 요청)
void TestUserManager::save() {
    repository->save();
}


//id로만 검색가능한거 수정
// 사용자 관련 메소드 추가
//