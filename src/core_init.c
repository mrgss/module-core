#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <mruby.h>
#include <mruby/data.h>
#include <mruby/class.h>
#include <mruby/variable.h>
#include <stdio.h>
#include <string.h>
#include <mrgss.h>

static struct RClass *mrgss;

void
mrb_mrgss_core_gem_init(mrb_state *mrb) {
    mrgss = mrb_define_module(mrb, "MRGSS");
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
}

void
mrb_mrgss_core_gem_final(mrb_state* mrb) {
    /* finalizer */
}

struct RClass* mrgss_module(){
    return mrgss;
};

void mrgss_raise(mrb_state *mrb, struct RClass *exception, const char *message) {
    mrb_raisef(mrb, exception, "MRGSS error: %S", message);
}
