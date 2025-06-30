#ifndef TESTUSER_H
#define TESTUSER_H

#include <string>  // std::string 클래스 사용

// 사용자 데이터를 표현하는 엔티티 클래스
// Entity 클래스: 비즈니스 로직의 핵심 데이터 구조
// 캡슐화 원칙 적용: private 멤버 변수 + public getter/setter
class TestUser {
private:
    // 멤버 변수들 (private으로 캡슐화)
    std::string m_name;           // 사용자 이름 (m_ 접두사: 멤버 변수 표시)
    std::string m_phoneNumber;    // 사용자 전화번호
    std::string m_id;
    std::string m_password;
    std::string m_email;
    std::string m_address;
    std::string m_role; // 권한 필드 추가
public:
    // 생성자: 이름과 전화번호로 객체 초기화
    // const 참조 매개변수: 복사 비용 절약 + 원본 수정 방지
    TestUser(const std::string& name, const std::string& phoneNumber, 
            const std::string& id, const std::string& password, 
            const std::string& email, const std::string& address,
            const std::string& role);

    // 소멸자: 객체 소멸 시 호출 (현재는 기본 구현)
 
    // Getter 함수들 (const 멤버 함수: 객체 상태 변경 안함)
    std::string getName() const;        // 이름 반환
    std::string getPhoneNumber() const; // 전화번호 반환
    std::string getId() const;
    std::string getPassword() const;
    std::string getEmail() const;
    std::string getAddress() const;
    std::string getRole() const;
    // Setter 함수들 (const 참조 매개변수: 복사 비용 절약)
    void setName(const std::string& name);           // 이름 변경
    void setPhoneNumber(const std::string& phoneNumber);
    void setId(const std::string& id);
    void setPassword(const std::string& password);
    void setEmail(const std::string& email);
    void setAddress(const std::string& address);
    void setRole(const std::string& role);

    // 비교 연산자 오버로딩
    // const 멤버 함수: 객체 상태 변경 안함
    // const 참조 매개변수: 복사 비용 절약 + 원본 수정 방지
    bool operator==(const TestUser& other) const;  // 동등 비교 (이름과 전화번호가 같으면 true)
    bool operator!=(const TestUser& other) const;  // 부등 비교 (이름과 전화번호가 다르면 true)
};

#endif // TESTUSER_H
