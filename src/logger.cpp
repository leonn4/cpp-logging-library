#include "../include/logger.h"

Logger::Logger(const std::string& filename) {
    logFile.open(filename, std::ios::app);
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void Logger::log(const std::string& message, LogLevel level) {
    if (logFile.is_open()) {
        logFile << "[" << currentDateTime() << "] ";
        switch (level) {
            case INFO:
                logFile << "INFO: ";
                break;
            case WARNING:
                logFile << "WARNING: ";
                break;
            case ERROR:
                logFile << "ERROR: ";
                break;
        }
        logFile << message << std::endl;
    }
}

std::string Logger::currentDateTime() {
    std::time_t now = std::time(nullptr);
    char buf[100];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    return buf;
}
