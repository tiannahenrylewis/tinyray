#include "color.h"
#include "vec3.h"

#include <iostream>

int main() {
    // Image
    int image_width = 256;
    int image_height = 256;

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        //Adds a progress indicator using the logging output stream
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            //Calculate the colour of the pixel based on its position in the image
            auto pixel_color = color(double(i)/(image_width-1), double(j)/(image_height-1), 0);

            //Write the pixel's colour out to the standard stream
            write_color(std::cout, pixel_color);
        }
    }

    //Notify rendering has completed
    std::clog << "\rDone.                 \n";
}



/*
Build Command: 
    - g++ -o <desired program_name> <file>
        ex: `g++ -o tinyray tinyray.cc`
    - g++ -std=c++11 -o tinyRay tinyray.cc 
        - adds flag to use C++11 standard when compiling
Run Command: ./<program name>
    ex: `./tinyray`
Output Command: ./<program name> > <desired image name>.ppm
    ex: `./tinryray > image.ppm`
*/

