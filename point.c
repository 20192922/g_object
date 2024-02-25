/* point.c */

#include "point.h"
#include <math.h>

G_DEFINE_TYPE(Point, point, G_TYPE_OBJECT)

static gdouble point_calculate_distance_default (Point *self, Point *other);

static void point_class_init(PointClass *klass)
{
    klass->calculate_distance = point_calculate_distance_default;
}

static void point_init(Point *self)
{
    self->x = 0;
    self->y = 0;
}

Point* point_new (gdouble x, gdouble y)
{
    Point *self = g_object_new(POINT_TYPE, NULL);
    self->x = x;
    self->y = y;
    return self;
}

static gdouble point_calculate_distance_default(Point *self, Point *other)
{
    g_return_val_if_fail(IS_POINT(self) && IS_POINT(other), 0);
    return sqrt(pow(self->x - other->x, 2) + pow(self->y - other->y, 2));
}

gdouble point_calculate_distance(Point *self, Point *other)
{
    PointClass *klass;
    g_return_val_if_fail(IS_POINT(self) && IS_POINT(other), 0);
    klass = POINT_GET_CLASS(self);
    return klass->calculate_distance(self, other);
}
