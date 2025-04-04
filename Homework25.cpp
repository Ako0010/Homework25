#include <iostream>
#include <iomanip>
using namespace std;

#include "workerqueue.h"


int main() {
    Printer printer;

    Worker worker1("Ali", "Mammadov", 30, 2);
    Worker worker2("Aysha", "Qasimova", 25, 3);
    Worker worker3("Rashad", "Mammadov", 35, 1);

    printer.request(worker1);
    printer.request(worker2);
    printer.request(worker3);

    printer.start();

    return 0;
}
