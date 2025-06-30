#include "productRepository.h"


#include <fstream>      // 파일 입출력 (ifstream, ofstream)
#include <sstream>      // 문자열 스트림 (stringstream)
#include <iostream>     // 콘솔 출력용 (std::cout)
#include <algorithm>    // 문자열 처리용 (std::find_first_not_of 등)

using namespace std;

ProductFileRepository::ProductFileRepository(const string& filename)
    : filename(filename)
{
    load();
}


//문자열 좌우 공백 제거
string ProductFileRepository::trim(const string& s){
    size_t start = s.find_first_not_of(" \t\r\n");
    if (start == string::npos) return "";
    
    size_t end = s.find_last_not_of(" \t\r\n");
    return s.substr(start, end - start + 1);
}


//CSV 파싱    "," 기준 문자열 분환 및 vector<string> 반환

vector<string> ProductFileRepository::splitCSV(const string& line, char delim){
    vector<string> tokens;
    stringstream ss(line);
    string token;
    while (getline(ss, token, delim)){
        tokens.push_back(trim(token));
    }
    return tokens;
    
}

//파일 읽기

void ProductFileRepository::load(){
    ifstream file(filename);

    if(!file.is_open()){
        cout<<"can't open file"<<filename<<endl;
        return;
    }

    productList.clear();
    string line;
    int product_num = 1;

    if(getline(file, line)){
        if(line.find("ID") != string::npos){}
    }

    if(getline(file, line)){
        if(line.find("ID") != string::npos){
          } else{
            vector<string> tokens = splitCSV(line, ',');
            if(tokens.size() >= 2){
                productList.insert(make_pair(product_num++, Product(stoi(tokens[0]), stod(tokens[1]), tokens[2], tokens[3])));
            }
        }
    }

    while(getline(file, line)){
        if(line.empty()) continue;

        vector<string> tokens = splitCSV(line, ',');
        if(tokens.size() >= 2){
            productList.insert
            (make_pair(product_num++, Product(stoi(tokens[0]), stod(tokens[1]), tokens[2], tokens[3])));
        }
    }

    file.close();
}



void ProductFileRepository::save() const{
    ofstream file(filename);
    if(!file.is_open()){
        cout<<"can't open file"<<filename<<endl;
        return;
    }

    file<<"ID,Name,Price,Stock,Category\n";

    for(const auto& pair : productList){
        int product_num = pair.first;
        const Product& product = pair.second;

        file<<product_num<<","
        <<product.getName()<<","
        <<product.getPrice()<<","
        <<product.getStock()<<","
        <<product.getCategory()<<"\n";
    }
    file.close();
}                           







