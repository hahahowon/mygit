#ifndef TEST_USER_MANAGER_H
#define TEST_USER_MANAGER_H
//management인데 class 선언이 manager로 되어있음 조심
#include "testRepository.h"  // UserFileRepository 클래스 포함
#include <memory>            // std::unique_ptr 사용

// 사용자 관리 기능 (CRUD) 을 담당하는 클래스
// Service/Manager 계층: 비즈니스 로직 처리
// Repository 패턴의 Service 계층 구현
class TestUserManager {
private:
    // 멤버 변수: Repository 객체를 소유 (Composition 관계)
    std::unique_ptr<UserFileRepository> repository;    // 저장소를 소유 (RAII 패턴)

public:
    // 생성자: 파일명을 받아서 Repository 객체 생성
    // unique_ptr은 생성자에서 초기화해야 함
    TestUserManager(const std::string& filename);

    // CRUD (Create, Read, Update, Delete) 작업들
    
    // Create: 사용자 추가 (새 ID 자동 생성)
    // 반환값: 새로 생성된 사용자의 ID
    int addUser(const std::string& id, const std::string& name, const std::string& phoneNumber, const std::string& password, const std::string& email, const std::string& address, const std::string& role);

    // Update: 사용자 수정 (ID로 찾아서 이름/전화번호 변경)
    // 반환값: 수정 성공 여부 (true/false)
    bool updateUser(int user_num, const std::string& id, const std::string& name, const std::string& phoneNumber, const std::string& password, const std::string& email, const std::string& address);
    
    // Delete: 사용자 삭제 (ID로 삭제)
    // 반환값: 삭제 성공 여부 (true/false)
    bool deleteUser(int user_num);

    // Read: 전체 사용자 조회
    // 반환값: ID와 TestUser 쌍의 벡터
    std::vector<std::pair<int, TestUser>> getAllUsers() const;

    // Read: 이름으로 사용자 검색 (최초 1개 리턴)
    // 반환값: 찾은 사용자 포인터 (nullptr이면 찾지 못함)
    // 메모리 관리: 호출자가 delete 해야 함
    std::pair<int, TestUser>* findUserByName(const std::string& name) const;

    // 데이터 저장: CSV 파일에 저장
    void save();
};

#endif // TEST_USER_MANAGER_H
