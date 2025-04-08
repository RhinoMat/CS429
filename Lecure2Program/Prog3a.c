#include  "FPToolkit.c"
typedef struct {
    double x, y;
    double radius;
    double orbit_position;
    double orbit_radius;
    double r, g, b;
    double day_rads;
} Body;
int main()
{
    double swidth, sheight;
    swidth = 800.0; sheight = 800.0;
    G_init_graphics(swidth, sheight);
    G_rgb(0.0, 0.0, 0.0);
    G_clear();

    Body sun_entity;
    sun_entity.x = swidth/2;
    sun_entity.y = sheight/2;
    sun_entity.radius = 200;
    sun_entity.r = 255.0 / 255;
    sun_entity.g = 127.5 / 255;
    sun_entity.b = 0.0 / 255;
    G_rgb(sun_entity.r, sun_entity.g, sun_entity.b);
    G_fill_circle(sun_entity.x, sun_entity.y, sun_entity.radius);

    Body earth_entity;
    earth_entity.orbit_radius = 350;
    earth_entity.orbit_position = 0;
    earth_entity.radius = 50;
    earth_entity.day_rads = 2 * M_PI / 365;
    earth_entity.x = sun_entity.x + earth_entity.orbit_radius * cos(earth_entity.orbit_position);
    earth_entity.y = sun_entity.y + earth_entity.orbit_radius * sin(earth_entity.orbit_position);
    earth_entity.r = 0;
    earth_entity.g = 0;
    earth_entity.b = 1;
    G_rgb(earth_entity.r, earth_entity.g, earth_entity.b);
    G_fill_circle(earth_entity.x, earth_entity.y, earth_entity.radius);

    Body moon_entity;
    moon_entity.orbit_radius = 100;
    moon_entity.orbit_position = 0;
    moon_entity.radius = 20;
    moon_entity.day_rads = 2 * M_PI / 28;
    moon_entity.x = earth_entity.x + moon_entity.orbit_radius * cos(moon_entity.orbit_position);
    moon_entity.y = earth_entity.y + moon_entity.orbit_radius * sin(moon_entity.orbit_position);
    moon_entity.r = 1;
    moon_entity.g = 1;
    moon_entity.b = 1;
    G_rgb(moon_entity.r, moon_entity.g, moon_entity.b);
    G_fill_circle(moon_entity.x, moon_entity.y, moon_entity.radius);

    while (True)
    {
        G_rgb(0.0, 0.0, 0.0);
        G_clear();
        G_rgb(sun_entity.r, sun_entity.g, sun_entity.b);
        G_fill_circle(sun_entity.x, sun_entity.y, sun_entity.radius);
        earth_entity.orbit_position += earth_entity.day_rads;
        earth_entity.orbit_position = fmod(earth_entity.orbit_position, 2 * M_PI);
        earth_entity.x = sun_entity.x + earth_entity.orbit_radius * cos(earth_entity.orbit_position);
        earth_entity.y = sun_entity.y + earth_entity.orbit_radius * sin(earth_entity.orbit_position);
        G_rgb(earth_entity.r, earth_entity.g, earth_entity.b);
        G_fill_circle(earth_entity.x, earth_entity.y, earth_entity.radius);
        moon_entity.orbit_position += moon_entity.day_rads;
        moon_entity.orbit_position = fmod(moon_entity.orbit_position, 2 * M_PI);
        moon_entity.x = earth_entity.x + moon_entity.orbit_radius * cos(moon_entity.orbit_position);
        moon_entity.y = earth_entity.y + moon_entity.orbit_radius * sin(moon_entity.orbit_position);
        G_rgb(moon_entity.r, moon_entity.g, moon_entity.b);
        G_fill_circle(moon_entity.x, moon_entity.y, moon_entity.radius);
        
        G_wait_key();
    }

     
}