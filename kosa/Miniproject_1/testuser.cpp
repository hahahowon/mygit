#include "testuser.h"

// 생성자 구현
TestUser::TestUser(const std::string& name, const std::string& phoneNumber, 
            const std::string& id, const std::string& password, 
            const std::string& email, const std::string& address, const std::string& role)
    : m_name(name), m_phoneNumber(phoneNumber), m_id(id), m_password(password), m_email(email), m_address(address), m_role(role) {}

// 소멸자 구현


std::string TestUser::getId() const { return m_id; }
std::string TestUser::getName() const { return m_name; }
std::string TestUser::getEmail() const { return m_email; }
std::string TestUser::getAddress() const { return m_address; }
std::string TestUser::getPassword() const { return m_password; }
std::string TestUser::getPhoneNumber() const { return m_phoneNumber; }
std::string TestUser::getRole() const { return m_role; }

void TestUser::setId(const std::string& id) { m_id = id; }
void TestUser::setName(const std::string& name) { m_name = name; }
void TestUser::setEmail(const std::string& email) { m_email = email; }
void TestUser::setAddress(const std::string& address) { m_address = address; }
void TestUser::setPassword(const std::string& password) { m_password = password; }
void TestUser::setPhoneNumber(const std::string& phoneNumber) { m_phoneNumber = phoneNumber; }
void TestUser::setRole(const std::string& role) { m_role = role; }

// 비교 연산자 (==)
bool TestUser::operator==(const TestUser& other) const {
    return m_id == other.m_id;
}

// 비교 연산자 (!=)
bool TestUser::operator!=(const TestUser& other) const { return !(*this == other);}
