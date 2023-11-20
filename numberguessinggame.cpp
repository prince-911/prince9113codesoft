#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    int randomNumber = std::rand() % 100 + 1;
    int guess;
    int attempts = 0;
    std::cout << "Welcome to number gussing game R!\n";
    std::cout << "We have picked a random number greater than 1 and less than 100.\n";
    do {
        std::cout << "Please Guess the number: ";
        std::cin >> guess;
        attempts++;
        if (guess > randomNumber) {
            std::cout << " It's Too high! Try again.\n";
        } else if (guess < randomNumber) {
            std::cout << "It's Too low! Try again.\n";
        } else {
            std::cout << " You guessed the correct number " << randomNumber << " in " << attempts << " number of  attempts.\n";
        }
    } while (guess != randomNumber);
    return 0;
}
