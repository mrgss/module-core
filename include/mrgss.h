#ifndef MRGSS_H
#define	MRGSS_H
#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#include <GL/glew.h>
#include <mruby.h>
#include <mruby/class.h>

#ifdef	__cplusplus
extern "C" {
#endif
    void mrgss_raise(mrb_state *mrb, struct RClass *exception, const char *message);
    struct RClass* mrgss_module();
#ifdef	__cplusplus
}
#endif

#endif	/* MRGSS_H */

