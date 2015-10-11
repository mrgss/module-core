#ifndef MRGSS_H
#define	MRGSS_H
#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#include <GL/glew.h>
#include <mruby.h>
#include <mruby/class.h>
#include <kazmath/kazmath.h>

#ifdef	__cplusplus
extern "C" {
#endif
    void mrgss_raise(mrb_state *mrb, struct RClass *exception, const char *message);
    void draw_sprite (mrb_state *mrb, mrb_value sprite, kmMat4* matrices);
    void mrgss_viewport_draw(mrb_state *mrb, mrb_value viewport);
    void viewport_add_children(mrb_state *mrb, mrb_value viewport, mrb_value child);
    void viewport_remove_children(mrb_state *mrb, mrb_value viewport, mrb_value child);
    struct RClass* mrgss_module();
#ifdef	__cplusplus
}
#endif

#endif	/* MRGSS_H */

