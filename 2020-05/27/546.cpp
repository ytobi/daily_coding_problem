#include <iostream>

/**
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Microsoft.
 * Given a clock time in hh:mm format, determine, to the nearest degree, the angle between the hour and the minute hands.
 * Bonus: When, during the course of a day, will the angle be zero?
 *
*/
int main()
{
        int hh, mm;

        while (true)
        {                
                do{
                        std::cout << "Enter time in hh:mm :";
                        scanf("%d:%d", &hh, &mm);
                        fflush(stdin);
                }while(hh < 0 or hh > 11 or mm < 0 or mm > 59);

                int angle_btw_hh = 30;
                int angle_btw_mm = 6;

                int angle_btw = (hh*angle_btw_hh) - (mm*angle_btw_mm);
                angle_btw = std::abs(angle_btw);

                std::cout << "Angle between " << hh << ":" << mm << " is " << angle_btw;
                std::cout << std::endl;
        }

        return 0;
}
