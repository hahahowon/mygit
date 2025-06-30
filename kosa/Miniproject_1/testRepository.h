#ifndef USER_FILE_REPOSITORY_H
#define USER_FILE_REPOSITORY_H

// 표준 라이브러리 헤더 포함
#include <string>   // std::string 클래스 사용
#include <map>      // std::map 컨테이너 사용 (키-값 쌍 저장)
#include <vector>   // std::vector 컨테이너 사용 (동적 배열)
#include "testuser.h"  // TestUser 클래스 정의 포함

// CSV 파일을 통한 사용자 데이터 저장/로드를 담당하는 클래스
// Repository 패턴 구현: 데이터 접근 계층
class UserFileRepository {
private:
    // 멤버 변수들
    std::string filename;                    // CSV 파일 경로 저장
    std::map<int, TestUser> userList;       // user_num를 키로, TestUser를 값으로 하는 맵

    // 정적 멤버 함수들 (클래스 인스턴스 없이도 호출 가능)
    static std::string trim(const std::string& s);                    // 문자열 앞뒤 공백 제거
    static std::vector<std::string> splitCSV(const std::string& line, char delim);  // CSV 라인 분할

public:
    // 생성자: 파일명을 받아서 멤버 변수 초기화
    UserFileRepository(const std::string& fname);
    
    // 멤버 함수들
    void load();    // CSV 파일에서 데이터 읽어와 userList에 저장
    void save() const;  // userList의 데이터를 CSV 파일에 저장 (const: 멤버 변수 수정 안함)

    // getter 함수들 (const 참조 반환으로 성능 최적화)
    const std::map<int, TestUser>& getUserList() const { return userList; }  // 읽기 전용 접근
    std::map<int, TestUser>& getUserList() { return userList; }              // 읽기/쓰기 접근
};

#endif // USER_FILE_REPOSITORY_H
