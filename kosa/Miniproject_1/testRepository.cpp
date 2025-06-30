#include "testRepository.h"
#include <fstream>      // 파일 입출력 (ifstream, ofstream)
#include <sstream>      // 문자열 스트림 (stringstream)
#include <iostream>     // 콘솔 출력용 (std::cout)
#include <algorithm>    // 문자열 처리용 (std::find_first_not_of 등)


using namespace std;

// 생성자 구현
// 파일명을 멤버 변수에 저장하고, 즉시 load() 호출
UserFileRepository::UserFileRepository(const string& fname) 
    : filename(fname)   // 멤버 초기화 리스트 사용
{
    load();
}

// 문자열 좌우 공백 제거 (유틸리티 함수)
// C++ string.find_first_not_of() 사용
string UserFileRepository::trim(const string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");  // 공백 문자가 아닌 첫 위치
    if (start == std::string::npos) return "";      // 문자열이 비어있으면 빈 문자열 반환

    size_t end = s.find_last_not_of(" \t\r\n");     // 공백 문자가 아닌 마지막 위치
    return s.substr(start, end - start + 1);        // 부분 문자열 반환
}

// CSV 파싱 함수
// ',' 를 기준으로 문자열을 분할 → vector<string> 으로 반환
vector<string> UserFileRepository::splitCSV(const string& line, char delim) {
    vector<string> tokens;
    stringstream ss(line);    // 문자열 스트림 생성
    string token;

    while (getline(ss, token, delim)) {
        // 한 토큰씩 읽어오고, trim 후 vector 에 저장
        tokens.push_back(trim(token));
    }

    return tokens;
}

// CSV 파일 읽기 (load)
// 파일에서 사용자 데이터를 읽어서 userList 에 저장
void UserFileRepository::load() {
    ifstream file(filename);  // 파일 열기 (읽기 전용)

    // 파일 열기 실패 시 오류 출력
    if (!file.is_open()) {
        cout << "can't open file " << filename << endl;
        return;
    }

    userList.clear();    // 기존 데이터 초기화

    string line;
    int user_num = 1;          // ID는 1부터 자동 증가

    // 첫 번째 줄 처리 (헤더인지 데이터인지 판별)
    if (getline(file, line)) {
        if (line.find("ID") != string::npos) {
            // 헤더인 경우 → skip
        } else {
            // 데이터 라인인 경우 → 첫 줄도 처리
            vector<string> tokens = splitCSV(line, ',');
            if (tokens.size() >= 2) {
                userList.insert(make_pair(user_num++, TestUser(
                    tokens[2], // name
                    tokens[3], // phoneNumber
                    tokens[1], // id
                    tokens[4], // password
                    tokens[5], // email
                    tokens[6], // address
                    tokens[7]  // role
                )));
            }
        }
    }

    // 나머지 줄 처리
    while (getline(file, line)) {
        if (line.empty()) continue;    // 빈 줄 skip

        vector<string> tokens = splitCSV(line, ',');
        if (tokens.size() >= 2) {
            userList.insert(make_pair(user_num++, TestUser(
                tokens[2], // name
                tokens[3], // phoneNumber
                tokens[1], // id
                tokens[4], // password
                tokens[5], // email
                tokens[6], // address
                tokens[7]  // role
            )));
        }
    }

    file.close();    // 파일 닫기
}

// CSV 파일 저장 (save)
// userList 내용을 CSV 형식으로 저장
void UserFileRepository::save() const {
    ofstream file(filename);    // 파일 열기 (쓰기 모드)

    if (!file.is_open()) {
        cout << "can't creative file " << filename << endl;
        return;
    }

    // CSV 헤더 출력
    file << "ID,Name,PhoneNumber,Password,Email,Address\n";

    // map 의 모든 요소 출력
    for (const auto& pair : userList) {
        int user_num = pair.first;
        const TestUser& user = pair.second;

        // 각 항목을 CSV 형식으로 저장
        file << "No." << user_num << ","
             << user.getId() << ","
             << user.getName() << ","
             << user.getPhoneNumber() << ","
             << user.getPassword() << ","
             << user.getEmail() << ","
             << user.getAddress() << ","    
             << user.getRole() << "\n";
    }

    file.close();    // 파일 닫기
}
