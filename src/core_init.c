#include <mruby.h>
#include <mruby/data.h>
#include <mruby/class.h>
#include <mruby/variable.h>
#include <stdio.h>
#include <string.h>
#include <mrgss.h>

void
mrb_mrgss_core_gem_init(mrb_state *mrb) {
    mrb_define_module(mrb, "MRGSS");
}

void
mrb_mrgss_core_gem_final(mrb_state* mrb) {
    /* finalizer */
}

/**
 * MRGSS module Accessor
 */
struct RClass* mrgss_get_module(mrb_state* mrb) {
    return mrb_module_get(mrb, "MRGSS");
}

struct RClass* mrgss_create_class(mrb_state *mrb, const char* name) {
    return mrb_define_class_under(mrb, mrgss_get_module(mrb), name, mrb->object_class);
}

struct RClass* mrgss_get_class(mrb_state *mrb, const char* name) {
    return mrb_class_get_under(mrb, mrgss_get_module(mrb), name);
}

mrb_value mrgss_obj_new(mrb_state *mrb, const char *type, int argc, mrb_value *args) {
    struct RClass *class = mrb_class_get_under(mrb, mrgss_get_module(mrb), type);
    return mrb_obj_new(mrb, class, argc, args);
}

void mrgss_iv_create(mrb_state *mrb, mrb_value object, const char* name, mrb_value value) {
    mrb_sym symbol = mrb_intern_static(mrb, name, strlen(name));
    mrb_iv_set(mrb, object, symbol, value);
}

mrb_value mrgss_iv_get(mrb_state *mrb, mrb_value object, const char *name) {
    mrb_sym symbol = mrb_intern_static(mrb, name, strlen(name));
    return mrb_iv_get(mrb, object, symbol);
}

int mrgss_is_disposable(mrb_state *mrb, mrb_value object) {
    void* data = DATA_PTR(object);
    if (data) {
        return 1;
    }
    return 0;
}

void mrgss_raise(mrb_state *mrb, struct RClass *exception, const char *message) {
    mrb_raisef(mrb, exception, "MRGSS error: %s", message);
    printf("MRGSS error: %s", message);
}

mrb_bool mrgss_object_is_a(mrb_state *mrb, mrb_value object, const char *mrgss_class_name) {
    return mrb_obj_is_kind_of(mrb, object, mrgss_get_class(mrb, mrgss_class_name));
}

