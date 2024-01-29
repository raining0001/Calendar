#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>

int main() {
    std::map<int, std::vector<std::pair<std::string, int>>> Month;

    Month[1].push_back({"January", 31});
    Month[2].push_back({"February", 28});
    Month[3].push_back({"March", 31});
    Month[4].push_back({"April", 30});
    Month[5].push_back({"May", 31});
    Month[6].push_back({"June", 30});
    Month[7].push_back({"July", 31});
    Month[8].push_back({"August", 31});
    Month[9].push_back({"September", 30});
    Month[10].push_back({"October", 31});
    Month[11].push_back({"November", 30});
    Month[12].push_back({"December", 31});

    std::map<int, std::string> Day;
    Day[1] = ("Mon");
    Day[2] = ("Tue");
    Day[3] = ("Wed");
    Day[4] = ("Thu");
    Day[5] = ("Fri");
    Day[6] = ("Sat");
    Day[7] = ("Sun");

    int year;
    int answer;

    std::cout << "Enter a year: ";
    std::cin >> year;

    std::cout << "Enter the first day of the year [1: Monday,....7: Sunday]: ";
    std::cin >> answer;
    std::cout << std::endl;

    std::cout << "Calendar for " << year << std::endl;

    for (auto monthPair : Month) {
        std::cout << monthPair.second[0].first << " " << year << std::endl;

        for (auto dayPair : Day) {
            std::cout << std::setw(4) << dayPair.second;
        }
        std::cout << std::endl;

        for (int i = 1; i < answer; ++i) {
            std::cout << std::setw(4) << " ";
        }

        for (int i = 1; i <= monthPair.second[0].second; ++i) {
            std::cout << std::setw(4) << i;
            if ((answer + i - 1) % 7 == 0 || i == monthPair.second[0].second) {
                std::cout << std::endl;
            }
        }
        answer = (answer + monthPair.second[0].second) % 7;  // Update starting day for the next month
    }

    return 0;
}