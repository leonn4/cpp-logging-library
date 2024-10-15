#include "../include/logger.h"

int main() {
    Logger logger("log.txt");

    logger.log("This is an info message.");
    logger.log("This is a warning message.", Logger::WARNING);
    logger.log("This is an error message.", Logger::ERROR);

    return 0;
}
