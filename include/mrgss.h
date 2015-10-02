#ifndef MRGSS_H
#define	MRGSS_H
#include <mruby.h>
#include <mruby/class.h>

#ifdef	__cplusplus
extern "C" {
#endif
       
    struct RClass* mrgss_get_module(mrb_state* mrb);
    struct RClass* mrgss_create_class(mrb_state *mrb, const char *name);
    struct RClass* mrgss_get_class(mrb_state *mrb, const char *name);
    
    mrb_value mrgss_obj_new(mrb_state *mrb, const char *type, int argc, mrb_value *args);
    mrb_bool mrgss_object_is_a(mrb_state *mrb, mrb_value object, const char *mrgss_class_name);
    
    void mrgss_iv_create(mrb_state *mrb, mrb_value object, const char *name, mrb_value value);
    mrb_value mrgss_iv_get(mrb_state *mrb,mrb_value object, const char *name);
    int mrgss_is_disposable(mrb_state *mrb, mrb_value object);
    
    void mrgss_raise(mrb_state *mrb, struct RClass *exception, const char *message);
    
    
#ifdef	__cplusplus
}
#endif

#endif	/* MRGSS_H */

