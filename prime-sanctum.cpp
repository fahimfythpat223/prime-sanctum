#include <iostream>
#include <memory> //for unique and shared pointers

#include "headers/bcrypt.h" //for bcrypt library
#include "headers/encryption.h" //for encryption/decryption relatexd classes

#define true_password_hashed "$2a$10$hMyWLd1qANFBxmoqspAWDeA4Jz2k5cgitNVlu1eSh4TgmliO/eKcO"

int main(int argc, char *argv[]){
    
    /*
    
    this if statement checks whether the use provided the sufficient amount of arguments needed to proceed
    */
    if(argc != 2){                                                    

        std::cerr << "CORRECT USAGE:\n./prime-sanctum [PASSWORD]\n";
        return 1;
    }

    std::string user_provided_password_not_hashed = argv[1]; //saves it to a variable

    std::shared_ptr<VerificationManager> PTRVerificationManager; //instantiates shared_ptr of the VerificationManager class

    /*
    PROVIDES THE validate password function with the user provided password as plain and then the true password's hash
    */

    if (bcrypt::validatePassword(user_provided_password_not_hashed, true_password_hashed)){ //if the user's password matches, then 
                                                                //then the program returns a positive messege. if not, an ACCESS DENIED messege
        std::cout << "Welcome to the Prime Sanctum\n";
        return 0;

    }else{

        std::cout << "ACCESS DENIED\n";
        return 1;
    }
}