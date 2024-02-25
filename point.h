/* point.h */

#ifndef __POINT_H__
#define __POINT_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define POINT_TYPE (point_get_type())
#define POINT(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), POINT_TYPE, Point))
#define POINT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), POINT_TYPE, PointClass))
#define IS_POINT(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), POINT_TYPE))
#define IS_POINT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), POINT_TYPE))
#define POINT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), POINT_TYPE, PointClass))

typedef struct _Point Point;
typedef struct _PointClass PointClass;

struct _Point {
    GObject parent_instance;

    /* Instance members */
    gdouble x;
    gdouble y;
};

struct _PointClass {
    GObjectClass parent_class;

    /* Class members */
    gdouble (*calculate_distance) (Point *self, Point *other);
};

GType point_get_type (void);

Point* point_new (gdouble x, gdouble y);
gdouble point_calculate_distance (Point *self, Point *other);

G_END_DECLS

#endif /* __POINT_H__ */
