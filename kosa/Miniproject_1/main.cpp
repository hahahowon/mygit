#include "testManagement.h"   // Includes TestUserManager class
#include <iostream>           // For standard I/O (std::cout, std::cin)
#include <string>             // For std::string
#include "LoginManager.h"     // Includes LoginManager (required)
#include "productManagement.h"

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Function declarations for admin/customer UI
void adminUI();
void customerUI(const std::string& user_id);
void customerProductManager(ProductManagement& productManager);
void adminUserManager(TestUserManager& testManager);
void adminProductManager(ProductManagement& productManager);

// Login screen function
std::string loginPage(LoginManager& loginManager, bool& isAdmin) {
    std::string id, password;
    std::cout << "\n==== Login ====" << std::endl;
    std::cout << "ID: ";
    std::getline(std::cin, id);
    std::cout << "Password: ";
    std::getline(std::cin, password);

    int loginResult = loginManager.login(id, password);
    if (loginResult == 1) {
        isAdmin = true;
        return id;
    } else if (loginResult == 0) {
        isAdmin = false;
        return id;
    } else {
        std::cout << "Login failed! Incorrect ID or password." << std::endl;
        return "";
    }
}

int main() {
    LoginManager loginManager("user_data.csv");

    while (true) {
        clearScreen();
        std::cout << "\n========== Main Menu ==========\n";
        std::cout << "1. Login\n";
        std::cout << "2. Exit\n";
        std::cout << "===============================\n";
        std::cout << "Enter your choice: ";
        int mainChoice;
        std::cin >> mainChoice;
        std::cin.ignore();

        if (mainChoice == 1) {
            clearScreen();
            bool isAdmin = false;
            std::string user_id = loginPage(loginManager, isAdmin);
            if (!user_id.empty()) {
                if (isAdmin) {
                    adminUI();      // 로그아웃(return) 시 main 메뉴로 복귀
                } else {
                    customerUI(user_id); // 로그아웃(return) 시 main 메뉴로 복귀
                }
            } else {
                std::cout << "Login failed! Press any key to continue...";
                std::cin.get();
            }
        } else if (mainChoice == 2) {
            clearScreen();
            std::cout << "Exiting program..." << std::endl;
            break;
        } else {
            clearScreen();
            std::cout << "Invalid choice! Press any key to continue...";
            std::cin.get();
        }
    }
    return 0;
}

// Admin UI: For testing all features
void adminUI() {
    while(true){
        clearScreen();
        std::cout << "\n=========== Admin Management ===========\n";
        std::cout << "1. User Management" << std::endl;
        std::cout << "2. Product Management" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "===========================================\n";
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore();
        clearScreen();
        switch(choice){
            case 1: {
                TestUserManager testManager("user_data.csv");
                adminUserManager(testManager);
                break;
            }
            case 2: {
                ProductManagement productManager("product_data.csv");
                adminProductManager(productManager);
                break;
            }
            case 3:
                return;
            default:
                std::cout << "Invalid choice!" << std::endl;
                break;
        }
    }
}

// Customer UI: Only product search for testing

void customerUI(const std::string& user_id)  {
    while(true){
        clearScreen();
        std::cout << "\n============= Customer Page =============\n";
        std::cout << "1. Product" << std::endl;
        std::cout << "2. Exit" << std::endl;
        std::cout << "===========================================\n";
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore();
        clearScreen();
        switch(choice){
            case 1: {
                ProductManagement productManager("product_data.csv");
                customerProductManager(productManager);
                break;
            }
            case 2:
                return;
            default:
                std::cout << "Invalid choice!" << std::endl;
                break;
        }
    }
}
void customerProductManager(ProductManagement& productManager){
    while(true){
        clearScreen();
        std::cout << "\n=========== Product Management ===========\n";
        std::cout << "1. Search Product" << std::endl;
        std::cout << "2. Exit" << std::endl;
        std::cout << "===========================================\n";
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore();
        clearScreen();
        switch(choice){

            case 1: {
                std::cout << "--search product--" << std::endl;
                auto products = productManager.getAllProducts();
                std::cout << "===== Product List =====" << std::endl;
                for(const auto& product : products){
                        std::cout << product.first << " " << product.second.getName() << " "
                            << product.second.getName() << " "
                            << product.second.getPrice() << " "
                            << product.second.getStock() << " "
                            << product.second.getCategory() << std::endl;
                }
                std::cout << "product name: ";
                std::string searchName;
                std::getline(std::cin, searchName);
                auto result = productManager.findProductByName(searchName);
                std::cout << result->second.getName() << " " << result->second.getPrice() << " " << result->second.getStock() << " " << result->second.getCategory() << std::endl;
                break;
            }
            case 2:
                return;
            default:
                std::cout << "Invalid choice!" << std::endl;
                break;
        }
        std::cout << "Press any key to continue...";
        std::cin.get();
    }
}

void adminUserManager(TestUserManager& testManager){

    while(true){
        clearScreen();
        std::cout << "\n=========== Test Management ===========\n";
        std::cout << "1. Add User" << std::endl;
        std::cout << "2. Update User" << std::endl;
        std::cout << "3. Delete User" << std::endl;
        std::cout << "4. search User" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "===========================================\n";
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore();
        clearScreen();
        switch(choice){
            case 1: {
                std::cout << "--add test user--" << std::endl;
                std::cout << "user id: ";
                std::string id;
                std::getline(std::cin, id);
                std::cout << "user password: ";
                std::string password;
                std::getline(std::cin, password);
                std::cout << "user name: ";
                std::string name;
                std::getline(std::cin, name);
                std::cout << "user phone number: ";
                std::string phoneNumber;
                std::getline(std::cin, phoneNumber);
                std::cout << "user email: ";
                std::string email;
                std::getline(std::cin, email);
                std::cout << "user address: ";
                std::string address;
                std::getline(std::cin, address);
                testManager.addUser(id, name, phoneNumber, password, email, address, "customer");
                break;
            }
            case 2: {
                std::cout << "--update test user--" << std::endl;
                auto users = testManager.getAllUsers();
                for(const auto& user : users){
                    std::cout << user.first << " " << user.second.getName() << " " << user.second.getPhoneNumber() << " " << user.second.getEmail() << " " << user.second.getAddress() << " " << user.second.getRole() << std::endl;
                }
                std::cout << "user number: ";
                int user_num;
                std::cin >> user_num;
                std::cin.ignore();
                std::cout << "user name: ";
                std::string name;
                std::getline(std::cin, name);
                std::cout << "user id: ";
                std::string id;
                std::getline(std::cin, id);
                std::cout << "user password: ";
                std::string password;
                std::getline(std::cin, password);
                std::cout << "user phone number: ";
                std::string phoneNumber;
                std::getline(std::cin, phoneNumber);
                std::cout << "user email: ";
                std::string email;
                std::getline(std::cin, email);
                std::cout << "user address: ";
                std::string address;
                std::getline(std::cin, address);
                testManager.updateUser(user_num, id, name, phoneNumber, password, email, address);
                break;
            }
            case 3: {
                std::cout << "--delete user--" << std::endl;
                auto users = testManager.getAllUsers();
                for(const auto& user : users){
                    std::cout << user.first << " " << user.second.getName() << " " << user.second.getPhoneNumber() << " " << user.second.getEmail() << " " << user.second.getAddress() << " " << user.second.getRole() << std::endl;
                }
                std::cout << "user number: ";
                int user_num;
                std::cin >> user_num;
                std::cin.ignore();
                testManager.deleteUser(user_num);
                break;
            }
            case 4: {
                std::cout << "--search user--" << std::endl;

                // 1. 전체 유저 리스트 출력
                auto users = testManager.getAllUsers();
                std::cout << "===== User List =====" << std::endl;
                for(const auto& user : users){
                    std::cout << user.first << " " << user.second.getName() << " "
                            << user.second.getPhoneNumber() << " "
                            << user.second.getEmail() << " "
                            << user.second.getAddress() << " "
                            << user.second.getRole() << std::endl;
                }
                std::cout << "=====================" << std::endl;

                // 2. 이름 입력받아 검색
                std::cout << "Enter user name to search: ";
                std::string searchName;
                std::cin.ignore(); 
                std::getline(std::cin, searchName);

                bool found = false;
                for(const auto& user : users){
                    if(user.second.getName() == searchName){
                        std::cout << ">> Found: " << user.first << " " << user.second.getName() << " "
                                << user.second.getPhoneNumber() << " "
                                << user.second.getEmail() << " "
                                << user.second.getAddress() << " "
                                << user.second.getRole() << std::endl;
                        found = true;
                    }
                }
                if(!found) {
                    std::cout << "No user found with name: " << searchName << std::endl;
                }
                break;
        }
        std::cout << "Press any key to continue...";
        std::cin.get();
    }
}
}


void adminProductManager(ProductManagement& productManager){
    while(true){
        clearScreen();
        std::cout << "\n=========== Product Management ===========\n";
        std::cout << "1. Add Product" << std::endl;
        std::cout << "2. Update Product" << std::endl;
        std::cout << "3. Delete Product" << std::endl;
        std::cout << "4. Search Product" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "===========================================\n";
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore();
        clearScreen();
        switch(choice){
            case 1: {
                std::cout << "--add product--" << std::endl;
                
                std::cout << "product name: ";
                std::string name;
                std::getline(std::cin, name);
                std::cout << "product price: ";
                double price;
                std::cin >> price;
                std::cin.ignore();
                std::cout << "product stock: ";
                int stock;
                std::cin >> stock;
                std::cin.ignore();
                std::cout << "product category: ";
                std::string category;
                std::getline(std::cin, category);
                productManager.addProduct(name, price, stock, category);
                break;
            }
            case 2: {
                std::cout << "--update product--" << std::endl;
                auto products = productManager.getAllProducts();
                for(const auto& product : products){
                    std::cout << product.first << " " << product.second.getName() << " " << product.second.getPrice() << " " << product.second.getStock() << " " << product.second.getCategory() << std::endl;
                }
                std::cout << "product number: ";
                int product_num;
                std::cin >> product_num;
                std::cin.ignore();
                std::cout << "product name: ";
                std::string name;
                std::getline(std::cin, name);
                std::cout << "product price: ";
                double price;
                std::cin >> price;
                std::cin.ignore();
                std::cout << "product stock: ";
                int stock;
                std::cin >> stock;
                std::cin.ignore();
                std::cout << "product category: ";
                std::string category;
                std::getline(std::cin, category);
                productManager.updateProduct(product_num, name, price, stock, category);
                break;
            }
            case 3: {
                std::cout << "--delete product--" << std::endl;
                auto products = productManager.getAllProducts();
                for(const auto& product : products){
                    std::cout << product.first << " " << product.second.getName() << " " << product.second.getPrice() << " " << product.second.getStock() << " " << product.second.getCategory() << std::endl;
                }
                std::cout << "product number: ";
                int product_num;
                std::cin >> product_num;
                std::cin.ignore();
                productManager.deleteProduct(product_num);
                break;
            }
            case 4: {
                std::cout << "--search product--" << std::endl;
                std::cout << "product name: ";
                std::string searchName;
                std::getline(std::cin, searchName);
                auto result = productManager.findProductByName(searchName);
                std::cout << result->second.getName() << " " << result->second.getPrice() << " " << result->second.getStock() << " " << result->second.getCategory() << std::endl;
                break;
            }
            case 5:
                return;
            default:
                std::cout << "Invalid choice!" << std::endl;
                break;
        }
        std::cout << "Press any key to continue...";
        std::cin.get();
    }
}
