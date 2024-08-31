#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

/*
Purpose:
    - Defines a utility function that writes a single pixel's colour out to the standard output stream

Notes:
*/

using color = vec3;

void write_color(std::ostream& out, const color& pixel_color, int samples_per_pixel) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    //Divide the color by the number of samples and gamma-correct for gamma=2.0
    auto scale = 1.0 / samples_per_pixel;
    r = sqrt(scale * r);
    g = sqrt(scale * g);
    b = sqrt(scale * b);

    //Translate the [0,1] component values to the byte range [0,255]
    int rbyte = int(255.999 * r);
    int gbyte = int(255.999 * g);
    int bbyte = int(255.999 * b);

    //Write the translated [0,255] value of each colour component
    out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' ' << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' ' << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';

}

#endif