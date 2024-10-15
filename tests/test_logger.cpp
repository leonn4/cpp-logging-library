#include "../include/logger.h"

int main() {
    Logger logger("log.txt");

    logger.log("This is an info message bro.");
    logger.log("This is a warning message bro.", Logger::WARNING);
    logger.log("This is an error message bro.", Logger::ERROR);

    return 0;
}
