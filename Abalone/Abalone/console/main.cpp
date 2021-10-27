#include <iostream>
#include "Controller.h"
using namespace std;

int main()
{

    Controller controller=Controller(View(),Game());
    controller.start();
}
