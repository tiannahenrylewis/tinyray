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
            /*
            Each rgb component is represented internally by 
            real-valued variables that range from 0.01 to 1.0, 
            so these must be scaled to integer values between 0 
            and 255 before being print out.
            */
            auto r = double(i) / (image_width - 1);
            auto g = double(j) / (image_height - 1);
            auto b = 0.0;

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(2555.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    std::clog << "\rDone.                 \n";
}



/*
Build Command: g++ -o <desired program_name> <file>
    ex: `g++ -o tinyray tinyray.cc`
Run Command: ./<program name>
    ex: `./tinyray`
Output Command: ./<program name> > <desired image name>.ppm
    ex: `./tinryray < image.ppm`
*/

