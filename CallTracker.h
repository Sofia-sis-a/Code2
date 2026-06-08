#ifndef CALL_TRACKER_H
#define CALL_TRACKER_H

#include <iostream>

class CallTracker {
private:
    char* subscriberName;
    char* phoneNumber;

    double maxCallDuration = 0.0;
    double minCallDuration = 0.0;
    double totalDuration = 0.0;
    int totalCalls = 0;

    static constexpr double FREQUENT_THRESHOLD = 60.0;  // Именованная константа

public:
    CallTracker(const char* name, const char* phone);
    ~CallTracker();

    // Селекторы
    const char* getName() const;
    const char* getPhone() const;
    double getMaxDuration() const;
    double getMinDuration() const;
    double getTotalDuration() const;
    int getTotalCalls() const;

    double getAverageDuration() const;
    bool isFrequentCommunication() const;

    void addCall(double duration);
    void printInfo() const;
};

#endif
