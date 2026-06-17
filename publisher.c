#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

char *locations[] =
{                             //locations in banglore 
    "12.9788,77.5996",
    "12.9763,77.5929",
    "12.9797,77.5907",
    "12.9507,77.5848",
    "12.9756,77.6066",
    "12.9987,77.5920",
    "13.0098,77.5511",
    "12.8008,77.5773",
    "12.8346,77.4010",
    "13.3702,77.6835"
};

int main()
{
    int i = 0;

    while(1)
    {
        char cmd[200];

        sprintf(cmd,
                "mosquitto_pub -h localhost -t vehicle/location -m \"%s\"",
                locations[i]);

        system(cmd);

        printf("Location Sent: %s\n", locations[i]);

        i++;

        if(i >= 10)
            i = 0;

        Sleep(6000);
    }

    return 0;
}