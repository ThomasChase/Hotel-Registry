/*
Created By Thomas Chase
Created on May 27, 2020
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "hotelroom.h"
#include "guestroom.h"
#include "meetingroom.h"

using namespace std;

//Funtion Prototypes
void displayHotelRoom(const HotelRoom& r);

int main()
{
    cout << "Base class hotel room first!" << endl;
    cout << "Display Hotel Room executing..." << endl;
    displayHotelRoom(HotelRoom(14, 65.60));
    cout << endl;
    cout << "Now for the guest room!" << endl;
    cout << "Display Hotel Room executing..." << endl;
    displayHotelRoom(GuestRoom(3,3,62, 45.90));
    cout << endl;
    cout << "Lastly the meeting room!" << endl;
    cout << "Display Hotel Room executing..." << endl;
    displayHotelRoom(MeetingRoom(15, 2));
    cout << endl;
    cout << "Thank you!" << endl;

    return 0;
}

void displayHotelRoom(const HotelRoom& r){
    cout << "Final bill: $" << r.calculateBill() << endl;
    cout << r.toString() << endl;
}
