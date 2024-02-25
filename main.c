/* main.c */

#include "point.h"
#include <glib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    g_type_init();

    Point *p1 = point_new(5.0, 10.0);
    Point *p2 = point_new(1.0, 2.0);

    gdouble distance = point_calculate_distance(p1, p2);
    printf("Distance between points: %f\n", distance);

    g_object_unref(p1);
    g_object_unref(p2);

    return 0;
}
