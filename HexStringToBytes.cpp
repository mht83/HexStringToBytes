//////////////////////////////////////////////written by mht83/////////////////////////////////////////
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

void to_hex(std::string hexString) {
    bool is_alpha = false;
    for (char x : hexString) {
        if (!isdigit(x)) {
            is_alpha = true; break;
        }
    }
    if (is_alpha) {
        std::vector<uint8_t> result;
        std::istringstream iss(hexString);
        uint32_t value;


        iss >> std::hex >> value;
        for (int i = 0; i < 4; ++i) {
            result.push_back(static_cast<uint8_t>(value >> (i * 8)));
        }

        std::cout << "Input: " << hexString << ", output:";
        for (size_t i = result.size()-1; ; --i) {
            std::cout << "0x" << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(result[i]);
            std::cout << "  ";
            if (i == 0) break;
        }
    }
       
    else {
        std::vector<int> result;
        for (int i = 1; i < hexString.length(); i += 2) {
            result.push_back(hexString[i]);
        }

        for (char x :result) {
            std::cout << x<<' ';
        }

    }
}

int main()
{
    std::string inputHex1 = "BAADF00D";
    to_hex(inputHex1) ;

    std::string inputHex2 = "010203040506";
    to_hex(inputHex2);

}
