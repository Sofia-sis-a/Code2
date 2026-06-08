#include "CallTracker.h"
#include <cstring>
#include <stdexcept>

CallTracker::CallTracker(const char* name, const char* phone) {
    if (name == nullptr || phone == nullptr) {
        throw std::invalid_argument("Ошибка: Указатели не могут быть nullptr!");
    }
    if (std::strlen(name) == 0) {
        throw std::logic_error("Ошибка: Имя абонента не может быть пустым!");
    }
    if (std::strlen(phone) == 0) {
        throw std::logic_error("Ошибка: Номер телефона не может быть пустым!");
    }

    subscriberName = new char[std::strlen(name) + 1];
    std::strcpy(subscriberName, name);

    phoneNumber = new char[std::strlen(phone) + 1];
    std::strcpy(phoneNumber, phone);
}

CallTracker::~CallTracker() {
    delete[] subscriberName;
    delete[] phoneNumber;
}

const char* CallTracker::getName() const { 
    return subscriberName; 
}

const char* CallTracker::getPhone() const { 
    return phoneNumber; 
}

double CallTracker::getMaxDuration() const { return maxCallDuration; }
double CallTracker::getMinDuration() const { return minCallDuration; }
double CallTracker::getTotalDuration() const { return totalDuration; }
int CallTracker::getTotalCalls() const { return totalCalls; }

double CallTracker::getAverageDuration() const {
    if (totalCalls == 0) {
        throw std::runtime_error("Ошибка: Невозможно вычислить среднюю длительность, так как звонков еще не было!");
    }
    return totalDuration / totalCalls;
}

bool CallTracker::isFrequentCommunication() const {
    return totalDuration > FREQUENT_THRESHOLD;
}

void CallTracker::addCall(double duration) {
    if (duration <= 0) {
        throw std::out_of_range("Ошибка: Длительность звонка должна быть строго больше нуля!");
    }

    if (totalCalls == 0) {
        minCallDuration = duration;
        maxCallDuration = duration;
    } else {
        if (duration > maxCallDuration) maxCallDuration = duration;
        if (duration < minCallDuration) minCallDuration = duration;
    }

    totalDuration += duration;
    totalCalls++;
}

void CallTracker::printInfo() const {
    std::cout << "========================================" << std::endl;
    std::cout << "Абонент: " << subscriberName << std::endl;
    std::cout << "Телефон: " << phoneNumber << std::endl;
    std::cout << "Всего звонков: " << totalCalls << std::endl;
    std::cout << "Общая длительность: " << totalDuration << " мин." << std::endl;
    std::cout << "Макс. звонок: " << maxCallDuration << " мин." << std::endl;
    std::cout << "Мин. звонок: " << minCallDuration << " мин." << std::endl;
    std::cout << "Частое общение: " << (isFrequentCommunication() ? "Да" : "Нет") << std::endl;
    std::cout << "========================================" << std::endl;
}
